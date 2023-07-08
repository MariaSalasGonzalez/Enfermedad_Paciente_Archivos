#include "Analisis.h"

Analisis::Analisis() {
	gestorcito = new GestorArchivos();
	pacientito = new Arreglo<Paciente>(100);
	enfermedadcita = new Arreglo<Enfermedad>(30);
}

void Analisis::llenar() {
	gestorcito->recuperarJson(pacientito, enfermedadcita);
}

string Analisis::Analisis1() {
	try {
		stringstream s;
		string secuPaci;
		string secuEnfer;
		Paciente* p1 = nullptr;
		Enfermedad* e1 = nullptr;
		cout << "-----------------------------------------ANALISIS 1----------------------------------------------" << endl;
		for (int i = 0; i < enfermedadcita->numElementos(); i++) {
			int can = 0;
			e1 = enfermedadcita->obtener(i);
			secuEnfer = e1->getSecuencia();
			for (int j = 0; j < pacientito->numElementos(); j++) {
				p1 = pacientito->obtener(j);
				secuPaci = p1->getSecuencia();
				if (secuPaci.find(secuEnfer) != string::npos) {
					can++;
				}
			}
			s << "Nombre: " << e1->getNombre() << ", Secuencia: " << e1->getSecuencia() << ", Incidencia: " << can << endl;
		}
		return s.str();
	}
	catch (...) {
		return "Hubo un error";
	}
	
}

string Analisis::Analisis2(string id) {
	stringstream bases;
	Paciente* carlitos = nullptr;
	string sec = "";
	string extraer = "";
	float  A = 0, T = 0, G = 0, C = 0, total = 0, APor = 0, TPor = 0, GPor = 0, CPor = 0;
		cout << "-----------------------------------------ANALISIS 2----------------------------------------------" << endl;
		for (int i = 0; i < pacientito->maxElemento(); i++) {
			carlitos = pacientito->obtener(i);
			if (carlitos->getId() == id) {
				sec = carlitos->getSecuencia();
				for (unsigned int i = 0; i < sec.size(); i++) {
					extraer = sec.substr(i, 1);
					total++;
					if (extraer == "A") {
						A++;
					}
					if (extraer == "T") {
						T++;
					}
					if (extraer == "G") {
						G++;
					}
					if (extraer == "C") {
						C++;
					}
				}
				APor = A / total * 100;
				TPor = T / total * 100;
				GPor = G / total * 100;
				CPor = C / total * 100;
				bases << carlitos->toString();
				bases << "Base nitrogenada tipo A: " << A << endl;
				bases << "Porcentaje: " << APor << "%" << endl;
				bases << "Base nitrogenada tipo T: " << T << endl;
				bases << "Porcentaje: " << TPor << "%" << endl;
				bases << "Base nitrogenada tipo G: " << G << endl;
				bases << "Porcentaje: " << GPor << "%" << endl;
				bases << "Base nitrogenada tipo C: " << C << endl;
				bases << "Porcentaje: " << CPor << "%" << endl;
			}
		}
		return bases.str();
		if (carlitos == nullptr) {
			throw "No se encontro ese codigo en la lista de pacientes. \n\n";
		}
}

string Analisis::Analisis3(string id) {
	stringstream s;
	string secuPaci;
	string secuEnfer;
	Paciente* p1 = nullptr;
	Enfermedad* e1 = nullptr;
	cout << "-----------------------------------------ANALISIS 3----------------------------------------------" << endl;
	for (int i = 0; i < pacientito->numElementos(); i++) {
		int can = 0;
		p1 = pacientito->obtener(i);
		if (p1->getId() == id) {
			secuPaci = p1->getSecuencia();
			for (int j = 0; j < enfermedadcita->numElementos(); j++) {
				e1 = enfermedadcita->obtener(j);
				secuEnfer = e1->getSecuencia();
				if (secuPaci.find(secuEnfer) != string::npos) {
					can++;
				}
			}
			if (can == 2) {
				s << "La concidencia indica un 35% de posibilidad para el paciente " << p1->getNombre() << endl;
			}
			if (can >= 3) {
				s << "La coincidencia indica un 65%  de probabilidad para el paciente " << p1->getNombre() << endl;
			}
		}
	}
	return s.str();
	if (p1 == nullptr) {
		throw "No se encontro ese codigo de paciente. \n\n";
	}
}
	
//std::string parentstring = "Hello Agnosticdev, I love Tutorials";
//std::string substring = "Agnosticdev";
//
//if (std::size_t index = parentstring.find(substring)) {
//	std::cout << "Substring found at index " << index << ", with length " << substring.length() << std::endl;
//}
//else {
//	std::cout << "Substring not found at all in parent string" << std::endl;
//}

void Analisis::guardar() {
	gestorcito->guardarBinarios(pacientito, enfermedadcita);
}

Analisis::~Analisis() {
	delete pacientito, enfermedadcita, gestorcito;
}