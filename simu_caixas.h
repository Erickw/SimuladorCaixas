#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef _simu_caixas_h_
#define _simu_caixas_h_

using namespace std;


template <class T>

class Nodo{

public:

	T dado;

	Nodo *proximo;

public:

	Nodo(const T& new_dado);
	
};

template <class T>

class ListaEncadeada{

public:

	
	Nodo<T> *inicio;

public:

	ListaEncadeada();

	~ListaEncadeada();

	void inserir(const T& dado);

	Nodo<T>* menor_caixa();

	int Top();

	int Peek();

	bool buscar(const T& dado);

	void imprime();

	int quantidade();

	void remover_inicio();

	void remover_final();

	void visitar();
};

class Clientes{

public:

	int caixa_associado;
	int tempo_chegada;
	int tempo_atendimento;

public:

	Clientes(int chegada_min, int chegada_max , int temp_min_atd , int temp_max_atd);

	int random(int min , int max);


};


class Caixas{

public:

	ListaEncadeada<Clientes> fila_clientes;

	bool estado;
	int chegada_min;
	int chegada_max;
	int temp_min_atd;
	int temp_max_atd;

public:

	Caixas();
	void novo_cliente();
};



class Supermercado{

public:

	ListaEncadeada<Caixas> caixas;

	int caixas_abertos;
	int temp_max_fila;

public:

	Supermercado(int temp_max_fila);
	void abre_caixa();
	void seleciona_caixa(ListaEncadeada<Caixas> &c2);
	
	

};


#include "simu_caixas.inl"
#endif