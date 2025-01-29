#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogador.hpp"
#include "tabuleiro.hpp"
#include "gerente.hpp"
#include "lig4.hpp"
#include "velha.hpp"
#include "reversi.hpp"
#include "minimax.hpp"

TEST_CASE("Testando a classe Jogador") {
    Jogador jogador("apelido1", "Nome Completo", 5, 3, 2, 1, 4, 2);

    CHECK(jogador.GetNome() == "Nome Completo");
    CHECK(jogador.GetApelido() == "apelido1");
    CHECK(jogador.GetVit("velha") == 5);
    CHECK(jogador.GetDer("lig4") == 4);

    jogador.SomarVit("reversi");
    CHECK(jogador.GetVit("reversi") == 3);

    jogador.SomarDer("velha");
    CHECK(jogador.GetDer("velha") == 2);

    SUBCASE("Testando inicialização padrão") {
        Jogador jogadorPadrao("player2", "Default");
        CHECK(jogadorPadrao.GetVit("velha") == 0);
        CHECK(jogadorPadrao.GetDer("lig4") == 0);
    }
}

TEST_CASE("Testando a classe Tabuleiro") {
    Tabuleiro tabuleiro(3, 3, ' ');

    CHECK_NOTHROW(tabuleiro.atualizarCelula(0, 0, 'X'));
    CHECK_NOTHROW(tabuleiro.atualizarCelula(1, 1, 'O'));

    auto grid = tabuleiro.getGrid();
    CHECK(grid[0][1] == 'X');
    CHECK(grid[1][3] == 'O');

    SUBCASE("Testando estado limpo do tabuleiro") {
        std::string estadoLimpo = tabuleiro.getEstadoLimpo();
        CHECK(estadoLimpo.size() == 9);
    }
}

TEST_CASE("Testando todas as jogadas possíveis do jogo da Velha") {
    CadastroJogadores cadastro("test_data.txt");
    Velha velha("player1", "player2", cadastro);
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            CHECK_NOTHROW(velha.verificaJogada(i, j, 'X', "player1"));
        }
    }
}

TEST_CASE("Testando cenário de empate no jogo da Velha") {
    CadastroJogadores cadastro("test_data.txt");
    Velha velha("player1", "player2", cadastro);
    velha.jogada("player1", "player2", 'X');
    velha.jogada("player2", "player1", 'O');
    velha.jogada("player1", "player2", 'X');
    velha.jogada("player2", "player1", 'O');
    velha.jogada("player1", "player2", 'X');
    velha.jogada("player2", "player1", 'O');
    velha.jogada("player1", "player2", 'X');
    velha.jogada("player2", "player1", 'O');
    velha.jogada("player1", "player2", 'X');
    CHECK(velha.verificaTabuleiroCompleto("player1", "player2", false) == true);
}

TEST_CASE("Testando Minimax em cenários extremos") {
    Tabuleiro tab(3, 3, ' ');
    Minimax minimax("player1", "player2", 'X', 'O');

    auto melhorJogada = minimax.melhoraco(tab, 'X', false);
    CHECK(melhorJogada.size() == 2);
    CHECK(melhorJogada[0] >= 0);
    CHECK(melhorJogada[0] < 3);
    CHECK(melhorJogada[1] >= 0);
    CHECK(melhorJogada[1] < 3);
}

TEST_CASE("Testando o jogo Lig4") {
    CadastroJogadores cadastro("test_data.txt");
    Lig4 lig4("player1", "player2", cadastro);

    SUBCASE("Iniciar jogo e realizar jogadas válidas e inválidas") {
        CHECK_NOTHROW(lig4.iniciarJogo());
        CHECK_NOTHROW(lig4.realizarJogada(0, 'X'));
        CHECK_NOTHROW(lig4.realizarJogada(1, 'O'));
        CHECK_THROWS(lig4.realizarJogada(7, 'X')); // Coluna fora do limite
        CHECK_THROWS(lig4.realizarJogada(-1, 'O')); // Coluna negativa
    }

    SUBCASE("Testar condições de vitória") {
        lig4.realizarJogada(0, 'X');
        lig4.realizarJogada(1, 'X');
        lig4.realizarJogada(2, 'X');
        lig4.realizarJogada(3, 'X');
        CHECK(lig4.verificaLinha(0, 'X') == true);
    }

    SUBCASE("Testar condições de empate") {
        // Preencher o tabuleiro com jogadas que resultam em empate
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                char jogador = (i + j) % 2 == 0 ? 'X' : 'O';
                CHECK(lig4.realizarJogada(j, jogador) == true);
            }
        }
        CHECK(lig4.verificaColuna(0, 'X') == false);
    }
}

TEST_CASE("Testando o jogo Reversi") {
    CadastroJogadores cadastro("test_data.txt");
    Reversi reversi("player1", "player2", cadastro);

    SUBCASE("Iniciar jogo e realizar jogadas válidas e inválidas") {
        CHECK_NOTHROW(reversi.iniciarJogo());
        CHECK(reversi.verificaJogada(4, 5, 'X', "player1") == true);
        CHECK(reversi.verificaJogada(3, 5, 'O', "player2") == true);
        CHECK(reversi.verificaJogada(0, 0, 'X', "player1") == false); // Jogada inválida
    }

    SUBCASE("Testar verificação de vitória e empate") {
        CHECK(reversi.verificaEmpate() == false);
        CHECK(reversi.verificaGanhador("player1", "player2", 'X', false) == false);
    }

    SUBCASE("Testar recursão para captura de peças") {
        CHECK(reversi.iniciaRecursao(3, 4, 'X', true) == true);
        CHECK(reversi.iniciaRecursao(5, 6, 'O', true) == false); // Jogada inválida
    }
}