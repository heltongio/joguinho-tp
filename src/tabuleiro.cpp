#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro(int linhas, int colunas, char valorInicial){
    grid.resize(linhas, std::vector<char>(colunas * 2 + 1, ' ')); // Redimensiona a matriz

    for (auto& linha : grid) {
        for (size_t i = 0; i < linha.size(); i += 2) {
            linha[i] = '|'; // Insere os delimitadores |
        }
    }
}

Tabuleiro::Tabuleiro(const std::vector<char>& child){
   int totalElementos = child.size();
   int colunas = static_cast<int>(std::sqrt(totalElementos));
   int linhas = (colunas * colunas == totalElementos) ? colunas : (colunas + 1);
   grid.resize(linhas, std::vector<char>(colunas * 2 + 1, ' '));
   for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
        grid[i][j * 2] = '|'; // Insere os delimitadores |
        grid[i][j * 2 + 1] = child[i * colunas + j];
    }
    grid[i][colunas * 2] = '|'; // Fecha a linha com |
   }
}



void Tabuleiro::exibirTabuleiro() const {

    for (size_t i = 0; i < grid.size(); ++i) {
        std::cout << i + 1 << " ";

        for (const auto& celula : grid[i]) {
            std::cout << celula;}
        std::cout << '\n';}

    std::cout << "   ";
    size_t numColunas = grid[0].size() / 2;
    for (size_t j = 0; j < numColunas; ++j) {
        std::cout << j + 1 << " ";}
    std::cout << '\n';
}


 
void Tabuleiro::atualizarCelula(int linha, int coluna, char valor) {
    grid[linha][coluna * 2 + 1] = valor;
    
}

std::string Tabuleiro::getEstadoLimpo() {
    std::string estadoLimpo;
    for (const auto& linha : grid) {
        for (char c : linha) {
            if (c != '|' && c != '\n') {
                estadoLimpo += c;
            }
        }
    }

    return estadoLimpo;
}

//Função provisoria
std::vector<char> Tabuleiro::getCleanState() {
    std::vector<char> cleanState;
    for (const auto& linha : grid) {
        for (char c : linha) {
            if (c == 'X' || c == 'O' || c == ' ' || c == '\n') {
                cleanState.push_back(c);
            }
        }
    }
    return cleanState;
}

void Tabuleiro::setTabuleiro(Tabuleiro tab){
    grid = tab.getGrid();
}

std::vector<std::vector<char>> Tabuleiro::getGrid(){
    return grid;
}


Tabuleiro::~Tabuleiro(){
    return;
};
