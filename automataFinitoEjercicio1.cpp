//AUTOR: HERBER ABEL BRAN AYAPAN
//UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA
//AUTOMATAS Y LENGUAJES FORMALES

//PRIMER EJERCICIO
//SE IMPLEMENTA LAS FUNCIONES DE VALIDACION E Y F, PARA QUE INGRESEN COMAS EN LOS CONJUNTOS
//LA VARIABLE I CONTIENE EL ESTADO INICIAL Y LA VARIABLE F EL ESTADO FINAL
//
//SE LEE LA ENTRADA DEL LENGUAJE Y SE INTERPRETA CARACTER POR CARACTER EN UN CICLO WHILE PARA IR CAMBIANDO LOS ESTADOS
//SI AL FINALIZAR EL ESTADO ACTUAL ES IGUAL AL FINAL, EL LENGUAJE ES VALIDO.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool validarE(const string&);
bool validarF(const string&);

enum class Estado {q1, q2, q3};
Estado actual;
Estado final;

Estado validarEntrada(const string&, const string&, const string&);

int main (){
	cout<<"Automata Finito Ejercicio 1"<<endl;
	cout<<"Ingrese el automata finito de la forma A = (E, Q, f, q1, F)"<<endl;
	cout<<"E: conjunto de simbolos que constituyen el vocabulario"<<endl;
	cout<<"Q: conjunto de estados"<<endl;
	cout<<"F: conjunto de estados finales"<<endl;
	
	string E, F, I, lenguajeEntrada;
	int i;
	
	printf("\n\n");
	
	cout<<"Q = q1, q2, q3"<<endl;
	
	cout<<"Ingrese E:";
	cin>>E;
	
	if(validarE(E)){
		cout<<"E es valido"<<endl;
	}else{
		cout<<"E no es valido"<<endl;
		system("pause");
		system("cls");
		main();
	}

	printf("\n\n");

	cout<<"Ingrese F: ";
	cin>>F;

	if (validarF(F)){
		cout<<"F es subconjunto de Q"<<endl;
	}else{
		cout<<"F NO es subconjunto de Q"<<endl;
		system("pause");
		system("cls");
		main();
	}

	printf("\n\n");

	cout<<"Ingrese estado Inicial: ";
	cin>>I;

	if (validarF(I)){
		cout<<"I es subconjunto de Q"<<endl;
	}else{
		cout<<"I NO es subconjunto de Q"<<endl;
		system("pause");
		system("cls");
		main();
	}

	printf("\n\n");

	cout<<"Ingrese lenguaje: ";
	cin>>lenguajeEntrada;

	Estado ultimo = validarEntrada(lenguajeEntrada, I, F);

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

bool validarE(const string& E){
	int i, sizeE, countLetters, countComma;
	sizeE = E.length();

	if(E[0] == ',' || E[sizeE-1] == ','){
		return false;
	}

	if(sizeE<=0)
		return false;

	countComma = 0;
	for(i = 0; i <sizeE; i++){
		if(E[i] == ',')
			countComma++;
		else
			countLetters++;
	}

	if((countLetters - countComma) != 1){
		return false;
	}
	return true;
}

bool validarF(const string& F){

	if (F == "q1" || F == "q2" || F == "q3")
		return true;


	return false;
}

Estado validarEntrada(const string& lenguajeEntrada, const string& estadoInicial, const string& estadoFinal){
	int i, tamanoLenguajeEntrada;
	bool lenguajeValido;

	tamanoLenguajeEntrada = lenguajeEntrada.length();

	if (estadoInicial == "q1")
		actual = Estado::q1;

	if (estadoInicial == "q2")
		actual = Estado::q2;

	if (estadoInicial == "q3")
		actual = Estado::q3;

	// estadoFinal
	if (estadoFinal == "q1")
		final = Estado::q1;

	if (estadoFinal == "q2")
		final = Estado::q2;

	if (estadoFinal == "q3")
		final = Estado::q3;

	lenguajeValido = true;

	i = 0;
	while (lenguajeValido || i < tamanoLenguajeEntrada){
		switch (actual){
		case Estado::q1:
			if (lenguajeEntrada[i] == '1')
				actual = Estado::q1;
			else if(lenguajeEntrada[i] == '2')
				actual = Estado::q1;
			else if(lenguajeEntrada[i] == '3')
				actual = Estado::q2;
			else
				lenguajeValido = false;

			break;
		case Estado::q2:
			if (lenguajeEntrada[i] == '1')
				actual = Estado::q3;
			else if(lenguajeEntrada[i] == '2')
				actual = Estado::q3;
			else if(lenguajeEntrada[i] == '3')
				actual = Estado::q3;
			else
				lenguajeValido = false;

			break;
		case Estado::q3:
			if (lenguajeEntrada[i] == '1')
				actual = Estado::q3;
			else if(lenguajeEntrada[i] == '2')
				actual = Estado::q3;
			else if(lenguajeEntrada[i] == '3')
				actual = Estado::q3;
			else
				lenguajeValido = false;
			break;
		}
		i++;
	}

	return actual;
}
