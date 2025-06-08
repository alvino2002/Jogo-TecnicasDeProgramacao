#include "ObservadorMenu.h"
#include "GerenciadorEstado.h"
#include "GerenciadorTempo.h"
#include "EstadoSelecaoPrim.h"
#include "EstadoSelecaoSeg.h"


using namespace Masmorra::Observadores;

ObservadorMenu::ObservadorMenu():
	Observador()
{
}


ObservadorMenu::~ObservadorMenu()
{
}


void ObservadorMenu::notificarEvento(const std::string& evento)
{
	if (evento == "PRIMEIRA FASE")
	{
		Estados::EstadoSelecaoPrim* selecaoPrim = new Estados::EstadoSelecaoPrim();
		pGEs->adicionarEstado(selecaoPrim);
	}

	if (evento == "SEGUNDA FASE")
	{
		Estados::EstadoSelecaoSeg* selecaoSeg = new Estados::EstadoSelecaoSeg();
		pGEs->adicionarEstado(selecaoSeg);
	}

	if (evento == "RANKING")
	{
	}
}


