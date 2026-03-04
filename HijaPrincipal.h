#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "lista.h"

class HijaPrincipal : public VentanaPrincipal {
	
private:
	Lista *m_lista;
	int m_FilaSeleccionada = -1;
protected:
	void m_grillaOnGridCmdLabelLeftClick( wxGridEvent& event )  override;
	void ClickBotonBuscarEmp( wxCommandEvent& event )  override;
	void ClickBotonEditarEmpresa( wxCommandEvent& event )  override;
	void ClickAgregarEmpresa( wxCommandEvent& event )  override;
	void AlSeleccionarCelda( wxGridEvent& event )  override;
	void ClickVerProds( wxCommandEvent& event )  override;
	void ClickBotEliminarEmp( wxCommandEvent& event )  override;
	
public:
	void RefrescarGrilla();
	HijaPrincipal(Lista *lista);
	~HijaPrincipal();
};

#endif
