#include "velha.hpp"

bool Velha::jogada(std::string jogador1, std::string jogador2, char valor ){
    int linha;
    int coluna;

    if (verificaGanhador()){
        // CadastroJogadores manager;
        std::cout << jogador1 << " ganhou com " << valor <<  std::endl;
        // manager.AddVit(jogador1, "velha");
        // manager.AddDer(jogador2, "velha");
        // manager.SalvarArquivo();
        return true;
    }
            
    std::cout << jogador1 <<" qual a jogada: ";
    std::cin >> linha;
    std::cin >> coluna;

    
    while (true){

        if (verificaJogada(linha,coluna,valor,jogador1)){
            break;
        }else{
            std::cin >> linha;
            std::cin >> coluna;
        }
    }

    //melhorar para não ter q repitir
    if (verificaGanhador()){
        // CadastroJogadores manager;
        std::cout << jogador1 << " ganhou com " << valor <<  std::endl;
        // manager.AddVit(jogador1, "velha");
        // manager.AddDer(jogador2, "velha");
        // manager.SalvarArquivo();
        return true;
    }
    return false;
            
}

//deixar jogador selecionar qual vai ser
void Velha::iniciarJogo(){
    int cont = 0;
    char valor;
    char valor2;

    std::cout << jogador1 <<" escolha X ou O: ";
    std::cin >> valor;
    tabuleiro.exibirTabuleiro();
     
    if (valor == 'X'){
        valor2 = 'O';
    }else{
        valor2 = 'X';}

    while (true){

        if (cont%2 == 0){
            cont++;
            if (jogada(jogador1, jogador2,valor)){
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

    if (grid[linha][coluna * 2 + 1] != ' '){
        std::cerr << jogador << " posição inválida, tente novamente: ";
        return false;
    }else if (linha >= 0 && linha <= 3 && coluna >= 0 && coluna <= 3) {
        tabuleiro.atualizarCelula(linha,coluna,valor);
        tabuleiro.exibirTabuleiro();
        return true;
    }else {
        std::cerr << jogador << " posição inválida, tente novamente: "; // retorna falso
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

bool Velha::verificaGanhador() {
    std::string estado = tabuleiro.getEstadoLimpo();

    for (int i = 0; i < 3; ++i) {
        if (verificaLinha(estado, i) || verificaColuna(estado, i)||verificaDiagonais(estado)) {
            return true;
        }
    }

    return false;
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