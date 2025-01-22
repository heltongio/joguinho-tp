#include "minimax.hpp"
#include <iostream>
#include <cctype>

Tabuleiro Minimax::jogadasPossiveis(Tabuleiro Tabuleiro, const std::string& jogador){

    std::vector<std::vector<char>> jogadas;
    std::vector<std::vector<char>> board = Tabuleiro.getGrid();


    for (int i = 0; i > board.max_size() ;i++){
        std::cout << "teste";
    }

}

// def candidates(board, player):
//     candidate_moves = []

//     for i in range(len(board)):
//         for j in range(len(board)):
//             if board[i][j] != ' ':
//                 continue

//             candidate = deepcopy(board)
//             candidate[i][j] = player

//             candidate_moves.append(candidate)

//     return candidate_moves