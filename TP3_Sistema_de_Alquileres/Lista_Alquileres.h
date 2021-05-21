#pragma once
#include "Lista.h"
#include "Alquiler.h"
template <class V>
class Lista_Alquileres :
	protected Lista
{
public:
	Lista_Alquileres(int tam = NMAX, bool eliminar = false) {
		this->tamanio = tam;
		ocupado = 0;
		Concesionaria = new V * [tam];
		for (int i = 0; i < ; i++)
		{
			Concesionaria[i] = NULL;
		}
		eliminar_objetos = eliminar;
	};
	Alquiler* crear_alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion) {
		Alquiler* alquilado = new Alquiler(vehiculo, cliente, duracion);
		Agregar(alquilado);

	};
	float Listar_por_Vehiculo() {};
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
 
