#include "HijaWinProductos.h"
#include <vector>
#include <wx/numdlg.h>
#include <wx/msgdlg.h>
#include "HijaWinAgregarProd.h"
#include "HijaWinEditarProd.h"
#include "string_conv.h"
using namespace std;

HijaWinProductos::HijaWinProductos(wxWindow *parent, Empresa *emp, Lista *lista) : VentanaProductos(parent),
	m_emp(emp), m_lista(lista)
{
	m_textEmpActual->SetLabel(std_to_wx(emp->ObtenerNombre()));
	RefrescarGrilla();
}

HijaWinProductos::~HijaWinProductos() {
	
}

void HijaWinProductos::RefrescarGrilla() {
	if (m_grillaProd->GetNumberRows() != 0)
		m_grillaProd->DeleteRows(0, m_grillaProd->GetNumberRows());
	
	const vector<Producto> &p = m_emp->ObtenerListaProductos();
	
	for(int i = 0; i < m_emp->ObtenerCantidadProductos(); i++) {
		m_grillaProd->AppendRows(1);
		m_grillaProd->SetCellValue(i, 0, wxString::Format("%d", p[i].ObtenerID()));
		m_grillaProd->SetCellValue(i, 1, std_to_wx(p[i].ObtenerNombre()));
		m_grillaProd->SetCellValue(i, 2, std_to_wx("$") + wxString::Format("%.2f", p[i].ObtenerPrecio()));
		m_grillaProd->SetCellValue(i, 3, wxString::Format("%d", p[i].ObtenerStock()));
		m_grillaProd->SetCellValue(i, 4, wxString::Format("%d", p[i].ObtenerCantidadVentas()));
		m_grillaProd->SetCellValue(i, 5, std_to_wx("$") + wxString::Format("%.2f", p[i].ObtenerVentas()));
	}
	m_FilaSeleccionada = -1;
}

void HijaWinProductos::ClickBotonVender( wxCommandEvent& event )  {
	if (m_FilaSeleccionada < 0) {
		wxMessageBox("Debe seleccionar un producto para vender");
		return;
	}
	vector<Producto> &p = m_emp->ObtenerListaProductos();
	int StockDisponible = p[m_FilaSeleccionada].ObtenerStock();
	if (StockDisponible == 0) {
		wxMessageBox("¡No hay stock!");
		return;
	}
	int cantidad = wxGetNumberFromUser(
		"¿Cuántas unidades quieres vender?",
		"Cantidad entre 1 y " + to_string(StockDisponible) + ": ",
		"Confirmar Venta",
		1,
		1,
		StockDisponible,
		this
	);
	
	if (cantidad > StockDisponible) {
		wxMessageBox("Cantidad mayor al stock disponible");
		return;
	}

	if (cantidad != -1) {
		p[m_FilaSeleccionada].VenderProducto(cantidad);
		RefrescarGrilla();
		try {
			m_lista->GuardarCambios();
		} catch (const std::runtime_error& e) {
			wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
		} catch (const std::exception& e) {
			wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
		}
	}
	m_FilaSeleccionada = -1;
}

void HijaWinProductos::AlSeleccionarCelda( wxGridEvent& event )  {
	m_FilaSeleccionada = event.GetRow();
	event.Skip();
}

void HijaWinProductos::ClickEditarProd( wxCommandEvent& event )  {
	if (m_FilaSeleccionada < 0) {
		wxMessageBox("Debe seleccionar un producto para editar");
		return;
	}
	
	HijaWinEditarProd win(this, m_emp, m_FilaSeleccionada);
	win.ShowModal();
	try {
		m_lista->GuardarCambios();
	} catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
	} catch (const std::exception& e) {
		wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
	}
	RefrescarGrilla();
}

void HijaWinProductos::ClickAgregarProd( wxCommandEvent& event )  {
	HijaWinAgregarProd win(this, m_emp);
	win.ShowModal();
	try {
		m_lista->GuardarCambios();
	} catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
	} catch (const std::exception& e) {
		wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
	}
	RefrescarGrilla();
}

void HijaWinProductos::ClickEliminarProd( wxCommandEvent& event )  {
	if (m_FilaSeleccionada < 0) {
		wxMessageBox("Debe seleccionar un producto para eliminar");
		return;
	}
	wxMessageDialog dial(this, 
		"¿Estás seguro de que deseas eliminar este producto?", 
		"Confirmar eliminación", 
		wxYES_NO | wxNO_DEFAULT | wxICON_WARNING);
	
	if (dial.ShowModal() == wxID_YES) {
		m_emp->QuitarProducto(m_FilaSeleccionada);
		RefrescarGrilla();
		try {
			m_lista->GuardarCambios();
		} catch (const std::runtime_error& e) {
			wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
		} catch (const std::exception& e) {
			wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
		}
	}
	m_FilaSeleccionada = -1;
}

void HijaWinProductos::ClickBotonAtrasProds( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaWinProductos::ClickOrdenarProductos( wxGridEvent& event )  {
	int columna = event.GetCol();
	//0=id; 1=nombre; 4=Productos; 5=Ventas;
	
	m_emp->OrdenarProductos(columna);
	try {
		m_lista->GuardarCambios();
	} catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
	} catch (const std::exception& e) {
		wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
	}
	RefrescarGrilla();
}

