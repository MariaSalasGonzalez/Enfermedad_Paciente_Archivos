#include "GestorArchivos.h"

GestorArchivos::GestorArchivos(){}

void GestorArchivos::recuperarJson(Arreglo<Paciente>* pacientito, Arreglo<Enfermedad>* enfermedadcita) {
	ifstream entradaE("jsonEnfermedad.txt");
	ifstream entradaP("jsonPaciente.txt");
	Json::Value objetoE;
	Json::Value objetoP;
	Json::Reader reader;
	reader.parse(entradaE, objetoE); 
	reader.parse(entradaP, objetoP);
	for (unsigned int i = 0; i < objetoP.size(); i++) {
			Paciente* p1 = new Paciente;
			p1->setId(objetoP[i]["Id: "].asString());
			p1->setNombre(objetoP[i]["Nombre: "].asString());
			p1->setTelefono(objetoP[i]["Telefono: "].asString());
			p1->setCorreo(objetoP[i]["Correo: "].asString());
			p1->setSecuencia(objetoP[i]["Secuencia: "].asString());
			pacientito->ingresaAlArreglo(p1);
			cout << pacientito->toString();		
	}
	entradaP.close();
	for (unsigned int i = 0; i < objetoE.size(); i++) {
		Enfermedad* e1 = new Enfermedad;
		e1->setNombre(objetoE[i]["Nombre: "].asString());
		e1->setSecuencia(objetoE[i]["Secuencia: "].asString());
		enfermedadcita->ingresaAlArreglo(e1);
		cout << enfermedadcita->toString();	
	}
	entradaE.close();
	system("pause");
}

void GestorArchivos::guardarBinarios(Arreglo<Paciente>* pacientito, Arreglo<Enfermedad>* enfermedadcita) {
	Paciente* KamalaHarris = nullptr;
	Enfermedad* GeorgeBush = nullptr;
	ofstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		for (int i = 0; i < pacientito->maxElemento(); i++) {
			KamalaHarris = pacientito->obtener(i);
			infile.write((char*)&KamalaHarris, sizeof(Paciente));
		}
		for (int j = 0; j < enfermedadcita->maxElemento(); j++) {
			GeorgeBush = enfermedadcita->obtener(j);
			infile.write((char*)&KamalaHarris, sizeof(Enfermedad));
		}
		infile.close();
	}
	else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

GestorArchivos::~GestorArchivos() {}