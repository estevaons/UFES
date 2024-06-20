#include<stdio.h>
#include"Campeonato.h"



int main(){

    //criando campeonato
    tCampeonato* mundial = criaCampeonato("Mundial", 2);

    // criando atletas
    tAtleta* atl1 = criaAtleta("atl1",32143,40,1.65,78.6,"atacante");
    tAtleta* atl2 = criaAtleta("atl2", 4234,43,1.87,87.6,"goleiro");
    tAtleta* atl3 = criaAtleta("atl3",4324,34,1.86,76.8,"atacante");
    tAtleta* atl4 = criaAtleta("atl4",4271,30,1.96,86.4,"goleiro");

    //usando funções de atleta
    float alturaAtleta1 = retornaAltura(atl1);
    float pesoAtleta3 = retornaPeso(atl3);
    char *nomeAtleta4 = retornaNome(atl4);


    // criando times
    tTime* brasil = CriaTime("brasil",2);
    tTime* argentina = CriaTime("argentina",2);

    //usando funções de time
    tTime* adicionaJogador(brasil,atl1);
    tTime* adicionaJogador(brasil,atl2);
    tTime* adicionaJogador(argentina,atl3);
    tTime* adicionaJogador(argentina,atl4);
    char* nomeDoTime1= retornaNomeDoTime(brasil);
    char* nomeDoTime2= retornaNomeDoTime(argentina);
    int qtdJogadoresTime1 = retornaQtdJogadoresDoTime(brasil);
    int qtdJogadoresTime2 = retornaQtdJogadoresDoTime(argentina);

    //criando partidas
    tPartida* jogoDeIda = criaPartida(brasil,argentina,"dia-01/02/2025");
    tPartida* jogoDeVolta = criaPartida(brasil,argentina,"dia-02-02/2025");

    //usando funções de partidas
    AtribuiVencedor(jogoDeIda, brasil);
    AtribuiVencedor(jogoDeVolta, brasil);
    tTime* vencedorPartida1 = retornaVencedor(jogoDeIda);
    tTime* vencedorPartida2 = retornaVencedor(jogoDeVolta);
    int numGolsPartida1 = numeroDeGolsDaPartida(jogoDeIda);
    int numGolsPartida2 = numeroDeGolsDaPartida(jogoDeVolta);
    tAtleta* artilheiroPartida1 = artilheiroDaPartida(jogoDeIda);
    tAtleta* artilheiroPartida2 = artilheiroDaPartida(jogoDeVolta);
    int numeroDeFaltasPartida1 = numeroDeFaltas(jogoDeIda);
    int numeroDeFaltasPartida2 = numeroDeFaltas(jogoDeVolta);


    //usando funções de campeonato
    adicionaPartida(mundial,jogoDeIda);
    adicionaPartida(mundial,jogoDeVolta);
    tTime* vencedorCamp = retnornaTimeVencedor(mundial);
    tAtleta* artilheiroDoCampeonato = retornaArtilheiroDoCampeonato(mundial);


    //libera
    void liberaAtleta(atl1);
    void liberaAtleta(atl2);
    void liberaAtleta(atl3);
    void liberaAtleta(atl4);
    void liberaTime(brasil);
    void liberaTime(argentina);
    void liberaPartida(jogoDeIda);
    void liberaPartida(jogoDeVolta);
    void liberaCampeonato(mundial);






    return 0;
}