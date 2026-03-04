#ifndef HIJAWINPRODUCTOS_H
#define HIJAWINPRODUCTOS_H
#include "wxfb_project.h"
#include "empresa.h"
#include "lista.h"

class HijaWinProductos : public VentanaProductos {
	
private:
	Empresa *m_emp;
	Lista *m_lista;
	int m_FilaSeleccionada = -1;
protected:
	void ClickOrdenarProductos( wxGridEvent& event )  override;
	void ClickBotonAtrasProds( wxCommandEvent& event )  override;
	void ClickEditarProd( wxCommandEvent& event )  override;
	void ClickAgregarProd( wxCommandEvent& event )  override;
	void ClickEliminarProd( wxCommandEvent& event )  override;
	void AlSeleccionarCelda( wxGridEvent& event )  override;
	void ClickBotonVender( wxCommandEvent& event )  override;
	
public:
	HijaWinProductos(wxWindow *parent=NULL, Empresa *emp=nullptr, Lista *lista=nullptr);
	~HijaWinProductos();
	void RefrescarGrilla();
};

#endif

