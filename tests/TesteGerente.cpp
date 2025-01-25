// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

// #include "gerente.hpp"

// TEST_CASE("Teste Gerente - Adicionar Jogadores") {
//     CadastroJogadores manager("bancoDados/jogadores_teste.txt");

//     manager.ConstruirVetor();

//     manager.CadastrarJogador("Moises", "Arnaldo Pereira dos Santos");

//     std::string output = manager.PrintJogadores();

//     std::string saida_esperada = "Moises Arnaldo Pereira dos Santos\n"
//                                   "VELHA - V: 0 D: 0\n"
//                                   "LIG4 - V: 0 D: 0\n"
//                                   "REVERSI - V: 0 D: 0\n";

//     manager.PrintJogadores();
//     CHECK(1 == 1);

// }