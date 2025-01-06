#ifndef JOGOS_HPP
#define  JOGOS_HPP
#include <iostream>
#include <string>


class Jogos{
    protected:
        std::string jogador1;
        std::string jogador2;
        std::string nomeJogo;
    public:
        Jogos(std::string jogador1, std::string jogador2);
        virtual void iniciarJogo();
        virtual bool verificaJogada(int linha, int coluna, char valor, std::string jogador) = 0;
        virtual void criaTabuleiro() = 0;
        virtual bool verificaGanhador() = 0;
        ~Jogos();};

#endif