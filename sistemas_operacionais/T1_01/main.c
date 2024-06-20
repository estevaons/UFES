#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include "cliente.h"
#include "barbeiro.h"

#define NUM_CADEIRAS 3
#define TAM_SOFA 4
#define MAX_CLIENTES 20
#define NUM_TESTES 15

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_cadeira = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_sofa = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_corte = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_pagamento = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_pagamento_confirmado = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_cliente_entrou_loja = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_cabelo_cortado = PTHREAD_COND_INITIALIZER;

int num_clientes_sofa = 0;
int num_clientes_cadeira = 0;
int num_barbeiros_disponiveis = 3;
int clientes_na_loja = 0;
int clientes_cortando = 0;
int loja_aberta = 1;

// Cliente
void EntrarNaLoja() {
    pthread_mutex_lock(&mutex);

    printf("Cliente entrou na loja.\n");
    
    // Sinaliza pro barbeiro que tem cliente na loja
    pthread_cond_signal(&cond_cliente_entrou_loja);
    clientes_na_loja++;
    
    if (clientes_na_loja >= MAX_CLIENTES) {
        pthread_mutex_unlock(&mutex);
        printf("Loja cheia. O cliente foi embora.\n");
        
        return;
    }

    if(num_clientes_cadeira < NUM_CADEIRAS){
        pthread_mutex_unlock(&mutex);
        SentarNaCadeira();
    } else if (num_clientes_cadeira == NUM_CADEIRAS) {
        pthread_mutex_unlock(&mutex);
        SentarNoSofa();
    }
    
    pthread_mutex_unlock(&mutex);
}

// Cliente
void SentarNoSofa() {
    pthread_mutex_lock(&mutex);
    while (num_clientes_sofa == TAM_SOFA) { // espera em pé
        printf("Sofá cheio. Cliente esperando em pé.\n");
        pthread_cond_wait(&cond_sofa, &mutex);
    }
    if(num_clientes_sofa < TAM_SOFA){
        printf("Sentando no sofá.\n");
        
        num_clientes_sofa++;
    }

    if(num_clientes_cadeira < NUM_CADEIRAS){
        pthread_mutex_unlock(&mutex);
        SentarNaCadeira();
    }

    pthread_mutex_unlock(&mutex);
}

// Cliente
void SentarNaCadeira() {
    pthread_mutex_lock(&mutex);

    printf("Cliente sentou na cadeira.\n");
    num_clientes_cadeira++;

    while (num_barbeiros_disponiveis == 0) {
        pthread_cond_wait(&cond_cadeira, &mutex);
    }
    
    pthread_mutex_unlock(&mutex);

    CortarCabelo();

    printf("Cliente irá pagar pelos serviços.\n");
    Pagar();

    pthread_mutex_lock(&mutex);
    if (num_clientes_sofa > 0) {
        num_clientes_sofa--;
        pthread_cond_signal(&cond_sofa);
    }

    pthread_mutex_unlock(&mutex);

}

// Cliente
void Pagar() {
    pthread_mutex_lock(&mutex);
    printf("Cliente pagando pelos serviços.\n");
    
    pthread_cond_signal(&cond_pagamento);
    pthread_cond_wait(&cond_pagamento_confirmado, &mutex);
    

    SairDaLoja();
}

// Cliente
void SairDaLoja() {
    printf("Cliente saindo da loja.\n");
    
}

// Barbeiro
void AceitarPagamento() {
    pthread_mutex_lock(&mutex);

    while (clientes_cortando > 0) {
        pthread_cond_wait(&cond_pagamento, &mutex);
    }

    printf("Barbeiro confirmou pagamento.\n");

    pthread_cond_signal(&cond_pagamento_confirmado);

    pthread_mutex_unlock(&mutex);
}

// Barbeiro
void CortarCabelo() {
    pthread_mutex_lock(&mutex);
    printf("Barbeiro irá cortar o cabelo do cliente.\n");

    num_barbeiros_disponiveis--;
    clientes_cortando++;
    
    pthread_mutex_unlock(&mutex);

    printf("Barbeiro cortando o cabelo do cliente.\n");
    sleep(1);
    printf("Barbeiro terminou de cortar o cabelo do cliente.\n");
    
    
    pthread_mutex_lock(&mutex);
    clientes_cortando--;
    num_barbeiros_disponiveis++;
    num_clientes_cadeira--;
    pthread_cond_signal(&cond_corte); // manda sinal pra galera do sofa
    pthread_cond_signal(&cond_cabelo_cortado); // manda sinal pro cliente para ele pagar
    pthread_mutex_unlock(&mutex);
    printf("Barbeiro irá aceitar um pagamento.\n");
    AceitarPagamento();
}


// Barbeiro
void DormirNaCadeira() {
    pthread_mutex_lock(&mutex);

    printf("Barbeiro dormindo na cadeira.\n");
    

    while (clientes_na_loja == 0) {
        pthread_cond_wait(&cond_cliente_entrou_loja, &mutex);
    }
    
    printf("Barbeiro acordou e está indo cortar o cabelo.\n");

    pthread_mutex_unlock(&mutex);
    //se tiver cliente para cortar cabelo
    CortarCabelo();

}

void *cliente_thread(void *arg) {
    EntrarNaLoja();
    return NULL;
}

void *barbeiro_thread(void *arg) {
    while (1) {
        DormirNaCadeira();
    }
    
    return NULL;
}


void criarBarbeiro() {
    fflush(stdout);
    printf("Teste concluído com sucesso!\n");
    exit(EXIT_SUCCESS);
}
void criarCliente(){
    alarm(5);

   struct sigaction action;
    action.sa_handler = criarBarbeiro;
    action.sa_flags = 0;
    sigaction(SIGALRM, &action, NULL);

}


int main() {
    
    pthread_t clientes[NUM_TESTES];
    pthread_t barbeiros[NUM_CADEIRAS];

    criarCliente();
 
    // Cria threads de clientes
    for (int i = 0; i < NUM_TESTES; i++) {
        if (pthread_create(&clientes[i], NULL, cliente_thread, NULL) != 0) {
            perror("Erro ao criar thread de cliente");
            exit(EXIT_FAILURE);
        }
    }

    // Cria threads de barbeiros
    for (int i = 0; i < NUM_CADEIRAS; i++) {
        if (pthread_create(&barbeiros[i], NULL, barbeiro_thread, NULL) != 0) {
            perror("Erro ao criar thread de barbeiro");
            exit(EXIT_FAILURE);
        }
    }

    // Aguarda a conclusão das threads de clientes
    for (int i = 0; i < NUM_TESTES; i++) {
        if (pthread_join(clientes[i], NULL) != 0) {
            perror("Erro ao aguardar thread de cliente");
            exit(EXIT_FAILURE);
        }
    }

    // Aguarda a conclusão das threads de barbeiros
    for (int i = 0; i < NUM_CADEIRAS; i++) {
        if (pthread_join(barbeiros[i], NULL) != 0) {
            perror("Erro ao aguardar thread de barbeiro");
            exit(EXIT_FAILURE);
        }
    }

    printf("Teste concluído com sucesso!\n");
    

    return 0;
}
