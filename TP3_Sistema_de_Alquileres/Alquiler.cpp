#include "Alquiler.h"
Alquiler::Alquiler() {};
float Alquiler::Calcular_Tarifa_Dia(Adicional ad1, int can1, Adicional ad2, int can2) {
	Tarifa_por_Dia = Extras.Calcular_Precio_Dia(Alquilado, ad1, can1, ad2, can2);
	return Tarifa_por_Dia;
};
float Alquiler::Calcular_Tarifa_Total() {
	int Duracion = Calcular_Dias(Fecha_Adquisicion, Fecha_Retorno);
	return Alquilado->Tarifa_Base + (Duracion * Tarifa_por_Dia);
};
Alquiler::Alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion) :Alquiler() {
	time_t now = time(0);
	tm* aux = localtime(&now);
	Fecha_Adquisicion = *aux;
	this->Usuario = cliente;
	this->Alquilado = vehiculo;
};
void Alquiler::Set_Extras(Adicional ad1, int can1, Adicional ad2, int can2) {
	Extras.Set_Todo(ad1, can1, ad2, can2);
};
Alquiler::~Alquiler() {};
string Alquiler::To_String_e_Imprimir() {
	string Aux;
	string User = Usuario->To_String_e_Imprimir();
	char* Adq = asctime(&Fecha_Adquisicion);
	char* Rtrn = asctime(&Fecha_Retorno);
	Aux = "El cliente" + User + "\n Ha alquilado el vehículo" + Alquilado->To_String_e_Imprimir_Vehiculo() +
		Extras.To_String_e_Imprimir() + "\n desde el " + Adq + " hasta el " + Rtrn + "\n Por un precio total de " +
		to_string(Calcular_Tarifa_Total());
};