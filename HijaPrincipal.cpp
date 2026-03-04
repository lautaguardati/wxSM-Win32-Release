#include "HijaPrincipal.h"
#include <iostream>
#include "HijaWinProductos.h"
#include <wx/msgdlg.h>
#include "HijaWinAgregarEmp.h"
#include "HijaWinEditarEmp.h"
#include <string>
#include "string_conv.h"
#include <wx/icon.h>
using namespace std;

HijaPrincipal::HijaPrincipal(Lista *lista) : VentanaPrincipal(nullptr), m_lista(lista)
{
	SetIcon(wxIcon("icon_win.ico", wxBITMAP_TYPE_ICO));
	int cantidad = m_lista->cantidadDeEmpresas();
	if (cantidad > 0) {
		m_grilla->AppendRows(cantidad);
	}
	
	for(int i = 0; i < cantidad; i++) {
		Empresa &emp = m_lista->VerEmpresa(i);
		m_grilla->SetCellValue(i, 0, wxString::Format("%d", emp.ObtenerID()));
		m_grilla->SetCellValue(i, 1, std_to_wx(emp.ObtenerNombre()));
		m_grilla->SetCellValue(i, 2, std_to_wx(emp.ObtenerCorreo()));
		m_grilla->SetCellValue(i, 3, std_to_wx(emp.ObtenerTelefono()));
		m_grilla->SetCellValue(i, 4, wxString::Format("%d", emp.ObtenerCantidadProductos()));
		m_grilla->SetCellValue(i, 5, std_to_wx("$") + wxString::Format("%.2f", emp.CalcularVentasTotales()));
	}
}

HijaPrincipal::~HijaPrincipal() {
	
}

void HijaPrincipal::RefrescarGrilla() {
	if (m_grilla->GetNumberRows() != 0)
		m_grilla->DeleteRows(0, m_grilla->GetNumberRows());
	for(int i = 0; i < m_lista->cantidadDeEmpresas(); i++) {
		const Empresa &emp = m_lista->VerEmpresa(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i, 0, wxString::Format("%d", emp.ObtenerID()));
		m_grilla->SetCellValue(i, 1, std_to_wx(emp.ObtenerNombre()));
		m_grilla->SetCellValue(i, 2, std_to_wx(emp.ObtenerCorreo()));
		m_grilla->SetCellValue(i, 3, std_to_wx(emp.ObtenerTelefono()));
		m_grilla->SetCellValue(i, 4, wxString::Format("%d", emp.ObtenerCantidadProductos()));
		m_grilla->SetCellValue(i, 5, std_to_wx("$") + wxString::Format("%.2f", emp.CalcularVentasTotales()));
	}
	m_FilaSeleccionada = -1;
}

void HijaPrincipal::ClickBotEliminarEmp( wxCommandEvent& event )  {
	if (m_FilaSeleccionada < 0) {
		wxMessageBox("Debe seleccionar una empresa para eliminar");
		return;
	}
	if (m_lista->cantidadDeEmpresas() == 0) {
		wxMessageBox("No hay empresas para eliminar.");
		return;
	}
	wxMessageDialog dial(this, 
		"¿Estás seguro de que deseas eliminar esta empresa?", 
		"Confirmar eliminación", 
		wxYES_NO | wxNO_DEFAULT | wxICON_WARNING);
	
	if (dial.ShowModal() == wxID_YES) {
		m_lista->EliminarEmpesa(m_FilaSeleccionada);
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

void HijaPrincipal::ClickVerProds( wxCommandEvent& event )  {
	if (m_FilaSeleccionada < 0) {
		wxMessageBox("Debe seleccionar una empresa para ver los productos");
		return;
	}

	Empresa &emp = m_lista->VerEmpresa(m_FilaSeleccionada);
	
	HijaWinProductos win(this, &emp, m_lista);
	win.ShowModal();
	RefrescarGrilla();
}

void HijaPrincipal::AlSeleccionarCelda( wxGridEvent& event )  {
	m_FilaSeleccionada = event.GetRow();
	event.Skip();
}

void HijaPrincipal::ClickAgregarEmpresa( wxCommandEvent& event )  {
	HijaWinAgregarEmp win(this, m_lista);
	win.ShowModal();
	RefrescarGrilla();
}

void HijaPrincipal::ClickBotonEditarEmpresa( wxCommandEvent& event )  {
	if (m_FilaSeleccionada < 0) {
		wxMessageBox("Debe seleccionar una empresa para editar");
		return;
	}
	
	HijaWinEditarEmp win(this, m_FilaSeleccionada ,m_lista);
	win.ShowModal();
	RefrescarGrilla();
}

void HijaPrincipal::ClickBotonBuscarEmp( wxCommandEvent& event )  {
	
	string nombre = wx_to_std(m_empBuscar->GetValue());
	if (nombre.size()==0) {
		return;
	}
	Empresa *emp = m_lista->BuscarEmpresa(nombre, -1);
	
	if (emp==nullptr) {
		wxMessageBox("No se encontró la empresa");
		return;
	}
	HijaWinProductos win(this, emp, m_lista);
	win.ShowModal();
	m_empBuscar->Clear();
	RefrescarGrilla();
}

//	Este evento lo usamos para ordenar las empresas 
//  según donde clickee el usuario
void HijaPrincipal::m_grillaOnGridCmdLabelLeftClick( wxGridEvent& event )  {
	int columna = event.GetCol();
	//0=id; 1=nombre; 4=Productos; 5=Ventas;

	m_lista->OrdenarEmpresas(columna);
	RefrescarGrilla();
	try {
		m_lista->GuardarCambios();
	} catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
	} catch (const std::exception& e) {
		wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
	}
}
