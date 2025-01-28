//Arquivo .cpp
#include "reversi.hpp"
#include <iostream>
#include <cctype>
#include <limits>


Reversi::Reversi(const std::string& jogador1, const std::string& jogador2, CadastroJogadores& manager)
    : Jogos(jogador1, jogador2, manager), tabuleiro(8, 8, ' '), jogadas(0) {
        tabuleiro.atualizarCelula(3, 3, 'O');
        tabuleiro.atualizarCelula(3, 4, 'X');
        tabuleiro.atualizarCelula(4, 3, 'X');
        tabuleiro.atualizarCelula(4, 4, 'O');
    }


Reversi::~Reversi() {
    return;
}
void Reversi::criaTabuleiro() {
    tabuleiro.exibirTabuleiro();
}

void Reversi::iniciarJogo() {   
    char jogadorAtual = 'X'; // O jogador X sempre começa

    tabuleiro.exibirTabuleiro(); // Mostra o tabuleiro vazio
    std::string entrada;
    int linha, coluna;
    bool movimentoValido = false;
    bool jogadaValida = false;
    bool pularJogada = false;
    bool var = false;
    while (true) {
        

        
        if (jogadas == 0) {
            std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", Faça sua jogada: ";
            getline(std::cin >> std::ws, entrada);
        } else {
            for(int i = 0; i <= 7; i++){
                for(int j = 0; j <= 7; j++){
                    if(tabuleiro.getGrid()[i][j * 2 + 1] == ' '){
                        var = iniciaRecursao(i, j, jogadorAtual, 0);
                        if(var){
                            pularJogada = false;
                            movimentoValido = true;
                            break;
                        }
                    }
                }
                if(movimentoValido){
                    break;
                }
            }
            if(movimentoValido){
                std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", Faça sua jogada: ";
                getline(std::cin, entrada);
            }
            else{
                if(pularJogada){
                    std::cout << "Não há jogadas possíveis para o jogador " << (jogadorAtual == 'X' ? jogador1 : jogador2) << ".\n O jogo acabou.\n";
                    if(verificaEmpate()){
                        std::cout << "O jogo terminou em empate!\n";
                        manager.AddDer(jogador1, "reversi");
                        manager.AddDer(jogador2, "reversi");
                        return;
                    }
                    else if(verificaGanhador(jogador1, jogador2, jogadorAtual, false)){
                        std::cout << "Parabéns! " << jogador1 << " venceu!\n";
                        manager.AddVit(jogador1, "reversi");
                        manager.AddDer(jogador2, "reversi");
                        return;
                    }
                    else{
                        std::cout << "Parabéns! " << jogador2 << " venceu!\n";
                        manager.AddVit(jogador2, "reversi");
                        manager.AddDer(jogador1, "reversi");
                        return;
                    }
                }
                else{
                    std::cout << "Não há jogadas possíveis para o jogador " << (jogadorAtual == 'X' ? jogador1 : jogador2) << ". O jogador passará a vez.\n";
                    pularJogada = true;
                    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
                    jogadas++;
                    continue;
                }
            }
            
        }
        
        linha = entrada[0] - '0';
        coluna = entrada[2] - '0';


        jogadaValida = !verificaJogada(linha, coluna, jogadorAtual, (jogadorAtual == 'X' ? jogador1 : jogador2));


        while (jogadaValida) {
            tabuleiro.exibirTabuleiro(); // Mostra o tabuleiro atualizado
            std::cout << (jogadorAtual == 'X' ? jogador1 : jogador2) << ", insira o novo valor para sua jogada: ";
            getline(std::cin, entrada);
            linha = entrada[0] - '0';
            coluna = entrada[2] - '0';
            jogadaValida = !verificaJogada(linha, coluna, jogadorAtual, (jogadorAtual == 'X' ? jogador1 : jogador2));
        }



        tabuleiro.exibirTabuleiro(); // Mostra o tabuleiro atualizado
        jogadas++; // Incrementa o número de jogadas

        //Alterna para o próximo jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        movimentoValido = false;


    }
}


bool Reversi::verificaJogada(int linha, int coluna, char valor, std::string jogador) {
    
    if (linha < 1 || linha > 8 || coluna < 1 || coluna > 8) {
        std::cout << "Entrada inválida. Insira dois números entre 1 e 8.\n";
        return false;
    }

    if (tabuleiro.getGrid()[linha - 1][(coluna - 1) * 2 + 1] != ' ') {
        std::cout << "Jogada inválida. A posição já está ocupada. Tente novamente.\n";
        return false;
    }

    if (!iniciaRecursao(linha - 1, coluna - 1, valor, 1)) {
        std::cout << "Jogada inválida. Tente novamente com uma jogada possível\n";
        return false;
    }

    return true;
}

