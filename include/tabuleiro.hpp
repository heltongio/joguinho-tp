#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

/**
 * @class Tabuleiro
 * @brief Representa um tabuleiro que pode ser utilizado para diferentes aplicações.
 * 
 * A classe Tabuleiro oferece funcionalidades para criar, exibir, atualizar e manipular um tabuleiro de jogo
 * com valores organizados em células. O tabuleiro utiliza delimitadores para representar colunas e mantém
 * os valores dentro de uma matriz.
 */

class Tabuleiro {
        private:
            int linhas; /**< Número de linhas do tabuleiro. */
            int colunas; /**< Número de colunas do tabuleiro. */
            std::vector<std::vector<char>> grid; /**< Matriz que representa o estado do tabuleiro. */


        public:
            /**
             * @brief Construtor que cria um tabuleiro com valores iniciais.
             *
             * @param linhas Número de linhas do tabuleiro.
             * @param colunas Número de colunas do tabuleiro.
             * @param valorInicial Valor inicial para as células do tabuleiro.
             */
            Tabuleiro(int linhas, int colunas, char valorInicial);

            /**
             * @brief Construtor que cria o tabuleiro a partir de um vetor linear de valores.
             * 
             * @param child Vetor de caracteres representando o estado inicial do tabuleiro.
             */
            Tabuleiro(const std::vector<char>& child);

            /**
             * @brief Exibe o tabuleiro no console.
             * 
             * Mostra o estado atual do tabuleiro, incluindo os índices das linhas e colunas.
             */
            void exibirTabuleiro() const;

            /**
             * @brief Atualiza o valor de uma célula específica no tabuleiro.
             * 
             * @param linha Índice da linha da célula a ser atualizada (baseado em zero).
             * @param coluna Índice da coluna da célula a ser atualizada (baseado em zero).
             * @param valor Novo valor para a célula.
             */
            void atualizarCelula(int linha, int coluna, char valor);

             /**
             * @brief Obtém o estado do tabuleiro como uma string sem delimitadores.
             * 
             * @return String representando os valores do tabuleiro, sem os delimitadores '|' e '\n'.
             */
            std::string getEstadoLimpo();

            /**
             * @brief Obtém o estado do tabuleiro como um vetor linear.
             * 
             * Inclui os valores válidos das células ('X', 'O', ' ' ou '\n').
             * 
             * @return Vetor de caracteres representando o estado do tabuleiro.
             */
            std::vector<char> getCleanState();

            /**
             * @brief Define o estado do tabuleiro com base em outro objeto Tabuleiro.
             * 
             * @param Tab Objeto Tabuleiro cujo estado será copiado.
             */
            void setTabuleiro(Tabuleiro Tab);

            /**
             * @brief Retorna a matriz que representa o estado do tabuleiro.
             * 
             * @return Matriz de caracteres que representa o estado atual do tabuleiro.
             */
            std::vector<std::vector<char>> getGrid();

            /**
             * @brief Destrutor da classe Tabuleiro.
             * 
             * Libera os recursos utilizados pela classe (se aplicável).
             */
            ~Tabuleiro();
    };

#endif