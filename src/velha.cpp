#include "velha.hpp"


//deixar jogador selecionar qual vai ser
void Velha::iniciarJogo(std::string nomeJogo){
    int cont = 0;
    char valor;
    std::cout << "escolha X ou O" << jogador1;
    std::cin >> valor;
    while (true){

        if (cont%2 == 0){
            int linha;
            int coluna;

            std::cout << jogador1 <<"qual a jogada:" << std::endl;
            std::cin >> linha;
            std::cin >> coluna;

            verificaJogada(linha,coluna,valor);

            if (verificaGanhador()){
                std::cout << jogador1 << "ganhou" << std::endl;
                break;
            }

        }else if (cont%2 != 0){
            //em construção
        }
        
        
        
    }
    
}

void Velha::criaTabuleiro(){
    tabuleiro.exibirTabuleiro();
}

void Velha::verificaJogada(int linha, int coluna, char valor){
    if (linha >= 0 && linha <= 3 && coluna >= 0 && coluna <= 3) {
        tabuleiro.atualizarCelula(linha,coluna,valor);
        tabuleiro.exibirTabuleiro(); //retorna true
    } else {
        std::cerr << "Posição inválida no tabuleiro!\n"; // retorna falso
    }
    
}


bool Velha::verificaLinha(const std::string& estado, int linha) {
    int inicio = linha * 3;
    if (estado[inicio] != ' ' && 
        estado[inicio] == estado[inicio + 1] &&
        estado[inicio + 1] == estado[inicio + 2]) {
        vencedor = estado[inicio];
        return true;
    }
    return false;
}

bool Velha::verificaColuna(const std::string& estado, int coluna) {
    if (estado[coluna] != ' ' &&
        estado[coluna] == estado[coluna + 3] &&
        estado[coluna + 3] == estado[coluna + 6]) {
        vencedor = estado[coluna];
        return true;
    }
    return false;
}

bool Velha::verificaDiagonais(const std::string& estado) {
    if ((estado[0] != ' ' && estado[0] == estado[4] && estado[4] == estado[8]) || 
        (estado[2] != ' ' && estado[2] == estado[4] && estado[4] == estado[6])) {
        vencedor = estado[4];
        return true;
    }
    return false;
}

char Velha::verificaGanhador() {
    std::string estado = tabuleiro.getEstadoLimpo();

    for (int i = 0; i < 3; ++i) {
        if (verificaLinha(estado, i) || verificaColuna(estado, i)||verificaDiagonais(estado)) {
            std::cout << "Vencedor: " << vencedor << '\n';
            return vencedor;
        }
    }

    return vencedor;
}


Velha::~Velha(){

}

// void Velha::verificaGanhador() {
//     std::string estadoTabuleiro = tabuleiro.getEstadoLimpo();
    
//     char vencedor = '\0';

//     for (int i = 0; i < 3; ++i) {
//         int start = i * 3;
//         if (estadoTabuleiro[start] != ' ' &&
//             estadoTabuleiro[start] == estadoTabuleiro[start + 1] &&
//             estadoTabuleiro[start + 1] == estadoTabuleiro[start + 2]) {
//             vencedor = estadoTabuleiro[start];
//             break;
//         }
//     }

//     for (int i = 0; i < 3; ++i) {
//         if (estadoTabuleiro[i] != ' ' &&
//             estadoTabuleiro[i] == estadoTabuleiro[i + 3] &&
//             estadoTabuleiro[i + 3] == estadoTabuleiro[i + 6]) {
//             vencedor = estadoTabuleiro[i];
//             break;
//         }
//     }


//     if (estadoTabuleiro[0] != ' ' &&
//         estadoTabuleiro[0] == estadoTabuleiro[4] &&
//         estadoTabuleiro[4] == estadoTabuleiro[8]) {
//         vencedor = estadoTabuleiro[0];
//     }


//     if (estadoTabuleiro[2] != ' ' &&
//         estadoTabuleiro[2] == estadoTabuleiro[4] &&
//         estadoTabuleiro[4] == estadoTabuleiro[6]) {
//         vencedor = estadoTabuleiro[2];
//     }

//     if (vencedor != '\0') {
//         std::cout << "O jogador '" << vencedor << "' venceu o jogo!\n";
//     } else {
//         std::cout << "Nenhum vencedor ainda.\n";
//     }



//     if (vencedor == '\0' && estadoTabuleiro.find(' ') == std::string::npos) {
//     std::cout << "O jogo terminou em empate!\n";
//     }

// }