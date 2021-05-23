#include "Camioneta.h"
Camioneta::Camioneta() {
	//en patente y chasis ver si es necesario aleatorizar 
	this->Patente = 12398;
	this->Chasis = 20465800;
	this->Color = "gris";
	this->Cant_Pasajeros_Max = 5;
	this->Poliza = 6669743;
	this->Tarifa_Base = 15000;

};
Camioneta::~Camioneta() {};
void Camioneta::set_Tarifa_dia() { Precio_Por_Dia = 30000; };
void Camioneta::PasoMantenimiento() {
	string aux = "\n Mantenimiento de una Camioneta:\n";
	aux = aux + "Comprobar el nivel de aceite. ";
	aux = aux + "\n Comprobar si las ruedas estan infladas.";
	aux = aux + "\n Comprobar la batería.";
	aux = aux + "\n Comprobar las pastillas de freno y los limpia parabrisa.";
	aux = aux + "\n Mirar el nivel de combustible.";
	aux = aux + "\n Cualquier desperfecto avisar a la compania antes de retirar el vehiculo o SE LE COBRARA luego";
	cout << aux;
	set_ultimo_mantenimiento();
};