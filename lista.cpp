#include <iostream>
#include "lista.h"
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

Lista::Lista(std::string arch) : m_archivo(arch) {
	
	// Para evitar que se puedan cargar duplicados desde la memoria
	// vaciamos el array empresas antes de cargar los datos.
	empresas.clear();
	
	ifstream archivo(m_archivo, ios::binary);
	if (!archivo.is_open()) {
		return; 
	}
	int idEmpresa;
	while (archivo.read((char*) &idEmpresa, sizeof(idEmpresa))) {
		char auxNombre[256] = {0};
		char auxCorreo[256] = {0};
		char auxTelefono[20] = {0};
		int CantidadProductos;
		
		archivo.read(auxNombre, sizeof(auxNombre));
		archivo.read(auxCorreo, sizeof(auxCorreo));
		archivo.read(auxTelefono, sizeof(auxTelefono));
		archivo.read((char*) &CantidadProductos, sizeof(CantidadProductos));
		
		string nombre = auxNombre;
		string correo = auxCorreo;
		string telefono = auxTelefono;
		
		Empresa nuevaEmpresa(idEmpresa, nombre, correo, telefono);
		
		for(int i=0;i<CantidadProductos;i++) {
			char auxNombreProd[256] = {0};
			int idProducto, stock, cantidadVendida;
			double precio, ventas;
			archivo.read(auxNombreProd, sizeof(auxNombreProd));
			archivo.read((char*) &idProducto, sizeof(idProducto));
			archivo.read((char*) &stock, sizeof(stock));
			archivo.read((char*) &precio, sizeof(precio));
			archivo.read((char*) &cantidadVendida, sizeof(cantidadVendida));
			archivo.read((char*) &ventas, sizeof(ventas));
			
			string NombreProd = auxNombreProd;
			nuevaEmpresa.AgregarProducto(NombreProd, idProducto, stock, precio, cantidadVendida, ventas);
		}
		empresas.push_back(nuevaEmpresa);
	}
	archivo.close();
	
}

void Lista::GuardarCambios() {
	// Vamos a usar un guardado atómico. Usamos un archivo temporal para evitar perder
	// datos ante un imprevisto (corte de luz, apagado inesperado, etc).
	
	string archivoTemporal = "lista_prov.tmp";
	string archivoFinal = (m_archivo);
	if (empresas.empty()) {
		ofstream archivo(archivoTemporal, ios::binary | ios::trunc);
		archivo.close();
		return;
	}
	
	ofstream archivo(archivoTemporal, ios::binary | ios::trunc);
	if (!archivo.is_open()) throw runtime_error("No se pudo crear el archivo temporal. No se pudo guardar los cambios.");
	
	for (Empresa &emp : empresas) {
		int id = emp.ObtenerID();
		
		string auxNombre = emp.ObtenerNombre();
		char Nombre[256] = {0};
		// Usamos Strncpy y "255" para evitar un desvortamiento si el nombre es
		// muy largo. Así se nos aseguramos el "\0" en la última posición [255].
		strncpy(Nombre, auxNombre.c_str(), 255);
		
		string auxCorreo = emp.ObtenerCorreo();
		char Correo[256] = {0};
		strncpy(Correo, auxCorreo.c_str(), 255);
		
		string auxTelefono = emp.ObtenerTelefono();
		char Telefono[20] = {0};
		strncpy(Telefono, auxTelefono.c_str(), 19);
		
		int cantidadProductos = emp.ObtenerCantidadProductos(); 
		
		archivo.write((char*) &id, sizeof(id));
		archivo.write(Nombre, sizeof(Nombre));
		archivo.write(Correo, sizeof(Correo));
		archivo.write(Telefono, sizeof(Telefono));
		archivo.write((char*) &cantidadProductos, sizeof(cantidadProductos));
		
		
		// Pasamos por referencia el vector así no lo copiamos entero
		const vector<Producto> &productos = emp.ObtenerListaProductos();
		for(const Producto &p : productos) { 
			string auxNombreProd = p.ObtenerNombre();
			char NombreProd[256] = {0};
			strncpy(NombreProd, auxNombreProd.c_str(), 255);
			
			int idProd = p.ObtenerID();
			int stockProd = p.ObtenerStock();
			double precioProd = p.ObtenerPrecio();
			int cantidadVendida = p.ObtenerCantidadVentas();
			double ventas = p.ObtenerVentas();
			
			archivo.write(NombreProd, sizeof(NombreProd));
			archivo.write((char*) &idProd, sizeof(idProd));
			archivo.write((char*) &stockProd, sizeof(stockProd));
			archivo.write((char*) &precioProd, sizeof(precioProd));
			archivo.write((char*) &cantidadVendida, sizeof(cantidadVendida));
			archivo.write((char*) &ventas, sizeof(ventas));
		}
	}
	
	if (archivo.fail())	{
		archivo.close();
		remove(archivoTemporal.c_str()); // Borramos el archivo temporal corrupto

		throw runtime_error("Error durante la escritura. No se modificaron los datos originales. No se pudo guardar los cambios.");
	}
	archivo.close();
	
	if (remove(archivoFinal.c_str()) != 0) { // Si falla borrar, puede ser porque no existía (primera vez).
		if(ExisteArchivo(archivoFinal)) {
			throw runtime_error("Error: no se puede borrar el archivo original. No se pudo guardar los cambios.");
		}
	}
	// Renombramos el archivo temporal y lo volvemos la base de datos
	if (rename(archivoTemporal.c_str(), archivoFinal.c_str()) != 0) {
		throw runtime_error("Error: se guardó el temporal pero no se pudo renombrar. No se pudo guardar los cambios.");
	}
}

