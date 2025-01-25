#include "minimax.hpp"
#include <iostream>
#include <cctype>



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


void Minimax::imprimirTabuleiro(const std::vector<std::vector<char>>& tabs) {
    for (const auto& linha : tabs) {
        for (char c : linha) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

bool Minimax::is_win(Tabuleiro board){

    std::string jogador1;
    std::string jogador2;
    char valor;

    // Chama a função verificaGanhador e recebe o resultado
    bool resultado = velha->verificaGanhador(jogador1, jogador2, valor);

    // Inicializa o ponteiro compartilhado com o valor retornado
    char valorGanhador = valor;

    if (resultado) {
        if (valorGanhador == 'X') {
            return 1;
        } else if (valorGanhador == 'O') {
            return -1;
        }
        return 0;
    }

    return 5;
}


int Minimax::minimax(Tabuleiro board, bool minimizing , char humano, char cpu) {
        int cont = 0;
        if (is_win(board) != 5) {
            return is_win(board);
        }

        if (minimizing) {
            //da uma olhada aq
            int value = std::numeric_limits<int>::min();
            std::vector<std::vector<char>> children = jogadasPossiveis(board, cpu);

            for (const auto& child : children) {
                Tabuleiro novoTabuleiro(children);
                value = std::max(value, minimax(novoTabuleiro, false, humano, cpu));
                cont++;
            }

            // for (const auto& child : children) {
            //     // std::string childEstado(child.begin(), child.end());
            //     Tabuleiro novoTabuleiro(children);
            //     value = std::max(value, minimax(novoTabuleiro[cont], false, humano, cpu));
            // }
            return value;

        } else {
            int value = std::numeric_limits<int>::max();
            std::vector<std::vector<char>> children = jogadasPossiveis(board, humano);

            for (const auto& child : children) {
                std::string childEstado(child.begin(), child.end());
                Tabuleiro novoTabuleiro(children);
                value = std::min(value, minimax(novoTabuleiro, true, humano, cpu));
            }
            return value;
        }
}
    Minimax::~Minimax() {
        delete velha;
    }









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