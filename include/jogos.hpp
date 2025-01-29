#ifndef JOGOS_HPP
#define  JOGOS_HPP
#include <iostream>
#include <string>
#include "gerente.hpp"

class Jogos{
    protected:
        /**
         * @brief Nome do jogador 1.
         */
        std::string jogador1;

        /**
         * @brief Nome do jogador 2.
         */
        std::string jogador2;

        /**
         * @brief Nome do jogo.
         */
        std::string nomeJogo;

        /**
         * @brief Referência ao gerenciador de cadastro de jogadores.
         */
        CadastroJogadores& manager;
    public:

        /**
         * @brief Construtor da classe Jogos.
         *
         * @param jogador1 Nome do jogador 1.
         * @param jogador2 Nome do jogador 2.
         * @param manager Referência ao objeto CadastroJogadores responsável pelo gerenciamento de jogadores.
         */
        Jogos(std::string jogador1, std::string jogador2,CadastroJogadores& manager);
        /**
         * @brief Método virtual para iniciar o jogo.
         * 
         * Pode ser sobrescrito pelas classes derivadas para implementar o comportamento específico do início de um jogo.
         */
        virtual void iniciarJogo();
        /**
         * @brief Método virtual puro para verificar a jogada.
         * 
         * @param linha Linha onde a jogada foi realizada.
         * @param coluna Coluna onde a jogada foi realizada.
         * @param valor Valor representando a jogada (exemplo: 'X' ou 'O').
         * @param jogador Nome do jogador que fez a jogada.
         * @return `true` se a jogada for válida, `false` caso contrário.
         */
        virtual bool verificaJogada(int linha, int coluna, char valor, std::string jogador) = 0;
        /**
         * @brief Método virtual puro para criar o tabuleiro do jogo.
         */
        virtual void criaTabuleiro() = 0;
        /**
         * @brief Método virtual puro para verificar se há um ganhador.
         *
         * @param jogador1 Nome do jogador 1.
         * @param jogador2 Nome do jogador 2.
         * @param valor Valor representando o jogador (exemplo: 'X' ou 'O').
         * @param minimax Define se a verificação será feita com suporte a algoritmos de IA. Valor padrão: `false`.
         * @return `true` se houver um ganhador, `false` caso contrário.
         */
        virtual bool verificaGanhador(std::string jogador1, std::string jogador2, char valor, bool minimax = false) = 0;
        /**
         * @brief Destrutor virtual da classe Jogos.
         */
        virtual ~Jogos();};

#endif