#include "Motocicleta.h"
Motocicleta::Motocicleta() {
	this->Patente = 12398;
	this->Chasis = 20465800;
	this->Color = "negro";
	this->Cant_Pasajeros_Max = 2;
	this->Poliza = 6669743;
	this->Tarifa_Base = 5000;

};
void Vehiculo::set_Tarifa_dia() { Precio_Por_Dia = 10000; };
Motocicleta::~Motocicleta() {};
void Vehiculo::PasoMantenimiento() {
	string aux = "\n Mantenimiento de una Motocicleta:\n";
	aux = aux + "Comprobar el nivel de aceite del carter";
	aux = aux + "\n Comprobar las ruedas";
	aux = aux + "\n Comprobar la batería.";
	aux = aux + "\n Comprobar las pastillas de freno y la cadena";
	aux = aux + "\n Limpiar y lubricar.";
	aux = aux + "\n Cualquier desperfecto avisar a la compania antes de retirar el vehiculo o SE LE COBRARA luego";
	cout << aux;
	set_ultimo_mantenimiento();
};