#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Enfermedad.h"
#include "Paciente.h"
#include "GestorArchivos.h"
using namespace std;

class Vista {
public:
	static void presentacionInicial();
	static int menuPrincipal();
	static string menuAnalsis2();
	static bool cargaJSON();
	static void despedida();
	static string menuAnalisis3();
	static bool guardaBinario();
};
