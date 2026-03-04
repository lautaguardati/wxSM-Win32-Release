#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "producto.h"
#include "Utils.h"

class Empresa {
private:
	int m_idEmpresa;
	std::string m_nombre;
	std::string m_correo;
	std::string m_telefono;
	std::vector<Producto> Productos;
public:
	Empresa(int idEmpresa, const std::string &nombre, const std::string &correo, const std::string &telefono) : m_idEmpresa(idEmpresa),
		m_nombre(nombre), m_correo(correo), m_telefono(telefono){}
	int ObtenerID() const {return m_idEmpresa;};
	const std::string& ObtenerNombre() const {return m_nombre;};
	const std::string& ObtenerCorreo() const {return m_correo;};
	const std::string& ObtenerTelefono() const {return m_telefono;};
	int ObtenerCantidadProductos() const ;
	const std::vector<Producto>& ObtenerListaProductos()const{ return Productos; };
	std::vector<Producto>& ObtenerListaProductos(){ return Productos; };
	
	void EditarID(int id) {m_idEmpresa = id;};
	void EditarNombre(std::string nombre) {m_nombre = nombre;};
	void EditarCorreo(std::string correo) {m_correo = correo;};
	void EditarTelefono(std::string telefono) {m_telefono = telefono;};
	
	bool AgregarProducto(const std::string &nombre, int id, int stock, double precio, int cantidadVendida, double ventas);
	void QuitarProducto(int id);
	bool VenderProducto(int id, int cant);
	bool ExisteProducto(const std::string &nombre, int id);
	Producto& BuscarProducto(int pos);


	double CalcularVentasTotales() const;
	std::string ValidarDatos();
	
	void OrdenarProductos(int seleccion);
	
	// Ordena producto por id del menor al mayor
	static bool criterio_comparacion_ID(const Producto &p1, const Producto &p2); 
	
	// Ordena productos alfabéticamente 
	static bool criterio_comparacion_nombre(const Producto &p1, const Producto &p2);
	
	// Ordena productos por precio del menor al mayor
	static bool criterio_comparacion_precio(const Producto &p1, const Producto &p2);
	
	// Ordena productos por stock de menor al mayor
	static bool criterio_comparacion_stock(const Producto &p1, const Producto &p2);
	
	// Ordena productos por cantidad de productos vendidos de mayor al menor
	static bool criterio_comparacion_cantVendida(const Producto &p1, const Producto &p2);
	
	// Ordena productos por ventas del mayor al menor
	static bool criterio_comparacion_ventas(const Producto &p1, const Producto &p2);
	
	int VerificarDuplicados(int idOriginal, int nuevoID, std::string& nombre);
};
