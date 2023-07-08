#include "Vista.h"

void Vista::presentacionInicial() {
	cout << "--------------Bienvenidos------------------" << endl;
	cout << "---------A NUESTRA APLICACION--------------" << endl;
	cout << "-------------------------------------------" << endl;
}

int Vista::menuPrincipal() {
	int opcion;
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "--------------MENU PRINCIPAL--------------" << endl;
	cout << "------------------------------------------" << endl;
	cout << "    1- Analisis 1						   " << endl;
	cout << "    2- Analisis 2						   " << endl;
	cout << "    3- Analisis 3						   " << endl;
	cout << "    4- Salir                              " << endl;
	cout << "------------------------------------------" << endl;
	cout << "     Digite la opcion..: ";
	cin >> opcion;
	while (cin.fail()) {
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "--------------MENU PRINCIPAL--------------" << endl;
		cout << "------------------------------------------" << endl;
		cout << "    1- Analisis 1						   " << endl;
		cout << "    2- Analisis 2						   " << endl;
		cout << "    3- Analisis 3						   " << endl;
		cout << "    4- Salir                              " << endl;
		cout << "------------------------------------------" << endl;
		cout << "     Digite la opcion..: ";
		cin >> opcion;
	}
	system("cls");
	return opcion;
}

bool Vista::cargaJSON() {
	bool opcion = false;
	cout << "------Primero debe cargar los datos------" << endl;
	cout << "-----Digite '1' para cargar los datos----" << endl;
	Sleep(2000);
	cin >> opcion;
	system("cls");
	if (opcion != 1) {
		throw "La aplicacion debe cargar sus datos primero. \n\n";
		return 0;
	}else {
		return opcion;
	}
}

void Vista::despedida() {
	cout << "------------------------------------" << endl;
	cout << "-----------MUCHAS GRACIAS-----------" << endl;
	cout << "---POR UTILIZAR NUESTRA APLICACION--" << endl;
	cout << "------------------------------------" << endl;
	Sleep(3000);
}

string Vista::menuAnalsis2() {
	string id = "";
	cout << "Digite el id del paciente. " << endl;
	cin >> id;
	return id;
}

string Vista::menuAnalisis3() {
	string id = "";
	cout << "Escriba el id del paciente. " << endl;
	cin >> id;
	return id;
}

bool Vista::guardaBinario() {
	bool op = false;
	cout << "¿Desea guardar la informacion?" << endl;
	cout << " Digite 1 se desea guardar la informacion" << endl;
	cin >> op;
	if (op == true) {
		return op;
	}
	else {
		throw "Datos no guardados. \n\n";
		return 0;
	}
}