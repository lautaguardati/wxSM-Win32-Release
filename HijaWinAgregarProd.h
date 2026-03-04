#ifndef HIJAWINAGREGARPROD_H
#define HIJAWINAGREGARPROD_H
#include "wxfb_project.h"
#include "empresa.h"

class HijaWinAgregarProd : public VentanaAgregarProd {
	
private:
	Empresa *m_emp;
protected:
	void ClickCancelarAgregarProd ( wxCommandEvent& event ) override;
	void ClickAceptarAgregarProd ( wxCommandEvent& event ) override;
public:
	HijaWinAgregarProd(wxWindow *parent=NULL, Empresa *emp=nullptr);
	~HijaWinAgregarProd();
};

#endif

