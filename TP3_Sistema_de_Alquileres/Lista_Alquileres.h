#pragma once
#include "Lista.h"
#include "Alquiler.h"
template <class V>
class Lista_Alquileres:
	public Lista
{
public:
	Lista_Alquileres<V>(int tam = NMAX);
	Alquiler* crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion);
	float Listar_por_Vehiculo_y_Dar_Precio();
	~Lista_Alquileres();
};
 
template<class V>
inline Lista_Alquileres<V>::Lista_Alquileres(int tam) {
	this->tamanio = tam;
	this->ocupado = 0;
	this->Concesionaria = new V * [tam];
	for (int i = 0; i < tam; i++)
	{
		this->Concesionaria[i] = NULL;
	};
};
template<class V>
inline Alquiler* Lista_Alquileres<V>::crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion) {
	Alquiler* alquilado = new Alquiler(vehiculo, cliente, duracion);
	this->agregar(alquilado);
};
template<class V>
inline float Lista_Alquileres<V>::Listar_por_Vehiculo_y_Dar_Precio() {
	int Cont = 0;
	float Ganancia = 0;
	Vehiculo* Aux1;
	Vehiculo* Aux2;
	Vehiculo* Lista = new Vehiculo[this->ocupado];
	//Listamos en orden Moto-Auto-Camioneta-Trafic
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Motocicleta*> (Aux2);
		if (Aux1 != NULL) {
			Lista[Cont] = *Aux1;
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Automovil*> (Aux2);
		if (Aux1 != NULL) {
			Lista[Cont] = *Aux1;
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Camioneta*> (Aux2);
		if (Aux1 != NULL) {
			Lista[Cont] = *Aux1;
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Trafic*> (Aux2);
		if (Aux1 != NULL) {
			Lista[Cont] = *Aux1;
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	return Ganancia;
};
template<class V>
inline Lista_Alquileres<V>::~Lista_Alquileres() {
	if (this->Concesionaria != NULL) {
		for (int i = 0; i < this->ocupado; i++)
		{
			if (this->Concesionaria[i] != NULL)
				delete this->Concesionaria[i];
		}
	}
	delete[] this->Concesionaria;
}

