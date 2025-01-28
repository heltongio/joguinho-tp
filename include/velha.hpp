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

/**
 * @class Velha
 * @brief Classe que implementa o jogo da velha.
 *
 * Esta classe gerencia o jogo da velha, incluindo a lógica do jogo, verificação de vitória/empate,
 * e interação com os jogadores.
 */



class Velha:public Jogos{
    protected:
        char vencedor;///< Armazena o caractere do jogador vencedor ('X' ou 'O').
        Tabuleiro tabuleiro;///< Objeto que representa o tabuleiro do jogo.
    public:
         /**
         * @brief Construtor da classe Velha.
         * @param board Objeto Tabuleiro que será usado no jogo, para acessar classes no minimax.
         */

        Velha(Tabuleiro board)
        : Jogos("", "", *(std::make_shared<CadastroJogadores>().get())), tabuleiro(board) {}

        /**
         * @brief Construtor da classe Velha.
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         * @param manager Referência para o gerenciador de jogadores.
         */
        Velha(std::string jogador1, std::string jogador2,CadastroJogadores& manager)
        : Jogos(jogador1, jogador2, manager), tabuleiro(3, 3, '|') {}
        
        /**
         * @brief Inicia o jogo da velha.
         *
         * Este método é responsavel por pela inicialização do jogo da velha.
        */
        void iniciarJogo() override;

        /**
         * @brief Verifica se uma jogada é válida.
         * @param linha Linha da jogada (1-3).
         * @param coluna Coluna da jogada (1-3).
         * @param valor Caractere da jogada ('X' ou 'O').
         * @param jogador Nome do jogador que está realizando a jogada.
         * @return true se a jogada for válida, false caso contrário.
        */
        bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override;

        /**
         * @brief Cria e exibe o tabuleiro do jogo da velha.
        */
        void criaTabuleiro() override;

        /**
         * @brief Verifica se há um vencedor no jogo.
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         * @param valor Caractere a ser verificado ('X' ou 'O').
         * @param minimax Indica se a verificação está sendo feita dentro do algoritmo Minimax.
         * @return true se houver um vencedor, false caso contrário.
        */
        bool verificaGanhador(std::string jogador1, std::string jogador2, char valor, bool minimax) override;

        /**
         * @brief Verifica se há uma sequência vencedora nas diagonais do tabuleiro.
         * @param estado String que representa o estado atual do tabuleiro.
         * @param valor Caractere a ser verificado ('X' ou 'O').
         * @return true se houver uma sequência vencedora, false caso contrário.
        */
        bool verificaDiagonais(const std::string& estado, char valor);

        /**
         * @brief Verifica se há uma sequência vencedora em uma coluna do tabuleiro.
         * @param estado String que representa o estado atual do tabuleiro.
         * @param coluna Coluna a ser verificada (0-2).
         * @param valor Caractere a ser verificado ('X' ou 'O').
         * @return true se houver uma sequência vencedora, false caso contrário.
        */
        bool verificaColuna(const std::string& estado, int coluna, char valor);

        /**
         * @brief Verifica se há uma sequência vencedora em uma linha do tabuleiro.
         * @param estado String que representa o estado atual do tabuleiro.
         * @param linha Linha a ser verificada (0-2).
         * @param valor Caractere a ser verificado ('X' ou 'O').
         * @return true se houver uma sequência vencedora, false caso contrário.
        */
        bool verificaLinha(const std::string& estado, int linha, char valor);

        /**
         * @brief Verifica se o tabuleiro está completamente preenchido (empate).
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         * @param minimax Indica se a verificação está sendo feita dentro do algoritmo Minimax.
         * @return true se o tabuleiro estiver completo, false caso contrário.
        */
        bool verificaTabuleiroCompleto(const std::string& jogador1, const std::string& jogador2, bool minimax);

        /**
         * @brief Solicita ao jogador que insira uma jogada.
         * @param jogador Nome do jogador.
         * @param linha Referência para armazenar a linha da jogada.
         * @param coluna Referência para armazenar a coluna da jogada.
         * @return true se a jogada for válida, false caso contrário.
        */
        bool solicitarJogada(std::string& jogador,int& linha, int& coluna);

        /**
         * @brief Retorna uma frase aleatória de um arquivo de texto.
         * @return Uma string contendo uma frase aleatória.
        */
        std::string frase();

        /**
         * @brief Realiza uma jogada no tabuleiro.
         * @param jogador1 Nome do primeiro jogador.
         * @param jogador2 Nome do segundo jogador.
         * @param valor Caractere da jogada ('X' ou 'O').
         * @return true se o jogo terminar após a jogada, false caso contrário.
        */
        bool jogada(std::string jogador1, std::string jogador2, char valor);

        /**
         * @brief Destrutor da classe Velha.
        */
        ~Velha();
};

#endif