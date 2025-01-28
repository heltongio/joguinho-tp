#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gerente.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "jogos.hpp"
#include "velha.hpp"
#include "lig4.hpp"
#include "reversi.hpp"
#include <stdexcept>
#include <fstream>


// Teste da classe Velha
TEST_CASE("Teste da classe Velha") {
    CadastroJogadores manager("bancoDados/jogadores.txt");
    manager.ConstruirVetor();

    Velha jogo("apelido1", "apelido2", manager);

    // SUBCASE("Teste de jogada do jogador") {
        // std::stringstream input("1\n2\n"); // Simula a entrada do usuário: linha = 1, coluna = 2
        // std::cin.rdbuf(input.rdbuf());    // Redireciona std::cin para a string simulada

        // CHECK_NOTHROW(jogo.iniciarJogo());

    //     // Verifica se a jogada foi processada corretamente
    //     CHECK(jogo. == 'X'); // Exemplo de validação
    // }

    CHECK_FALSE(jogo.verificaJogada(0, 0, 'X', "Jogador 1")); // Fora dos limites
    CHECK_FALSE(jogo.verificaJogada(4, 4, 'X', "Jogador 1")); // Fora dos limites

    CHECK(jogo.verificaJogada(1, 1, 'X', "Jogador 1")); // Jogada válida
    CHECK_FALSE(jogo.verificaJogada(1, 1, 'O', "Jogador 2")); // Posição já ocupada

    std::string estado = "XXX      "; // Linha 1 preenchida com X
    CHECK(jogo.verificaLinha(estado, 0, 'X'));
    CHECK_FALSE(jogo.verificaLinha(estado, 1, 'X'));







    std::ofstream arquivo("bancoDados/frases.txt");
    arquivo << "Frase 1\nFrase 2\nFrase 3\n";
    arquivo.close();

    std::string resultado = jogo.frase();
    CHECK((resultado == "Frase 1" || resultado == "Frase 2" || resultado == "Frase 3"));
}

// Teste da classe Reversi
TEST_CASE("Teste da classe Reversi") {
    CadastroJogadores manager("bancoDados/jogadores.txt");
    manager.ConstruirVetor();

    Reversi jogo("apelido1", "apelido2", manager);

    // SUBCASE("Teste de inicialização do jogo Reversi") {
    //     CHECK_NOTHROW(jogo.iniciarJogo());
    // }
}

// Teste da classe Lig4
TEST_CASE("Teste da classe Lig4") {
    CadastroJogadores manager("bancoDados/jogadores.txt");
    manager.ConstruirVetor();

    Lig4 jogo("apelido1", "apelido2", manager);

    // SUBCASE("Teste de inicialização do jogo Lig4") {
    //     CHECK_NOTHROW(jogo.iniciarJogo());
    // }
}

// // Teste da função limparConsole
// TEST_CASE("Teste da função limparConsole") {
//     CHECK_NOTHROW(limparConsole(1));
// }
