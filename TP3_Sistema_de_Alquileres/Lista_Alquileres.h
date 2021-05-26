#pragma once
#include "Lista.h"
#include "Alquiler.h"

class Lista_Alquileres :
	public Lista<Alquiler>
{
public:
	Lista_Alquileres(int tam);
	void Set_Extras(int pos, Adicional ad1, int can1, Adicional ad2, int can2);
	Alquiler* crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion);
	float Listar_por_Vehiculo_y_Dar_Precio();
	~Lista_Alquileres();
};

inline Lista_Alquileres::Lista_Alquileres(int tam) {
	tamanio = tam;
	this->ocupado = 0;
	this->Concesionaria = new Alquiler * [tam];
	for (int i = 0; i < tam; i++)
	{
		this->Concesionaria[i] = NULL;
	};
};

inline Alquiler* Lista_Alquileres::crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion) {
	Alquiler* alquilado = new Alquiler(vehiculo, cliente, duracion);
	this->agregar(alquilado);
	return alquilado;
};

inline float Lista_Alquileres::Listar_por_Vehiculo_y_Dar_Precio() {
	int Cont = 0, aux = 0;
	aux = this->ocupado;
	float Ganancia = 0;
	Vehiculo* Aux1;
	Vehiculo* Aux2;
	//Listamos en orden Moto-Auto-Camioneta-Trafic
	for (int i = 0; i < this->ocupado; i++) {

		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Motocicleta*> (Aux2);
		if (Aux1 != NULL) {
			Concesionaria[i]->To_String_e_Imprimir();
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Automovil*> (Aux2);
		if (Aux1 != NULL) {
			Concesionaria[i]->To_String_e_Imprimir();
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Camioneta*> (Aux2);
		if (Aux1 != NULL) {
			Concesionaria[i]->To_String_e_Imprimir();
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	for (int i = 0; i < this->ocupado; i++) {
		Aux2 = this->Concesionaria[i]->Get_Vehiculo();
		Aux1 = dynamic_cast<Trafic*> (Aux2);
		if (Aux1 != NULL) {
			Concesionaria[i]->To_String_e_Imprimir();
			Cont++;
			Ganancia = Ganancia + this->Concesionaria[i]->Calcular_Tarifa_Total();
		}
	}
	cout << "\n Con una ganancia total de:" << to_string(Ganancia);
	return Ganancia;
};

inline void Lista_Alquileres::Set_Extras(int pos, Adicional ad1, int can1, Adicional ad2, int can2) {
this->Concesionaria[pos]->Set_Extras(ad1, can1, ad2, can2);
this->Concesionaria[pos]->Calcular_Tarifa_Dia(ad1, can1, ad2, can2);
};

inline Lista_Alquileres:: ~Lista_Alquileres() {
	if (this->Concesionaria != NULL) {
		for (int i = 0; i < this->ocupado; i++)
		{
			if (this->Concesionaria[i] != NULL)
				delete this->Concesionaria[i];
		}
	}
	delete[] this->Concesionaria;
};

