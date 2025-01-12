#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
#include <limits>
#include <cctype>

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
        cout << "Qual comando deseja utilizar: ";
        cin >> comando;
        cout << endl;

        //deixa o comando em mausculo
        transform(comando.begin(), comando.end(), comando.begin(), [](unsigned char c) {
            return std::toupper(c);});

        if (comando == "CJ"){
            // CJ <Apelido> <Nome>
            string apelido;
            string nome;
            cout << "Nome do jogador:" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nome);
            cout << "Apelido do jogador:" << endl;
            cin >> apelido;
            manager.CadastrarJogador(apelido, nome);
        }else if (comando == "RJ"){
            // RJ <Apelido>
            cout << "Apelido do jogador que sera removido:" << endl;
            string apelido;
            cin >> apelido;
            manager.RemoverJogador(apelido);
        }else if (comando == "LJ"){
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
                Velha jogoVelha(apelido1,apelido2,manager);
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
            cout <<"\033[31m" << "Comando invalido tenta novamente!!" << "\033[0m"<< endl;
        }
        




    }


}
