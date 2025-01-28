#include "velha.hpp"

std::string Velha::frase(){
    std::ifstream arquivo("bancoDados/frases.txt");
    std::vector<std::string> frases;

    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo!" << std::endl;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        frases.push_back(linha);
    }
    arquivo.close();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int indiceAleatorio = std::rand() % frases.size();

    return frases[indiceAleatorio];
}


bool Velha::solicitarJogada(std::string& jogador,int& linha, int& coluna) {
    while (true) {
        std::cout << jogador <<" digite a linha e coluna (1-3) (1-3): ";
        std::cin >> linha >> coluna;


        if (std::cin.fail()) {
            std::cerr << "Entrada inválida! Apenas números inteiros são permitidos.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
            std::cerr << "Posição inválida! As linhas e colunas devem ser entre 1 e 3.\n";
        } else {
            return true;
        }
    }
}

bool Velha::jogada(std::string jogador1, std::string jogador2, char valor) {
    int linha, coluna;

    while (!solicitarJogada(jogador1, linha, coluna)) {}

    while (true) {
        if (verificaJogada(linha, coluna, valor, jogador1)) {
            if (verificaGanhador(jogador1, jogador2, valor, false) || verificaTabuleiroCompleto(jogador1, jogador2, false)) {
                return true;
            }
            break;
        } else {
            std::cerr << "Posição já ocupada, tente novamente.\n";
            solicitarJogada(jogador1, linha, coluna);
        }
    }

    return false;
}


void Velha::iniciarJogo(){
    int cont = 0;
    std::string valor_teste;
    char valor;
    char valor2;

    std::cout << jogador1 << " escolha X ou O: ";
    std::cout << std::endl;
    std::getline(std::cin, valor_teste);
    while (valor_teste.length() != 1 || ((toupper(valor_teste[0]) != 'X') && (toupper(valor_teste[0]) != 'O')) || (valor_teste.empty())) {
        std::cout << "Entrada invalida,use apenas X ou O" << std::endl;
        std::getline(std::cin, valor_teste);}
    valor_teste[0] = toupper(valor_teste[0]);
    valor = valor_teste[0];
    tabuleiro.exibirTabuleiro();
    
    valor = std::toupper(valor);

    valor2 = (valor == 'X') ? 'O' : 'X';

    while (true){

        if (cont%2 == 0){
            cont++;
            if (jogada(jogador1, jogador2,valor)){
                break;
            }
           
        } else if (cont%2 != 0 && jogador2 == "Glados"){
            cont++;
            Minimax minimaxSolver (jogador1, jogador2, valor, valor2);
            std::vector<int> melhorJogada = minimaxSolver.melhoraco(tabuleiro, false);
            tabuleiro.atualizarCelula(melhorJogada[0],melhorJogada[1],valor2);

            std::cout << "\033[1;34m" << "GLADOS" << "\033[0m" << " jogou:" << std::endl;
            tabuleiro.exibirTabuleiro();

            if (verificaGanhador(jogador2, jogador1, valor2, false) || verificaTabuleiroCompleto(jogador2,jogador1, false)){
                std::cout << std::endl;
                std::cout << "\033[1;34m" << frase() << "\033[0m" << std::endl;
                break;
            }

            
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


bool Velha::verificaJogada(int linha, int coluna, char valor, std::string jogador){
    std::vector<std::vector<char>> grid = tabuleiro.getGrid();
    linha = linha-1;
    coluna = coluna-1;

    if ((linha < 0 || linha >= 3) || (coluna < 0 || coluna >= 3)) {
        std::cerr << jogador << " posição inválida, tente novamente:";
        return false;
    }
    else if (grid[linha][coluna * 2 + 1] != ' '){
        std::cerr << jogador << " posição inválida, tente novamente: ";
        return false;
    }else {
        tabuleiro.atualizarCelula(linha,coluna,valor);
        tabuleiro.exibirTabuleiro();
        return true;
    }

}


bool Velha::verificaLinha(const std::string& estado, int linha, char valor) {
    int inicio = linha * 3;
    if (estado[inicio] == valor &&
        estado[inicio] == estado[inicio + 1] &&
        estado[inicio + 1] == estado[inicio + 2]) {
        vencedor = estado[inicio];
        return true;
    }
    return false;
}

bool Velha::verificaColuna(const std::string& estado, int coluna, char valor) {
    if (estado[coluna] == valor &&
        estado[coluna] == estado[coluna + 3] &&
        estado[coluna + 3] == estado[coluna + 6]) {
        vencedor = estado[coluna];
        return true;
    }
    return false;
}

bool Velha::verificaDiagonais(const std::string& estado, char valor) {
    if ((estado[0] == valor && estado[0] == estado[4] && estado[4] == estado[8]) ||
        (estado[2] == valor && estado[2] == estado[4] && estado[4] == estado[6])) {
        vencedor = valor;
        return true;
    }
    return false;
}

bool Velha::verificaTabuleiroCompleto(const std::string& jogador1, const std::string& jogador2, bool minimax) {
    std::string estado = tabuleiro.getEstadoLimpo();

    for (char pos : estado) {
        if (pos == ' ') {
            return false;
        }
    }


    if(!minimax){
        std::cout << "\033[31m" << "O jogo terminou em um empate, ambos jogadores perdem\n" << "\033[0m" << std::endl;
        manager.AddDer(jogador1, "velha");
        manager.AddDer(jogador2, "velha");
    }


    return true;
}


bool Velha::verificaGanhador(std::string jogador1, std::string jogador2, char valor, bool minimax) {
    std::string estado = tabuleiro.getEstadoLimpo();

    for (int i = 0; i < 3; ++i) {
        if (verificaLinha(estado, i, valor) || verificaColuna(estado, i, valor)||verificaDiagonais(estado, valor)) {


            if(!minimax){
                std::cout << "\033[32m" << jogador1 << "\033[0m" <<" ganhou com " << valor <<  std::endl;
                manager.AddVit(jogador1, "velha");
                manager.AddDer(jogador2, "velha");}
            return true;
        }
    }

    return false;
}


Velha::~Velha(){

}