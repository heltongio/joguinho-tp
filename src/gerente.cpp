#include "gerente.hpp"

void CadastroJogadores::PullJogadores() {
    std::ifstream fileIn(arquivo);
    if (!fileIn.is_open()) {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    std::string linha;
    while(std::getline(fileIn, linha)) {
        std::stringstream ss(linha);
        std::string apelido, nome;
        
        int a, b, c, d, e, f;
        ss >> apelido >> nome >> a >> b >> c >> d >> e >> f;

        jogadores.push_back(Jogador(apelido, nome, a, b, c, d, e, f));
    }
    std::ofstream fileOut(arquivo, std::ofstream::trunc);
    fileIn.close();
    return;
}

void CadastroJogadores::PushJogadores() {
    std::fstream file(arquivo, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }
    for (auto& jogador : jogadores){
        file << jogador.GetApelido() << " " << jogador.GetNome() << " "
        << jogador.GetVit("velha") << " " << jogador.GetVit("lig4") << " "
        << jogador.GetVit("reversi") << " " << jogador.GetDer("velha") << " "
        << jogador.GetDer("lig4") << " " << jogador.GetDer("reversi");
        file << "\n";
    }
    file.close();
    return;
}

void CadastroJogadores::ConstruirVetor() {
    PullJogadores();
    return;
}

void CadastroJogadores::CadastrarJogador(std::string apelido, std::string nome) {
    for (auto& jogador : jogadores) {
            if (jogador.GetApelido() == apelido) {
                std::cout << "ERRO: jogador repetido" << "\n" << std::endl;
                return;
            }
        }
    std::cout << "Jogador " << apelido << " cadastrado com sucesso" "\n" << std::endl;
    jogadores.push_back(Jogador(apelido, nome));
    return;
}

void CadastroJogadores::SalvarArquivo() {
    PushJogadores();
    return;
}

void CadastroJogadores::AddVit(std::string apelido, std::string jogo) {
    for (auto& jogador : jogadores){
        if (apelido == jogador.GetApelido()){
            jogador.SomarVit(jogo);
        }
    }
}

void CadastroJogadores::AddDer(std::string apelido, std::string jogo) {
    for (auto& jogador : jogadores){
        if (apelido == jogador.GetApelido()){
            jogador.SomarDer(jogo);
        }
    }
}

void CadastroJogadores::PrintJogadores() {
    for (auto jogador : jogadores){
        std::cout << jogador.GetApelido() << " " << jogador.GetNome() << std::endl;
        std::cout << "VELHA - " << "V: " << jogador.GetVit("velha") << " D: " << jogador.GetDer("velha") << std::endl;
        std::cout << "LIG4 - " << "V: " << jogador.GetVit("lig4") << " D: " << jogador.GetDer("lig4") << std::endl;
        std::cout << "REVERSI - " << "V: " << jogador.GetVit("reversi") << " D: " << jogador.GetDer("reversi") << std::endl;
        std::cout << std::endl;
    }
    return;
}

CadastroJogadores::~CadastroJogadores() {
    return;
}



