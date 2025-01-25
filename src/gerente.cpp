#include "gerente.hpp"


CadastroJogadores::CadastroJogadores(std::string caminho) {
    arquivo = caminho;
}

void CadastroJogadores::PullJogadores() {

    std::ifstream fileIn(arquivo);
    if (!fileIn.is_open()) {
        throw std::runtime_error("ERRO: nao foi possivel abrir o arquivo");
    }

    //Abrindo o arquivo e coletando as linhas
    std::string linha;
    while(std::getline(fileIn, linha)) {
        std::stringstream ss(linha);
        std::string apelido, nome, nome_temp;
        
        int a, b, c, d, e, f;
        ss >> apelido >> nome >> nome_temp;
        while (!std::isdigit(nome_temp[0])) { //Pegando nomes compostos
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
    OrganizaJogadores();
    SalvarArquivo();
    fileIn.close();
    return;
}

void CadastroJogadores::PushJogadores() {
    std::fstream file(arquivo, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir arquivo" << std::endl;
        return;
    }
    //Modificando os dados do arquivo
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
    //variaveis usadas para formatar nomes e apelidos
    std::stringstream ss(nome);
    std::string palavra, novo_nome;

    //Verifica se o nome está de acordo com o padrão esperado
    for (auto& letra : nome){
        if (!isalpha(letra) && letra != ' '){
            throw std::invalid_argument("ERRO: nome com algarismos nao alfabeticos '" + nome + "'");
        }
    }
    //Verifica se o apelido está de acordo com o padrão esperado
    for (auto& letra : apelido){
        if (!isalpha(letra)){
            throw std::invalid_argument("ERRO: apelido com algarismos nao alfabeticos ou com mais de uma palavra '" + apelido + "'");
        }
    }
    //Formata o nome deixa-los padronizados
    
    while (ss >> palavra) {
        for (auto& letra : palavra) letra = std::tolower(letra);
        palavra[0] = std::toupper(palavra[0]);
        novo_nome += palavra + ' ';
    }
    novo_nome.pop_back();

    //Formata o apelido
    for(auto& letra : apelido) letra = std::tolower(letra);
    apelido[0] = std::toupper(apelido[0]);

    //Verifica se o jogador já está cadastrado
    for (auto& jogador : jogadores) {
            if (jogador.GetApelido() == apelido) {
                throw std::invalid_argument("ERRO: jogador(a) '" + jogador.GetApelido() + "' repetido");
            }
        }

    jogadores.push_back(Jogador(apelido, novo_nome));
    std::cout << "Jogador(a) " << apelido << " cadastrado com sucesso" "\n" << std::endl;

    OrganizaJogadores();

    SalvarArquivo();
    return;
}

void CadastroJogadores::RemoverJogador(std::string apelido) {
    int aux = -1;
    int verif = 0;
    
    //Fomatando o apelido recebido do usuario para encaixar em nosso padrao
    for(auto& letra : apelido) letra = std::tolower(letra);
    apelido[0] = std::toupper(apelido[0]);

    //Procura jogador repetido
    for (auto& jogador : jogadores) {
        aux++;
        if (jogador.GetApelido() == apelido) {
            jogadores.erase(jogadores.begin() + aux);
            verif = 1;
            std::cout << "Jogador(a) " << apelido << " removido" << std::endl;
        }
    }
    if (verif == 0){
        throw std::runtime_error("ERRO: jogador(a) inexistente");
    }
    SalvarArquivo();
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

void CadastroJogadores::OrganizaJogadores(){
    std::sort(jogadores.begin(), jogadores.end(), [](const Jogador& a, const Jogador& b) {
        return (a.GetApelido() < b.GetApelido());
    });
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
    SalvarArquivo();
}

void CadastroJogadores::AddDer(std::string apelido, std::string jogo) {
    for (auto& jogador : jogadores){
        if (apelido == jogador.GetApelido()){
            jogador.SomarDer(jogo);
        }
    }
    SalvarArquivo();
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



