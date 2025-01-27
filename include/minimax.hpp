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
        // void imprimirTabuleiro(const std::vector<std::vector<char>>& tabs);
        // int pontuaGanhadores(Tabuleiro board);
        // int is_win(Tabuleiro board);
        ~Minimax();

    
};

#endif







// função MINIMAX_ALFA_BETA(estado, profundidade, alfa, beta, maximizando)
//     se profundidade = 0 ou estado é terminal então
//         retorne VALOR(estado)

//     se maximizando então
//         valor_max = -∞
//         para cada filho em SUCESSORES(estado) faça
//             valor = MINIMAX_ALFA_BETA(filho, profundidade - 1, alfa, beta, falso)
//             valor_max = máximo(valor_max, valor)
//             alfa = máximo(alfa, valor_max)
//             se beta <= alfa então
//                 pare  // Poda
//         fim para
//         retorne valor_max

//     senão (minimizando)
//         valor_min = +∞
//         para cada filho em SUCESSORES(estado) faça
//             valor = MINIMAX_ALFA_BETA(filho, profundidade - 1, alfa, beta, verdadeiro)
//             valor_min = mínimo(valor_min, valor)
//             beta = mínimo(beta, valor_min)
//             se beta <= alfa então
//                 pare  // Poda
//         fim para
//         retorne valor_min
