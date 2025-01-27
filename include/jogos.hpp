#ifndef JOGOS_HPP
#define  JOGOS_HPP
#include <iostream>
#include <string>
#include "gerente.hpp"

class Jogos{
    protected:
        std::string jogador1;
        std::string jogador2;
        std::string nomeJogo;
        CadastroJogadores& manager;
    public:
        Jogos(std::string jogador1, std::string jogador2,CadastroJogadores& manager);
        virtual void iniciarJogo();
        virtual bool verificaJogada(int linha, int coluna, char valor, std::string jogador) = 0;
        virtual void criaTabuleiro() = 0;
        virtual bool verificaGanhador(std::string jogador1, std::string jogador2, char valor) = 0;
        virtual ~Jogos();};

#endif