#include "lista_encadeada.h"

void lista_encadeada::buscaElemento(int elemento){
	std::cout << "Busca: tentativa de bloqueio do mutex.\n";
	mtx.lock();
	std::cout << "Busca: mutex bloqueado.\n";

	bool achou = false;

	for(auto it{this->lista.begin()}; it != this->lista.end(); ++it){
		if(*it == elemento){
			achou = true;
		}
	}

	if(achou){
		std::cout << "\tBusca: elemento " << elemento << " encontrado.\n";
	}else{
		std::cout << "\tBusca: elemento " << elemento << " NÃO encontrado.\n";
	}

	std::cout << "Busca: mutex liberado.\n";
	mtx.unlock();
}

void lista_encadeada::removeElemento(int elemento){
	std::cout << "Remoção: tentativa de bloqueio do mutex.\n";
	mtx.lock();
	std::cout << "Remoção: mutex bloqueado.\n";

	this->lista.remove(elemento);
	std::cout << "\tRemoção: elemento " << elemento << " removido (se existente).\n";

	std::cout << "Remoção: mutex liberado.\n";
	mtx.unlock();
}

void lista_encadeada::insereElemento(int elemento){
	std::cout << "Inserção: tentativa de bloqueio do mutex.\n";
	mtx.lock();
	std::cout << "Inserção: mutex bloqueado.\n";
	
	auto it = this->lista.before_begin();
	auto it2 = it;
	while(it != this->lista.end()){
		++it;
		if(it != this->lista.end()){
			it2 = it;
		}
	}
	this->lista.insert_after(it2, elemento);
	std::cout << "\tInserção: elemento " << elemento << " inserido.\n";
	
	std::cout << "Inserção: mutex liberado.\n";
	mtx.unlock();
}