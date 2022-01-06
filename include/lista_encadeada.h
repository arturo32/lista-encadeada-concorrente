#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <forward_list>
#include <iostream>

class lista_encadeada {
	private:
		std::forward_list<int> lista;

	public:
		void leLista();
		void removeElemento(int elemento);
		void insereElemento(int elemento);
};

#endif