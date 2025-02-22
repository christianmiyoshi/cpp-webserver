CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17
SRC = src/http_tcpserver.cpp src/server_linux.cpp
OBJ = $(SRC:src/%.cpp=build/%.o)

TARGET = main.out

all: $(TARGET)

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o build/$(TARGET)

clean:
	rm -rf build $(TARGET)