#include "HijaWinEditarEmp.h"
#include "empresa.h"
#include "string_conv.h"
#include <string>
#include <wx/msgdlg.h>
using namespace std;

HijaWinEditarEmp::HijaWinEditarEmp(wxWindow *parent, int seleccion, Lista *lista) : VentanaEditarEmp(parent),
	m_EmpSeleccionada(seleccion), m_lista(lista)
{
	Empresa& emp = m_lista->VerEmpresa(m_EmpSeleccionada);
	m_id->SetValue(emp.ObtenerID());
	m_nombre->SetValue(std_to_wx(emp.ObtenerNombre()));
	m_correo->SetValue(std_to_wx(emp.ObtenerCorreo()));
	m_telefono->SetValue(std_to_wx(emp.ObtenerTelefono()));
	m_idOriginal = emp.ObtenerID();
}

void HijaWinEditarEmp::ClickAceptarAgregarEmp( wxCommandEvent& event )  {	
	int id;
	string nombre, correo, telefono;
	Empresa& emp = m_lista->VerEmpresa(m_EmpSeleccionada);
	

	id = m_id->GetValue();
	nombre = wx_to_std(m_nombre->GetValue());
	correo = wx_to_std(m_correo->GetValue());
	telefono = wx_to_std(m_telefono->GetValue());
	
	int duplicados = m_lista->VerificarDuplicados(m_idOriginal, id, nombre);
	
	switch (duplicados){
	case 0:
		break;
	case 1:
		wxMessageBox("Ya hay una empresa con el mismo id");
		return;
	case 2:
		wxMessageBox("Ya hay una empresa con el mismo nombre");
		return;
	}
	
	Empresa aux(id, nombre, correo, telefono);
	string errores = aux.ValidarDatos();
	
	if(errores != "") {
		wxMessageBox(errores);
		return;
	}
	
	
	emp.EditarID(id);
	emp.EditarNombre(nombre);
	emp.EditarCorreo(correo);
	emp.EditarTelefono(telefono);
	try {
		m_lista->GuardarCambios();
	} catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error en el sistema", wxOK | wxICON_ERROR);
	} catch (const std::exception& e) {
		wxMessageBox("Error inesperado en el sistema.", "Error crítico", wxOK | wxICON_ERROR);
	}
	EndModal(1);
}

void HijaWinEditarEmp::ClickCancelarEditarEmp( wxCommandEvent& event )  {
	EndModal(0);
}

HijaWinEditarEmp::~HijaWinEditarEmp() {
	
}

