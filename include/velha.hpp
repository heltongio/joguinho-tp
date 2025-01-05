#ifndef VELHA_HPP
#define  VELHA_HPP
#include <iostream>
#include <string>
#include "jogos.hpp"
#include "tabuleiro.hpp"

class Velha:public Jogos{
    protected:
        char vencedor;
        Tabuleiro tabuleiro;
    public:
        Velha(std::string nomeJogo,std::string jogador1, std::string jogador2)
        : Jogos(nomeJogo,jogador1, jogador2), tabuleiro(3, 3, '|') {}

        void iniciarJogo(std::string nomeJogo) override;
        void verificaJogada(int linha, int coluna, char valor) override;
        void criaTabuleiro() override;
        char verificaGanhador() override;
        bool verificaDiagonais(const std::string& estado);
        bool verificaColuna(const std::string& estado, int coluna);
        bool verificaLinha(const std::string& estado, int linha);
        ~Velha();
};

#endif