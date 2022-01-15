#include "lista_encadeada.h"

void lista_encadeada::leLista(){
	for(auto it{this->lista.begin()}; it != this->lista.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void lista_encadeada::removeElemento(int elemento){
	mtx.lock();

	this->lista.remove(elemento);

	mtx.unlock();
}

void lista_encadeada::insereElemento(int elemento){
	mtx.lock();
	
	auto it = this->lista.before_begin();
	auto it2 = it;
	while(it != this->lista.end()){
		++it;
		if(it != this->lista.end()){
			it2 = it;
		}
	}
	this->lista.insert_after(it2, elemento);
	
	mtx.unlock();
}