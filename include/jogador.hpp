#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iomanip>
#include <map>

class Jogador {
    
    private:
        std::string _apelido;
        std::string _nome;
        std::map<std::string, std::pair<int, int>> _estatisticas; //map que armazena [Nome do Jogo] {vitórias,}

    public:
        //Construtores <apelido> <nome> <VitVelha> <VitLig4> <VitReversi> <DerVelha> <DerLig4> <DerReversi>
        Jogador(std::string, std::string, int, int, int, int, int, int);//Criar jogador com determinado número de vitórias/derrotas
        Jogador(std::string, std::string); //Criar jogador com 0 vitórias/derrotas

        //Get de nome e apelido
        std::string GetNome();
        std::string GetApelido();

        //Adicionar vitória/derrota ao jogador com <jogo> (velha, lig4, reversi)
        void SomarVit(const std::string&);
        void SomarDer(const std::string&);

        //Get para vitória/derrota do jogador com <jogo> (velha, lig4, reversi)
        int GetVit(const std::string&);
        int GetDer(const std::string&);

        //Destrutor
        ~Jogador();
};

#endif