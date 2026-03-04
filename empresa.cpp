#include <iostream>
#include "empresa.h"


int Empresa::ObtenerCantidadProductos() const {
	int aux = Productos.size();
	return aux;
}

bool Empresa::AgregarProducto(const std::string &nombre, int id, int stock,
		double precio, int cantidadVendida, double ventas) {
	
	if (ExisteProducto(nombre, id)) return false;
	
	Producto auxProd(nombre, id, stock, precio, cantidadVendida, ventas);
	Productos.push_back(auxProd);
	return true;
}

bool Empresa::ExisteProducto(const std::string &nombre, int id) {
	for (Producto &p : Productos) {
		if (p.ObtenerID() == id || p.ObtenerNombre() == nombre) return true;
	}
	return false;
}

Producto& Empresa::BuscarProducto(int pos) {
	return Productos[pos];
}

void Empresa::QuitarProducto(int i) {
	Productos.erase(Productos.begin() + i);
}

bool Empresa::VenderProducto(int id, int cant) {
	for(Producto &p : Productos) { 
		if (id == p.ObtenerID()) {
			if(p.ObtenerStock() < cant) {
				return false;
			}
			p.EditarStock((p.ObtenerStock()-cant));
			p.VenderProducto(cant);
			return true;
		}
	}
	return false;
}


double Empresa::CalcularVentasTotales() const {
	double aux = 0;
	for (const Producto &p : Productos) {
		aux += p.ObtenerVentas();
	}
	return aux;
}

std::string Empresa::ValidarDatos() {
	std::string errores;
	if (m_idEmpresa < 0) errores+="El id debe ser mayor a 0. Y debe tener menos de 10 dígitos\n";
	if (m_nombre.size()==0) errores+="El nombre no puede estar vacio\n";
	if (m_nombre.size()>255) errores+="El nombre es demasiado largo\n";
	if (m_correo.size()==0) errores+="El correo no puede estar vacio\n";
	if (m_correo.size()>255) errores+="El correo es demasiado largo\n";
	if (m_telefono.size()>20) errores+="El telefono es demasiado largo\n";
	if (m_telefono.size()==0) errores+="El telefono no puede estar vacio\n";
	
	return errores;
}

void Empresa::OrdenarProductos(int seleccion){
	switch (seleccion) {
	case 0:
		sort(Productos.begin(), Productos.end(), criterio_comparacion_ID);
		break;
	case 1:
		sort(Productos.begin(), Productos.end(), criterio_comparacion_nombre);
		break;
	case 2:
		sort(Productos.begin(), Productos.end(), criterio_comparacion_precio);
		break;
	case 3:
		sort(Productos.begin(), Productos.end(), criterio_comparacion_stock);
		break;
	case 4:
		sort(Productos.begin(), Productos.end(), criterio_comparacion_cantVendida);
		break;
	case 5:
		sort(Productos.begin(), Productos.end(), criterio_comparacion_ventas);
		break;
	}
}

// Ordena producto por id del menor al mayor
bool Empresa::criterio_comparacion_ID(const Producto &p1, const Producto &p2){
	int id1 = p1.ObtenerID();
	int id2 = p2.ObtenerID();
	return id1 < id2;
}

// Ordena productos alfabéticamente 
bool Empresa::criterio_comparacion_nombre(const Producto &p1, const Producto &p2){
	std::string s1 = p1.ObtenerNombre();
	std::string s2 = p2.ObtenerNombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1 < s2;
}

// Ordena productos por precio del menor al mayor
bool Empresa::criterio_comparacion_precio(const Producto &p1, const Producto &p2){
	double precio1 = p1.ObtenerPrecio();
	double precio2 = p2.ObtenerPrecio();
	return precio1 < precio2;
}

// Ordena productos por stock de mayor al menor
bool Empresa::criterio_comparacion_stock(const Producto &p1, const Producto &p2){
	int st1 = p1.ObtenerStock();
	int st2 = p2.ObtenerStock();
	return st1 > st2;
}

// Ordena productos por cantidad de productos vendidos de mayor al menor
bool Empresa::criterio_comparacion_cantVendida(const Producto &p1, const Producto &p2){
	int cant1 = p1.ObtenerCantidadVentas();
	int cant2 = p2.ObtenerCantidadVentas();
	return cant1 > cant2;
}

// Ordena productos por ventas del mayor al menor
bool Empresa::criterio_comparacion_ventas(const Producto &p1, const Producto &p2){
	double v1 = p1.ObtenerVentas();
	double v2 = p2.ObtenerVentas();
	return v1 > v2;
}


int Empresa::VerificarDuplicados(int idOriginal,int nuevoID, std::string& nombre){
	int duplicado = 0;
	for (size_t i = 0; i < Productos.size(); i++) {
		if (Productos[i].ObtenerID() == idOriginal) {
			continue;
		}
		if (Productos[i].ObtenerID() == nuevoID) {
			duplicado = 1;
		}
		if (Productos[i].ObtenerNombre() == nombre) {
			duplicado = 2;
		}
	}
	return duplicado;
}
