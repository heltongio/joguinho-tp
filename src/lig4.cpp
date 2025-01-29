// Arquivo .cpp
#include "lig4.hpp" // Inclui o cabeçalho da classe Lig4 que contém sua definição
#include <iostream> // Biblioteca padrão para manipulação de entrada e saída de dados
#include <cctype> // Biblioteca usada para funções de manipulação de caracteres
#include <limits> // Biblioteca para acessar os limites de variáveis numéricas

// Construtor da classe Lig4
// Este método é chamado automaticamente ao criar um objeto Lig4.
// Ele inicializa os atributos jogador1, jogador2, e manager na classe base "Jogos",
// e também configura o tabuleiro com dimensões de 6x7 e células vazias (' ').
// O número de jogadas é inicializado como 0.
Lig4::Lig4(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager)
    : Jogos(jogador1, jogador2, manager), tabuleiro(6, 7, ' '), jogadas(0) {}

// Método para iniciar o jogo Lig4
// Este método implementa a lógica principal do jogo e o loop que continua até
// que haja um vencedor ou o tabuleiro esteja cheio.
void Lig4::iniciarJogo() {
    char jogadorAtual = 'X'; // Define que o jogador 'X' sempre começa o jogo
    tabuleiro.exibirTabuleiro(); // Exibe o tabuleiro vazio no início do jogo

    while (true) { // Loop principal que gerencia o fluxo do jogo
        int coluna; // Variável para armazenar a coluna escolhida pelo jogador
        std::string entrada; // Armazena a entrada bruta do jogador

        // Solicita ao jogador atual que insira a coluna desejada
        std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2)
                  << ", insira a coluna para sua jogada (1-7): ";
        std::cin >> entrada;

        // Verifica se a entrada do jogador é válida (um único dígito numérico entre 1 e 7)
        if (entrada.size() == 1 && std::isdigit(entrada[0])) {
            coluna = std::stoi(entrada); // Converte a entrada de string para inteiro

            // Garante que o número está dentro dos limites aceitáveis
            if (coluna >= 1 && coluna <= 7) {
                // Tenta realizar a jogada na coluna especificada
                if (realizarJogada(coluna - 1, jogadorAtual)) { // Ajusta para índice baseado em zero
                    jogadas++; // Incrementa o contador de jogadas realizadas
                    tabuleiro.exibirTabuleiro(); // Atualiza o tabuleiro visível no terminal

                    // Verifica se o jogador atual ganhou o jogo
                    if (verificaGanhador(jogadorAtual)) {
                        std::cout << "Parabéns! "
                                  << (jogadorAtual == 'X' ? jogador1 : jogador2)
                                  << " venceu!\n";
                        manager.AddVit(jogadorAtual == 'X' ? jogador1 : jogador2, "lig4"); // Adiciona vitória
                        manager.AddDer(jogadorAtual == 'X' ? jogador2 : jogador1, "lig4"); // Adiciona derrota
                        return; // Encerra o método e o jogo
                    }

                    // Verifica se o tabuleiro está cheio e declara empate
                    if (jogadas == 6 * 7) {
                        std::cout << "O jogo terminou em empate!\n";
                        return; // Encerra o jogo
                    }

                    // Alterna o turno para o próximo jogador ('X' ou 'O')
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

        // Limpa o buffer de entrada para evitar problemas com entradas inválidas
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Verifica se o jogador atual conseguiu uma sequência de 4 peças
// Este método percorre as linhas, colunas e diagonais do tabuleiro para identificar
// uma sequência de 4 peças consecutivas do jogador atual.
bool Lig4::verificaGanhador(char jogador) {
    // Verifica todas as linhas do tabuleiro
    for (int linha = 0; linha < 6; ++linha) {
        if (verificaLinha(linha, jogador)) {
            return true; // Retorna verdadeiro se encontrar sequência na linha
        }
    }

    // Verifica todas as colunas do tabuleiro
    for (int coluna = 0; coluna < 7; ++coluna) {
        if (verificaColuna(coluna, jogador)) {
            return true; // Retorna verdadeiro se encontrar sequência na coluna
        }
    }

    // Verifica as diagonais do tabuleiro
    if (verificaDiagonais(jogador)) {
        return true; // Retorna verdadeiro se encontrar sequência em diagonal
    }

    return false; // Retorna falso se nenhuma condição de vitória for atendida
}

// Realiza a jogada na coluna especificada
// Este método tenta colocar a peça do jogador na coluna escolhida, na posição mais baixa disponível.
bool Lig4::realizarJogada(int coluna, char jogador) {
    // Garante que a coluna está dentro dos limites do tabuleiro
    if (coluna < 0 || coluna >= 7) {
        return false; // Retorna falso se a coluna for inválida
    }

    // Percorre a coluna de baixo para cima procurando a primeira célula vazia
    for (int linha = 5; linha >= 0; --linha) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == ' ') {
            tabuleiro.atualizarCelula(linha, coluna, jogador); // Coloca a peça do jogador
            return true; // Retorna verdadeiro ao realizar a jogada
        }
    }
    return false; // Retorna falso se a coluna estiver cheia
}

// Verifica uma sequência de 4 peças consecutivas em uma linha específica
bool Lig4::verificaLinha(int linha, char jogador) {
    int consecutivos = 0; // Contador para peças consecutivas do jogador
    for (int coluna = 0; coluna < 7; ++coluna) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == jogador) {
            consecutivos++; // Incrementa o contador se encontrar peça do jogador
            if (consecutivos == 4) {
                return true; // Retorna verdadeiro se encontrar 4 peças consecutivas
            }
        } else {
            consecutivos = 0; // Reinicia o contador se encontrar peça de outro jogador ou espaço vazio
        }
    }
    return false; // Retorna falso se não encontrar sequência na linha
}

// Verifica uma sequência de 4 peças consecutivas em uma coluna específica
bool Lig4::verificaColuna(int coluna, char jogador) {
    int consecutivos = 0; // Contador para peças consecutivas do jogador
    for (int linha = 0; linha < 6; ++linha) {
        if (tabuleiro.getGrid()[linha][coluna * 2 + 1] == jogador) {
            consecutivos++; // Incrementa o contador se encontrar peça do jogador
            if (consecutivos == 4) {
                return true; // Retorna verdadeiro se encontrar 4 peças consecutivas
            }
        } else {
            consecutivos = 0; // Reinicia o contador se encontrar peça de outro jogador ou espaço vazio
        }
    }
    return false; // Retorna falso se não encontrar sequência na coluna
}

// Verifica uma sequência de 4 peças consecutivas nas diagonais
bool Lig4::verificaDiagonais(char jogador) {
    // Aqui poderia ser implementada a lógica para verificar diagonais principais e secundárias
    return false;
}

// Destrutor da classe Lig4
// Este método é chamado automaticamente quando um objeto Lig4 é destruído.
Lig4::~Lig4() {
    return;
}
