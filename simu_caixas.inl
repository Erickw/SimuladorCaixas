#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


	template <class T>

	Nodo<T>::Nodo(const T& new_dado) :
		dado( new_dado ),
		proximo( NULL ) 
	{
	}

template <class T>

ListaEncadeada<T>::ListaEncadeada() : inicio( NULL )
{
}

template <class T>

ListaEncadeada<T>::~ListaEncadeada(){
	while(inicio){
		Nodo<T> *proximo = inicio->proximo;
		delete inicio;
		inicio = proximo;
	}
}

template <class T>

void ListaEncadeada<T>::inserir(const T& dado){

	Nodo<T> *no = new Nodo<T>(dado);

		if(inicio == NULL){
			inicio = no;
		}
		else{

			Nodo<T> *novo = inicio;

			while(novo->proximo){
				novo = novo->proximo;
			}
			novo->proximo = no;
		
		}
}

template <class T>

bool ListaEncadeada<T>::buscar(const T& dado){

	bool result = 0;

	Nodo<T> *no = inicio;

	Nodo<T> *ant;

	while(no!= NULL){
		ant = no;
		if(ant->dado == dado){
			result = 1;
			break;			
	}	
	
		no = no->proximo;
	}

	return result;



	/*cout << dado << endl;
	cout << ant->dado << endl;*/


/*
	for(Nodo<T> *no = inicio, i < qtd; no = no->proximo, i++){

		cout << "Valor de no" << no->dado << endl;
		if(no->dado == dado){
			return true;
		}
		else{
			return false;
		}
	}*/
}

template <class T> 

Nodo<T>* ListaEncadeada<T>::menor_caixa(){

	Nodo<T> *aux = inicio;
	Nodo<T>	*menor = inicio;

	while(aux){
	
		if (aux->dado.fila_clientes.quantidade() < menor->dado.fila_clientes.quantidade()){
			menor = aux;
		}

		aux = aux->proximo;
	}

	return menor;
}

template <class T> 
	
int ListaEncadeada<T>::Top(){

	Nodo<T> *aux = inicio;

	Nodo<T> *no;

	while(aux->proximo != NULL){
		no = aux;
		aux = aux->proximo;
	}

	cout<< aux->dado<< endl;

}

template <class T>

int ListaEncadeada<T>::Peek(){

	return inicio->dado;

}

template <class T>

void ListaEncadeada<T>::imprime(){

	Nodo<T> *no = inicio; 

	//cout << "Os elementos da lista são:" << endl;

	while(no){
		cout << no->dado.fila_clientes.quantidade() << endl;
		no = no->proximo;
	}
}

template <class T>

int ListaEncadeada<T>::quantidade(){

	Nodo<T> *no = inicio; 

	int i = 0;

	while(no){
		no = no->proximo;
		i++;
	}

	return i;
}


template <class T>


void ListaEncadeada<T>::remover_inicio(){

	Nodo<T> *aux = inicio;

	inicio = aux->proximo;

	delete aux;

}

template <class T>


void ListaEncadeada<T>::remover_final(){

	Nodo<T> *aux = inicio;

	Nodo<T> *no;

	while(aux->proximo != NULL){
		no = aux;
		aux = aux->proximo;

	}

	if(aux == inicio){
		*inicio = aux->proximo;
	}
	else{
		no->proximo = aux->proximo;
	}
	delete aux;

}

Supermercado::Supermercado(int t_max_fila){


	cout << "Bem vindo ao VAPT-VUPT" << endl;

	temp_max_fila = t_max_fila;
	abre_caixa();

}


void Supermercado::abre_caixa(){

		Caixas caixa1;
		caixas.inserir(caixa1);
		cout << "CAIXA CRIADO" << endl;
		

		Caixas caixa2;
		caixas.inserir(caixa2);
		cout << "CAIXA CRIADO" << endl;
			
		Caixas caixa3;
		caixas.inserir(caixa3);
		cout << "CAIXA CRIADO" << endl;
		
		
		caixa1.novo_cliente();
		caixa1.novo_cliente();
		cout << "Tamanho da fila 1: " << caixa1.fila_clientes.quantidade() << endl;
		seleciona_caixa(caixas);
}


void Supermercado::seleciona_caixa(ListaEncadeada<Caixas> &c2){

	Nodo<Caixas> *menorfila;
	menorfila = c2.menor_caixa();
	Clientes cliente2(menorfila->dado.chegada_min, menorfila->dado.chegada_max, menorfila->dado.temp_min_atd, menorfila->dado.chegada_max);
	menorfila->dado.fila_clientes.inserir(cliente2);
	cout << "CLIENTE CRIADO" << endl;
	cout << "Tempo temp_atd: " << cliente2.tempo_atendimento << endl;

	cout << "Tamanho da fila 2: " << endl;
	c2.imprime();
}

Caixas::Caixas(){

	cout << "Defina o tempo de atendimento minimo" << endl;
	cin >> temp_min_atd;
	cout << "Defina o tempo de atendimento maximo" << endl;
	cin >> temp_max_atd;
	cout << "Defina o tempo de chegada minimo" << endl;
	cin >> chegada_min;
	cout << "Defina o tempo de chegada maximo" << endl;
	cin >> chegada_max;
	cout << "Defina se o caixa estará aberto" << endl;
	cin >> estado;
}


void Caixas::novo_cliente(){

	Clientes cliente1(chegada_min, chegada_max, temp_min_atd, temp_max_atd);
	
	cout << "CLIENTE CRIADO " << endl;
	fila_clientes.inserir(cliente1);
	//caixas.imprime();

}

Clientes::Clientes(int chegada_min, int chegada_max , int temp_min_atd , int temp_max_atd){
	srand(time(NULL));
	tempo_chegada = rand()%(chegada_min + chegada_max);
	tempo_atendimento = rand()%(temp_min_atd + temp_max_atd);
}




