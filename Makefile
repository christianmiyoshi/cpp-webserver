CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++20

SRC = $(wildcard src/*.cpp)  # Captura automaticamente todos os arquivos .cpp dentro de src/
OBJ_DIR = build/obj
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

TARGET = build/main.out

# Coletar automaticamente todos os arquivos de teste na pasta tests/
TEST_SRC = $(wildcard tests/*.cpp) $(filter-out src/main.cpp, $(wildcard src/*.cpp))
TEST_OBJ = $(TEST_SRC:tests/%.cpp=$(OBJ_DIR)/tests/%.o)
TEST_TARGET = build/test.out

# Flag de debug para testes
DEBUG_FLAGS = -g

all: $(TARGET)

run:
	./$(TARGET)

# Regra para compilar todos os arquivos da pasta src/
$(OBJ_DIR)/%.o: src/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -rf build

# Compilar os arquivos de teste com debug
$(OBJ_DIR)/tests/%.o: tests/%.cpp
	mkdir -p $(OBJ_DIR)/tests
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Criar o executável de testes com debug ativado
test: $(TEST_OBJ)
	$(CXX) ${CXXFLAGS} $(TEST_OBJ) -o $(TEST_TARGET) -lgtest -lgtest_main -pthread $(DEBUG_FLAGS)
	./$(TEST_TARGET)
