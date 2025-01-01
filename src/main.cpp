#include "gerente.hpp"
#include "jogador.hpp"
using namespace std;

int main() {

    CadastroJogadores manager;
    manager.ConstruirVetor();
    manager.PrintJogadores();
    manager.CadastrarJogador("Revo", "Roberto");
    manager.CadastrarJogador("shaolin matador", "Pedro");
    manager.AddVit("Alga", "velha");
    manager.AddDer("Revo", "velha");
    manager.AddVit("Revo", "reversi");
    manager.AddDer("Revo", "reversi");
    manager.PrintJogadores();
    manager.SalvarArquivo();
    return 0;
}