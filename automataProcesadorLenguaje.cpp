#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//lenguajes
string lenguajeAlfabetico = ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
string lenguajeNumerico = ("1234567890");
string lenguajeAlfanumerico = ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
string lenguajePuntuacion = (".;:,()*/[]'-_?!");
bool hayLenguajeAlfabetico = false, hayLenguajeNumerico = false, hayLenguajePuntuacion = false, hayLenguajeAlfanumerico = false;
int sizeString;

//funciones
void buscarLenguajeAlfabetico(string);
void buscarLenguajeNumerico(string);
void buscarLenguajePuntuacion(string);
void buscarLenguajeAlfanumerico(string);
void respuesta(string, string, bool);

int main(){
	string buscar;
	cout<<"Ingrese la cadena a buscar en los lenguajes predeterminados:";
	cin>>buscar;
	sizeString = buscar.length()/sizeof(buscar[0]);
	buscarLenguajeAlfabetico(buscar);
}

void respuesta(string buscar, string lenguaje, bool exito){
	if(exito){
		cout<<"La cadena: "<<buscar<<" pertenece al lenguaje: "<<lenguaje;
	}else{
		cout<<"La cadena: "<<buscar<<" NO pertenece a ningun lenguaje.";
	}
	return;
}

void buscarLenguajeAlfabetico(string buscar){
	for(int i = 0; i <sizeString; i++){
		if(lenguajeAlfabetico.find(buscar[i], 0) != std::string::npos){
			hayLenguajeAlfabetico = true;
		}else{
			hayLenguajeAlfabetico = false;
			break;
		}
	}
	if(!hayLenguajeAlfabetico)
		buscarLenguajeAlfanumerico(buscar);
	else
		respuesta(buscar, "Alfabetico", 1);
}

void buscarLenguajeAlfanumerico(string buscar){
	for(int i = 0; i <sizeString; i++){
		if(lenguajeAlfanumerico.find(buscar[i], 0) != std::string::npos){
			hayLenguajeAlfanumerico = true;
		}else{
			hayLenguajeAlfanumerico = false;
			break;
		}
	}
	if(!hayLenguajeAlfanumerico)
		buscarLenguajeNumerico(buscar);
	else
		respuesta(buscar, "Alfanumerico", 1);
}


void buscarLenguajeNumerico(string buscar){
	for(int i = 0; i <sizeString; i++){
		if(lenguajeNumerico.find(buscar[i], 0) != std::string::npos){
			hayLenguajeNumerico = true;
		}else{
			hayLenguajeNumerico = false;
			break;
		}
	}
	if(!hayLenguajeNumerico)
		buscarLenguajePuntuacion(buscar);
	else
		respuesta(buscar, "Numerico", 1);
}

void buscarLenguajePuntuacion(string buscar){
	for(int i = 0; i <sizeString; i++){
		if(lenguajePuntuacion.find(buscar[i], 0) != std::string::npos){
			hayLenguajePuntuacion = true;
		}else{
			hayLenguajePuntuacion = false;
			break;
		}
	}
	respuesta(buscar, "Puntuacion", hayLenguajePuntuacion);
}
