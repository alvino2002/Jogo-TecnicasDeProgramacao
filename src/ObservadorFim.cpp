#include "ObservadorFim.h"
#include "GerenciadorEstado.h"
#include "EstadoMenu.h"


using namespace Masmorra::Observadores;


ObservadorFim::ObservadorFim():
	Observador(),
	pFim()
{
}

ObservadorFim::~ObservadorFim()
{
}

void ObservadorFim::setFim(Masmorra::Interfaces::Fim* pF)
{
	if (pF)
	{
		pFim = pF;
	}
}

void ObservadorFim::notificarEvento(const std::string& evento)
{
	if (evento == "SAIR")
	{
		Estados::EstadoMenu* estado = new Estados::EstadoMenu();
		pGEs->adicionarEstado(estado);
	}
}

