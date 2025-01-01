#ifndef JOGO_HPP
#define  JOGO_HPP
#include <iostream>
#include <string>
#include "tabuleiro.hpp"

class Jogo{
    public:
    Tabuleiro iniciarJogo(const std::string& nomeDoJogo);
    ~Jogo();
};

#endif