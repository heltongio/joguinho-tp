#include "gerente.hpp"



void CadastroJogadores::PullJogadores() {

    std::ifstream fileIn(arquivo);
    if (!fileIn.is_open()) {
        throw std::runtime_error("ERRO: nao foi possivel abrir o arquivo");
    }

    std::string linha;
    while(std::getline(fileIn, linha)) {
        std::stringstream ss(linha);
        std::string apelido, nome, nome_temp;
        
        int a, b, c, d, e, f;
        ss >> apelido >> nome >> nome_temp;
        while (!((nome_temp[0] <= 57)&&(48 <= nome_temp[0]))) {
                if (!nome.empty()) {
                    nome += " ";
                }
                nome += nome_temp;
                ss >> nome_temp;
        }
        std::istringstream iss(nome_temp);
        iss >> a;
        ss >> b >> c >> d >> e >> f;

        jogadores.push_back(Jogador(apelido, nome, a, b, c, d, e, f));
    }
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
                throw std::runtime_error("ERRO: jogador(a) repetido");
            }
        }
    std::cout << "Jogador(a) " << apelido << " cadastrado com sucesso" "\n" << std::endl;
    jogadores.push_back(Jogador(apelido, nome));
    return;
}

void CadastroJogadores::RemoverJogador(std::string apelido) {
    int aux = -1;
    int verif = 0;
    for (auto& jogador : jogadores) {
        aux++;
        if (jogador.GetApelido() == apelido) {
            jogadores.erase(jogadores.begin()+ aux);
            verif = 1;
            std::cout << "Jogador(a) " << apelido << " removido" << std::endl;
        }
    }
    if (verif == 0){
        throw std::runtime_error("ERRO: jogador(a) inexistente");
    }
    return;
}

void CadastroJogadores::VerificaJogadores(std::string apelido){
    for (auto& jogador : jogadores) {
            if (jogador.GetApelido() == apelido) {
                return;
            }
    }
    throw std::runtime_error("ERRO: jogador(a) nao cadastrado");
}

void CadastroJogadores::SalvarArquivo() {
    std::ifstream fileIn(arquivo);
    std::ofstream fileOut(arquivo, std::ofstream::trunc);
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
    
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b) {
        return (a.GetApelido() < b.GetApelido());
    });

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



