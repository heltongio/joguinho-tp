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

    std::vector<std::vector<int>> tabsjogPossiveis;
    std::string boardLimpo = board.getEstadoLimpo();
    std::vector<char> listLimpa(boardLimpo.begin(), boardLimpo.end());


    for (std::vector<char>::size_type i = 0; i < listLimpa.size(); ++i) {
        if (listLimpa[i] == ' ') {
            int linha = i / 3;
            int coluna = i % 3;
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

//precisa implementar codigo de otimização
int Minimax::minimax(Tabuleiro board, char jogador, char eu, int maxdepth, int depth) {
    Velha velha(board);


    if (velha.verificaGanhador(jogador2, jogador1, cpu, true)) {
        return 10 - depth;
    }
    if (velha.verificaGanhador(jogador1, jogador2, humano, true)) {
        return depth - 10;
    }
    if (velha.verificaTabuleiroCompleto(jogador1, jogador2, true)) {
        return 0;  // Empate
    }


    if (depth >= maxdepth) {
        return 0;
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
        Tabuleiro resultado = jogada(board, vetor, cpu);
        int valor = minimax(resultado, cpu == 'X' ? 'O' : 'X', cpu,9);
        if (valor > melhorValor){
            melhorValor = valor;
            besta = vetor;
        }
    }
    return besta;

}


Minimax::~Minimax(){
    return;}