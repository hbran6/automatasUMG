//Autor: Herber Abel Bran Ayapan
//Carne: 9490-12-3785
//Automatas y Lenguajes Formales
//Problema 3

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

string VT, VN;
int cantVT, cantVN, sizeString;

bool existenTerminales(string);

int main(){
	int i;
	std::map< std::string, std::string > reglasGramatica;
	std::map< std::string, std::string >::iterator reglasGramaticaIterador; 
	
	reglasGramatica["2S"] = "aA";
	reglasGramatica["3A"] = "bA";
	reglasGramatica["4A"] = "b";
	reglasGramatica["L"] = "aS";    

	cout<<" INGRESE LA GRAMATICA "<<endl<<endl;
	
	cout<<"Cantidad de VT:";
	cin>>cantVT;
	for(i = 0; i < cantVT; i++){
		printf("Ingrese el VT%i: ", i);
		cin>>VT[i];
	}
	
	cout<<"Cantidad de VN:";
	cin>>cantVN;
	for(i = 0; i < cantVN; i++){
		printf("Ingrese el VN%i: ", i);
		cin>>VN[i];
	}
	
	int found;
	
	while(existenTerminales(reglasGramatica["L"]) == true){
		reglasGramaticaIterador = reglasGramatica.begin();
		while(reglasGramaticaIterador != reglasGramatica.end() ) {
			std::string key = (*reglasGramaticaIterador).first;
			string search = key;
			search.replace(0, 1, "");
			if(search.length()>0){
				if(reglasGramatica["L"].find(search, 0) != std::string::npos){
					found = reglasGramatica["L"].find(search, 0);
					reglasGramatica["L"] = reglasGramatica["L"].replace(found, search.length(), reglasGramatica[key]);
				}
			}
			reglasGramaticaIterador++;
		}
	}
	
	//	salida de la gramatica ingresada
	cout<<"G = ({";
	bool init = false;
	for(i = 0; i < cantVT; i++){
		if(init)
			cout<<", ";
			
		cout<<VT[i];
		init = true;
	}
	cout<<"}, ";
	
	cout<<"{";
	init = false;
	for(i = 0; i < cantVN; i++){
		if(init)
			cout<<", ";
			
		cout<<VN[i];
		init = true;
	}
	cout<<")"<<endl;
	cout<<"S -> 000S111"<<endl;
	reglasGramaticaIterador = reglasGramatica.begin();
	while(reglasGramaticaIterador != reglasGramatica.end() ) {
		std::string key = (*reglasGramaticaIterador).first;
		string search = key;
		search.replace(0, 1, "");
		if(search.length()>0){
			std::cout<<search<<" -> " << reglasGramatica[key] <<std::endl;
		}
		reglasGramaticaIterador++;
	}
	
	cout<<"El lenguaje que genera es: "<<reglasGramatica["L"];
}

bool existenTerminales(string lenguaje){
	bool hayTerminal = false;
	for(int i = 0; i < cantVT; i++){
		if(lenguaje.find(VT[i], 0) != std::string::npos){
			hayTerminal = true;
			break;
		}
	}
	return hayTerminal;
}
