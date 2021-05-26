#include "Alquiler.h"
/*Alquiler::Alquiler() {
	this->Tarifa_Total = 5000, 5;
	this->Tarifa_por_Dia = 1000;
};*/
Alquiler::Alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion){
	time_t now = time(0);
	tm* aux = localtime(&now);
	Fecha_Adquisicion = *aux;
	Fecha_Retorno = Calcular_Dias_Reverso(Fecha_Adquisicion, duracion);
	this->Duracion = duracion;
	this->Usuario = cliente;
	this->Alquilado = vehiculo;
};
float Alquiler::Calcular_Tarifa_Dia(Adicional ad1, int can1, Adicional ad2, int can2) {
	Tarifa_por_Dia = Extras.Calcular_Precio_Dia(Alquilado, ad1, can1, ad2, can2);
	Alquilado->set_Tarifa_dia(Tarifa_por_Dia);
	return Tarifa_por_Dia;
};
float Alquiler::Calcular_Tarifa_Total() {
	return Alquilado->Tarifa_Base + (this->Duracion * Tarifa_por_Dia);
};
void Alquiler::Set_Extras(Adicional ad1, int can1, Adicional ad2, int can2) {
	Extras.Set_Todo(ad1, can1, ad2, can2);
	Calcular_Tarifa_Total();
};
Vehiculo* Alquiler::Get_Vehiculo() { return Alquilado; };
Alquiler::~Alquiler() {};
string Alquiler::To_String_e_Imprimir() {
	string Aux;
	string User = Usuario->To_String_e_Imprimir();
	Aux = "El cliente: " + User + "\n Ha alquilado el vehículo: " + Alquilado->To_String_e_Imprimir_Vehiculo() +
		Extras.To_String_e_Imprimir() + "\n desde el " + Pasar_Fecha_to_String(Fecha_Adquisicion) + " hasta el "
		+ Pasar_Fecha_to_String(Fecha_Retorno) + "\n Por un precio total de " + to_string(Calcular_Tarifa_Total());
	return Aux;
};