#include "jogos.hpp"
#include "velha.hpp"

Jogos::Jogos(std::string jogador1, std::string jogador2, CadastroJogadores& manager)
    : jogador1(jogador1), jogador2(jogador2), manager(manager) {}

void Jogos::iniciarJogo(){
    // nomeJogo = "V";
    // std::string teste = "V";
    // Velha velha;
    // if (nomeJogo == teste){
    //     Velha jogoVelha();
    // }else if(nomeJogo == std::string("R")){
    //     std::cout << "jogo em construção" << std::endl;
    // }else if(nomeJogo == std::string("L")){
    //     std::cout << "jogo em construção" << std::endl;
    // }else{
    //     std::cout << "jogo não reconhecido" << std::endl;
    // }

   
}

// bool Jogos::verificaJogada(int linha, int coluna, char valor, std::string jogador){

// }

// bool Jogos::verificaGanhador(std::string jogador1, std::string jogador2, char valor){
//   //problema no retorno não void 
// }

void Jogos::criaTabuleiro(){

}


Jogos::~Jogos() {
    return;
}