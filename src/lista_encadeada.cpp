#include "lista_encadeada.h"

void lista_encadeada::leLista(){
	mtx.lock();
	std::cout << "Mutex bloqueado em leLista." << std::endl;

	for(auto it{this->lista.begin()}; it != this->lista.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Mutex liberado em leLista." << std::endl;
	mtx.unlock();
}

void lista_encadeada::removeElemento(int elemento){
	mtx.lock();
	std::cout << "Mutex bloqueado em removeElemento." << std::endl;

	this->lista.remove(elemento);

	std::cout << "Mutex liberado em removeElemento." << std::endl;
	mtx.unlock();
}

void lista_encadeada::insereElemento(int elemento){
	mtx.lock();
	std::cout << "Mutex bloqueado em insereElemento." << std::endl;
	
	auto it = this->lista.before_begin();
	auto it2 = it;
	while(it != this->lista.end()){
		++it;
		if(it != this->lista.end()){
			it2 = it;
		}
	}
	this->lista.insert_after(it2, elemento);
	
	std::cout << "Mutex liberado em insereElemento." << std::endl;
	mtx.unlock();
}