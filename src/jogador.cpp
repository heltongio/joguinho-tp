#include "jogador.hpp"
#include <iostream>
#include <string>

Jogador::Jogador(std::string apelido, std::string nome,int VitVelha, int VitLig4, int VitReversi, int DerVelha, int DerLig4, int DerReversi) :  _apelido(apelido), _nome(nome) {
    _estatisticas["velha"] = {VitVelha,DerVelha};
    _estatisticas["lig4"] = {VitLig4,DerLig4};
    _estatisticas["reversi"] = {VitReversi,DerReversi};
};

Jogador::Jogador(std::string apelido, std::string nome) : Jogador(apelido, nome, 0, 0, 0, 0, 0, 0) {};

std::string Jogador::GetNome() {
    return this->_nome;
};

std::string Jogador::GetApelido() {
    return this->_apelido;
};

void Jogador::SomarVit(const std::string& jogo) {
    this->_estatisticas[jogo].first++;
    return;
}

void Jogador::SomarDer(const std::string& jogo) {
    this->_estatisticas[jogo].second++;
    return;
}

int Jogador::GetVit(const std::string& jogo) {
    return this->_estatisticas[jogo].first;
}

int Jogador::GetDer(const std::string& jogo) {
    return this->_estatisticas[jogo].second;
}

Jogador::~Jogador() {
    return;
}