#include <iostream>
#include "lista_encadeada.h"
#include <thread>

#define T_NUMERO_INSERCAO 6
#define T_NUMERO_REMOCAO 2
#define T_NUMERO_BUSCA 2

int main(){
	std::thread threads_insercao[T_NUMERO_INSERCAO];	
	std::thread threads_remocao[T_NUMERO_REMOCAO];
	std::thread threads_busca[T_NUMERO_BUSCA];

	lista_encadeada lista;

	for(int i = 0; i < T_NUMERO_INSERCAO; ++i){
		threads_insercao[i] = std::thread(&lista_encadeada::insereElemento, &lista, i);	
	}

	for(int i = 0; i < T_NUMERO_REMOCAO; ++i){
		threads_remocao[i] = std::thread(&lista_encadeada::removeElemento, &lista, i);	
	}

	for(int i = 0; i < T_NUMERO_BUSCA; ++i){
		threads_busca[i] = std::thread(&lista_encadeada::leLista, &lista);	
	}

	

	for(int i = 0; i < T_NUMERO_INSERCAO; ++i){
		threads_insercao[i].join();
	}

	for(int i = 0; i < T_NUMERO_REMOCAO; ++i){
		threads_remocao[i].join();
	}

	for(int i = 0; i < T_NUMERO_BUSCA; ++i){
		threads_busca[i].join();
	}

	lista.leLista();
	std::cout << "aaaa" << std::endl;

	return 0;
}
