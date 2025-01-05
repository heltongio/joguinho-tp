#include "jogos.hpp"
#include "velha.hpp"

Jogos::Jogos(std::string nomeJogo,std::string jogador1,std::string jogador2){
    this->jogador1 = jogador1;
    this->jogador2 = jogador2;
    this->nomeJogo = nomeJogo;

    iniciarJogo(nomeJogo);
}

void Jogos::iniciarJogo(std::string nomeJogo){
    if (nomeJogo == "V"){
        Velha jogoVelha();
    }else if(nomeJogo == "R"){
        std::cout << "jogo em construção" << std::endl;
    }else if(nomeJogo == "L"){
        std::cout << "jogo em construção" << std::endl;
    }else{
        std::cout << "jogo não reconhecido" << std::endl;
    }

   
}

void Jogos::verificaJogada(int linha, int coluna, char valor){

}

char Jogos::verificaGanhador(){
  //problema no retorno não void 
}

void Jogos::criaTabuleiro(){

}


Jogos::~Jogos() {
    return;
}