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


/**
 * @class Minimax
 * @brief Implementa o algoritmo Minimax para tomada de decisão no jogo da velha.
 */

class Minimax {
    private:
        char valorGanhador;///< Armazena o símbolo do jogador vencedor.
        std::string jogador1; ///< Nome do primeiro jogador.
        std::string jogador2; ///< Nome do segundo jogador.
        char humano; ///< Símbolo do jogador humano.
        char cpu;///< Símbolo do jogador CPU.
    public:

        /**
         * @brief Construtor da classe Minimax.
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         * @param humano Símbolo do jogador humano.
         * @param cpu Símbolo do jogador CPU.
         */
        Minimax(std::string jogador1, std::string jogador2, char humano, char cpu);

        /**
         * @brief Obtém todas as jogadas possíveis no tabuleiro.
         * @param board Estado atual do tabuleiro.
         * @return Um vetor contendo as coordenadas das jogadas possíveis.
         */
        std::vector<std::vector<int>> jogadasPossiveis(Tabuleiro board);

        /**
         * @brief Realiza uma jogada no tabuleiro.
         * @param board Estado atual do tabuleiro.
         * @param coordenadas Posição da jogada.
         * @param valor Símbolo do jogador que está realizando a jogada.
         * @return Um novo tabuleiro atualizado com a jogada.
         */
        Tabuleiro jogada(Tabuleiro board, const std::vector<int>& coordenadas,char valor);

        /**
         * @brief Encontra a melhor jogada para a CPU.
         * @param board Estado atual do tabuleiro.
         * @param jogador Símbolo do jogador atual.
         * @param minimizing Define se a jogada deve minimizar ou maximizar a pontuação.
         * @return Coordenadas da melhor jogada encontrada.
         */
        std::vector<int> melhoraco(Tabuleiro board,char jogador ,bool minimizing = false);

        /**
         * @brief Implementação do algoritmo Minimax.
         * @param board Estado atual do tabuleiro.
         * @param jogador Símbolo do jogador atual.
         * @param eu Símbolo do jogador que chamou a função.
         * @param maxdepth Profundidade máxima de busca.
         * @param depth Profundidade atual da busca.
         * @return Um valor inteiro representando a pontuação da jogada.
         */
        int minimax(Tabuleiro board, char jogador, char eu, int maxdepth, int depth = 0);

        /**
         * @brief Destrutor da classe Minimax.
         */
        ~Minimax();

    
};

#endif