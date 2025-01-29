//Cabeçalho Reversi
#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "gerente.hpp"
#include <string>


/**
 * @class Reversi
 * @brief Classe responsável por implementar os movimentos e regras do jogo Reversi
 */
class Reversi : public Jogos
{
private:
    Tabuleiro tabuleiro; //Tabuleiro do jogo
    std::string vencedor; //Nome do jogador vencedor
    int jogadas; //Contador de jogadas realizadas
<<<<<<< HEAD
    /**
     * @brief Verifica se os valores passados são validos para jogada
     * @param linha Linha do tabuleiro (tem que estar entre 1 e 8)
     * @param coluna Coluna do tabuleiro (tem que estar entre 1 e 8)
     * @param valor Char do jogador atual (X ou O)
     * @param jogador Nome do jogador atual
     * @return true se a jogada é válida, false caso contrário
     */
    bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override; //Verifica se a jogada é possível
    
    /**
     * @brief Verifica se o jogo terminou em empate
     * @return true se o jogo terminou em empate, false caso contrário
     */
    bool verificaEmpate();

    /**
     * @brief Verifica se o jogador venceu
     * @param jogador1 Nome do jogador 1
     * @param jogador2 Nome do jogador 2
     * @param valor Char do jogador atual (X ou O)
     * @param minimax Se o método está sendo chamado pelo minimax
     * @return true se o jogador venceu, false caso contrário
     */
    bool verificaGanhador(std::string jogador1, std::string jogador2, char valor,bool minimax = false) override;

    /**
     * @biref Inicializa o tabuleiro 8 por 8 com as peças centrais
     */
    void criaTabuleiro() override;

    /**
     * @brief Inicia a Recursão de Verificação se a Jogada Realmente pode acontecer (após verificação de validade)
     * @param linha linha inicial da jogada
     * @param coluna coluna inicial da jogada
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool iniciaRecursao(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Diagonal Superior Esquerda
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoDSE(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Diagonal Superior
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoS(int linha, int coluna, char jogador, bool opcao); 

    /**
     * @brief Realiza a recursão para verificar a Diagonal Superior Direita
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoDSD(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Esquerda
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoE(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Direita
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoD(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Diagonal Inferior Esquerda
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoDIE(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Inferior
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoI(int linha, int coluna, char jogador, bool opcao);

    /**
     * @brief Realiza a recursão para verificar a Diagonal Inferior Direita
     * @param linha linha que está sendo verificada no momento
     * @param coluna coluna inicial da jogada sendo verificada no momento
     * @param jogador Char do jogador atual (X ou O)
     * @param opcao 0 apenas para verificação da validade da jogada, 1 para atualizar o tabuleiro caso a jogada seja válida
     * @return true se a jogada é possível e/ou foi realizada, false caso contrário
     */
    bool recursaoDID(int linha, int coluna, char jogador, bool opcao);

public:
    /**
     * @brief Construtor da classe Reversi
     * @param jogador1 Nome do jogador 1
     * @param jogador2 Nome do jogador 2
     * @param manager Gerente de jogadores
     */
=======

    void criaTabuleiro() override;

    bool recursaoDSE(int linha, int coluna, char jogador, bool opcao); //Recursão para a diagonal superior esquerda
    bool recursaoS(int linha, int coluna, char jogador, bool opcao); //Recursão superior
    bool recursaoDSD(int linha, int coluna, char jogador, bool opcao); //Recursão para a diagonal superior direita
    bool recursaoE(int linha, int coluna, char jogador, bool opcao); //Recursão para a esquerda
    bool recursaoD(int linha, int coluna, char jogador, bool opcao); //Recursão para a direita
    bool recursaoDIE(int linha, int coluna, char jogador, bool opcao); //Recursão para a diagonal inferior esquerda
    bool recursaoI(int linha, int coluna, char jogador, bool opcao); //Recursão inferior
    bool recursaoDID(int linha, int coluna, char jogador, bool opcao); //Recursão para a diagonal inferior direita

public:
    bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override; //Verifica se a jogada é possível
    bool verificaEmpate(); //Verifica se o jogo terminou em empate
    bool verificaGanhador(std::string jogador1, std::string jogador2, char valor,bool minimax = false) override; //Verifica se o jogador venceu
    bool iniciaRecursao(int linha, int coluna, char jogador, bool opcao); //Quando 0 verifica a validade do movimento, quando 1 atualiza os valores do tabuleiro
>>>>>>> f114f8af2991643100f5c2f23993922d6614ab49
    Reversi(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);
    
    /**
     * @brief Inicia o jogo Reversi
     */
    void iniciarJogo() override;

    /**
     * @brief Destrutor da classe Reversi
     */
    ~Reversi();

    /**
     * @brief Realiza uma jogada no tabuleiro (não utlizado)
     * @param linha Linha da jogada
     * @param coluna Coluna da jogada
     * @param jogador Char do jogador atual (X ou O)
     * @return true se a jogada foi realizada, false caso contrário
     */
    bool realizarJogada(int linha, int coluna, char jogador);
    
};
#endif
