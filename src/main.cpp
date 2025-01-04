#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
using namespace std;

// Tabuleiro iniciarJogo (const std::string& nomeDoJogo){  //funçao prov para teste
// if (nomeDoJogo == "R") {
//         Tabuleiro tabuleiro(8, 8, '|');
//         tabuleiro.atualizarCelula(2,2,'X');
//         tabuleiro.atualizarCelula(2,4,'X');
//         tabuleiro.exibirTabuleiro();
//         return tabuleiro;
//     } else if (nomeDoJogo == "V") {
//         Tabuleiro tabuleiro(3,3 , '|');
//         tabuleiro.exibirTabuleiro();
//         return tabuleiro;
//     } else if (nomeDoJogo == "L") {
//         Tabuleiro tabuleiro(7, 6, '|');
//         tabuleiro.exibirTabuleiro();
//         return tabuleiro;
//     } else {
//         std::cerr << "Jogo não reconhecido!\n";
//         return Tabuleiro(0, 0, '\0');}

// }




int main() {

    CadastroJogadores manager;
    manager.ConstruirVetor();
    manager.PrintJogadores();
    manager.CadastrarJogador("Revo", "Roberto");
    manager.CadastrarJogador("shaolin", "Pedro");
    manager.AddVit("Alga", "velha");
    manager.AddDer("Revo", "velha");
    manager.AddVit("Revo", "reversi");
    manager.AddDer("Revo", "reversi");
    manager.PrintJogadores();
    manager.SalvarArquivo();
    
    // iniciarJogo("R");
    // cout<<"---------------------"<<endl;
    // iniciarJogo("V");
    // cout<<"---------------------"<<endl;
    // iniciarJogo("L");
    // return 0;


    Velha velha("rafael","paulo");
    velha.verificaJogada(4,4,'X');
    velha.verificaJogada(2,2,'X');
    velha.verificaJogada(1,2,'O');
    velha.verificaJogada(3,3,'X');
    velha.verificaJogada(3,1,'O');
    velha.verificaJogada(1,1,'X');

}
