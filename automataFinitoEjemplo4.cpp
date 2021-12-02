//AUTOR: HERBER ABEL BRAN AYAPAN
//UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA
//AUTOMATAS Y LENGUAJES FORMALES

//CUARTO EJEMPLO
//DISPENSADOR DE PERIODICO QUE NO DA VUELTO
//SEGUN EL PROBLEMA INDICA QUE C = 5, D = 10 Y V = 25
//
//SE LEE LA ENTRADA DEL LENGUAJE Y SE INTERPRETA CARACTER POR CARACTER EN UN CICLO WHILE PARA IR CAMBIANDO LOS ESTADOS
//SI AL FINALIZAR EL ESTADO ACTUAL ES IGUAL AL FINAL, EL LENGUAJE ES VALIDO.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

enum class Estado {q30, q25, q20, q15, q10, q5, q0};
Estado actual;
Estado final;

Estado validarEntrada(const string&);

int main (){
	cout<<"Automata Finito Ejemplo 4"<<endl;
	cout<<"Dispensador de periodico de precio 30 centavos que no da vuelto"<<endl;
	cout<<"c = 5 cinco"<<endl;
	cout<<"d = 10 diez"<<endl;
	cout<<"v = 25 veinticinco"<<endl;
	cout<<"Ingrese el lenguaje para validar"<<endl;
	
	string lenguajeEntrada;
	int i;

	printf("\n\n");

	cout<<"Ingrese lenguaje: ";
	cin>>lenguajeEntrada;

	Estado ultimo = validarEntrada(lenguajeEntrada);

	if (ultimo == final){
		cout<<"El lenguaje ingresado es valido";
	}else{
		cout<<"el lenguaje ingresado NO es valido";
	}

	printf("\n\n");

	system("pause");
	system("cls");
	main();
	return 0;
}


Estado validarEntrada(const string& lenguajeEntrada){
	int i, tamanoLenguajeEntrada;
	bool lenguajeValido;

	tamanoLenguajeEntrada = lenguajeEntrada.length();
	
	actual = Estado::q30;
	final = Estado::q0;

	lenguajeValido = true;

	i = 0;
	while (lenguajeValido && i < tamanoLenguajeEntrada){
		switch (actual){
		case Estado::q30:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q25;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q20;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
		case Estado::q25:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q20;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q15;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
		case Estado::q20:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q15;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q10;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
		case Estado::q15:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q10;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q5;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
			
		case Estado::q10:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q5;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q0;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
		case Estado::q5:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q0;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q0;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
		case Estado::q0:
			if (lenguajeEntrada[i] == 'c'){
				actual = Estado::q0;
			}else if (lenguajeEntrada[i] == 'd'){
				actual = Estado::q0;
			}else if (lenguajeEntrada[i] == 'v'){
				actual = Estado::q0;
			}else{
				lenguajeValido = false;
			}
			break;
		}
		i++;
	}
	return actual;
}
