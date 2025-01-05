#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
using namespace std;


int main() {
    cout << "CJ" << " : " << "Cadastrar Jogador" << endl;
    cout << "RJ" << " : " << "Remover Jogador" << endl;
    cout << "LJ" << " : " << "Listar de jogadores" << endl;
    cout << "EP" << " : " << "" << endl;
    cout << "FS" << " : " << "Finalizar Sistema" << endl;


    string comando;
    CadastroJogadores manager;
    manager.ConstruirVetor();


    //colocar tudo na mesma linha ex: EP <Jogo: (R|L|V)> <Apelido Jogador 1> <Apelido Jogador 2>
    while (true){
        cin >> comando;
        
        if (comando == "CJ"){
            string apelido;
            string nome;
            cout << "Nome do jogador:";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nome);
            cout << "Apelido do jogador:";
            cin >> apelido;
            manager.CadastrarJogador(apelido, nome);
        }else if (comando == "RJ"){
            string apelido;
            cout << "Apelido do jogador:";
            cin >> apelido;
            manager.RemoverJogador(apelido);
        }else if (comando == "LJ"){
            manager.PrintJogadores();
        }else if (comando == "EP"){
            //em construção
        }
        else if (comando == "FS"){
            manager.SalvarArquivo();
            return 0;
        }
        




    }
    
    // CadastroJogadores manager;
    // manager.ConstruirVetor();
    // manager.PrintJogadores();
    // manager.CadastrarJogador("Revo", "Roberto");
    // manager.CadastrarJogador("shaolin", "Pedro");
    // manager.AddVit("Alga", "velha");
    // manager.AddDer("Revo", "velha");
    // manager.AddVit("Revo", "reversi");
    // manager.AddDer("Revo", "reversi");
    // manager.PrintJogadores();
    // manager.SalvarArquivo();
    
    // iniciarJogo("R");
    // cout<<"---------------------"<<endl;
    // iniciarJogo("V");
    // cout<<"---------------------"<<endl;
    // iniciarJogo("L");
    // return 0;


    // Velha velha("rafael","paulo");
    // velha.verificaJogada(1,1,'X');
    // velha.verificaGanhador();
    // velha.verificaJogada(2,1,'X');
    // velha.verificaGanhador();
    // velha.verificaJogada(3,1,'X');
    // velha.verificaGanhador();
    // velha.verificaJogada(1,2,'X');
    // velha.verificaGanhador();
    // velha.verificaJogada(2,2,'O');
    // velha.verificaGanhador();
    // velha.verificaJogada(3,2,'X');
    // velha.verificaGanhador();
    // velha.verificaJogada(1,3,'O');
    // velha.verificaGanhador();
    // velha.verificaJogada(2,3,'X');
    // velha.verificaGanhador();
    // velha.verificaJogada(3,3,'O');
    // velha.verificaGanhador();

}