bool Reversi::iniciaRecursao(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    int keep = 0;
    if(linha > 0 && coluna > 0) {
        if(tabuleiro.getGrid()[linha - 1][(coluna - 1) * 2 + 1] == jogadorAdversario){
            if(recursaoDSE(linha - 1, coluna - 1, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(linha > 0) {
        if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == jogadorAdversario){
            if(recursaoS(linha - 1, coluna, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(linha > 0 && coluna < 7) {
        if(tabuleiro.getGrid()[linha - 1][(coluna + 1) * 2 + 1] == jogadorAdversario){
            if(recursaoDSD(linha - 1, coluna + 1, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(coluna > 0) {
        if(tabuleiro.getGrid()[linha][(coluna - 1) * 2 + 1] == jogadorAdversario){
            if(recursaoE(linha, coluna - 1, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(coluna < 7) {
        if(tabuleiro.getGrid()[linha][(coluna + 1) * 2 + 1] == jogadorAdversario){
            if(recursaoD(linha, coluna + 1, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(linha < 7 && coluna > 0) {
        if(tabuleiro.getGrid()[linha + 1][(coluna - 1) * 2 + 1] == jogadorAdversario){
            if(recursaoDIE(linha + 1, coluna - 1, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(linha < 7) {
        if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == jogadorAdversario){
            if(recursaoI(linha + 1, coluna, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(linha < 7 && coluna < 7) {
        if(tabuleiro.getGrid()[linha + 1][(coluna + 1) * 2 + 1] == jogadorAdversario){
            if(recursaoDID(linha + 1, coluna + 1, jogador, opcao)){
                if(opcao){
                    tabuleiro.atualizarCelula(linha, coluna, jogador);
                }
                keep++;
            }
        }
    }
    if(keep > 0){
        return true;
    }
    else return false;
}













bool Reversi::recursaoDSE(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(linha == 0 || coluna == 0){
        return false;
    }
    if(tabuleiro.getGrid()[linha - 1][(coluna - 1) * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha - 1][(coluna - 1) * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha - 1][(coluna - 1) * 2 + 1] == jogadorAdversario){
        if(recursaoDSE(linha - 1, coluna - 1, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}












bool Reversi::recursaoS(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(linha == 0){
        return false;
    }
    if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha - 1][coluna * 2 + 1] == jogadorAdversario){
        if(recursaoS(linha - 1, coluna, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}











bool Reversi::recursaoDSD(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(linha == 0 || coluna == 7){
        return false;
    }
    if(tabuleiro.getGrid()[linha - 1][(coluna + 1) * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha - 1][(coluna + 1) * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha - 1][(coluna + 1) * 2 + 1] == jogadorAdversario){
        if(recursaoDSD(linha - 1, coluna + 1, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}












bool Reversi::recursaoE(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(coluna == 0){
        return false;
    }
    if(tabuleiro.getGrid()[linha][(coluna - 1) * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha][(coluna - 1) * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha][(coluna - 1) * 2 + 1] == jogadorAdversario){
        if(recursaoE(linha, coluna - 1, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}












bool Reversi::recursaoD(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(coluna == 7){
        return false;
    }
    if(tabuleiro.getGrid()[linha][(coluna + 1) * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha][(coluna + 1) * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha][(coluna + 1) * 2 + 1] == jogadorAdversario){
        if(recursaoD(linha, coluna + 1, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}











bool Reversi::recursaoDIE(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(linha == 7 || coluna == 0){
        return false;
    }
    if(tabuleiro.getGrid()[linha + 1][(coluna - 1) * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha + 1][(coluna - 1) * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha + 1][(coluna - 1) * 2 + 1] == jogadorAdversario){
        if(recursaoDIE(linha + 1, coluna - 1, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}













bool Reversi::recursaoI(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(linha == 7){
        return false;
    }
    if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha + 1][coluna * 2 + 1] == jogadorAdversario){
        if(recursaoI(linha + 1, coluna, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}














bool Reversi::recursaoDID(int linha, int coluna, char jogador, bool opcao) {
    char jogadorAdversario = (jogador == 'X') ? 'O' : 'X';
    if(linha == 7 || coluna == 7){
        return false;
    }
    if(tabuleiro.getGrid()[linha + 1][(coluna + 1) * 2 + 1] == ' '){
        return false;
    }
    if(tabuleiro.getGrid()[linha + 1][(coluna + 1) * 2 + 1] == jogador){
        if (opcao){
            tabuleiro.atualizarCelula(linha, coluna, jogador);
        }
        return true;
    }
    if(tabuleiro.getGrid()[linha + 1][(coluna + 1) * 2 + 1] == jogadorAdversario){
        if(recursaoDID(linha + 1, coluna + 1, jogador, opcao)){
            if (opcao){
                tabuleiro.atualizarCelula(linha, coluna, jogador);
            }
            return true;
        }
    }
    return false;
}



bool Reversi::verificaEmpate() {
    int pecasJogador1 = 0;
    int pecasJogador2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro.getGrid()[i][j * 2 + 1] == 'X') {
                pecasJogador1++;
            } else if (tabuleiro.getGrid()[i][j * 2 + 1] == 'O') {
                pecasJogador2++;
            }
        }
    }
    if (pecasJogador1 == pecasJogador2) {
        return true;
    }
    return false;
}







bool Reversi::verificaGanhador(std::string jogador1, std::string jogador2, char valor, bool minimax) {
    int pecasJogador1 = 0;
    int pecasJogador2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro.getGrid()[i][j * 2 + 1] == 'X') {
                pecasJogador1++;
            } else if (tabuleiro.getGrid()[i][j * 2 + 1] == 'O') {
                pecasJogador2++;
            }
        }
    }
    if (pecasJogador1 > pecasJogador2) {
        return true;
    } 
    return false;
}