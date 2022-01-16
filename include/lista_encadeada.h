#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <mutex>

class lista_encadeada {
	private:
		std::forward_list<int> lista;
		std::mutex mtx;

	public:
		void buscaElemento(int elemento);
		void removeElemento(int elemento);
		void insereElemento(int elemento);
};

#endif