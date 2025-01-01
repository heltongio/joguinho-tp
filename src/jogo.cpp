#include "jogo.hpp"
#include "tabuleiro.hpp"


Tabuleiro Jogo::iniciarJogo(const std::string& nomeDoJogo){
    if (nomeDoJogo == "R") {
        Tabuleiro tabuleiro(8, 8, '|');
        tabuleiro.exibirTabuleiro();
        std::cout<<"teste"<<std::endl;
        tabuleiro.atualizarCelula(2,2,'X');
        tabuleiro.atualizarCelula(2,4,'X');
        tabuleiro.exibirTabuleiro();
        return tabuleiro;
    } else if (nomeDoJogo == "V") {
        Tabuleiro tabuleiro(3,3 , '|');
        tabuleiro.exibirTabuleiro();
        return tabuleiro;
    } else if (nomeDoJogo == "L") {
        Tabuleiro tabuleiro(7, 6, '|');
        tabuleiro.exibirTabuleiro();
        tabuleiro.exibirTabuleiro();
        return tabuleiro;
    } else {
        std::cerr << "Jogo não reconhecido!\n";
        return Tabuleiro(0, 0, '\0');}
}
Jogo::~Jogo() {
    return;
}