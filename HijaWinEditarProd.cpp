#include "HijaWinEditarProd.h"
#include "string_conv.h"
#include <vector>
#include "producto.h"
#include <wx/msgdlg.h>
using namespace std;

HijaWinEditarProd::HijaWinEditarProd(wxWindow *parent, Empresa *emp, int pos) : VentanaEditarProd(parent),
	m_emp(emp), m_productoSeleccionado(pos)
{
	Producto &p = m_emp->BuscarProducto(m_productoSeleccionado);
	m_nameProd->SetValue(std_to_wx(p.ObtenerNombre()));
	m_idProd->SetValue(wxString::Format("%d", p.ObtenerID()));
	m_precioProd->SetValue(wxString::Format("%f", p.ObtenerPrecio()));
	m_stockProd->SetValue(wxString::Format("%d", p.ObtenerStock()));
	m_cantVentasProd->SetValue(wxString::Format("%d", p.ObtenerCantidadVentas()));
	m_ventasProd->SetValue(wxString::Format("%f", p.ObtenerVentas()));
	m_idOriginal = p.ObtenerID();
}

void HijaWinEditarProd::ClickAceptarEditarProd( wxCommandEvent& event )  {
	string nombre;
	int id, stock, cantVentas;
	double precio, ventas;
	nombre = wx_to_std(m_nameProd->GetValue());
	id = m_idProd->GetValue();
	stock = m_stockProd->GetValue();
	cantVentas = m_cantVentasProd->GetValue();
	precio = m_precioProd->GetValue();
	ventas = m_ventasProd->GetValue();
	Producto &p = m_emp->BuscarProducto(m_productoSeleccionado);
	
	int duplicados = m_emp->VerificarDuplicados(m_idOriginal, id, nombre);
	
	switch (duplicados){
	case 0:
		break;
	case 1:
		wxMessageBox("Ya hay un producto con el mismo id");
		return;
	case 2:
		wxMessageBox("Ya hay un producto con el mismo nombre");
		return;
	}
	
	Producto aux(nombre, id, stock, precio, cantVentas, ventas);
	string errores = aux.ValidarDatos();
	
	if(errores != "") {
		wxMessageBox(errores);
		return;
	}
	
	// acá va un if con las validaciones
	p.EditarID(id);
	p.EditarNombre(nombre);
	p.EditarStock(stock);
	p.EditarCantVend(cantVentas);
	p.EditarPrecio(precio);
	p.EditarVentas(ventas);
	EndModal(1);
}

void HijaWinEditarProd::ClickCancelarEditarProd( wxCommandEvent& event )  {
	EndModal(0);
}

HijaWinEditarProd::~HijaWinEditarProd() {
	
}

