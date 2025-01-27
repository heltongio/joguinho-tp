#include "velha.hpp"


bool Velha::jogada(std::string jogador1, std::string jogador2, char valor ){
    int linha;
    int coluna;
            
    std::cout << jogador1 << " qual a jogada: ";
    std::cin >> linha;
    std::cin >> coluna;

    
    while (true){

        if(verificaJogada(linha,coluna,valor,jogador1)){
            if (verificaGanhador(jogador1, jogador2,valor)){
                return true;}
            break;
        }else{
            std::cin >> linha;
            std::cin >> coluna;
        }
    }

    return false;
            
}


void Velha::iniciarJogo(){
    int cont = 0;
    char valor;
    char valor2;

    std::cout << jogador1 << " escolha X ou O: ";
    std::cin >> valor;
    tabuleiro.exibirTabuleiro();
    
    valor = std::toupper(valor);
    valor2 = (valor == 'X') ? 'O' : 'X';

    while (true){

        if (cont%2 == 0){
            cont++;
            if (jogada(jogador1, jogador2, valor)){
                break;
            }

            // std::cout << "A pontuação da melhor jogada é: " << melhorJogada << std::endl;

            // std::vector<std::vector<char>> jogadas = minimaxSolver.jogadasPossiveis(tabuleiro, valor2);
            // std::cout << "Jogadas possíveis para CPU: " << std::endl;
            // minimaxSolver.imprimirTabuleiro(jogadas);
           
            
        }else if (cont%2 != 0){
            cont++;

            Minimax minimaxSolver (jogador1, jogador2, valor, valor2);
            // minimaxSolver.jogadasPossiveis(tabuleiro,valor);
            std::vector<int> melhorJogada = minimaxSolver.melhoraco(tabuleiro, false);
            // std::cout << melhorJogada[0] + 1 << std::endl;
            // std::cout << melhorJogada[1] + 1 << std::endl;

            tabuleiro.atualizarCelula(melhorJogada[0],melhorJogada[1],valor2);
            tabuleiro.exibirTabuleiro();

            // melhorJogada.exibirTabuleiro();


            //melhorar definição de parada
            // tabuleiro.setTabuleiro(melhorJogada);
            // break;

            //pvp
            // if (jogada(jogador2, jogador1,valor2)){
            //     break;
            // }

            
        }
        
        
        
    }
    
}

void Velha::criaTabuleiro(){
    tabuleiro.exibirTabuleiro();
}


//verifica se digitou apenas um numero
bool Velha::verificaJogada(int linha, int coluna, char valor, std::string jogador){
    std::vector<std::vector<char>> grid = tabuleiro.getGrid();
    linha = linha-1;
    coluna = coluna-1;

    if (grid[linha][coluna * 2 + 1] != ' '){
        std::cerr << jogador << " posição inválida, tente novamente: ";
        return false;
    }else if (linha >= 0 && linha <= 3 && coluna >= 0 && coluna <= 3) {
        tabuleiro.atualizarCelula(linha,coluna,valor);
        tabuleiro.exibirTabuleiro();
        return true;
    }else {
        std::cerr << jogador << " posição inválida, tente novamente: ";
        return false;
    }
    
}


// bool Velha::verificaLinha(const std::string& estado, int linha) {
//     int inicio = linha * 3;
//     if (estado[inicio] != ' ' &&
//         estado[inicio] == estado[inicio + 1] &&
//         estado[inicio + 1] == estado[inicio + 2]) {
//         vencedor = estado[inicio];
//         return true;
//     }
//     return false;
// }

// bool Velha::verificaColuna(const std::string& estado, int coluna) {
//     if (estado[coluna] != ' ' &&
//         estado[coluna] == estado[coluna + 3] &&
//         estado[coluna + 3] == estado[coluna + 6]) {
//         vencedor = estado[coluna];
//         return true;
//     }
//     return false;
// }

// bool Velha::verificaDiagonais(const std::string& estado) {
//     if ((estado[0] != ' ' && estado[0] == estado[4] && estado[4] == estado[8]) ||
//         (estado[2] != ' ' && estado[2] == estado[4] && estado[4] == estado[6])) {
//         vencedor = estado[4];
//         return true;
//     }
//     return false;
// }

bool Velha::verificaTabLimpo(std::string estado){
    bool tabuleiroCheio = true;

    for (char c : estado) {
        if (c == ' ') {
            tabuleiroCheio = false;
            return false;
        }
    }
    return true;
}





bool Velha::verificaLinha(const std::string& estado, int linha, char valor) {
    int inicio = linha * 3;
    return (estado[inicio] == valor && estado[inicio + 1] == valor && estado[inicio + 2] == valor);
}


bool Velha::verificaColuna(const std::string& estado, int coluna, char valor) {
    return (estado[coluna] == valor && estado[coluna + 3] == valor && estado[coluna + 6] == valor);
}


bool Velha::verificaDiagonais(const std::string& estado, char valor) {
    return ((estado[0] == valor && estado[4] == valor && estado[8] == valor) ||
            (estado[2] == valor && estado[4] == valor && estado[6] == valor));
}


bool Velha::verificaGanhador(std::string jogador1, std::string jogador2, char valor) {
    std::string estado = tabuleiro.getEstadoLimpo();

    for (int i = 0; i < 3; ++i) {
        if (verificaLinha(estado, i, valor) || verificaColuna(estado, i, valor) || verificaDiagonais(estado, valor)) {
            return true;
        }
    }
    return false;
}





// valorGanhador = std::make_shared<char>(valor);



// std::string estado = tabuleiro.getEstadoLimpo();

//     for (int i = 0; i < 3; ++i) {
//         if (verificaLinha(estado, i) || verificaColuna(estado, i)||verificaDiagonais(estado)) {
//             // std::cout << jogador1 << " ganhou com " << valor <<  std::endl;
//             // manager.AddVit(jogador1, "velha");
//             // manager.AddDer(jogador2, "velha");


//             return true;
//         }
//     }

//     if(verificaTabLimpo(estado)){
//         // std::cout << "O jogo terminou em empate!" << std::endl;
//         return true;
//     }

//     return false;




Velha::~Velha(){

}