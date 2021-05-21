#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Enum.h"
#include"Vehiculo.h"
#include"Motocicleta.h"
#include"Camioneta.h"
#include "Automovil.h"
#include "Trafic.h"
using namespace std;
class Adicionales
{
	Adicional adicional1 = Nada;
	Adicional adicional2 = Nada;
	int cant1 = 0;
	int cant2 = 0;
public:
	Adicionales() {};
	void Set_Todo(Adicional ad1, int can1, Adicional ad2, int can2) {
		adicional1 = ad1;
		adicional2 = ad2;
		cant1 = can1;
		cant2 = can2;
	};
	~Adicionales() {};
	float Calcular_Precio_Dia(Vehiculo* vehiculo, Adicional ad1, int can1, Adicional ad2, int can2) {
		int iaux = 0;
		if (ad1 == Nada) {
			return 0;
		}
		if (ad1 == Casco || ad2 == Casco) {
			Vehiculo* Aux = dynamic_cast<Motocicleta*> (vehiculo);
			if (Aux == NULL) {
				cout << "Adicionales no compatibles";
				return 0;
			}
			if (Aux != NULL) {
				return (500 * can1);
			}
		}
		if (ad1 == Porta_Equipaje || ad2 == Porta_Equipaje) {
			Vehiculo* Aux = dynamic_cast<Camioneta*> (vehiculo);
			if (Aux == NULL) {
				cout << "Adicionales no compatibles";
				return 0;
			}
			if (Aux != NULL) {
				iaux = 900;
			}
		}
		if (ad1 == Silla_Ninios || ad2 == Silla_Ninios) {
			Vehiculo* Aux = dynamic_cast<Automovil*> (vehiculo);
			if (Aux == NULL) {
				Vehiculo* Aux = dynamic_cast<Camioneta*> (vehiculo);
				if (Aux == NULL) {
					Vehiculo* Aux = dynamic_cast<Trafic*> (vehiculo);
					if (Aux == NULL) {
						cout << "Adicionales no compatibles";
						return 0;
					}
				}

			}
			if (Aux != NULL) {
				if (ad1 == Silla_Ninios) {
					iaux = iaux + (700 * can1);
					if (iaux > (700 * can1)) { return iaux; }
				}
				if (ad2 == Silla_Ninios) {
					iaux = iaux + (700 * can2);
					if (iaux > (700 * can1)) { return iaux; }
				}
			}

		}
		if (ad1 == Asiento_Rebatible || ad2 == Asiento_Rebatible) {
			Vehiculo* Aux = dynamic_cast<Automovil*> (vehiculo);
			if (Aux == NULL) {
				Vehiculo* Aux = dynamic_cast<Camioneta*> (vehiculo);
				if (Aux == NULL) {
					Vehiculo* Aux = dynamic_cast<Trafic*> (vehiculo);
					if (Aux == NULL) {
						cout << "Adicionales no compatibles";
						return 0;
					}
				}

			}
			if (Aux != NULL) {
				if (ad1 == Asiento_Rebatible) {
					iaux = iaux + (700 * can1);
					if (iaux > (700 * can1)) { return iaux; }
				}
				if (ad2 == Asiento_Rebatible) {
					iaux = iaux + (700 * can2);
					if (iaux > (700 * can2)) { return iaux; }
				}
			}

		}
		return iaux;
	};
	string To_String_e_Imprimir() {
		string Aux = "Sin Editar";
		if (adicional1 == Nada) {
			return "Sin cargos adicionales";
		}
		if (adicional1 == Casco) {
			Aux = "\n Con " + to_string(cant1) + " casco/s";
			return Aux;
		}
		if (adicional2 == Casco) {
			Aux = "\n Con " + to_string(cant2) + " casco/s";
			return Aux;
		}
		if (adicional1 == Porta_Equipaje) {
			Aux = "\n Con portaequipaje";
		}
		if (adicional2 == Porta_Equipaje) {
			Aux = "\n Con portaequipaje";
		}
		if (adicional1 == Silla_Ninios) {
			if (Aux == "Sin Editar") {
				Aux = "\n Con " + to_string(cant1) + " silla/s para ninios";
			}
			if (Aux != "Sin Editar") {
				Aux = Aux + "y " + to_string(cant1) + " silla/s para ninios";
				return Aux;
			}
		}
		if (adicional2 == Silla_Ninios) {
			if (Aux == "Sin Editar") {
				Aux = "\n Con " + to_string(cant2) + " silla/s para ninios";
			}
			if (Aux != "Sin Editar") {
				Aux = Aux + "y " + to_string(cant2) + " silla/s para ninios";
				return Aux;
			}
		}
		if (adicional1 == Asiento_Rebatible) {
			if (Aux == "Sin Editar") {
				Aux = "\n Con " + to_string(cant1) + " asiento/s rebatibles";
			}
			if (Aux != "Sin Editar") {
				Aux = Aux + "y " + to_string(cant1) + " asiento/s rebatibles";
				return Aux;
			}
		}
		if (adicional2 == Asiento_Rebatible) {
			if (Aux == "Sin Editar") {
				Aux = "\n Con " + to_string(cant2) + " asiento/s rebatibles";
			}
			if (Aux != "Sin Editar") {
				Aux = Aux + "y " + to_string(cant2) + " asiento/s rebatibles";
				return Aux;
			}
		}
		return Aux;
	};

};

