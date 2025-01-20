//Arquivo .cpp
#include "reversi.hpp"
#include <iostream>
#include <cctype>
#include <limits>


Reversi::Reversi(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager)
    : Jogos(jogador1, jogador2, manager), tabuleiro(8, 8, ' '), jogadas(0) {
        tabuleiro.atualizarCelula(3, 3, 'O');
        tabuleiro.atualizarCelula(3, 4, 'X');
        tabuleiro.atualizarCelula(4, 3, 'X');
        tabuleiro.atualizarCelula(4, 4, 'O');
    }

Reversi::~Reversi() {
    return;
}

void Reversi::iniciarJogo() {   
    char jogadorAtual = 'X'; // O jogador X sempre começa
    tabuleiro.exibirTabuleiro(); // Mostra o tabuleiro vazio
    std::string entrada;
    int linha, coluna;
    while (true) {

        // Pede ao jogador atual para escolher uma linha e uma coluna
        std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", insira a linha e a coluna para sua jogada (1-8): ";

        for (int i = 0; i < 8; i++) {
            for (int j = 1; j < 16; (j + 2))
            {
                if(tabuleiro.getGrid()[i][j] == ' ' && !verificaFeito(i, j, jogadorAtual, 0, 0)) {
                    
                }
                else{
                    std::cout << "Não há jogadas disponíveis para " << (jogadorAtual == 'X' ? jogador1 : jogador2) << ". O próximo jogador deve jogar.\n";
                    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
                }
            }
        }


        
        getline(std::cin >> std::ws, entrada);
        linha = entrada[0] - '0';
        coluna = entrada[2] - '0';

        while(verificaJogada(linha, coluna, jogadorAtual)) {
            tabuleiro.exibirTabuleiro(); // Mostra o tabuleiro atualizado
            std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", insira o novo valor para sua jogada: ";
            getline(std::cin, entrada);
            linha = entrada[0] - '0';
            coluna = entrada[2] - '0';
        }
        jogadas++; // Incrementa o número de jogadas

        //Alterna para o próximo jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';


    }
}


bool Reversi::verificaJogada(int linha, int coluna, char jogador) {
    
    if (linha < 1 || linha > 8 || coluna < 1 || coluna > 8) {
        std::cout << "Entrada inválida. Insira dois números entre 1 e 8.\n";
        return false;
    }

    if (tabuleiro.getGrid()[linha - 1][(coluna - 1) * 2 + 1] != ' ') {
        std::cout << "Jogada inválida. A posição já está ocupada. Tente novamente.\n";
        return false;
    }

    if (!verificaFeito(linha - 1, coluna - 1, jogador, 1, 0)) {
        std::cout << "Jogada incorreta. Tente novamente com uma jogada possível\n";
    }

    return true;
}

