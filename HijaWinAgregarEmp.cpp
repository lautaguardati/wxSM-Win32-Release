#include "HijaWinAgregarEmp.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>
#include "empresa.h"
using namespace std;

HijaWinAgregarEmp::HijaWinAgregarEmp(wxWindow *parent, Lista *lista) : VentanaAgregarEmp(parent),
	m_lista(lista)
{
	
}

void HijaWinAgregarEmp::ClickAceptarAgregarEmp( wxCommandEvent& event )  {
	int id;
	string nombre, telefono, correo;
	id = m_id->GetValue();
	nombre = wx_to_std(m_nombre->GetValue());
	telefono = wx_to_std(m_telefono->GetValue());
	correo = wx_to_std(m_correo->GetValue());
	Empresa aux(id, nombre, correo, telefono);
	string errores = aux.ValidarDatos();
	
	if(errores != "") {
		wxMessageBox(errores);
		return;
	}
	
	if (!m_lista->AgregarEmpresa(id, nombre, correo, telefono)){
		wxMessageBox("Ya hay una empresa con el mismo nombre o id");
		return;
	}
	
	try {
		m_lista->GuardarCambios();
	} catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
	} catch (const std::exception& e) {
		wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
	}
	EndModal(1);
}

void HijaWinAgregarEmp::ClickCancelarAgregarEmp( wxCommandEvent& event )  {
	EndModal(0);
}

HijaWinAgregarEmp::~HijaWinAgregarEmp() {
	
}

