/**
 * @file gerente.hpp
 * @brief Declaração da classe CadastroJogadores para gerenciamento de jogadores.
 *
 * Esta classe permite cadastrar, remover e atualizar jogadores, além de
 * armazenar e recuperar os dados de um arquivo.
 */

#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "jogador.hpp"
#include <limits.h>
#include <algorithm>
#include <limits>


/**
 * @class CadastroJogadores
 * @brief Classe responsável por gerenciar o cadastro de jogadores.
 */
class CadastroJogadores {
    private:
        std::vector<Jogador> jogadores; ///< Vetor que armazenará os dados do txt com o objeto Jogador
        std::string arquivo; ///< Caminho do arquivo contendo os dados dos jogadores

        /**
         * @brief Coleta os dados do arquivo e preenche o vetor de jogadores.
         */
        void PullJogadores();
        /**
         * @brief Salva os dados dos jogadores no arquivo.
         */

        void PushJogadores();
    
    public:

        /**
        * @brief Construtor padrão.
        */
        CadastroJogadores() = default;

        /**
        * @brief Construtor que recebe o caminho do arquivo.
        * @param caminho Caminho do arquivo contendo os dados dos jogadores.
        */
        CadastroJogadores(std::string);

        /**
         * @brief Inicializa o vetor de jogadores com os dados do arquivo txt.
         */
        void ConstruirVetor();

        /**
         * @brief Adicona um jogador com nenhuma vitoria/derrota com o contrato <apelido> <nome>
         * @param apelido Apelido do jogador.
         * @param nome Nome completo do jogador.
         */
        void CadastrarJogador(const std::string, const std::string);

        /**
         * @brief Remove um jogador do cadastro utilizando o apelido <apelido>.
         * @param apelido Apelido do jogador a ser removido.
         */
        void RemoverJogador(const std::string);

        /**
         * @brief Salva os dados dos jogadores no arquivo.
         */
        void SalvarArquivo(); 

        /**
         * @brief Verifica se um jogador está cadastrado.
         * @param apelido Apelido do jogador.
         * @return O apelido do jogador, caso encontrado.
         * @throws std::runtime_error Se o jogador não estiver cadastrado.
         */
        std::string VerificaJogadores(std::string apelido);

        /**
         * @brief Ordena os jogadores em ordem alfabética pelo apelido.
         */
        void OrganizaJogadores();

        /**
         * @brief Adiciona uma vitória ao jogador em um jogo específico.
         * @param apelido Apelido do jogador.
         * @param jogo Nome do jogo ("velha", "lig4", "reversi").
         */
        void AddVit(const std::string, const std::string);

        /**
         * @brief Adiciona uma derrota ao jogador em um jogo específico.
         * @param apelido Apelido do jogador.
         * @param jogo Nome do jogo ("velha", "lig4", "reversi").
         */
        void AddDer(const std::string, const std::string);

        /**
         * @brief Exibe a lista de jogadores e seus dados.
         */
        void PrintJogadores();

        /**
         * @brief Destrutor da classe.
         */
        ~CadastroJogadores(); //Destrutor
        
};

#endif