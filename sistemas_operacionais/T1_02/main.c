#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 4  // Número de threads produtoras

// Estrutura que representa uma ordem de medicamento
typedef struct {
    char nomePaciente[50];
    int idMedicamento;
    int quantidade;
} Pedido;

// Buffer circular
Pedido buffer[N];

// Posições de escrita e leitura no buffer
int writepos = 0;
int readpos = 0;

// Semáforos
sem_t lock;
sem_t full;
sem_t empty;

// Função produtora
void* produtor(void* arg) {
    
    // Cria um pedido e abre o arquivo
    Pedido pedido;
    char* nomeArquivo = (char*)arg;
    FILE* arquivo = fopen(nomeArquivo, "r");

    // Enquanto houver pedidos no arquivo, insere no buffer
    while (fscanf(arquivo, "%s %d %d", pedido.nomePaciente, &pedido.idMedicamento, &pedido.quantidade) == 3) {
        
        // Wait nos semáforos
        sem_wait(&empty);
        sem_wait(&lock);

        // Insere o pedido no buffer e atualiza o índice de escrita
        buffer[writepos] = pedido;
        writepos = (writepos + 1) % N;  // indice circular

        // Post nos semáforos
        sem_post(&lock);
        sem_post(&full);
    }

    // insere um pedido vazio para sinalizar o fim do arquivo
    sem_wait(&empty);
    sem_wait(&lock);

    // Pedido vazio inicializado com -1
    Pedido ordemVirtual = {"", -1, -1};
    buffer[writepos] = ordemVirtual;
    writepos = (writepos + 1) % N;  // indice circular

    sem_post(&lock);
    sem_post(&full);


    // Fecha o arquivo e retorna
    fclose(arquivo);

    return NULL;
}

// Função consumidora
void* consumidor(void* arg) {
    // Variável para indicar quantos produtores ainda estão ativos
    int ativas = N;

    // Enquanto houver produtores ativos, fica no loop consumindo
    while (1) {

        // Wait nos semáforos
        sem_wait(&full);
        sem_wait(&lock);

        // Le o pedido do buffer e atualiza o índice de leitura
        Pedido pedido = buffer[readpos];
        readpos = (readpos + 1) % N;  // indice circular


        // Post nos semáforos
        sem_post(&lock);
        sem_post(&empty);

        // Se for pedido vazio, decrementa uma produtora ativa'
        if (pedido.idMedicamento == -1) {
            ativas--;
        }

        // Se nao houver mais produtores ativos, sai do loop
        if (ativas == 0) {
            break;
        }

        // Imprime o pedido
        if (pedido.idMedicamento != -1) {
            printf("CONSUMIDOR: %s %d %d\n", pedido.nomePaciente, pedido.idMedicamento, pedido.quantidade);
        }
    }
}

int main() {

    // Cria as threads
    pthread_t produtoras[N];
    pthread_t consumidora;

    // Inicializa os semáforos
    sem_init(&lock, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);

    // Nomes dos arquivos
    char* arquivos[N] = {"terminal1.txt", "terminal2.txt", "terminal3.txt", "terminal4.txt"};

    // Cria as threads produtoras
    for (int i = 0; i < N; i++) {
        pthread_create(&produtoras[i], NULL, produtor, (void*)arquivos[i]);
    }

    // Cria a thread consumidora
    pthread_create(&consumidora, NULL, consumidor, NULL);

    // Espera a thread consumidora terminar
    pthread_join(consumidora, NULL);

    // Join nas threads produtoras para garantir que todas terminaram
    for (int i = 0; i < N; i++) {
        pthread_join(produtoras[i], NULL);
    }

    // Destroi os semáforos e termina
    sem_destroy(&lock);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
