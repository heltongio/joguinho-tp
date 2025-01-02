#ifndef VELHA_HPP
#define  VELHA_HPP
#include <iostream>
#include <string>
#include "jogos.hpp"
#include "tabuleiro.hpp"

class Velha:public Jogos{
    protected:
        Tabuleiro tabuleiro;
    public:
        Velha(std::string jogador1, std::string jogador2)
        : Jogos(jogador1, jogador2), tabuleiro(3, 3, '|') {}

        void iniciarJogo() override;
        void verificaJogada(int linha, int coluna, char valor) override;
        void criaTabuleiro() override;
        void verificaGanhador() override;
        ~Velha();
};

#endif