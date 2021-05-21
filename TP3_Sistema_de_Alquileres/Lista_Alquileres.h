#pragma once
#include "Lista.h"
#include "Alquiler.h"
template <class V>
class Lista_Alquileres :
	protected Lista<V>
{
public:
	Lista_Alquileres<V>(int tam = NMAX);
	Alquiler* crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion);
	float Listar_por_Vehiculo_y_Dar_Precio();
	~Lista_Alquileres() {
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
	};
};
 
template<class V>
inline Lista_Alquileres<V>::Lista_Alquileres(int tam) {
	this->tamanio = tam;
	this->ocupado = 0;
	this->Concesionaria = new V * [tam];
	for (int i = 0; i < tam; i++)
	{
		this->Concesionaria[i] = NULL;
	}
};
template<class V>
inline Alquiler* Lista_Alquileres<V>::crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion) {
	Alquiler* alquilado = new Alquiler(vehiculo, cliente, duracion);
	this->agregar(alquilado);
};
template<class V>
inline float Lista_Alquileres<V>::Listar_por_Vehiculo_y_Dar_Precio() {
	int Cont = 0;
	Vehiculo* Aux1;
	Vehiculo* Aux2;
	//Listamos en orden Moto-Auto-Camioneta-Trafic
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Motocicleta*> (Aux2);
		if (Aux1 != NULL) {
			Cont++;
		}
	}
	Motocicleta* ListaM = new Motocicleta[Cont];
	for (int i = 0; i < Cont; i++) {

	}
	
};

