#include "Controladora.h"

Controladora::Controladora() : ana(new Analisis()) {}

Controladora::~Controladora() {
	delete ana;
}

void Controladora::control1() {
	try {
		Vista::cargaJSON();
		ana->llenar();
		int opcion;
		do {
			opcion = Vista::menuPrincipal();
			switch (opcion) {
			case 1:
				analisis1();
				break;
			case 2:
				analisis2();
				break;
			case 3:
				analisis3();
				break;
			case 4:
				guardarInfo();
				Vista::despedida();
				break;
			default:
				cout << "Debe digitar un numero del 1 al 4" << endl;
			}
		} while (opcion != 4);
	}
	catch (const char* excepcion) {
		cout << excepcion << endl;
	}
	catch (...) {
		cout << "Hubo un problema inesperado. " << endl;
	}
}

void Controladora::generaJSON() {
	cout << "Genera JSON" << endl;
	Sleep(4000);
}

void Controladora::cargaJSON() {
	Vista::cargaJSON();
}

void Controladora::analisis1() {
	cout << "Analisis 1" << endl;
	cout<<ana->Analisis1();
	system("pause");
}

void Controladora::analisis2() {
	cout << "Analisis 2" << endl;
	try {
		cout << ana->Analisis2(Vista::menuAnalsis2());
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
	system("pause");
}

void Controladora::analisis3() {
	cout << "Analisis 3" << endl;
	try {
		cout << ana->Analisis3(Vista::menuAnalisis3());
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
	system("pause");
}

void Controladora::guardarInfo() {
	try {
		Vista::guardaBinario();
		ana->guardar();
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
}