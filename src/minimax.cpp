#include "minimax.hpp"
#include <iostream>
#include <cctype>

Minimax::Minimax(std::string jogador1, std::string jogador2, char humano, char cpu){
    this->jogador1 = jogador1;
    this->jogador2 = jogador2;
    this->humano = humano;
    this->cpu = cpu;
}

std::vector<std::vector<char>> Minimax::jogadasPossiveis(Tabuleiro board,char valor){

    std::vector<std::vector<char>> tabsjogPossiveis;
    std::string boardLimpo = board.getEstadoLimpo();

    std::vector<char> listLimpa(boardLimpo.begin(), boardLimpo.end());

    for (size_t i = 0; i < listLimpa.size(); ++i) {
        if (listLimpa[i] != ' ') {
            continue;}

        std::vector<char> possivel = listLimpa;
        possivel[i] = valor;

        tabsjogPossiveis.push_back(possivel);
    }


    return tabsjogPossiveis;

}

//equisito
void Minimax::imprimirTabuleiro(const std::vector<std::vector<char>>& tabs) {
    for (const auto& linha : tabs) {
        for (char c : linha) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

int Minimax::is_win(Tabuleiro board) {
    Velha velha(board);

    if (velha.verificaTabLimpo(board.getEstadoLimpo())) {
        return 0;  // Empate ou jogo inicial
    }
    if (velha.verificaGanhador(jogador2, jogador1, cpu)) {
        return 1;  // Vitória do CPU
    }
    if (velha.verificaGanhador(jogador1, jogador2, humano)) {
        return -1; // Vitória do humano
    }
    return 5;  // Jogo em andamento
}



Tabuleiro Minimax::minimax(Tabuleiro board, bool minimizing) {
    int resultado = is_win(board);
    if (resultado != 5) {
        return board;  // Retorna o estado do tabuleiro se já houver resultado
    }

    std::vector<std::vector<char>> children;
    std::vector<char> melhorJogada;

    if (minimizing) {
        int melhorValor = std::numeric_limits<int>::min();
        children = jogadasPossiveis(board, humano);

        for (const auto& child : children) {
            Tabuleiro novoTabuleiro(child);
            auto jogada = minimax(novoTabuleiro, false);

            Tabuleiro tabuleiroTeste(jogada);
            int valor = is_win(tabuleiroTeste);

            if (valor > melhorValor) {
                melhorValor = valor;
                melhorJogada = child;  // Guarda a melhor jogada
            }
        }
    } else {
        int melhorValor = std::numeric_limits<int>::max();
        children = jogadasPossiveis(board, cpu);

        for (const auto& child : children) {
            Tabuleiro novoTabuleiro(child);
            auto jogada = minimax(novoTabuleiro, true);

            Tabuleiro tabuleiroTeste(jogada);
            int valor = is_win(tabuleiroTeste);

            if (valor < melhorValor) {
                melhorValor = valor;
                melhorJogada = child;  // Guarda a melhor jogada
            }
        }
    }

    return melhorJogada;  // Retorna apenas a melhor jogada
}

Minimax::~Minimax(){
    return;}









// int Minimax::minimax(Tabuleiro board, bool minimizing = false){
//     if (is_win(board) != 5){
//         return is_win(board);
//     }

//     if (minimizing){
//         float value = float('-inf')

//         for (child in jogadasPossiveis(board, CPU_PLAYER)){
//             value = max(value, minimax(child, False))
//         }

//     }else{
//         value = float('+inf')

//         for child in candidates(board, HUMAN_PLAYER):
//             value = min(value, minimax(child, True))
//     }
//     return value

// int Minimax::pontuaGanhadores(Tabuleiro board){
//     if (is_win(board)){
//         return 1;
//     }
//     if (is_win(board)){
//         return -1;
//     }
//     return 0;
// }




// i, j = randint(0, 2), randint(0, 2)

// while board[i][j] != ' ':
//     i, j = randint(0, 2), randint(0, 2)

// board[i][j] = CPU_PLAYER// candidate_moves = candidates(board, CPU_PLAYER)
// board = max(candidate_moves, key=minimax)

// candidate_moves = candidates(board, CPU_PLAYER)
// board = max(candidate_moves, key=minimax)