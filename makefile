# Variáveis
CC = g++
CFLAGS = -std=c++11 -Wall --coverage -I$(INCLUDE_DIR) -I$(TEST_DIR)
LDFLAGS = --coverage # Para suporte ao gcov/lcov
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests
COVERAGE_DIR = coverage
TARGET = $(BIN_DIR)/main
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

# gerar os arquivos objeto correspondentes
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_FILES))

# Regra padrão
all: setup $(TARGET)

# cria pastas DIR e OBJ caso não existam
setup:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(COVERAGE_DIR)

# Compilar o programa principal
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Main built. Rode com ./bin/main"

# Regra para compilar arquivos objeto de src
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar arquivos objeto de teste
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Testes
tests: setup $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/tests $(TEST_OBJ_FILES) $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES)) $(LDFLAGS)
	@echo "Tests built. Rode com ./bin/tests"
	@./bin/tests

# Gerar cobertura
coverage: tests
	@echo "Gerando relatório de cobertura de código..."
	@mkdir -p $(COVERAGE_DIR)
	@gcovr -r . --html --html-details -o $(COVERAGE_DIR)/relatorio.html
	@echo "Relatório gerado em $(COVERAGE_DIR)/index.html"

# Limpeza
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(COVERAGE_DIR)

.PHONY: all setup clean tests coverage
