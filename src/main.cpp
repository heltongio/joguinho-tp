#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
#include <limits>
#include <cctype>

using namespace std;


int main() {
    string const RED = "\033[31m";
    string const FIM = "\033[0m";
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
        cout << "Qual comando deseja utilizar: ";
        cin >> comando;
        cout << endl;

       
        transform(comando.begin(), comando.end(), comando.begin(), [](unsigned char c) {
            return std::toupper(c);});

        if (comando == "CJ"){
            string apelido;
            string nome;
            cout << "Nome do jogador:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nome);
            cout << "Apelido do jogador:" << endl;
            cin >> apelido;
            manager.CadastrarJogador(apelido, nome);
        }else if (comando == "RJ"){
            cout << "Apelido do jogador que sera removido:" << endl;
            string apelido;
            cin >> apelido;
            manager.RemoverJogador(apelido);
        }else if (comando == "LJ"){
            manager.PrintJogadores();
        }else if (comando == "EP"){
            
            string jogo;
            string apelido1;
            string apelido2;

            cout << "Qual jogo deseja jogar? (Velha(V)/Lig4(L)/Reversi(R))" << endl;
            cin >> jogo;

            transform(jogo.begin(), jogo.end(), jogo.begin(), [](unsigned char c) {
                return std::toupper(c);});

            cout << "Apelido do primeiro jogador:" ;
            cin >> apelido1;
            cout << "Apelido do segundo jogador:" ;
            cin >> apelido2;

            // verificar se jogador esta cadastrado
            try {
                manager.verificaJogadores(apelido1);
            } catch (const std::exception& e) {
                cout << RED << e.what() << ": " << apelido1 << FIM << endl;
                continue;}

            try {
                manager.verificaJogadores(apelido2);
            } catch (const std::exception& e) {
                cout << RED << e.what() << ": " << apelido1 << FIM << endl;
                continue;}
            

            if (jogo == "V" || jogo == "VELHA"){
                Velha jogoVelha(apelido1,apelido2,manager);
                jogoVelha.iniciarJogo();
            }else if(jogo == string("R") || jogo == "REVERSI"){
                cout << "jogo em construção" << endl;
            }else if(jogo == string("L") || jogo == "LIG4"){
                cout << "jogo em construção" << endl;
            }else{
                cout << RED << "jogo não reconhecido!" << FIM << endl;
            }
        
        }
        else if (comando == "FS"){
            manager.SalvarArquivo();
            return 0;
        }else{
            cout << RED << "Comando invalido tenta novamente!!" << FIM << endl;
        }
        




    }


}
