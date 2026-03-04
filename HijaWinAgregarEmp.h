#ifndef HIJAWINAGREGAREMP_H
#define HIJAWINAGREGAREMP_H
#include "wxfb_project.h"
#include "HijaWinAgregarEmp.h"
#include "lista.h"

class HijaWinAgregarEmp : public VentanaAgregarEmp {
	
private:
	Lista *m_lista;
protected:
	void ClickAceptarAgregarEmp( wxCommandEvent& event )  override;
	void ClickCancelarAgregarEmp( wxCommandEvent& event )  override;
	
public:
	HijaWinAgregarEmp(wxWindow *parent=NULL, Lista *lista=nullptr);
	~HijaWinAgregarEmp();
};

#endif

