#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iomanip>
#include <map>

/**
 * @class Jogador
 * @brief Representa um jogador, armazenando informações como apelido, nome e estatísticas de jogos.
 */
class Jogador {
    
    private:
        /**
         * @brief Apelido do jogador.
         */
        std::string _apelido;

        /**
        * @brief Nome completo do jogador.
        */
        std::string _nome;

        /**
         * @brief Estatísticas do jogador, organizadas por jogo.
         *
         * O mapa associa o nome do jogo (std::string) a um par contendo:
         * - Primeiro elemento: número de vitórias.
         * - Segundo elemento: número de derrotas.
         */
        std::map<std::string, std::pair<int, int>> _estatisticas; //map que armazena [Nome do Jogo] {vitórias,}

    public:
        /**
         * @brief Construtor que inicializa o jogador com o nome, apelido e estatísticas fornecidas.
         *
         * @param apelido Apelido do jogador.
         * @param nome Nome completo do jogador.
         * @param vitVelha Número de vitórias no jogo da velha.
         * @param vitLig4 Número de vitórias no jogo Lig4.
         * @param vitReversi Número de vitórias no jogo Reversi.
         * @param derVelha Número de derrotas no jogo da velha.
         * @param derLig4 Número de derrotas no jogo Lig4.
         * @param derReversi Número de derrotas no jogo Reversi.
         */
        Jogador(std::string, std::string, int, int, int, int, int, int);
        /**
         * @brief Construtor que inicializa o jogador com 0 vitórias e 0 derrotas.
         *
         * @param apelido Apelido do jogador.
         * @param nome Nome completo do jogador.
         */
        Jogador(std::string, std::string);

        /**
         * @brief Retorna o nome completo do jogador.
         *
         * @return Nome do jogador.
         */
        std::string GetNome();
        /**
         * @brief Retorna o apelido do jogador.
         *
         * @return Apelido do jogador.
         */
        std::string GetApelido() const;
        /**
         * @brief Adiciona uma vitória ao jogador para o jogo especificado.
         *
         * @param jogo Nome do jogo (ex: "velha", "lig4", "reversi").
         */
        void SomarVit(const std::string&);
        /**
         * @brief Adiciona uma derrota ao jogador para o jogo especificado.
         *
         * @param jogo Nome do jogo (ex: "velha", "lig4", "reversi").
         */
        void SomarDer(const std::string&);

        /**
         * @brief Retorna o número de vitórias do jogador para o jogo especificado.
         *
         * @param jogo Nome do jogo (ex: "velha", "lig4", "reversi").
         * @return Número de vitórias no jogo.
         */
        int GetVit(const std::string&);
        /**
         * @brief Retorna o número de derrotas do jogador para o jogo especificado.
         *
         * @param jogo Nome do jogo (ex: "velha", "lig4", "reversi").
         * @return Número de derrotas no jogo.
         */
        int GetDer(const std::string&);

        /**
         * @brief Destrutor da classe Jogador.
         */
        ~Jogador();
};

#endif