#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

class Enfermedad;
class Enfermedad {
private:
	string nombre;
	string secuencia;
	//Arreglo Pacientes
public:
	Enfermedad(string = "", string = "");
	Enfermedad(const Enfermedad&);
	void setNombre(string);
	void setSecuencia(string);
	string getNombre();
	string getSecuencia();
	Enfermedad& operator= (const Enfermedad&);
	friend ostream& operator<< (ostream&, Enfermedad&);
	string toString();
	string toStringEspecial();
	Enfermedad* cargarDatos(string sNombre, string sSecuencia);
	virtual ~Enfermedad();
};

