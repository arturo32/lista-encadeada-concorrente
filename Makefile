# Compila o main.cpp
all: mkbin main
	
# mkbin cria o diretório de objetos. -p é uma flag
# para o comando funcionar mesmo se o diretório já existe	
mkbin:
	mkdir -p bin
	

main: bin/lista_encadeada.o src/main.cpp
	g++ -std=c++11 src/main.cpp  bin/*.o -Iinclude -Wall -pedantic -o main -pthread

bin/lista_encadeada.o: src/lista_encadeada.cpp
	g++ -std=c++11 src/lista_encadeada.cpp -Iinclude -Wall -pedantic -c -o bin/lista_encadeada.o

# Apaga o arquivo executável
clean:
	rm -rf bin
	rm main