#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class Archivo {
private:
	ofstream escribirarchivo; //escribir
	ifstream leerarchivo; //leer
	string texto;
	int Nrodefichas;
public:
	Archivo() {

		leertexto();
	};
	~Archivo() {};

	void leertexto() {
		leerarchivo.open("datos.txt", ios::in);
		if (leerarchivo.is_open()) {
			getline(leerarchivo, texto);
			Nrodefichas = stoi(texto);
			leerarchivo.close();
		}
	}
	int getmax() { return Nrodefichas; }

};