bool Lista::ExisteArchivo(const string& nombre) {
	ifstream archivo(nombre);
	return archivo.good();
}

Empresa& Lista::VerEmpresa(int i) {
	return empresas[i];
}

bool Lista::AgregarEmpresa(int id, string nombre, string correo, string telefono) {
	if(!(BuscarEmpresa(nombre, id) == nullptr))
		return false;
	
	Empresa nuevaEmpresa(id, nombre, correo, telefono);
	empresas.push_back(nuevaEmpresa);
	return true;
}

void Lista::EliminarEmpesa(int i) {
	empresas.erase(empresas.begin() + i);
}
Empresa* Lista::BuscarEmpresa(const std::string &nombre = "", int id = -1) {
	for (auto &e : empresas) {
		if ((nombre != "" && e.ObtenerNombre() == nombre) || (id != -1 && e.ObtenerID() == id)) {
			return &e;
		}
	}
	return nullptr;
}

int Lista::cantidadDeEmpresas() {
	return empresas.size();
}

void Lista::OrdenarEmpresas(int seleccion){
	switch (seleccion) {
	case 0:
		sort(empresas.begin(), empresas.end(), criterio_comparacion_ID);
		break;
	case 1:
		sort(empresas.begin(), empresas.end(), criterio_comparacion_nombre);
		break;
	case 4:
		sort(empresas.begin(), empresas.end(), criterio_comparacion_productos);
		break;
	case 5:
		sort(empresas.begin(), empresas.end(), criterio_comparacion_ventas);
		break;
	}
}

bool Lista::criterio_comparacion_ID(const Empresa &e1, const Empresa &e2){
	int id1 = e1.ObtenerID();
	int id2 = e2.ObtenerID();
	return id1 < id2;
}
bool Lista::criterio_comparacion_nombre(const Empresa &e1, const Empresa &e2){
	string s1 = e1.ObtenerNombre();
	string s2 = e2.ObtenerNombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool Lista::criterio_comparacion_productos(const Empresa &e1, const Empresa &e2){
	int prods1 = e1.ObtenerCantidadProductos();
	int prods2 = e2.ObtenerCantidadProductos();
	return prods1 > prods2;
};
bool Lista::criterio_comparacion_ventas(const Empresa &e1, const Empresa &e2){
	double ventas1 = e1.CalcularVentasTotales();
	double ventas2 = e2.CalcularVentasTotales();
	return ventas1 > ventas2;
};

int Lista::VerificarDuplicados(int idOriginal,int nuevoID, std::string& nombre){

	int duplicado = 0;
	for (size_t i = 0; i < empresas.size(); i++) {
		if (empresas[i].ObtenerID() == idOriginal) {
			continue;
		}
		if (empresas[i].ObtenerID() == nuevoID) {
			duplicado = 1;
		}
		if (empresas[i].ObtenerNombre() == nombre) {
			duplicado = 2;
		}
	}
	return duplicado;
}



