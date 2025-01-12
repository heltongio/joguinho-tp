//Arquivo .cpp
#include "lig4.hpp"
#include <iostream>
#include <cctype>

//Construtor: inicializa o jogo Lig4 com dois jogadores e o tabuleiro
Lig4::Lig4(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager)
    : Jogos(jogador1, jogador2, manager), tabuleiro(6, 7, ' '), jogadas(0) {}

//Inicia o jogo Lig4
void Lig4::iniciarJogo() {
    char jogadorAtual = 'X'; // O jogador X sempre começa
    tabuleiro.exibirTabuleiro(); //Mostra o tabuleiro vazio

    while (true) {
        int coluna;
        //Pede ao jogador atual para escolher uma coluna
        std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", insira a coluna para sua jogada: ";
        std::cin >> coluna;

        //Tenta realizar a jogada
        if (realizarJogada(coluna - 1, jogadorAtual)) {
            jogadas++; //Incrementa o número de jogadas
            tabuleiro.exibirTabuleiro(); //Mostra o tabuleiro atualizado

            //Verifica se o jogador atual venceu
            if (verificaGanhador(jogadorAtual)) {
                std::cout << "Parabéns! " << (jogadorAtual == 'X' ? jogador1 : jogador2) << " venceu!\n";
                manager.AddVit(jogadorAtual == 'X' ? jogador1 : jogador2, "lig4");
                manager.AddDer(jogadorAtual == 'X' ? jogador2 : jogador1, "lig4");
                return; //Termina o jogo
            }

            //Verifica se o tabuleiro está cheio (empate)
            if (jogadas == 6 * 7) {
                std::cout << "O jogo terminou em empate!\n";
                return;
            }

            //Alterna para o próximo jogador
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        } else {
            //Informa que a jogada foi invalida
            std::cout << "Jogada invalida. Tente novamente.\n";
        }
    }
}