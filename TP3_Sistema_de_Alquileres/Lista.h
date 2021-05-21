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
	bool eliminar_objetos;
public:
	Lista<V>(int tam = NMAX, bool eliminar = false);
	~Lista();
	void agregar(V* objeto)
	{
	if (ocupado >= tamanio)
			throw exception("No hay lugar");
		Concesionaria[ocupado++] = objeto;
	}
	V* operator[](unsigned int pos) {
		if (pos < ocupado)
			return Concesionaria[pos];
		return NULL;
	}
	V* QuitarPos(int pos) {
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
	void operator+(V* objeto)
	{
		if (ocupado >= tamanio)
			throw exception("No hay lugar");
		Concesionaria[ocupado++] = objeto;
	}
	void operator<<(V* obj) { obj.To_String_e_Imprimir(); };
	unsigned int getocupado() const { return ocupado; }
};

template<class V>
inline Lista<V>::Lista(int tam, bool eliminar)
{
	{
		this->tamanio = tam;
		ocupado = 0;
		Concesionaria = new V * [tam];
		for (int i = 0; i < tam; i++)
		{
			Concesionaria[i] = NULL;
		}
		eliminar_objetos = eliminar;
	}
}
inline Lista::~Lista() {

	if (Concesionaria != NULL) {
		if (eliminar_objetos) {
			for (int i = 0; i < ocupado; i++)
			{
				if (Concesionaria[i] != NULL)
					delete Concesionaria[i];
			}
		}
		delete[] Concesionaria;
	}


}