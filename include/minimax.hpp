#ifndef MINIMAX_HPP
#define MINIMAX_HPP
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "tabuleiro.hpp"


class Minimax {
    private:
        std::shared_ptr<char> valorGanhador;
        Velha velha;
    public:
        std::vector<std::vector<char>> jogadasPossiveis(Tabuleiro board, const char valor);
        void imprimirTabuleiro(const std::vector<std::vector<char>>& tabs);
        int pontuaGanhadores(Tabuleiro board);
        bool is_win(Tabuleiro board);

    
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
