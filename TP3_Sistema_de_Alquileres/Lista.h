#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
using namespace std;
template <class V>
class Lista
{
protected:
	V** Concesionaria;
	int tamanio, ocupado;
public:
	Lista<V>(int tam = NMAX);
	~Lista();
	void agregar(V* objeto);
	V* operator[](unsigned int pos);
	V* QuitarPos(int pos);
	void operator+(V* objeto);
	void operator<<(V* obj);
	unsigned int getocupado() const;
};

template<class V>
inline Lista<V>::Lista(int tam)
{
	{
		this->tamanio = tam;
		ocupado = 0;
		Concesionaria = new V * [tam];
		for (int i = 0; i < tam; i++)
		{
			Concesionaria[i] = NULL;
		}
	}
}
template<class V>
inline Lista<V>::~Lista() {
	if (Concesionaria != NULL) {
		for (int i = 0; i < ocupado; i++)
		{
			if (Concesionaria[i] != NULL)
				delete Concesionaria[i];
		}
		delete[] Concesionaria;
	}
}
template<class V>
inline void Lista<V>::agregar(V* objeto)
{
	if (ocupado >= tamanio)
		throw exception("No hay lugar");
	Concesionaria[ocupado++] = objeto;
}
template<class V>
inline V* Lista<V>::operator[](unsigned int pos) {
	if (pos < ocupado)
		return Concesionaria[pos];
	return NULL;
}
template<class V>
inline V* Lista<V>::QuitarPos(int pos) {
	V* a = Concesionaria[pos];
	V* aux = NULL;
	Concesionaria[pos] = NULL;
	for (int i = pos; i < ocupado; i++)
	{
		aux = Concesionaria[i];
		Concesionaria[i] = Concesionaria[i + 1];
		Concesionaria[i + 1] = aux;
	}
	ocupado--;
	return NULL;
}
template<class V>
inline void Lista<V>::operator+(V* objeto)
{
	if (ocupado >= tamanio)
		throw exception("No hay lugar");
	Concesionaria[ocupado++] = objeto;
};
template<class V>
inline void Lista<V>::operator<<(V* obj) { obj->To_String_e_Imprimir(); };
template<class V>
inline unsigned int Lista<V>::getocupado() const { return ocupado; }