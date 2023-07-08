#include "Paciente.h"

Paciente::Paciente(string id, string nombre, string telefono, string correo, string secuencia) : id(id), nombre(nombre), telefono(telefono), correo(correo), secuencia(secuencia) {
	enfermedadcita = new Arreglo<Enfermedad>();
}

Paciente::Paciente(const Paciente& pa) {
	this->id = pa.id;
	this->nombre = pa.nombre;
	this->telefono = pa.telefono;
	this->correo = pa.correo;
	this->secuencia = pa.secuencia;
}

void Paciente::setId(string ced) {
	id = ced;
}

void Paciente::setNombre(string nom) {
	nombre = nom;
}

void Paciente::setTelefono(string cel) {
	telefono = cel;
}

void Paciente::setCorreo(string mail) {
	correo = mail;
}

void Paciente::setSecuencia(string secuancia) {
	secuencia = secuancia;
}

void Paciente::setEnfermedad(Arreglo<Enfermedad>* enfe) {
	enfermedadcita = enfe;
}

string Paciente::getId() {
	return id;
}

string Paciente::getNombre() {
	return nombre;
}

string Paciente::getTelefono() {
	return telefono;
}

string Paciente::getCorreo() {
	return correo;
}

string Paciente::getSecuencia() {
	return secuencia;
}

Paciente& Paciente::operator=(const Paciente& pa) {
	if (this != &pa) {
		this->id = pa.id;
		this->nombre = pa.nombre;
		this->telefono = pa.telefono;
		this->correo = pa.correo;
		this->secuencia = pa.secuencia;
	}
	return *this;
}

ostream& operator << (ostream& out, Paciente& pa) {
	return out
		<< "Cedula: " << pa.getId() << endl
		<< "Nombre: " << pa.getNombre() << endl
		<< "Numero telefonico: " << pa.getTelefono() << endl
		<< "Correo electronico: " << pa.getCorreo() << endl
		<< "Secuencia ADN: " << pa.getSecuencia() << endl;
}

string Paciente::toString() {
	stringstream s;
	s << "Datos del paciente. " << endl << endl;
	s << "Cedula: " << getId() << endl;
	s << "Nombre: " << getNombre() << endl;
	s << "Numero Telefonico: " << getTelefono() << endl;
	s << "Correo electronico: " << getCorreo() << endl;
	s << "Secuencia ADN: " << getSecuencia() << endl;
	s << endl;
	return s.str();
}

string Paciente::toStringSpecial() {
	stringstream s;
	//s << getId() << "," << getNombre() << "," << getTelefono() << "," << getCorreo() << "," << getSecuencia() << "\n";
	return s.str();
}

Paciente* Paciente::cargarDatos(string sId, string sNombre, string sTelefono, string sCorreo, string sSecuencia) {
	return new Paciente(sId, sNombre, sTelefono, sCorreo, sSecuencia);
}

//string Paciente::susceptibilidades(string id) {
//	stringstream CarlosObandoAvendana;
//	Enfermedad* enfe = new Enfermedad;
//	string codigoEnfe = "";
//	string codigoPaci = "";
//	for (int i = 0; i <; i++) {
//		int a = 0, index = 0;
//		enfe = enfermedadcita->obtener(i);
//		codigoEnfe = enfe->getSecuencia();
//		codigoPaci = getSecuencia();
//		codigoPaci.find(codigoEnfe);
//		const char* codigoPacicstring = codigoPaci.c_str();
//		const char* codigoEnfecstring = codigoEnfe.c_str();
//		for (int j = 0; j < strlen(codigoPacicstring); j++) {
//				if (codigoPacicstring[j] == codigoEnfecstring[a]) {
//						if (a == 0)
//							index = j;
//							a++;
//						if (a == strlen(codigoEnfecstring)) {
//							if (a < 3)
//							aux << "La probabilidad de sufrir " << enfe->getNombre() << " es de 33%. " << endl;
//							if (a >= 3)
//							aux << "La probabilidad de sufrir " << enfe->getNombre() << " es de 66%. " << endl;
//						} else {
//							a = 0;
//						}
//				}
//		}
//		return aux.str();
//	}
//	return 0;
//}

//3
//int FindSubstringindex(const std::string *parentstring, const std::string *substring) {
//	int e = 0, indx = -1;
//	const char *parentcstring = parentstring->c_str();
//	const char *csubstring = substring->c_str();
//
//	for (int i = 0; i < strlen(parentcstring); i++) {
//		if (parentcstring[i] == csubstring[e]) {
//			if (e == 0)
//				indx = i;
//			e++;
//			if (e == strlen(csubstring)) {
//				return indx;
//			}
//			else {
//				e = 0;
//			}
//		}
//	}
//	return -1;
//if (a < 3)
	//carlosObandoAvendano << "La probabilidad de sufrir " << enfe->getNombre() << " es de 33%. " << endl;
//if (a >= 3)
//carlosObandoAvendano << "La probabilidad de sufrir " << enfe->getNombre << " es de 66%. " << endl;
//}

Paciente::~Paciente() {}

