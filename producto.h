#pragma once
#include <iostream>
#include <string>

class Producto {
private:
	std::string m_nombre;
	int m_id;
	int m_stock;
	double m_precio;
	int m_cantidadVendida;
	double m_ventas;
public:
	Producto(const std::string &nombre, int id, int stock, double precio, int cantidadVendida, double ventas) : m_nombre(nombre), m_id(id), m_stock(stock),
		m_precio(precio), m_cantidadVendida(cantidadVendida), m_ventas(ventas){}
	const std::string& ObtenerNombre()const{return m_nombre;};
	int ObtenerID() const {return m_id;};
	int ObtenerStock() const {return m_stock;};
	double ObtenerPrecio() const {return m_precio;};
	int ObtenerCantidadVentas() const {return m_cantidadVendida;};
	double ObtenerVentas() const {return m_ventas;};
	
	void EditarID(int id) {m_id = id;};
	void EditarNombre(std::string &NuevoNombre) {m_nombre = NuevoNombre;};
	void EditarStock(int cantidad) {m_stock = cantidad;};
	void EditarPrecio(double cantidad) {m_precio = cantidad;};
	void EditarCantVend(int cantidad) {m_cantidadVendida = cantidad;};
	void EditarVentas(int cantidad) {m_ventas = cantidad;};
	std::string ValidarDatos();
	
	
	void VenderProducto(int cantidad);
	bool operator<(const Producto& otro) const;
};
