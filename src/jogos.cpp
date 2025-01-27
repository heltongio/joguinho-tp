#include "jogos.hpp"
#include "velha.hpp"

Jogos::Jogos(std::string jogador1, std::string jogador2, CadastroJogadores& manager)
    : jogador1(jogador1), jogador2(jogador2), manager(manager) {}

void Jogos::iniciarJogo(){}

void Jogos::criaTabuleiro(){}


Jogos::~Jogos() {
    return;
}