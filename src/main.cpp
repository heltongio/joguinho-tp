#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"

// #include <limits>
using namespace std;


int main() {
    //comandos não intuitivos
    cout << "CJ" << " : " << "Cadastrar Jogador" << endl;
    cout << "RJ" << " : " << "Remover Jogador" << endl;
    cout << "LJ" << " : " << "Listar de jogadores" << endl;
    cout << "EP" << " : " << "Inicia partida" << endl;
    cout << "FS" << " : " << "Finalizar Sistema" << endl;
    cout << endl;

    string comando;
    CadastroJogadores manager;
    manager.ConstruirVetor();


    while (true){
        cin >> comando;

        if (comando == "CJ"){
            // CJ <Apelido> <Nome>
            string apelido;
            string nome;
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> nome;
            cin >> apelido;
            manager.CadastrarJogador(apelido, nome);
        }else if (comando == "RJ"){
            // RJ <Apelido>
            string apelido;
            cin >> apelido;
            manager.RemoverJogador(apelido);
        }else if (comando == "LJ"){
            //Precisa listar em ordem alfabetica
            manager.PrintJogadores();
        }else if (comando == "EP"){
            // EP <Jogo: (R|L|V)> <Apelido Jogador 1> <Apelido Jogador 2>
            string jogo;
            string apelido1;
            string apelido2;

            cin >> jogo;
            cin >> apelido1;
            cin >> apelido2;

            //verificar se jogadores estão cadastrados
            if (jogo == "V"){
                //alguns bugs no jogo da velha (não salva jogador ganhador)
                Velha jogoVelha(apelido1,apelido2);
                jogoVelha.iniciarJogo();
            }else if(jogo == std::string("R")){
                std::cout << "jogo em construção" << std::endl;
            }else if(jogo == std::string("L")){
                std::cout << "jogo em construção" << std::endl;
            }else{
                std::cout << "jogo não reconhecido" << std::endl;
            }
        
        }
        else if (comando == "FS"){
            manager.SalvarArquivo();
            return 0;
        }else{
            cout << "comando invalido" << endl;
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
