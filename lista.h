#pragma once
#include <iostream>
#include <vector>
#include "empresa.h"
#include <string>
#include "Utils.h"


class Lista {
private:
	std::string m_archivo;
	std::vector<Empresa> empresas;
public:
	Lista(std::string arch); 

	void GuardarCambios();
	bool ExisteArchivo(const std::string& nombre);
	Empresa& VerEmpresa(int i);

	bool AgregarEmpresa(int id, std::string nombre, std::string correo, std::string telefono);
	void EliminarEmpesa(int i);

	int cantidadDeEmpresas();
	
	Empresa* BuscarEmpresa(const std::string &nombre, int id);
	
	void OrdenarEmpresas(int seleccion);
	
	// Ordena empresa por id del menor al mayor
	static bool criterio_comparacion_ID(const Empresa &e1, const Empresa &e2); 
	
	// Ordena empresa alfabéticamente 
	static bool criterio_comparacion_nombre(const Empresa &e1, const Empresa &e2);
	
	// Ordena empresa por cantidad de productos del mayor al menor
	static bool criterio_comparacion_productos(const Empresa &e1, const Empresa &e2);
	
	// Ordena empresa por ventas del mayor al menor
	static bool criterio_comparacion_ventas(const Empresa &e1, const Empresa &e2);
	
	int VerificarDuplicados(int idOriginal, int nuevoID, std::string& nombre);
};
