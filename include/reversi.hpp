//Cabeçalho Reversi
#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "gerente.hpp"
#include <string>


//classe que implementa o jogo Reversi
class Reversi : public Jogos
{
private:
    Tabuleiro tabuleiro; //Tabuleiro do jogo
    std::string vencedor; //Nome do jogador vencedor
    int jogadas; //Contador de jogadas realizadas

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
    Reversi(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);
    void iniciarJogo() override; //Metodo para iniciar o jogo
    bool realizarJogada(int linha, int coluna, char jogador); //Realiza uma jogada no tabuleiro
    ~Reversi();
};
#endif
