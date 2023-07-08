#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "Arreglo.h"
#include "Enfermedad.h"
using namespace std;

class Paciente;
class Enfermedad;

class Paciente {
private:
	string id;
	string nombre;
	string telefono;
	string correo;
	string secuencia;
	Arreglo<Enfermedad>* enfermedadcita;
public:
	Paciente(string = "", string = "", string = "", string = "", string = "");
	Paciente(const Paciente&);
	void setId(string);
	void setNombre(string);
	void setTelefono(string);
	void setCorreo(string);
	void setSecuencia(string);
	void setEnfermedad(Arreglo<Enfermedad>*);
	string getId();
	string getNombre();
	string getTelefono();
	string getCorreo();
	string getSecuencia();
	Paciente& operator=(const Paciente&);
	friend ostream& operator << (ostream&, Paciente&);
	string toString();
	string toStringSpecial();
	Paciente* cargarDatos(string sId, string sNombre, string sTelefono, string sCorreo, string sSecuencia);
	virtual ~Paciente();
};

