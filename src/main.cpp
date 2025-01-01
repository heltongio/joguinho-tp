#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogo.hpp"
using namespace std;

int main() {

    // CadastroJogadores manager;
    // manager.ConstruirVetor();
    // manager.PrintJogadores();
    // manager.CadastrarJogador("Revo", "Roberto");
    // manager.CadastrarJogador("shaolin matador", "Pedro");
    // manager.AddVit("Alga", "velha");
    // manager.AddDer("Revo", "velha");
    // manager.AddVit("Revo", "reversi");
    // manager.AddDer("Revo", "reversi");
    // manager.PrintJogadores();
    // manager.SalvarArquivo();
    Jogo jogo;
    jogo.iniciarJogo("R");

    // iniciarJogo<char>("V"); //Velha
    // std::cout << "-----" << std::endl;
    // iniciarJogo<char>("R"); //reversi
    // std::cout << "-----" << std::endl;
    // iniciarJogo<char>("L"); //LIG4
    return 0;
}