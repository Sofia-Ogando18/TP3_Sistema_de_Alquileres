#include "Vehiculo.h"
void Vehiculo::set_ultimo_mantenimiento() {

	time_t now = time(0);
	tm* aux = localtime(&now);
	Fecha_Ult_Mantenimiento = *aux;
	return;

};
string Vehiculo::To_String_e_Imprimir_Vehiculo() {
	string aux2 = Pasar_Fecha_to_String(Fecha_Ult_Mantenimiento);
	//char* dt = asctime(&Fecha_Ult_Mantenimiento);
	string aux = "\n Vehiculo de patente" + to_string(Patente) + "\n Numero de chasis: " + to_string(Chasis) +
		"\n Numero de poliza: " + to_string(Poliza) + "\n de color " + Color + "\n Tarifa : " + to_string(Tarifa_Base) +
		"+" + to_string(Precio_Por_Dia) + "\n Pasajeros max." + to_string(Cant_Pasajeros_Max) +
		"\n Fecha del ultimo mantenimiento: " + aux2; 
	cout << aux;
	return aux;
};