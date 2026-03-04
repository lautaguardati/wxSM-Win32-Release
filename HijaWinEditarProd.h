#ifndef HIJAWINEDITARPROD_H
#define HIJAWINEDITARPROD_H
#include "wxfb_project.h"
#include "empresa.h"

class HijaWinEditarProd : public VentanaEditarProd {
	
private:
	Empresa *m_emp;
	int m_productoSeleccionado;
	int m_idOriginal;
protected:
	void ClickAceptarEditarProd( wxCommandEvent& event )  override;
	void ClickCancelarEditarProd( wxCommandEvent& event )  override;
	
public:
	HijaWinEditarProd(wxWindow *parent=NULL, Empresa *emp=nullptr, int pos=-1);
	~HijaWinEditarProd();
};

#endif