bool Reversi::verificaFeito(int linha, int coluna, char jogador, bool opcao, int sentido) {

    int keep = 0;

    char jogador_op;
    jogador_op = (jogador == 'X') ? 'O' : 'X';

    switch (sentido){ //inicia a repercução de verificação do movimento
    case 0:
        if(linha - 1 >= 0 && tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == jogador_op) {
            keep += verificaFeito(linha - 1, coluna, jogador, opcao, 2); //inicia recursão para verificar a linha superior
            if(coluna - 1 >= 0 && tabuleiro.getGrid()[linha - 1][coluna * 2 - 1] == jogador_op) {
                keep += verificaFeito(linha - 1, coluna - 1, jogador, opcao, 1); //inicia recursão para verificar a diagonal superior esquerda
            }
            if(coluna + 1 <= 7 && tabuleiro.getGrid()[linha - 1][coluna * 2 + 3] == jogador_op) {
                keep += verificaFeito(linha - 1, coluna + 1, jogador, opcao, 3); //inicia recursão para verificar a diagonal superior direita
            }
        }
        if(coluna - 1 >= 0 && tabuleiro.getGrid()[linha][coluna * 2 - 1] == jogador_op) {
            keep += verificaFeito(linha, coluna - 1, jogador, opcao, 4); //inicia recursão para verificar a linha esquerda
        }
        if(coluna + 1 <= 7 && tabuleiro.getGrid()[linha][coluna * 2 + 3] == jogador_op) {
            keep += verificaFeito(linha, coluna + 1, jogador, opcao, 5); //inicia recursão para verificar a linha direita
        }
        if(linha + 1 <= 7 && tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == jogador_op) {
            keep += verificaFeito(linha + 1, coluna, jogador, opcao, 7); //inicia recursão para verificar a linha inferior
            if(coluna - 1 >= 0 && tabuleiro.getGrid()[linha + 1][coluna * 2 - 1] == jogador_op) {
                keep += verificaFeito(linha + 1, coluna - 1, jogador, opcao, 6); //inicia recursão para verificar a diagonal inferior esquerda
            }
            if(coluna + 1 <= 7 && tabuleiro.getGrid()[linha + 1][coluna * 2 + 3] == jogador_op) {
                keep += verificaFeito(linha + 1, coluna + 1, jogador, opcao, 8); //inicia recursão para verificar a diagonal inferior direita
            }
        }
        break;
    case 1:  //repercução da diagonal superior esquerda
        if (linha - 1 < 0 && coluna - 1 < 0) return false;
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 - 1] == jogador_op) keep += verificaFeito(linha - 1, coluna - 1, jogador, opcao, 1);
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 - 1] == jogador) keep++;
        break;
    case 2: //repercução da linha superior
        if (linha - 1 < 0) return false;
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == jogador_op) keep += verificaFeito(linha - 1, coluna, jogador, opcao, 2);
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == jogador) keep++;
        break;
    case 3: //repercução da diagonal superior direita
        if (linha - 1 < 0 && coluna + 1 > 8) return false;
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 3] == jogador_op) keep += verificaFeito(linha - 1, coluna + 1, jogador, opcao, 3);
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 3] == jogador) keep++;
        break;
    case 4: //repercução da linha esquerda
        if (coluna - 1 < 0) return false;
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 - 1] == jogador_op) keep += verificaFeito(linha, coluna - 1, jogador, opcao, 4);
        else if(tabuleiro.getGrid()[linha - 1][coluna * 2 - 1] == jogador) keep++;
        break;
    case 5: //repercução da linha direita
        if (coluna + 1 > 7) return false;
        else if(tabuleiro.getGrid()[linha][coluna * 2 + 3] == jogador_op) keep += verificaFeito(linha, coluna + 1, jogador, opcao, 5);
        else if(tabuleiro.getGrid()[linha][coluna * 2 + 3] == jogador) keep++;
        break;
    case 6: //repercução da diagonal inferior esquerda
        if (linha + 1 > 7 && coluna - 1 < 8) return false;
        else if(tabuleiro.getGrid()[linha + 1][coluna * 2 - 1] == jogador_op) keep += verificaFeito(linha + 1, coluna - 1, jogador, opcao, 6);
        else if(tabuleiro.getGrid()[linha + 1][coluna * 2 - 1] == jogador) keep++;
        break;
    case 7: //repercução da linha inferior
        if (linha + 1 > 7) return false;
        else if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == jogador_op) keep += verificaFeito(linha + 1, coluna, jogador, opcao, 7);
        else if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == jogador) keep++;
        break;
    case 8: //repercução da diagonal inferior direita
        if (linha + 1 > 7 && coluna + 1 > 8) return false;
        else if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 3] == jogador_op) keep += verificaFeito(linha + 1, coluna + 1, jogador, opcao, 8);
        else if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 3] == jogador) keep++;
        break; 
    default:
        break;
    
    }

    if (keep > 0) {
        if (opcao) {
            tabuleiro.atualizarCelula(linha, coluna, jogador); //atualiza as peças do tabuleiro
        }
        return true;
    }
    else return false;
}