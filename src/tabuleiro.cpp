#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro(int linhas, int colunas, char valorInicial){
    grid.resize(linhas, std::vector<char>(colunas * 2 + 1, ' ')); // Redimensiona a matriz

    for (auto& linha : grid) {
        for (size_t i = 0; i < linha.size(); i += 2) {
            linha[i] = '|'; // Insere os delimitadores |
        }
    }
}

void Tabuleiro::exibirTabuleiro() const {
    for (const auto& linha : grid) {
        for (const auto& celula : linha) {
            std::cout << celula; 
        }
        std::cout << '\n'; 
    }
}


 
void Tabuleiro::atualizarCelula(int linha, int coluna, char valor) {
    linha = linha-1;
    coluna = coluna-1;
    grid[linha][coluna * 2 + 1] = valor;




        // if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        //     std::ostringstream ss;
        //     ss << "|" << valor << "|";
        //     // grid[linha][coluna] = ss.str(); 
        // } else {
        //     std::cerr << "Posição inválida no tabuleiro!\n";
        // }
}


Tabuleiro::~Tabuleiro(){
    return;
};
