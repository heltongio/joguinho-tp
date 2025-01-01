#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "jogador.hpp"


class CadastroJogadores {
    private:
        std::vector<Jogador> jogadores; //Vetor que armazenará os dados do txt com o objeto Jogador
        const std::string arquivo = "../bancoDados/jogadores.txt"; //nome do txt
        //Métodos privados que acessam o arquivo para coleta e registro de dados
        void PullJogadores();
        void PushJogadores();
    
    public:

    void ConstruirVetor(); //Coleta os dados do txt e aloca no vetor jogadores
    void CadastrarJogador(const std::string, const std::string); //Adicona um jogador com nenhuma vitoria/derrota com o contrato <apelido> <nome>
    void SalvarArquivo(); //Salva os dados no txt

    //Add vitória/derrota com o contrato <apelido> <nome do jogo>(velha, lig4, reversi)
    void AddVit(const std::string, const std::string);
    void AddDer(const std::string, const std::string);

    void PrintJogadores(); //Imprime todos os dados dos jogadores
    
    ~CadastroJogadores(); //Destrutor
        
};

#endif