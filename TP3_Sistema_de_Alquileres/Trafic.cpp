#include "Trafic.h"
Trafic::Trafic() {
	//en patente y chasis ver si es necesario aleatorizar 
	this->Patente = 12398;
	this->Chasis = 20465800;
	this->Color = "blanca";
	this->Cant_Pasajeros_Max = 12;
	this->Poliza = 6669743;
	this->Tarifa_Base = 20000;
}
Trafic::~Trafic() {};
void Trafic::PasoMantenimiento() {
	string aux = "\n Mantenimiento de una Trafic:\n";
	aux = aux + "Comprobar el nivel de aceite. ";
	aux = aux + "\n Comprobar si las ruedas estan infladas.";
	aux = aux + "\n Comprobar la batería.";
	aux = aux + "\n Comprobar las pastillas de freno y suspension.";
	aux = aux + "\n Mirar el nivel de combustible.";
	aux = aux + "\n Cualquier desperfecto avisar a la compania antes de retirar el vehiculo o SE LE COBRARA luego";
	cout << aux;
	set_ultimo_mantenimiento();
};
void Trafic::set_Tarifa_dia() { Precio_Por_Dia = 40000; };