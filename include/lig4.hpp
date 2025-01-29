/**
 * @file lig4.hpp
 * @brief Declaração da classe Lig4, que implementa o jogo Lig4.
 */

#ifndef LIG4_HPP
#define LIG4_HPP

#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "gerente.hpp"
#include <string>

/**
 * @class Lig4
 * @brief Classe que implementa o jogo Lig4, derivada da classe base Jogos.
 */
class Lig4 : public Jogos {
private:
    Tabuleiro tabuleiro; ///< Objeto que representa o tabuleiro do jogo.
    std::string vencedor; ///< Nome do jogador vencedor.
    int jogadas; ///< Contador de jogadas realizadas.

    /**
     * @brief Verifica se há uma sequência vencedora em uma linha.
     * @param linha Índice da linha a ser verificada.
     * @param jogador Peça do jogador ('X' ou 'O').
     * @return true se houver uma sequência vencedora, false caso contrário.
     */
    bool verificaLinha(int linha, char jogador);

    /**
     * @brief Verifica se há uma sequência vencedora em uma coluna.
     * @param coluna Índice da coluna a ser verificada.
     * @param jogador Peça do jogador ('X' ou 'O').
     * @return true se houver uma sequência vencedora, false caso contrário.
     */
    bool verificaColuna(int coluna, char jogador);

    /**
     * @brief Verifica se há uma sequência vencedora em qualquer diagonal.
     * @param jogador Peça do jogador ('X' ou 'O').
     * @return true se houver uma sequência vencedora, false caso contrário.
     */
    bool verificaDiagonais(char jogador);

    /**
     * @brief Verifica se o jogador atual venceu o jogo.
     * @param jogador Peça do jogador ('X' ou 'O').
     * @return true se o jogador venceu, false caso contrário.
     */
    bool verificaGanhador(char jogador);

    /**
     * @brief Verifica a validade de uma jogada.
     * @param linha Linha da jogada.
     * @param coluna Coluna da jogada.
     * @param valor Valor da peça ('X' ou 'O').
     * @param jogador Nome do jogador que está realizando a jogada.
     * @return true se a jogada for válida, false caso contrário.
     */
    bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override;

    /**
     * @brief Cria o tabuleiro do jogo.
     */
    void criaTabuleiro() override;

    /**
     * @brief Verifica se há um vencedor no jogo.
     * @param jogador1 Nome do primeiro jogador.
     * @param jogador2 Nome do segundo jogador.
     * @param valor Valor da peça ('X' ou 'O').
     * @param minimax Indica se o método está sendo chamado em contexto de Minimax.
     * @return true se houver um vencedor, false caso contrário.
     */
    bool verificaGanhador(std::string jogador1, std::string jogador2, char valor, bool minimax) override;

public:
    /**
     * @brief Construtor da classe Lig4.
     * @param jogador1 Nome do primeiro jogador.
     * @param jogador2 Nome do segundo jogador.
     * @param manager Referência para o gerenciador de jogadores.
     */
    Lig4(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);

    /**
     * @brief Inicia o jogo Lig4.
     */
    void iniciarJogo() override;

    /**
     * @brief Realiza uma jogada no tabuleiro.
     * @param coluna Índice da coluna (0-6).
     * @param jogador Peça do jogador ('X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    bool realizarJogada(int coluna, char jogador);

    /**
     * @brief Destrutor da classe Lig4.
     */
    ~Lig4();
};

#endif // LIG4_HPP
