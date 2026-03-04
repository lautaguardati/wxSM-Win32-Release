///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaPrincipal
///////////////////////////////////////////////////////////////////////////////
class VentanaPrincipal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText31;
		wxTextCtrl* m_empBuscar;
		wxButton* m_BuscarEmp;
		wxGrid* m_grilla;
		wxButton* m_AgregarEmpresa;
		wxButton* m_EditEmp;
		wxButton* m_VerProds;
		wxButton* m_EliminarEmp;

		// Virtual event handlers, override them in your derived class
		virtual void ClickBotonBuscarEmp( wxCommandEvent& event ) { event.Skip(); }
		virtual void AlSeleccionarCelda( wxGridEvent& event ) { event.Skip(); }
		virtual void m_grillaOnGridCmdLabelLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAgregarEmpresa( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEditarEmpresa( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVerProds( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotEliminarEmp( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Stock Management"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~VentanaPrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarEmp
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarEmp : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nombre;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_id;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_correo;
		wxStaticText* m_staticText321;
		wxTextCtrl* m_telefono;
		wxButton* m_botonAceptarAgregarEmp;
		wxButton* m_botonCancelarAgregarEmp;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptarAgregarEmp( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarAgregarEmp( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAgregarEmp( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Empresa"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaAgregarEmp();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaEditarEmp
///////////////////////////////////////////////////////////////////////////////
class VentanaEditarEmp : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nombre;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_id;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_correo;
		wxStaticText* m_staticText321;
		wxTextCtrl* m_telefono;
		wxButton* m_botonAceptarEditarEmp;
		wxButton* m_botonCancelarEditarEmp;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptarAgregarEmp( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarEditarEmp( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaEditarEmp( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Editar Empresa"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaEditarEmp();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaProductos
///////////////////////////////////////////////////////////////////////////////
class VentanaProductos : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText23;
		wxStaticText* m_textEmpActual;
		wxGrid* m_grillaProd;
		wxButton* m_EditarProd;
		wxButton* m_AgregarProd;
		wxButton* m_EliminarProd;
		wxButton* m_BotonVender;
		wxButton* m_button19;

		// Virtual event handlers, override them in your derived class
		virtual void AlSeleccionarCelda( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickOrdenarProductos( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickEditarProd( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarProd( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminarProd( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonVender( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAtrasProds( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaProductos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Productos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,400 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaProductos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarProd
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarProd : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nameAddProd;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_idAddProd;
		wxStaticText* m_staticText32;
		wxSpinCtrlDouble* m_precioAddProd;
		wxStaticText* m_staticText321;
		wxSpinCtrl* m_stockAddProd;
		wxStaticText* m_staticText322;
		wxSpinCtrl* m_cantVentasAddProd;
		wxStaticText* m_staticText323;
		wxSpinCtrlDouble* m_ventasAddProd;
		wxButton* m_botonAceptarAgregarProd;
		wxButton* m_botonCancelarAgregarProd;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptarAgregarProd( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarAgregarProd( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAgregarProd( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaAgregarProd();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaEditarProd
///////////////////////////////////////////////////////////////////////////////
class VentanaEditarProd : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* m_nameProd;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_idProd;
		wxStaticText* m_staticText32;
		wxSpinCtrlDouble* m_precioProd;
		wxStaticText* m_staticText321;
		wxSpinCtrl* m_stockProd;
		wxStaticText* m_staticText322;
		wxSpinCtrl* m_cantVentasProd;
		wxStaticText* m_staticText323;
		wxSpinCtrlDouble* m_ventasProd;
		wxButton* m_botonAceptarEditarProd;
		wxButton* m_botonCancelarEditarProd;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptarEditarProd( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarEditarProd( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaEditarProd( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Editar producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~VentanaEditarProd();

};

