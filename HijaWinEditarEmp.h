#ifndef HIJAWINEDITAREMP_H
#define HIJAWINEDITAREMP_H
#include "wxfb_project.h"
#include "lista.h"

class HijaWinEditarEmp : public VentanaEditarEmp {
	
private:
	Lista *m_lista;
	int m_EmpSeleccionada;
	int m_idOriginal;
protected:
	void ClickAceptarAgregarEmp( wxCommandEvent& event )  override;
	void ClickCancelarEditarEmp( wxCommandEvent& event )  override;
	
public:
	HijaWinEditarEmp(wxWindow *parent=NULL, int seleccion = -1, Lista *lista=nullptr);
	~HijaWinEditarEmp();
};

#endif

