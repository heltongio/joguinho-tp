# Variáveis
CC = g++
CFLAGS = -std=c++11 -Wall #-Wextra -Iinclude 
LDFLAGS = #caso seja necessario no futuro
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests
TARGET = $(BIN_DIR)/main
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) #lista todos os arquivos no diretorio SRC
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp) #lista todos os arquivos no diretorio TEST

# gerar os arquivos objeto correspondentes
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_FILES))


all: setup $(TARGET)

#cria pastas DIR e OBJ caso não exista
setup:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Compilar o programa principal
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Main built. rode com ./bin/main"

# Regra para compilar arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Testes
tests: setup $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/tests $(TEST_OBJ_FILES) $(OBJ_FILES) $(LDFLAGS)
	@echo "Tests built. rode com ./bin/tests"

# Limpeza
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all setup clean tests #evita complitos ao executar o make clean
