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

bool Lig4::verificaGanhador(char){ // metodo provisorio para evitar erro
    return true;
}


//Realiza uma jogada na coluna especificada
bool Lig4::realizarJogada(int coluna, char jogador) {
    //Verifica se a coluna está dentro dos limites
    if (coluna < 0 || coluna >= 7) {
        return false;
    }

    //Procura a primeira célula disponível de baixo para cima
    for (int linha = 5; linha >= 0; --linha) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == ' ') {
            tabuleiro.atualizarCelula(linha, coluna, jogador); //Atualiza o tabuleiro
            return true;
        }
    }
    return false; //Se a coluna estiver cheia, a jogada é invalida
}

//Verifica se há uma sequência de 4 peças na linha
bool Lig4::verificaLinha(int linha, char jogador) {
    int consecutivos = 0;
    for (int coluna = 0; coluna < 7; ++coluna) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == jogador) {
            consecutivos++;
            if (consecutivos == 4) {
                return true; // Encontrou uma sequência de 4
            }
        } else {
            consecutivos = 0; // Reinicia a contagem se encontrar outra peça
        }
    }
    return false;
}

//Verifica se há uma sequência de 4 peças na coluna
bool Lig4::verificaColuna(int coluna, char jogador) {
    int consecutivos = 0;
    for (int linha = 0; linha < 6; ++linha) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == jogador) {
            consecutivos++;
            if (consecutivos == 4) {
                return true; //Encontrou uma sequência de 4
            }
        } else {
            consecutivos = 0; //Reinicia a contagem se encontrar outra peça
        }
    }
    return false;
}

//Verifica se há uma sequência de 4 peças nas diagonais
bool Lig4::verificaDiagonais(char jogador) {
    auto grid = tabuleiro.getGrid();
    for (int linha = 0; linha <= 5; ++linha) {
        for (int coluna = 0; coluna <= 6; ++coluna) {
            //Verifica a diagonal principal (esquerda para direita)
            if (linha <= 2 && coluna <= 3 &&
                grid[linha][coluna * 2 + 1] == jogador &&
                grid[linha + 1][(coluna + 1) * 2 + 1] == jogador &&
                grid[linha + 2][(coluna + 2) * 2 + 1] == jogador &&
                grid[linha + 3][(coluna + 3) * 2 + 1] == jogador) {
                return true;
            }
            // Verifica a diagonal inversa (direita para esquerda)
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
