#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "gerente.hpp"

TEST_CASE("Teste Gerente - Adicionar Jogadores") {
    CadastroJogadores manager("bancoDados/jogadores_teste.txt");

    manager.ConstruirVetor();

    //Alterando a saida de cout para o buffer, para poder coletar os dados printados pelo metodo
    std::ostringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    manager.CadastrarJogador("mOISes", "ArNAlDo pEreIra dOs SANtos");//Usando nome e apelido fora da formatação para testar esses casos também

    buffer.str("");
    buffer.clear();

    std::string saida_esperada = "Moises Arnaldo Pereira Dos Santos\n"
                                  "VELHA - V: 0 D: 0\n"
                                  "LIG4 - V: 0 D: 0\n"
                                  "REVERSI - V: 0 D: 0\n\n";

    manager.PrintJogadores();

    CHECK(buffer.str() == saida_esperada); //Testa o cadastro e impressao corretos de um jogador corretamente

    buffer.str("");
    buffer.clear();

    CHECK_THROWS_WITH ( //Testa um input incorreto do apelido
        manager.CadastrarJogador("M01535","Moises Arnaldo Pereira Dos Santos"),
        "ERRO: apelido com algarismos nao alfabeticos ou com mais de uma palavra 'M01535'"
    );

    CHECK_THROWS_WITH ( //Testa um input incorreto do nome
        manager.CadastrarJogador("Tauba","Em1l14 R0b35"),
        "ERRO: nome com algarismos nao alfabeticos 'Em1l14 R0b35'"
    );

    CHECK_THROWS_WITH ( //Testa um input repetido
        manager.CadastrarJogador("Moises", "Arnaldo Pereira Dos Santos"),
        "ERRO: jogador(a) 'Moises' repetido"
    );

    manager.CadastrarJogador("Mimi", "Emilia Robes");

    buffer.str("");
    buffer.clear();

    saida_esperada = "Mimi Emilia Robes\n"
                     "VELHA - V: 0 D: 0\n"
                     "LIG4 - V: 0 D: 0\n"
                     "REVERSI - V: 0 D: 0\n\n"
                     "Moises Arnaldo Pereira Dos Santos\n"
                     "VELHA - V: 0 D: 0\n"
                     "LIG4 - V: 0 D: 0\n"
                     "REVERSI - V: 0 D: 0\n\n";

    manager.PrintJogadores();

    CHECK(buffer.str() == saida_esperada); //Testar a organização alfabetica
    
    std::cout.rdbuf(oldCout);    
}

TEST_CASE("Teste Gerente - Remover Jogadores") {
    CadastroJogadores manager("bancoDados/jogadores_teste.txt");

    manager.ConstruirVetor();

    //Alterando a saida de cout para o buffer, para poder coletar os dados printados pelo metodo
    std::ostringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    std::string saida_esperada = "Jogador(a) Mimi removido\n";

    manager.RemoverJogador("MiMi"); //Usando MiMi fora da formatação para testar esses casos também

    CHECK(buffer.str() == saida_esperada); //Testando de a jogadora Mimi foi removida

    CHECK_THROWS_WITH (
        manager.RemoverJogador("Tauba"),
        "ERRO: jogador(a) inexistente 'Tauba'"
    );

    std::cout.rdbuf(oldCout);
}

TEST_CASE("Teste Gerente - Adicionar vitoria/derrotas") {
    CadastroJogadores manager("bancoDados/jogadores_teste.txt");

    manager.ConstruirVetor();

    //Alterando a saida de cout para o buffer, para poder coletar os dados printados pelo metodo
    std::ostringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    std::string saida_esperada = "Moises Arnaldo Pereira Dos Santos\n"
                                  "VELHA - V: 1 D: 1\n"
                                  "LIG4 - V: 1 D: 1\n"
                                  "REVERSI - V: 1 D: 1\n\n";
    
    manager.AddVit("Moises", "velha");
    manager.AddVit("Moises", "lig4");
    manager.AddVit("Moises", "reversi");

    manager.AddDer("Moises", "velha");
    manager.AddDer("Moises", "lig4");
    manager.AddDer("Moises", "reversi");

    manager.PrintJogadores();

    CHECK(buffer.str() == saida_esperada); //Teste para que a saída com as vit/der estejam atualizadas

    buffer.str("");//limpando buffer
    buffer.clear();

    manager.RemoverJogador("Moises");
    std::cout.rdbuf(oldCout);  
}
