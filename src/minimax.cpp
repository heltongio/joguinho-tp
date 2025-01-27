#include "minimax.hpp"
#include <iostream>
#include <cctype>

Minimax::Minimax(std::string jogador1, std::string jogador2, char humano, char cpu){
    this->jogador1 = jogador1;
    this->jogador2 = jogador2;
    this->humano = humano;
    this->cpu = cpu;
}

std::vector<std::vector<int>> Minimax::jogadasPossiveis(Tabuleiro board){
    int j = 0;
    std::vector<std::vector<int>> tabsjogPossiveis;
    std::string boardLimpo = board.getEstadoLimpo();
    std::vector<char> listLimpa(boardLimpo.begin(), boardLimpo.end());

    int x = listLimpa.size();

    for (int i = 0; i < listLimpa.size(); ++i) {
        if (listLimpa[i] == ' ') {
            int linha = i / 3;  // A linha é o resultado da divisão inteira por 3
            int coluna = i % 3; // A coluna é o resto da divisão por 3
            tabsjogPossiveis.push_back({linha, coluna});
        }
    }

        return tabsjogPossiveis;
    }

Tabuleiro Minimax::jogada(Tabuleiro board, const std::vector<int>& coordenadas,char valor) {
    Tabuleiro newBoard = board;
    newBoard.atualizarCelula(coordenadas[0], coordenadas[1], valor);

    return newBoard;
}


int Minimax::minimax(Tabuleiro board, char jogador, char eu, int maxdepth, int depth) {
    Velha velha(board);

    if (velha.verificaGanhador(jogador2, jogador1, cpu) && !velha.verificaTabLimpo(board.getEstadoLimpo())) {
        return 10 - depth;  // Vitória do CPU (quanto mais rápido, melhor)
    }
    if (velha.verificaGanhador(jogador1, jogador2, humano) && !velha.verificaTabLimpo(board.getEstadoLimpo())) {
        return depth - 10;  // Vitória do humano (quanto mais rápido, pior para o CPU)
    }
    if (velha.verificaTabLimpo(board.getEstadoLimpo())) {
        return 0;  // Empate
    }

    if (depth >= maxdepth) {
        return 0;  // Limite de profundidade alcançado, considera empate
    }

    std::vector<std::vector<int>> jogadas = jogadasPossiveis(board);

    if (jogador == cpu) { // Maximizar
        int melhorValor = std::numeric_limits<int>::min();

        for (const std::vector<int>& vetor : jogadas) {
            Tabuleiro resultado = jogada(board, vetor, jogador);
            int valor = minimax(resultado, jogador == 'X' ? 'O' : 'X', eu, maxdepth, depth + 1);
            melhorValor = std::max(melhorValor, valor);
        }
        return melhorValor;
    } else { // Minimizar
        int melhorValor = std::numeric_limits<int>::max();

        for (const std::vector<int>& vetor : jogadas) {
            Tabuleiro resultado = jogada(board, vetor, jogador);
            int valor = minimax(resultado, jogador == 'X' ? 'O' : 'X', eu, maxdepth, depth + 1);
            melhorValor = std::min(melhorValor, valor);
        }
        return melhorValor;
    }
}



std::vector<int> Minimax::melhoraco(Tabuleiro board, char jogador,bool minimizing) {

    std::vector<std::vector<int>> jogadas = jogadasPossiveis(board);

    int melhorValor = std::numeric_limits<int>::min();
    std::vector<int> besta;
    for (const std::vector<int>& vetor : jogadas) {
        // std::cout << "começando teste" << std::endl;
        Tabuleiro resultado = jogada(board, vetor, cpu);
        // resultado.exibirTabuleiro();
        int valor = minimax(resultado, cpu == 'X' ? 'O' : 'X', cpu,9);
        // std::cout << "valor: "<<valor<< std::endl;
        if (valor > melhorValor){
            melhorValor = valor;
            besta = vetor;
        }
        // std::cout<< "melhor valor:" << melhorValor << std::endl;
        // board.exibirTabuleiro();
    }
    return besta;

}

//     int resultado = is_win(board);
//     if (resultado != 5) {
//         return board;  // Retorna o estado do tabuleiro se já houver resultado
//     }

//     std::vector<std::vector<char>> children;
//     std::vector<char> melhorJogada;

//     if (minimizing) {
//         int melhorValor = std::numeric_limits<int>::min();
//         children = jogadasPossiveis(board, humano);

//         for (const auto& child : children) {
//             Tabuleiro novoTabuleiro(child);
//             auto jogada = minimax(novoTabuleiro, false);

//             Tabuleiro tabuleiroTeste(jogada);
//             int valor = is_win(tabuleiroTeste);

//             if (valor > melhorValor) {
//                 melhorValor = valor;
//                 melhorJogada = child;  // Guarda a melhor jogada
//             }
//         }
//     } else {
//         int melhorValor = std::numeric_limits<int>::max();
//         children = jogadasPossiveis(board, cpu);

//         for (const auto& child : children) {
//             Tabuleiro novoTabuleiro(child);
//             auto jogada = minimax(novoTabuleiro, true);

//             Tabuleiro tabuleiroTeste(jogada);
//             int valor = is_win(tabuleiroTeste);

//             if (valor < melhorValor) {
//                 melhorValor = valor;
//                 melhorJogada = child;  // Guarda a melhor jogada
//             }
//         }
//     }

//     return melhorJogada;  // Retorna apenas a melhor jogada




// //equisito
// void Minimax::imprimirTabuleiro(const std::vector<std::vector<char>>& tabs) {
//     for (const auto& linha : tabs) {
//         for (char c : linha) {
//             std::cout << c << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// int Minimax::is_win(Tabuleiro board) {
//     Velha velha(board);

//     if (velha.verificaTabLimpo(board.getEstadoLimpo())) {
//         return 0;  // Empate ou jogo inicial
//     }
//     if (velha.verificaGanhador(jogador2, jogador1, cpu)) {
//         return 1;  // Vitória do CPU
//     }
//     if (velha.verificaGanhador(jogador1, jogador2, humano)) {
//         return -1; // Vitória do humano
//     }
//     return 5;  // Jogo em andamento
// }


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