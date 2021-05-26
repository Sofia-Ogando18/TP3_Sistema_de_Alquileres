#include "Cliente.h"
Cliente::Cliente() {
	this->DNI = 987654321;
	this->Direccion = "calle siempre viva 123";
	this->Nombre_Apellido = "Juan Topo";

};
Cliente::Cliente(string NA,string dire,int dni) :Cliente(){
	this->DNI = dni;
	this->Nombre_Apellido = NA;
	this->Direccion = dire;
};
string Cliente::To_String_e_Imprimir() {
	string Aux;
	Aux = "\n" + Nombre_Apellido + "\n de direccion:" + Direccion + "\n y DNI" + to_string(DNI);
	cout << Aux;
	return Aux;
};
Cliente::~Cliente() {};