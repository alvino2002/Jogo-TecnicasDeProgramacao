#include "Observador.h"
#include "GerenciadorEstado.h"


using namespace Masmorra::Observadores;


Observador::Observador() 
{
	pGEs = Masmorra::Gerenciadores::GerenciadorEstado::getGerenciadorEstado();
}

Observador::~Observador()
{
}

Masmorra::Gerenciadores::GerenciadorEstado * Observador::pGEs = nullptr;
