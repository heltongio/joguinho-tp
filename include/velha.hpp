#ifndef VELHA_HPP
#define  VELHA_HPP
#include <iostream>
#include <string>
#include <memory>
#include <regex>
#include <algorithm>
#include "minimax.hpp"
#include "jogos.hpp"
#include "tabuleiro.hpp"
#include "gerente.hpp"

class Velha:public Jogos{
    protected:
        char vencedor;
        Tabuleiro tabuleiro;
    public:
        Velha(Tabuleiro board)
        : Jogos("", "", *(std::make_shared<CadastroJogadores>().get())), tabuleiro(board) {}
        Velha(std::string jogador1, std::string jogador2,CadastroJogadores& manager)
        : Jogos(jogador1, jogador2, manager), tabuleiro(3, 3, '|') {}
        
        void iniciarJogo() override;
        bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override;
        void criaTabuleiro() override;
        bool verificaGanhador(std::string jogador1, std::string jogador2, char valor, bool minimax) override;
        bool verificaDiagonais(const std::string& estado, char valor);
        bool verificaColuna(const std::string& estado, int coluna, char valor);
        bool verificaLinha(const std::string& estado, int linha, char valor);
        bool verificaTabuleiroCompleto(const std::string& jogador1, const std::string& jogador2, bool minimax);
        bool solicitarJogada(std::string& jogador,int& linha, int& coluna);
        std::string frase();
        bool jogada(std::string jogador1, std::string jogador2, char valor);
        ~Velha();
};

#endif