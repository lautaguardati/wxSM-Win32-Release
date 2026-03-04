#include <wx/image.h>
#include "Application.h"
#include "HijaPrincipal.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	m_lista = new Lista("lista_prov.dat");
	HijaPrincipal *win = new HijaPrincipal(m_lista);
	win->Show();
	return true;
}
