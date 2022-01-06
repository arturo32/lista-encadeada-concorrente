#include <iostream>
#include "lista_encadeada.h"
#include <thread>




int main(){
/*	std::forward_list<int> numeros{2, 3, 5, 6};
	auto it = numeros.begin();
	std::cout << *it << std::endl;


	std::thread threads[1];*/
	

	lista_encadeada lista;
	lista.insereElemento(2);
	lista.insereElemento(3);
	lista.insereElemento(4);
	lista.insereElemento(22);

	lista.removeElemento(3);

	lista.leLista();

	//Instancia e inicia as threads para calcular as linhas da matriz produto
	//threads[0] = std::thread(leLista, numeros);
	//threads[0].join();
	
	return 0;
}