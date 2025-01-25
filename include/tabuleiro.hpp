#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include <iostream>
#include <vector>
#include <string>
#include <sstream>



class Tabuleiro {
        private:
            int linhas;
            int colunas;
            std::vector<std::vector<char>> grid;

        public:
            Tabuleiro(int linhas, int colunas, char valorInicial);
        
            void exibirTabuleiro() const;
            void atualizarCelula(int linha, int coluna, char valor);
            std::string getEstadoLimpo();
            std::vector<char> getCleanState();
            std::vector<std::vector<char>> getGrid();
            ~Tabuleiro();
    };

#endif