/**
* @file Utils.cpp
* @brief Funciones varias para simplificar tareas
*
* En este archivo van las funciones generales. Es decir, las que no son 
* particulares de ninguna clase.
**/

#include "Utils.h"

/**
* Funcion auxiliar para las utilizar en las comparaciones y busquedas de modo
* que no importe si los nombres estan en mayusculas o minusculas.
**/
void pasar_a_minusculas(std::string &s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=std::tolower(s[i]);
}
