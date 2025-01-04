#include "gerente.hpp"


// std::string retornaPasta() {
//     char cwd[PATH_MAX];
//     if (getcwd(cwd, sizeof(cwd)) == nullptr) {
//         std::cout << "erro ao encontrar diretorio";
//     }

//     std::string caminhoAtual(cwd);
//     size_t pos = caminhoAtual.find_last_of('/');
//     if (pos == std::string::npos) {
//         return caminhoAtual;
//     }

//     return caminhoAtual.substr(pos + 1);
// }


void CadastroJogadores::PullJogadores() {
    
    
    // std::string pastaAtual = retornaPasta();
    //     if (pastaAtual == "src") {
    //         arquivo = "../bancoDados/jogadores.txt";
    //     } else if (pastaAtual == "joguinho-tp") {
    //         arquivo = "bancoDados/jogadores.txt";
    //     } else if (pastaAtual == "bin") {
    //         arquivo = "../bancoDados/jogadores.txt"; 
    //     }else {
    //         throw std::runtime_error("Pasta esperada não encontrada: " + pastaAtual);
    //     }
    std::ifstream fileIn(arquivo);
    if (!fileIn.is_open()) {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }

    std::string linha;
    while(std::getline(fileIn, linha)) {
        std::stringstream ss(linha);
        std::string apelido, nome, nome_temp;
        
        int a, b, c, d, e, f;
        ss >> apelido >> nome >> nome_temp;
        while (((nome_temp[0] <= 90)&&(65 <= nome_temp[0]))) {
                nome = nome + " " + nome_temp;
                ss >> nome_temp;
        }
        std::istringstream iss(nome_temp);
        iss >> a;
        ss >> b >> c >> d >> e >> f;

        jogadores.push_back(Jogador(apelido, nome, a, b, c, d, e, f));
    }
    std::ofstream fileOut(arquivo, std::ofstream::trunc);
    fileIn.close();
    return;}

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

void CadastroJogadores::RemoverJogador(std::string apelido) {
    int aux = -1;
    int verif = 0;
    for (auto& jogador : jogadores) {
        aux++;
        if (jogador.GetApelido() == apelido) {
            jogadores.erase(jogadores.begin()+ aux);
            verif = 1;
            std::cout << "Jogador " << apelido << " removido" << std::endl;
        }
    }
    if (verif == 0){
        std::cout << "ERRO: Jogador " << apelido << " inexistente" << std::endl;
    }
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



