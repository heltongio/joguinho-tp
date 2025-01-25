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

    bool verificaJogada(int linha, int coluna, char jogador); //Verifica se a jogada é possível
    bool verificaFeito(int linha, int coluna, char jogador, bool opcao, int sentido); //Quando 0 verifica a validade do movimento, quando 1 atualiza os valores do tabuleiro
    bool verificaGanhador(char jogador); //Verifica se o jogador venceu

public:
    Reversi(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);
    void iniciarJogo() override; //Metodo para iniciar o jogo
    bool realizarJogada(int linha, int coluna, char jogador); //Realiza uma jogada no tabuleiro
    ~Reversi();
};
#endif
