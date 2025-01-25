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

            std::vector<std::vector<char>> teste = minimax.jogadasPossiveis(tabuleiro,valor2);
            minimax.imprimirTabuleiro(teste);
           
            
        }else if (cont%2 != 0){
            cont++;
            if (jogada(jogador2, jogador1,valor2)){
                break;
            }

            
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

bool Velha::verificaGanhador(std::string jogador1, std::string jogador2, char valor) {
    std::string estado = tabuleiro.getEstadoLimpo();

    for (int i = 0; i < 3; ++i) {
        if (verificaLinha(estado, i) || verificaColuna(estado, i)||verificaDiagonais(estado)) {
            std::cout << jogador1 << " ganhou com " << valor <<  std::endl;
            // manager.AddVit(jogador1, "velha");
            // manager.AddDer(jogador2, "velha");
            valorGanhador = std::make_shared<char>(valor);

            return true;
        }
    }

    return false;
}


Velha::~Velha(){

}