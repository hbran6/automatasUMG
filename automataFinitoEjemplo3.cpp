//AUTOR: HERBER ABEL BRAN AYAPAN
//UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA
//AUTOMATAS Y LENGUAJES FORMALES

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

enum class Estado {q0, q1, q2};
Estado actual;
Estado final;

Estado validarEntrada(const string&);

int main (){
	cout<<"Automata Finito Ejemplo 3"<<endl;
	cout<<"El lenguaje sera valido si tiene un signo al final de la cadena"<<endl;
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
	
	actual = Estado::q0;
	final = Estado::q2;

	lenguajeValido = true;

	i = 0;
	while (lenguajeValido && i < tamanoLenguajeEntrada){
		switch (actual){
		case Estado::q0:
			if (isalpha(lenguajeEntrada[i])){
				actual = Estado::q1;
				cout<<"es letra en q0"<<endl;;
			}else{
				cout<<"no es letra en q0"<<endl;
				lenguajeValido = false;
			}

			break;
		case Estado::q1:
			if (isalpha(lenguajeEntrada[i])){
				cout<<"es letra en q1"<<endl;;
				actual = Estado::q1;
			}else if(isdigit(lenguajeEntrada[i])){
				cout<<"es numero en q1"<<endl;;
				actual = Estado::q1;
			}else{
				cout<<"no es nada en q1"<<endl;;
				actual = Estado::q2;
			}

			break;
		}
		i++;
	}

	return actual;
}
