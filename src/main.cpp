/**
 * @file main.cpp
 * @brief Programa principal para gerenciar jogadores e iniciar jogos interativos.
 * @details Este programa permite gerenciar jogadores (cadastrar, remover, listar) e iniciar jogos como Velha, Lig4 e Reversi.
 *          Ele utiliza diversas classes, como `CadastroJogadores`, `Velha`, `Lig4`, e `Reversi`, para implementar as funcionalidades.s
 */

#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
#include "lig4.hpp"
#include "minimax.hpp"
#include "reversi.hpp"
#include <limits>
#include <cctype>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;


/**
 * @brief Função para limpar o console após um intervalo de tempo.
 * @param segundos Tempo de espera antes da limpeza.
 */
void limparConsole(int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * @brief Função principal do programa.
 * @return int Retorna 0 ao finalizar o programa.
 */
int main() {
    string const RED   = "\033[31m";
    string const GREEN = "\033[32m";
    string const FIM   = "\033[0m";


    string comando;
    CadastroJogadores manager("bancoDados/jogadores.txt");

    //Tenta abrir o arquivo
    try {
        manager.ConstruirVetor();
    } catch(const exception& e){
        cout << RED << e.what() << FIM << endl;
    return 0;}

    while (true){
        cout << "1 - " << "CJ" << "  : " << "Cadastrar Jogador" << endl;
        cout << "2 - " << "RJ" << "  : " << "Remover Jogador" << endl;
        cout << "3 - " << "LJ" << "  : " << "Listar de jogadores" << endl;
        cout << "4 - " << "EP" << "  : " << "Inicia partida pvp" << endl;
        cout << "5 - " << "EPM"<<  " : " << "Inicia jogo da velha vs GLaDOS" << endl;
        cout << "6 - " << "FS" << "  : " << "Finalizar Sistema" << endl;
        cout << endl;


        cout << "Qual comando deseja utilizar: ";
        cin >> comando;
        cout << endl;

       
        transform(comando.begin(), comando.end(), comando.begin(), [](unsigned char c) {
            return std::toupper(c);});

        if (comando == "CJ" || comando == "1"){
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
            limparConsole(1);

        }else if (comando == "RJ" || comando == "2"){
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
            limparConsole(1);
            
        }else if (comando == "LJ"|| comando == "3"){
            manager.PrintJogadores();
            limparConsole(3);
        }else if (comando == "EP"|| comando == "4"){
            
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
                getline(cin, apelido1);}

            
            try {
                apelido1 = manager.VerificaJogadores(apelido1);
            } catch (const exception& e) {
                cout << RED << e.what() << FIM << endl;
                continue;}


            while (apelido2.empty()) {
                cout << endl;
                cout << "Apelido do segundo jogador: " << endl;
                getline(cin, apelido2);
                cout << endl;}
            try {
                std::regex pattern("glados", std::regex_constants::icase);

                if (std::regex_match(apelido2, pattern)) {
                    std::locale::global(std::locale("C"));

                // Converte todas as letras para maiúsculas
                std::transform(apelido2.begin(), apelido2.end(), apelido2.begin(), [](unsigned char c) {
                    return std::toupper(c);
                });}
                apelido2 = manager.VerificaJogadores(apelido2);
            } catch (const exception& e) {
                cout << RED << e.what() << FIM << endl;
                continue;}


            if (jogo == "V" || jogo == "VELHA"){
                Velha jogoVelha(apelido1,apelido2,manager);
                jogoVelha.iniciarJogo();
            }else if(jogo == string("R") || jogo == "REVERSI"){
                Reversi jogoReversi(apelido1,apelido2,manager);
                jogoReversi.iniciarJogo();
            }else if(jogo == string("L") || jogo == "LIG4"){
                Lig4 jogoLig4(apelido1,apelido2,manager);
                jogoLig4.iniciarJogo();
            }else{
                cout << RED << "jogo não reconhecido!" << FIM << endl;
            }
            limparConsole(3);
        }else if (comando == "EPC" || comando == "5"){
            cout << endl;
            string jogo;
            string apelido1;
            string apelido2 = "GLADOS";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (apelido1.empty()) {
                cout << "Apelido do primeiro jogador: " << endl;
                getline(cin, apelido1);}
            try {
                apelido1 = manager.VerificaJogadores(apelido1);
            } catch (const exception& e) {
                cout << RED << e.what() << FIM << endl;
                continue;}

            apelido2 = manager.VerificaJogadores(apelido2);

            Velha jogoVelha(apelido1,apelido2,manager);
            jogoVelha.iniciarJogo();
            limparConsole(3);

        }else if (comando == "FS" || comando == "5"){
            manager.SalvarArquivo();
            return 0;
        }else{
            cout << RED << "Comando invalido tenta novamente!!" << FIM << endl;
        }

    }


}
