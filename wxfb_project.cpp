///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

VentanaPrincipal::VentanaPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Empresa:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer7->Add( m_staticText31, 0, wxALL, 5 );

	m_empBuscar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_empBuscar, 1, wxALL, 5 );

	m_BuscarEmp = new wxButton( this, wxID_ANY, wxT("Buscar empresa"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_BuscarEmp, 0, wxALL, 5 );


	bSizer4->Add( bSizer7, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 6 );
	m_grilla->EnableEditing( true );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 47 );
	m_grilla->SetColSize( 1, 169 );
	m_grilla->SetColSize( 2, 153 );
	m_grilla->SetColSize( 3, 93 );
	m_grilla->SetColSize( 4, 77 );
	m_grilla->SetColSize( 5, 153 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("ID") );
	m_grilla->SetColLabelValue( 1, wxT("Nombre") );
	m_grilla->SetColLabelValue( 2, wxT("Correo") );
	m_grilla->SetColLabelValue( 3, wxT("Telefono") );
	m_grilla->SetColLabelValue( 4, wxT("Productos") );
	m_grilla->SetColLabelValue( 5, wxT("Ventas") );
	m_grilla->SetColLabelValue( 6, wxEmptyString );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->SetRowSize( 0, 1 );
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer5->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );

	m_AgregarEmpresa = new wxButton( this, wxID_ANY, wxT("Agregar Empresa"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer72->Add( m_AgregarEmpresa, 0, wxALL, 5 );


	bSizer6->Add( bSizer72, 1, 0, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_EditEmp = new wxButton( this, wxID_ANY, wxT("Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_EditEmp, 1, wxALL|wxEXPAND, 5 );

	m_VerProds = new wxButton( this, wxID_ANY, wxT("Ver productos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_VerProds, 1, wxALL|wxEXPAND, 5 );

	m_EliminarEmp = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_EliminarEmp, 1, wxALL|wxEXPAND, 5 );


	bSizer6->Add( bSizer9, 0, wxEXPAND, 5 );


	bSizer2->Add( bSizer6, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_BuscarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBotonBuscarEmp ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( VentanaPrincipal::AlSeleccionarCelda ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaPrincipal::m_grillaOnGridCmdLabelLeftClick ), NULL, this );
	m_AgregarEmpresa->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarEmpresa ), NULL, this );
	m_EditEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBotonEditarEmpresa ), NULL, this );
	m_VerProds->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickVerProds ), NULL, this );
	m_EliminarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBotEliminarEmp ), NULL, this );
}

VentanaPrincipal::~VentanaPrincipal()
{
	// Disconnect Events
	m_BuscarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBotonBuscarEmp ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( VentanaPrincipal::AlSeleccionarCelda ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaPrincipal::m_grillaOnGridCmdLabelLeftClick ), NULL, this );
	m_AgregarEmpresa->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarEmpresa ), NULL, this );
	m_EditEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBotonEditarEmpresa ), NULL, this );
	m_VerProds->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickVerProds ), NULL, this );
	m_EliminarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBotEliminarEmp ), NULL, this );

}

VentanaAgregarEmp::VentanaAgregarEmp( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer14->Add( m_staticText3, 0, wxALL, 5 );

	m_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_nombre, 1, wxALL, 5 );


	bSizer13->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer141->Add( m_staticText31, 0, wxALL, 5 );

	m_id = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer141->Add( m_id, 1, wxALL, 5 );


	bSizer13->Add( bSizer141, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Correo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer142->Add( m_staticText32, 0, wxALL, 5 );

	m_correo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer142->Add( m_correo, 1, wxALL, 5 );


	bSizer13->Add( bSizer142, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1421;
	bSizer1421 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer1421->Add( m_staticText321, 0, wxALL, 5 );

	m_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1421->Add( m_telefono, 0, wxALL, 5 );


	bSizer13->Add( bSizer1421, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_botonAceptarAgregarEmp = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonAceptarAgregarEmp, 1, wxALL|wxEXPAND, 5 );

	m_botonCancelarAgregarEmp = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonCancelarAgregarEmp, 1, wxALL|wxEXPAND, 5 );


	bSizer13->Add( bSizer20, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();
	bSizer13->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_botonAceptarAgregarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarEmp::ClickAceptarAgregarEmp ), NULL, this );
	m_botonCancelarAgregarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarEmp::ClickCancelarAgregarEmp ), NULL, this );
}

VentanaAgregarEmp::~VentanaAgregarEmp()
{
	// Disconnect Events
	m_botonAceptarAgregarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarEmp::ClickAceptarAgregarEmp ), NULL, this );
	m_botonCancelarAgregarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarEmp::ClickCancelarAgregarEmp ), NULL, this );

}

