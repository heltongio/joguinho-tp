Esse git representa um trabalho de jogo que será entregue na diciplina de PDSII - TW

Diretórios
-
- bin/: Armazena os executáveis gerados pela compilação.
- include/: Contém arquivos de cabeçalho (.hpp) usados no projeto.
- obj/: Guarda arquivos objeto (.o ou .obj) criados durante a compilação.
- src/: Onde estão os arquivos de código-fonte (.cpp).
- tests/: Abriga arquivos de teste para validação do código.
- .gitignore: Lista arquivos e pastas que o Git deve ignorar.
- makefile: Contém instruções para automatizar a compilação do projeto.
- wiki_images/: Imagens dos cartões CRC usados no Wiki

O Trabalho
-
  O objetivo deste código é implementar o funcionamento de alguns jogos de tabuleiro. Para isso é necessário conhecer e implementar as regras dos jogos escolhidos, que foram: 
- Jogo da Velha - https://pt.wikipedia.org/wiki/Jogo_da_velha
- Lig4 - https://pt.wikipedia.org/wiki/Lig_4
- Reversi - https://en.wikipedia.org/wiki/Reversi

O programa executa:
1. Construção de cada jogo utilizando conceitos como hierarquia, polimorfismo e composição.
2. Cadastro, armazenamento e edição de dados dos jogadores.
3. Realização de testes para verificar um código limpo, coberto e reútilizavel.
4. Interação com um oponente de Inteligência Artificial
Com isso precisamos trabalhar com todos os conceitos apresentados até aqui para produzir este código.

Estrutura
-
  - **Classe jogador** - Uma classe que foi utilizada para guardar dados simples dos jogadores que será usada com composição.
  - **Armazenamento de dados** - Para o tratamento de dados como cadastro, remoção e modificações nas vitórias e derrotas foi utilizado um arquivo.txt. Isto garante o armazenamento de dados para múltiplas execuções do código.
  O código realiza a coleta e salvamento de dados recorrentemente para minimizar a possibilidade de perda de dados em caso de quebra de funcionamento no meio da execução.
  - **Classe Jogos** - Uma classe virtual que abrange os métodos que serão comuns às classes filhas
    - **Classe Velha** - Classe que executa o jogo da velha e é subclasse de Jogos
    - **Classe Lig4** - Classe que executa o jogo da Lig4 e é subclasse de Jogos
    - **Classe Reversi** - Classe que executa o jogo da Reversi e é subclasse de Jogos
  - **Tabuleiro** - Classe que cria e printa o tabuleiro de cada jogo seguindo o devido padrão
  - **Minimax** - Classe que cria e executa o compotamento do oponente de Inteligência Artificial

Funcionamento
-
O funcionamento do código se dá através de comandos do usuário. É possível cadastrar novos jogadores com a classe gerente, permitindo que o jogador insira um apelido, que deverá ser único, com uma única palavra e um nome podendo ser apenas o primeiro nome ou nome e sobrenome, sendo que devem ser utilizados apenas algarismos alfabéticos. Pode-se também remover jogadores a partir de seu apelido único. Também é possível printar todos os jogadores cadastrados com seus respectivos dados. 
Indo além desses processos básicos, partimos para execução dos jogos. Após escolher o jogo desejado sua respectiva classe inicia o jogo e realizará todos os processos esperados para os jogos, estes são: realizar uma jogada, com base em cordenadas do tabuleiro; verificar se tal jogada é válida; verificar seu o jogador venceu após sua rodada; verificar empate; e por fim, atualizar os dados de vitória e derrota dos jogadores.  
É possível também realizar um duelo contra a Inteligência Artificial, que segue o mesmo padrão de regras descrito anteriormente

Problemas
-
Entre os problemas encontrados, o mais comum se deu em se tratar com entradas inesperadas. Por exemplo, uma entrada de algarismos alfabéticos quando se espera numeros inteiros. Outro problema inesperado foi lidar com o funcionameto do Git, em se tratando de que alguns dos desenvolvedores utilizavam Windows e outros Linux. Existiram outros pequenos problemas como a configuração do doctest e do doxygen, entretanto eles foram menos impactantes.

Extras
-
Por fim, a adição extra ao código está na previamente citada Inteligência Artificial através do Minimax. Permitindo que um usuário possa aproveitar o código mesmo se não houver um oponente humano para enfrentar.
