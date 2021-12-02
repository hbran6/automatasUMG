//AUTOR: HERBER ABEL BRAN AYAPAN
//UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA
//AUTOMATAS Y LENGUAJES FORMALES

//SEGUNDO EJERCICIO
//SE IMPLEMENTA LAS FUNCIONES DE VALIDACION E Y F, PARA QUE INGRESEN COMAS EN LOS CONJUNTOS
//LA VARIABLE DE ESATDO ACTUAL SE LE ASIGNA EL ESTADO INICIAL Y EN ESTE EJERCICIO SE CUENTA CON DOS ESTADOS FINALES, POR LO QUE SE CREAN
//LAS VARIABLES final y final2
//
//SE LEE LA ENTRADA DEL LENGUAJE Y SE INTERPRETA CARACTER POR CARACTER
//SI AL FINALIZAR EL ESTADO ACTUAL ES IGUAL AL FINAL O FINAL2, EL LENGUAJE ES VALIDO.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool validarE(const string&);
bool validarF(const string&);

enum class Estado {q1, q2, q3, q4, q5};
Estado actual;
Estado final, final2;

Estado validarEntrada(const string&);

int main (){
	cout<<"Automata Finito Ejercicio 1"<<endl;
	cout<<"Ingrese el automata finito de la forma A = (E, Q, f, q1, F)"<<endl;
	cout<<"E: conjunto de simbolos que constituyen el vocabulario"<<endl;
	cout<<"Q: conjunto de estados"<<endl;
	cout<<"F: conjunto de estados finales"<<endl;
	
	string E, lenguajeEntrada;
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

	cout<<"Estado Inicial: q1"<<endl;
	cout<<"Estado Final: q2, q4";

	printf("\n\n");

	cout<<"Ingrese lenguaje: ";
	cin>>lenguajeEntrada;

	Estado ultimo = validarEntrada(lenguajeEntrada);

	if (ultimo == final || ultimo == final2){
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

	if (F == "q1" || F == "q2" || F == "q3" || F == "q4" || F == "q5") 
		return true;


	return false;
}

Estado validarEntrada(const string& lenguajeEntrada){
	int i, tamanoLenguajeEntrada;
	bool lenguajeValido;

	tamanoLenguajeEntrada = lenguajeEntrada.length();

	actual = Estado::q1;


	// estadoFinal
	
	final = Estado::q2;
	final2 = Estado::q4;

	lenguajeValido = true;

	i = 0;
	while (lenguajeValido || i < tamanoLenguajeEntrada){
		switch (actual){
		case Estado::q1:
			if (lenguajeEntrada[i] == 'a')
				actual = Estado::q2;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q3;
			else if(lenguajeEntrada[i] == 'c')
				actual = Estado::q5;
			else
				lenguajeValido = false;

			break;
		case Estado::q2:
			if (lenguajeEntrada[i] == 'a')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'c')
				actual = Estado::q5;
			else
				lenguajeValido = false;

			break;
		case Estado::q3:
			if (lenguajeEntrada[i] == 'a')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'c')
				actual = Estado::q4;
			else
				lenguajeValido = false;
			break;
		case Estado::q4:
			if (lenguajeEntrada[i] == 'a')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'c')
				actual = Estado::q5;
			else
				lenguajeValido = false;
			break;
		case Estado::q5:
			if (lenguajeEntrada[i] == 'a')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q5;
			else if(lenguajeEntrada[i] == 'c')
				actual = Estado::q5;
			else
				lenguajeValido = false;
			break;
		}
		i++;
	}

	return actual;
}
