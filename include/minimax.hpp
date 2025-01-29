#ifndef MINIMAX_HPP
#define MINIMAX_HPP
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "tabuleiro.hpp"
#include "velha.hpp"
#include <limits>




class Minimax {
    private:
        char valorGanhador;
        std::string jogador1;
        std::string jogador2;
        char humano;
        char cpu;
    public:
        Minimax(std::string jogador1, std::string jogador2, char humano, char cpu);
        std::vector<std::vector<int>> jogadasPossiveis(Tabuleiro board);
        Tabuleiro jogada(Tabuleiro board, const std::vector<int>& coordenadas,char valor);
        std::vector<int> melhoraco(Tabuleiro board,char jogador ,bool minimizing = false);
        int minimax(Tabuleiro board, char jogador, char eu, int maxdepth, int depth = 0);
        ~Minimax();

    
};

#endif