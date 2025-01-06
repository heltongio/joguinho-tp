#ifndef VELHA_HPP
#define  VELHA_HPP
#include <iostream>
#include <string>
#include "jogos.hpp"
#include "tabuleiro.hpp"
#include "gerente.hpp"

class Velha:public Jogos{
    protected:
        char vencedor;
        Tabuleiro tabuleiro;
    public:
        Velha(std::string jogador1, std::string jogador2)
        : Jogos(jogador1, jogador2), tabuleiro(3, 3, '|') {}

        void iniciarJogo() override;
        bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override;
        void criaTabuleiro() override;
        bool verificaGanhador() override;
        bool verificaDiagonais(const std::string& estado);
        bool verificaColuna(const std::string& estado, int coluna);
        bool verificaLinha(const std::string& estado, int linha);
        bool jogada(std::string jogador1, std::string jogador2, char valor);
        ~Velha();
};

#endif