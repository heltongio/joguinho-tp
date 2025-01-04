#ifndef JOGOS_HPP
#define  JOGOS_HPP
#include <iostream>
#include <string>


class Jogos{
    protected:
        std::string jogador1;
        std::string jogador2;
    public:
        Jogos(std::string jogador1, std::string jogador2);
        virtual void iniciarJogo();
        virtual void verificaJogada(int linha, int coluna, char valor);
        virtual void criaTabuleiro();
        virtual char verificaGanhador();
        ~Jogos();};

#endif