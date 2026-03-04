#include "HijaWinAgregarProd.h"
#include <wx/msgdlg.h>
#include <string>
#include "string_conv.h"
#include "producto.h"
using namespace std;

HijaWinAgregarProd::HijaWinAgregarProd(wxWindow *parent, Empresa *emp) : VentanaAgregarProd(parent),
	m_emp(emp)
{
	
}

HijaWinAgregarProd::~HijaWinAgregarProd() {
	
}

void HijaWinAgregarProd::ClickCancelarAgregarProd(wxCommandEvent& event) {
	EndModal(0);
}

void HijaWinAgregarProd::ClickAceptarAgregarProd ( wxCommandEvent& event ) {
	string nom = wx_to_std(m_nameAddProd->GetValue());
	int id = m_idAddProd->GetValue();
	double precio = m_precioAddProd->GetValue();
	int stock = m_stockAddProd->GetValue();
	int cantVentas = m_cantVentasAddProd->GetValue();
	double ventas = m_ventasAddProd->GetValue();
	
	Producto aux(nom, id, stock, precio, cantVentas, ventas);
	string errores = aux.ValidarDatos();
	
	if(errores != "") {
		wxMessageBox(errores);
		return;
	}
	
	if(!(m_emp->AgregarProducto(nom, id, stock, precio, cantVentas, ventas))) {
		wxMessageBox("Ya hay un producto con el mismo nombre o id");
		return;
	}
	EndModal(1);
}
