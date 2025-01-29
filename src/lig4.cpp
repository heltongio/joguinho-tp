/**
 * @file lig4.cpp
 * @brief Implementação do jogo Lig4.
 */

#include "lig4.hpp"
#include <iostream>
#include <cctype>
#include <limits>

/**
 * @brief Construtor da classe Lig4.
 * @param jogador1 Nome do primeiro jogador.
 * @param jogador2 Nome do segundo jogador.
 * @param manager Referência para o gerenciador de jogadores.
 */
Lig4::Lig4(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager)
    : Jogos(jogador1, jogador2, manager), tabuleiro(6, 7, ' '), jogadas(0) {}

/**
 * @brief Inicia o jogo Lig4 e controla o fluxo do jogo.
 */
void Lig4::iniciarJogo() {
    char jogadorAtual = 'X'; // O jogador X sempre começa
    tabuleiro.exibirTabuleiro(); // Mostra o tabuleiro vazio

    while (true) {
        int coluna;
        std::string entrada;

        std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", insira a coluna para sua jogada (1-7): ";
        std::cin >> entrada;

        if (entrada.size() == 1 && std::isdigit(entrada[0])) {
            coluna = std::stoi(entrada);

            if (coluna >= 1 && coluna <= 7) {
                if (realizarJogada(coluna - 1, jogadorAtual)) {
                    jogadas++; 
                    tabuleiro.exibirTabuleiro(); 

                    if (verificaGanhador(jogadorAtual)) {
                        std::cout << "Parabéns! " << (jogadorAtual == 'X' ? jogador1 : jogador2) << " venceu!\n";
                        manager.AddVit(jogadorAtual == 'X' ? jogador1 : jogador2, "lig4");
                        manager.AddDer(jogadorAtual == 'X' ? jogador2 : jogador1, "lig4");
                        return;
                    }

                    if (jogadas == 6 * 7) {
                        std::cout << "O jogo terminou em empate!\n";
                        return;
                    }

                    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
                } else {
                    std::cout << "Jogada inválida. A coluna está cheia ou não existe. Tente novamente.\n";
                }
            } else {
                std::cout << "Entrada inválida. Escolha um número entre 1 e 7.\n";
            }
        } else {
            std::cout << "Entrada inválida. Insira apenas um número entre 1 e 7.\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
 * @brief Verifica se um jogador venceu o jogo.
 * @param jogador Peça do jogador ('X' ou 'O').
 * @return true se o jogador venceu, false caso contrário.
 */
bool Lig4::verificaGanhador(char jogador) {
    for (int linha = 0; linha < 6; ++linha) {
        if (verificaLinha(linha, jogador)) {
            return true;
        }
    }

    for (int coluna = 0; coluna < 7; ++coluna) {
        if (verificaColuna(coluna, jogador)) {
            return true;
        }
    }

    return verificaDiagonais(jogador);
}

/**
 * @brief Realiza uma jogada em uma determinada coluna.
 * @param coluna Índice da coluna (0-6).
 * @param jogador Peça do jogador ('X' ou 'O').
 * @return true se a jogada foi válida, false caso contrário.
 */
bool Lig4::realizarJogada(int coluna, char jogador) {
    if (coluna < 0 || coluna >= 7) {
        return false;
    }

    for (int linha = 5; linha >= 0; --linha) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == ' ') {
            tabuleiro.atualizarCelula(linha, coluna, jogador);
            return true;
        }
    }
    return false;
}

/**
 * @brief Verifica se há uma sequência de quatro peças na mesma linha.
 * @param linha Índice da linha a ser verificada.
 * @param jogador Peça do jogador ('X' ou 'O').
 * @return true se houver uma sequência de quatro, false caso contrário.
 */
bool Lig4::verificaLinha(int linha, char jogador) {
    int consecutivos = 0;
    for (int coluna = 0; coluna < 7; ++coluna) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == jogador) {
            consecutivos++;
            if (consecutivos == 4) {
                return true;
            }
        } else {
            consecutivos = 0;
        }
    }
    return false;
}

/**
 * @brief Verifica se há uma sequência de quatro peças na mesma coluna.
 * @param coluna Índice da coluna a ser verificada.
 * @param jogador Peça do jogador ('X' ou 'O').
 * @return true se houver uma sequência de quatro, false caso contrário.
 */
bool Lig4::verificaColuna(int coluna, char jogador) {
    int consecutivos = 0;
    for (int linha = 0; linha < 6; ++linha) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == jogador) {
            consecutivos++;
            if (consecutivos == 4) {
                return true;
            }
        } else {
            consecutivos = 0;
        }
    }
    return false;
}

/**
 * @brief Verifica se há uma sequência de quatro peças nas diagonais.
 * @param jogador Peça do jogador ('X' ou 'O').
 * @return true se houver uma sequência de quatro, false caso contrário.
 */
bool Lig4::verificaDiagonais(char jogador) {
    auto grid = tabuleiro.getGrid();
    for (int linha = 0; linha <= 5; ++linha) {
        for (int coluna = 0; coluna <= 6; ++coluna) {
            if (linha <= 2 && coluna <= 3 &&
                grid[linha][coluna * 2 + 1] == jogador &&
                grid[linha + 1][(coluna + 1) * 2 + 1] == jogador &&
                grid[linha + 2][(coluna + 2) * 2 + 1] == jogador &&
                grid[linha + 3][(coluna + 3) * 2 + 1] == jogador) {
                return true;
            }
            if (linha >= 3 && coluna <= 3 &&
                grid[linha][coluna * 2 + 1] == jogador &&
                grid[linha - 1][(coluna + 1) * 2 + 1] == jogador &&
                grid[linha - 2][(coluna + 2) * 2 + 1] == jogador &&
                grid[linha - 3][(coluna + 3) * 2 + 1] == jogador) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Destrutor da classe Lig4.
 */
Lig4::~Lig4() {
    return;
}

/**
 * @brief Método provisório para verificar jogada.
 */
bool Lig4::verificaJogada(int linha, int coluna, char valor, std::string jogador) {
    std::vector<std::vector<char>> grid = tabuleiro.getGrid();
    linha = linha - 1;
    coluna = coluna - 1;

    if (grid[linha][coluna * 2 + 1] != ' ') {
        std::cerr << jogador << " posição inválida, tente novamente: ";
        return false;
    }
    return true;
}

/**
 * @brief Método para criar o tabuleiro do jogo.
 */
void Lig4::criaTabuleiro() {
    tabuleiro.exibirTabuleiro();
}
