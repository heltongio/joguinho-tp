esse git representa um trabalho de jogo que será entregue na diciplina de PDSII



- bin/: Armazena os executáveis gerados pela compilação.
- include/: Contém arquivos de cabeçalho (.hpp) usados no projeto.
- obj/: Guarda arquivos objeto (.o ou .obj) criados durante a compilação.
- src/: Onde estão os arquivos de código-fonte (.cpp).
- tests/: Abriga arquivos de teste para validação do código.


.gitignore: Lista arquivos e pastas que o Git deve ignorar.
makefile: Contém instruções para automatizar a compilação do projeto.

use essas configurações no .vscode/tasks.json, para rodar o debug corretamente

"args": [
                "-fdiagnostics-color=always",
                "-g",
                "-I../include",                        
                "../src/main.cpp",                      // Arquivo principal
                "../src/gerente.cpp",                   // Arquivo .cpp do gerente
                "../src/jogador.cpp",                   // Arquivo .cpp do jogador
                "-o",                               // Especifica o arquivo de saída
                "${workspaceFolder}/bin/main"   
            ],




