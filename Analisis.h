#pragma once
#include <iostream>
#include <string>
#include "Arreglo.h"
#include "Paciente.h"
#include "GestorArchivos.h"
#include "stdlib.h"
using namespace std;

class Analisis{
private:
	Arreglo<Paciente>* pacientito;
	Arreglo<Enfermedad>* enfermedadcita;
	GestorArchivos* gestorcito;
public:
	Analisis();
	void llenar();
	string Analisis1();
	string Analisis2(string = "");
	string Analisis3(string = "");
	void guardar();
	virtual ~Analisis();
};

