#include "gerente.hpp"
#include "jogador.hpp"
using namespace std;

int main() {

    CadastroJogadores manager;
    manager.ConstruirVetor();
    manager.PrintJogadores();
    manager.CadastrarJogador("Revo", "Roberto");
    manager.AddVit("Alga", "velha");
    manager.AddDer("Revo", "velha");
    // manager.AddVit("Revo", "lig4");
    // manager.AddDer("Revo", "lig4");
    manager.AddVit("Revo", "reversi");
    manager.AddDer("Revo", "reversi");
    manager.PrintJogadores();
    manager.SalvarArquivo();
    return 0;
}