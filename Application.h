#ifndef APPLICATION_H
#define APPLICATION_H
#include <wx/app.h>
#include "lista.h"

class Application : public wxApp {
private:
	Lista *m_lista;
public:
	virtual bool OnInit();
};

#endif
