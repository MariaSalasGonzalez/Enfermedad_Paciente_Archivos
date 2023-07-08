#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include "Vista.h"
#include "Analisis.h"
using namespace std;

class Controladora;
class Controladora {
private:
	Analisis* ana;
public:
	Controladora();
	void control1();
	void generaJSON();
	void cargaJSON();
	void analisis1();
	void analisis2();
	void analisis3();
	void guardarInfo();
	virtual ~Controladora();
};
