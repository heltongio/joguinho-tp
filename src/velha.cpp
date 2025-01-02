#include "velha.hpp"



void Velha::iniciarJogo(){

}

void Velha::criaTabuleiro(){
    tabuleiro.exibirTabuleiro();
}

void Velha::verificaJogada(int linha, int coluna, char valor){
    if (linha >= 0 && linha <= 3 && coluna >= 0 && coluna <= 3) {
        tabuleiro.atualizarCelula(linha,coluna,valor);
        tabuleiro.exibirTabuleiro();
    } else {
        std::cerr << "Posição inválida no tabuleiro!\n";
    }
    
}

void Velha::verificaGanhador(){

}

Velha::~Velha(){

}