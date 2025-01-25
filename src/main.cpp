#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
#include "lig4.hpp"
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
    CadastroJogadores manager("bancoDados/jogadores.txt");

    //Tenta abrir o arquivo
    try {
        manager.ConstruirVetor();
    } catch(const exception& e){
        cout << RED << e.what() << FIM << endl;
    return 0;}

    while (true){
        cout << "Qual comando deseja utilizar: ";
        cin >> comando;
        cout << endl;

       
        transform(comando.begin(), comando.end(), comando.begin(), [](unsigned char c) {
            return std::toupper(c);});

        if (comando == "CJ"){
            string apelido;
            string nome;
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            while (nome.empty()) {
                cout << "Nome do jogador:" << endl;
                getline(cin, nome);
            }
            
            while (apelido.empty()){
                cout << "Apelido do jogador:" << endl;
                getline(cin, apelido);
            }
            
            try{
                manager.CadastrarJogador(apelido, nome);
            }   catch (const invalid_argument& e) {
                cout << RED << e.what() << FIM << endl;
            continue;}   

        }else if (comando == "RJ"){
            string apelido;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (apelido.empty()) {
                cout << "Apelido do jogador que sera removido:" << endl;
                getline(cin, apelido);
            }
           
            //verifica se jogador esta cadastrado para ser removido
            try {
                manager.RemoverJogador(apelido);
            } catch (const exception& e){
                cout << RED << e.what() << FIM << endl;
            continue;}
            
        }else if (comando == "LJ"){
            manager.PrintJogadores();
        }else if (comando == "EP"){
            
            string jogo;
            string apelido1;
            string apelido2;

            cout << "Qual jogo deseja jogar? (Velha(V)/Lig4(L)/Reversi(R)): " ;
            cin >> jogo;

            transform(jogo.begin(), jogo.end(), jogo.begin(), [](unsigned char c) {
                return std::toupper(c);});

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            while (apelido1.empty()) {
                cout << "Apelido do primeiro jogador: " << endl;
                getline(cin, apelido1);
            }
            
            //verificar se jogador esta cadastrado
            try {
                apelido1 = manager.VerificaJogadores(apelido1);
            } catch (const exception& e) {
                cout << RED << e.what() << FIM << endl;
                continue;}

            while (apelido2.empty()) {
                cout << "Apelido do segundo jogador: " << endl;
                getline(cin, apelido2);
            }

            try {
                apelido2 = manager.VerificaJogadores(apelido2);
            } catch (const exception& e) {
                cout << RED << e.what() << FIM << endl;
                continue;}


            if (jogo == "V" || jogo == "VELHA"){
                Velha jogoVelha(apelido1,apelido2,manager);
                jogoVelha.iniciarJogo();
            }else if(jogo == string("R") || jogo == "REVERSI"){
                cout << "jogo em construção" << endl;
            }else if(jogo == string("L") || jogo == "LIG4"){
                Lig4 jogoLig4(apelido1,apelido2,manager);
                jogoLig4.iniciarJogo();
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
