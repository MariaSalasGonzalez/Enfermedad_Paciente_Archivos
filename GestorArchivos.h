#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "Arreglo.h"
#include "Enfermedad.h"
#include "Paciente.h"
#include "json/json.h"
using namespace std;

class GestorArchivos;
class GestorArchivos{
public:
	GestorArchivos();
	void recuperarJson(Arreglo<Paciente>*, Arreglo<Enfermedad>*);
	void guardarBinarios(Arreglo<Paciente>*, Arreglo<Enfermedad>*);
	~GestorArchivos();
};