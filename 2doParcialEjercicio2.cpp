//AUTOR: HERBER ABEL BRAN AYAPAN
//UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA
//AUTOMATAS Y LENGUAJES FORMALES
//SEGUNDO PARCIAL

//SEGUNDO EJERCICIO
//SE IMPLEMENTA EL AUTOMATA QUE RECIBE UNA CADENA Y VALIDA QUE CONTENGA UN NUMERO IMPAR DE a's O UN NUMERO IMPAR DE b's

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool validarE(const string&);
bool validarF(const string&);

enum class Estado {q0, q1, q2, q3};
Estado actual;
Estado final, final2, final3;

Estado validarEntrada(const string&, const string&);

int main (){
	cout<<"Automata Ejercicio 2"<<endl;
	cout<<"Ingrese el automata finito de la forma A = (E, Q, f, q1, F)"<<endl;
	cout<<"E: conjunto de simbolos que constituyen el vocabulario"<<endl;
	cout<<"Q: conjunto de estados"<<endl;
	cout<<"F: conjunto de estados finales"<<endl;
	
	string E, lenguajeEntrada, estadoInicial;
	int i;
	
	printf("\n\n");
	
	cout<<"Q = q0, q1, q2, q3"<<endl;
	
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

	cout<<"Estado Inicial:";
	cin>>estadoInicial;
	
	if(validarF(estadoInicial)){
		cout<<"Estado inicial SI es subconjunto de Q"<<endl;
	}else{
		cout<<"Estado inicial NO es subconjunto de Q"<<endl;
		system("pause");
		system("cls");
		main();
	}
	
	cout<<"Estado Final: q1, q2, q3";

	printf("\n\n");

	cout<<"Ingrese lenguaje: ";
	cin>>lenguajeEntrada;

	Estado ultimo = validarEntrada(lenguajeEntrada, estadoInicial);

	if (ultimo == final || ultimo == final2 || ultimo == final3){
		cout<<"El lenguaje ingresado es valido";
	}else{
		cout<<"el lenguaje ingresado NO es valido";
	}

	printf("\n\n");
	
	cout<<"QUINTUPLA UTILIZADA:"<<endl;
	cout<<"Q = q0, q1, q2, q3"<<endl;
	cout<<"E = "<<lenguajeEntrada<<endl;
	cout<<"Estado inicial = "<<estadoInicial<<endl;
	cout<<"Estados finales = q1, q2, q3"<<endl;
	cout<<"E(lenguaje) = "<<lenguajeEntrada<<endl;
	
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
	if (F == "q0" || F == "q1" || F == "q2" || F == "q3") 
		return true;

	return false;
}

Estado validarEntrada(const string& lenguajeEntrada, const string& estadoInicial){
	int i, tamanoLenguajeEntrada;
	bool lenguajeValido;

	tamanoLenguajeEntrada = lenguajeEntrada.length();

	if(estadoInicial == "q0")
		actual = Estado::q0;
	
	if(estadoInicial == "q1")
		actual = Estado::q1;
	
	if(estadoInicial == "q2")
		actual = Estado::q2;
	
	if(estadoInicial == "q3")
		actual = Estado::q3;

	// estadoFinal
	
	final = Estado::q1;
	final2 = Estado::q2;
	final3 = Estado::q3;

	lenguajeValido = true;

	i = 0;
	while (lenguajeValido || i < tamanoLenguajeEntrada){
		switch (actual){
		case Estado::q0:
			if(lenguajeEntrada[i] == 'a')
				actual = Estado::q2;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q1;
			else
				lenguajeValido = false;
			break;
		case Estado::q1:
			if(lenguajeEntrada[i] == 'a')
				actual = Estado::q3;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q0;
			else
				lenguajeValido = false;

			break;
		case Estado::q2:
			if(lenguajeEntrada[i] == 'a')
				actual = Estado::q0;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q3;
			else
				lenguajeValido = false;

			break;
		case Estado::q3:-
			if(lenguajeEntrada[i] == 'a')
				actual = Estado::q1;
			else if(lenguajeEntrada[i] == 'b')
				actual = Estado::q2;
			else
				lenguajeValido = false;
			break;
		}
		i++;
	}

	return actual;
}
