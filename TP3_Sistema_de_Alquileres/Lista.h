#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
using namespace std;
template <class B>
class Lista
{
protected:
	B** Concesionaria;
	int tamanio, ocupado;
public:
	Lista<B>(int tam = NMAX);
	~Lista();
	void agregar(B* objeto);
	B* operator[](unsigned int pos);
	B* QuitarPos(int pos);
	void operator+(B* objeto);
	void operator<<(B* obj);
	unsigned int getocupado() const;
};

template<class B>
inline Lista<B>::Lista(int tam)
{
	{
		this->tamanio = tam;
		ocupado = 0;
		Concesionaria = new B * [tam];
		for (int i = 0; i < tam; i++)
		{
			Concesionaria[i] = NULL;
		}
	}
}
template<class B>
inline Lista<B>::~Lista() {
	if (Concesionaria != NULL) {
		for (int i = 0; i < ocupado; i++)
		{
			if (Concesionaria[i] != NULL)
				delete Concesionaria[i];
		}
		delete[] Concesionaria;
	}
}
template<class B>
inline void Lista<B>::agregar(B* objeto)
{
	if (ocupado >= tamanio)
		throw exception("No hay lugar");
	Concesionaria[ocupado++] = objeto;
}
template<class B>
inline B* Lista<B>::operator[](unsigned int pos) {
	if (pos < ocupado)
		return Concesionaria[pos];
	return NULL;
}
template<class B>
inline B* Lista<B>::QuitarPos(int pos) {
	B* a = Concesionaria[pos];
	B* aux = NULL;
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
template<class B>
inline void Lista<B>::operator+(B* objeto)
{
	if (ocupado >= tamanio)
		throw exception("No hay lugar");
	Concesionaria[ocupado++] = objeto;
};
template<class B>
inline void Lista<B>::operator<<(B* obj) { obj->To_String_e_Imprimir(); };
template<class B>
inline unsigned int Lista<B>::getocupado() const { return ocupado; }