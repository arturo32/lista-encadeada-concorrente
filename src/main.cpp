#include <iostream>
#include <forward_list>
#include <thread>


void leLista(std::forward_list<int> lista){
	for(auto it{lista.begin()}; it != lista.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void removeElemento(std::forward_list<int> &lista, int elemento){
	lista.remove(elemento);
}

void insereElemento(std::forward_list<int> &lista, int elemento){
	auto it = lista.begin();
	auto it2 = lista.begin();
	while(it != lista.end()){
		++it;
		if(it != lista.end()){
			it2 = it;
		}
	}

	std::cout << *it2 << std::endl;
	lista.insert_after(it2, elemento);
}

int main(){
	std::forward_list<int> numeros{2, 3, 5, 6};
	auto it = numeros.begin();
	std::cout << *it << std::endl;


	std::thread threads[1];
	
	insereElemento(numeros, 22);
	removeElemento(numeros, 3);
	leLista(numeros);

	//Instancia e inicia as threads para calcular as linhas da matriz produto
	//threads[0] = std::thread(leLista, numeros);
	//threads[0].join();
	
	return 0;
}