VentanaEditarEmp::VentanaEditarEmp( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer14->Add( m_staticText3, 0, wxALL, 5 );

	m_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_nombre, 1, wxALL, 5 );


	bSizer13->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer141->Add( m_staticText31, 0, wxALL, 5 );

	m_id = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer141->Add( m_id, 1, wxALL, 5 );


	bSizer13->Add( bSizer141, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Correo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer142->Add( m_staticText32, 0, wxALL, 5 );

	m_correo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer142->Add( m_correo, 1, wxALL, 5 );


	bSizer13->Add( bSizer142, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1421;
	bSizer1421 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer1421->Add( m_staticText321, 0, wxALL, 5 );

	m_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1421->Add( m_telefono, 0, wxALL, 5 );


	bSizer13->Add( bSizer1421, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_botonAceptarEditarEmp = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonAceptarEditarEmp, 1, wxALL|wxEXPAND, 5 );

	m_botonCancelarEditarEmp = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonCancelarEditarEmp, 1, wxALL|wxEXPAND, 5 );


	bSizer13->Add( bSizer20, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();
	bSizer13->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_botonAceptarEditarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarEmp::ClickAceptarAgregarEmp ), NULL, this );
	m_botonCancelarEditarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarEmp::ClickCancelarEditarEmp ), NULL, this );
}

VentanaEditarEmp::~VentanaEditarEmp()
{
	// Disconnect Events
	m_botonAceptarEditarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarEmp::ClickAceptarAgregarEmp ), NULL, this );
	m_botonCancelarEditarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarEmp::ClickCancelarEditarEmp ), NULL, this );

}

VentanaProductos::VentanaProductos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Empresa: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer11->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textEmpActual = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textEmpActual->Wrap( -1 );
	bSizer11->Add( m_textEmpActual, 1, wxALL, 5 );


	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_grillaProd = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grillaProd->CreateGrid( 0, 6 );
	m_grillaProd->EnableEditing( false );
	m_grillaProd->EnableGridLines( true );
	m_grillaProd->EnableDragGridSize( false );
	m_grillaProd->SetMargins( 0, 0 );

	// Columns
	m_grillaProd->SetColSize( 0, 50 );
	m_grillaProd->SetColSize( 1, 200 );
	m_grillaProd->SetColSize( 2, 101 );
	m_grillaProd->SetColSize( 3, 54 );
	m_grillaProd->SetColSize( 4, 108 );
	m_grillaProd->SetColSize( 5, 162 );
	m_grillaProd->EnableDragColMove( false );
	m_grillaProd->EnableDragColSize( true );
	m_grillaProd->SetColLabelValue( 0, wxT("ID") );
	m_grillaProd->SetColLabelValue( 1, wxT("Nombre") );
	m_grillaProd->SetColLabelValue( 2, wxT("Precio") );
	m_grillaProd->SetColLabelValue( 3, wxT("Stock") );
	m_grillaProd->SetColLabelValue( 4, wxT("Cantidad Vendida") );
	m_grillaProd->SetColLabelValue( 5, wxT("Ventas") );
	m_grillaProd->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grillaProd->SetRowSize( 0, 1 );
	m_grillaProd->EnableDragRowSize( true );
	m_grillaProd->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grillaProd->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer10->Add( m_grillaProd, 1, wxALL|wxEXPAND, 5 );


	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );

	m_EditarProd = new wxButton( this, wxID_ANY, wxT("Editar producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_EditarProd, 0, wxALL, 5 );

	m_AgregarProd = new wxButton( this, wxID_ANY, wxT("Agregar producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_AgregarProd, 0, wxALL, 5 );

	m_EliminarProd = new wxButton( this, wxID_ANY, wxT("Eliminar producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_EliminarProd, 0, wxALL, 5 );


	bSizer12->Add( bSizer42, 1, wxALIGN_LEFT, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	m_BotonVender = new wxButton( this, wxID_ANY, wxT("Vender"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_BotonVender, 0, wxALL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Atras"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_button19, 0, wxALL, 5 );


	bSizer12->Add( bSizer41, 0, 0, 5 );


	bSizer9->Add( bSizer12, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_grillaProd->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( VentanaProductos::AlSeleccionarCelda ), NULL, this );
	m_grillaProd->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaProductos::ClickOrdenarProductos ), NULL, this );
	m_EditarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickEditarProd ), NULL, this );
	m_AgregarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickAgregarProd ), NULL, this );
	m_EliminarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickEliminarProd ), NULL, this );
	m_BotonVender->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickBotonVender ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickBotonAtrasProds ), NULL, this );
}

VentanaProductos::~VentanaProductos()
{
	// Disconnect Events
	m_grillaProd->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( VentanaProductos::AlSeleccionarCelda ), NULL, this );
	m_grillaProd->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaProductos::ClickOrdenarProductos ), NULL, this );
	m_EditarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickEditarProd ), NULL, this );
	m_AgregarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickAgregarProd ), NULL, this );
	m_EliminarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickEliminarProd ), NULL, this );
	m_BotonVender->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickBotonVender ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProductos::ClickBotonAtrasProds ), NULL, this );

}

