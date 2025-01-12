//Cabeçalho Lig4
#ifndef LIG4_HPP
#define LIG4_HPP

#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "gerente.hpp"
#include <string>

//Classe que implementa o jogo Lig4
class Lig4 : public Jogos {
private:
    Tabuleiro tabuleiro; //Tabuleiro do jogo
    std::string vencedor; //Nome do jogador vencedor
    int jogadas; //Contador de jogadas realizadas

    //Metodos auxiliares para verificar condições de vitoria
    bool verificaLinha(int linha, char jogador); //Verifica vitoria em uma linha
    bool verificaColuna(int coluna, char jogador); //Verifica vitoria em uma coluna
    bool verificaDiagonais(char jogador); //Verifica vitoria em diagonais
    bool verificaGanhador(char jogador); //Verifica se o jogador atual venceu

public:
    Lig4(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);
    void iniciarJogo() override; //Metodo para iniciar o jogo
    bool realizarJogada(int coluna, char jogador); //Realiza uma jogada no tabuleiro
    ~Lig4();
};

#endif
