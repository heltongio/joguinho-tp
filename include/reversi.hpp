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
    
    bool verificaLinha(int linha, char jogador); //Verifica vitoria em uma linha
    bool verificaColuna(int coluna, char jogador); //Verifica vitoria em uma coluna
    bool verificaDiagonais(char jogador); //Verifica vitoria em diagonais
    bool verificaGanhador(char jogador); //Verifica se o jogador atual venceu

    bool verificaJogada(int linha, int coluna, char valor, std::string jogador) override; //provisorio
    void criaTabuleiro() override; //provisorio
    bool verificaGanhador(std::string jogador1, std::string jogador2, char valor) override;//provisorio
public:
    Reversi(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);
    void iniciarJogo() override; //Metodo para iniciar o jogo
    bool realizarJogada(int linha, int coluna, char jogador); //Realiza uma jogada no tabuleiro
    ~Reversi();
};
#endif