VentanaAgregarProd::VentanaAgregarProd( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer14->Add( m_staticText3, 0, wxALL, 5 );

	m_nameAddProd = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_nameAddProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer141->Add( m_staticText31, 0, wxALL, 5 );

	m_idAddProd = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer141->Add( m_idAddProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer141, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Precio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer142->Add( m_staticText32, 0, wxALL, 5 );

	m_precioAddProd = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1e+08, 0.000000, 1 );
	m_precioAddProd->SetDigits( 2 );
	bSizer142->Add( m_precioAddProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer142, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1421;
	bSizer1421 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( this, wxID_ANY, wxT("Stock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer1421->Add( m_staticText321, 0, wxALL, 5 );

	m_stockAddProd = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer1421->Add( m_stockAddProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer1421, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1422;
	bSizer1422 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText322 = new wxStaticText( this, wxID_ANY, wxT("Cantidad de Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322->Wrap( -1 );
	bSizer1422->Add( m_staticText322, 0, wxALL, 5 );

	m_cantVentasAddProd = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer1422->Add( m_cantVentasAddProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer1422, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1423;
	bSizer1423 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText323 = new wxStaticText( this, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323->Wrap( -1 );
	bSizer1423->Add( m_staticText323, 0, wxALL|wxEXPAND, 5 );

	m_ventasAddProd = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1e+09, 0, 1 );
	m_ventasAddProd->SetDigits( 2 );
	bSizer1423->Add( m_ventasAddProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer1423, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_botonAceptarAgregarProd = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonAceptarAgregarProd, 1, wxALL|wxEXPAND, 5 );

	m_botonCancelarAgregarProd = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonCancelarAgregarProd, 1, wxALL|wxEXPAND, 5 );


	bSizer13->Add( bSizer20, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();
	bSizer13->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_botonAceptarAgregarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarProd::ClickAceptarAgregarProd ), NULL, this );
	m_botonCancelarAgregarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarProd::ClickCancelarAgregarProd ), NULL, this );
}

VentanaAgregarProd::~VentanaAgregarProd()
{
	// Disconnect Events
	m_botonAceptarAgregarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarProd::ClickAceptarAgregarProd ), NULL, this );
	m_botonCancelarAgregarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarProd::ClickCancelarAgregarProd ), NULL, this );

}

VentanaEditarProd::VentanaEditarProd( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer14->Add( m_staticText3, 0, wxALL, 5 );

	m_nameProd = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_nameProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer14, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer141->Add( m_staticText31, 0, wxALL, 5 );

	m_idProd = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer141->Add( m_idProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer141, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer142;
	bSizer142 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Precio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer142->Add( m_staticText32, 0, wxALL, 5 );

	m_precioProd = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1e+08, 0.000000, 1 );
	m_precioProd->SetDigits( 2 );
	bSizer142->Add( m_precioProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer142, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1421;
	bSizer1421 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( this, wxID_ANY, wxT("Stock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer1421->Add( m_staticText321, 0, wxALL, 5 );

	m_stockProd = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer1421->Add( m_stockProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer1421, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1422;
	bSizer1422 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText322 = new wxStaticText( this, wxID_ANY, wxT("Cantidad de Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText322->Wrap( -1 );
	bSizer1422->Add( m_staticText322, 0, wxALL, 5 );

	m_cantVentasProd = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer1422->Add( m_cantVentasProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer1422, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1423;
	bSizer1423 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText323 = new wxStaticText( this, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323->Wrap( -1 );
	bSizer1423->Add( m_staticText323, 0, wxALL|wxEXPAND, 5 );

	m_ventasProd = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1e+09, 0, 1 );
	m_ventasProd->SetDigits( 2 );
	bSizer1423->Add( m_ventasProd, 1, wxALL, 5 );


	bSizer13->Add( bSizer1423, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_botonAceptarEditarProd = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonAceptarEditarProd, 1, wxALL|wxEXPAND, 5 );

	m_botonCancelarEditarProd = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_botonCancelarEditarProd, 1, wxALL|wxEXPAND, 5 );


	bSizer13->Add( bSizer20, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();
	bSizer13->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_botonAceptarEditarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarProd::ClickAceptarEditarProd ), NULL, this );
	m_botonCancelarEditarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarProd::ClickCancelarEditarProd ), NULL, this );
}

VentanaEditarProd::~VentanaEditarProd()
{
	// Disconnect Events
	m_botonAceptarEditarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarProd::ClickAceptarEditarProd ), NULL, this );
	m_botonCancelarEditarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarProd::ClickCancelarEditarProd ), NULL, this );

}
