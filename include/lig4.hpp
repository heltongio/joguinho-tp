#ifndef LIG4_HPP
#define LIG4_HPP

#include "jogos.hpp" // Inclui a classe base "Jogos", que será herdada
#include "tabuleiro.hpp" // Inclui a classe "Tabuleiro" para manipular o tabuleiro do jogo

// Classe Lig4
// Representa o jogo de tabuleiro Lig4, derivada da classe base "Jogos"
class Lig4 : public Jogos {
private:
    Tabuleiro tabuleiro; // Objeto responsável por gerenciar o tabuleiro do jogo
    int jogadas; // Contador de jogadas realizadas no jogo

    // Métodos auxiliares para verificar condições de vitória
    bool verificaLinha(int linha, char jogador); // Verifica uma sequência de 4 peças em uma linha
    bool verificaColuna(int coluna, char jogador); // Verifica uma sequência de 4 peças em uma coluna
    bool verificaDiagonais(char jogador); // Verifica uma sequência de 4 peças nas diagonais

public:
    // Construtor da classe Lig4
    // Recebe os nomes dos jogadores e uma referência para o gerenciador de jogadores
    Lig4(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager);

    // Método para iniciar o jogo
    // Contém a lógica principal do jogo e gerencia os turnos
    void iniciarJogo() override;

    // Método para realizar uma jogada
    // Recebe a coluna escolhida e o símbolo do jogador atual
    bool realizarJogada(int coluna, char jogador);

    // Método para verificar se o jogador atual venceu
    // Retorna true se houver uma sequência de 4 peças do jogador
    bool verificaGanhador(char jogador);

    // Destrutor da classe Lig4
    // Realiza limpeza necessária ao destruir um objeto Lig4
    ~Lig4();
};

#endif // LIG4_HPP
