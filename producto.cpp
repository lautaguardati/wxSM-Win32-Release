#include "producto.h"
using namespace std;

bool Producto::operator<(const Producto& otro) const {
	return this->m_id < otro.m_id;
}

void Producto::VenderProducto(int cantidad) {
	if (cantidad <= m_stock) {
		m_cantidadVendida+= cantidad;
		m_ventas += m_precio*cantidad;
		m_stock -= cantidad;
	}
}

string Producto::ValidarDatos() {
	string errores;
	if (m_nombre.size()==0) errores+="El nombre no puede estar vacio\n";
	if (m_nombre.size()>255) errores+="El nombre es demasiado largo\n";
	if (m_id < 0) errores+= "El id dedebe ser positivo o 0. Y debe tener menos de 10 dígitos\n";
	if (m_stock < 0) errores+= "El stock debe ser positivo o 0. Y debe tener menos de 10 dígitos\n";
	if (m_precio <= 0) errores+= "El precio debe ser positivo o 0. Y debe tener menos de 10 dígitos\n";
	if (m_cantidadVendida < 0) errores+= "El id debe ser positivo o 0. Y debe tener menos de 10 dígitos\n";
	if (m_ventas < 0) errores+= "El id debe ser positivo o 0. Y debe tener menos de 10 dígitos\n";
	
	return errores;
}
