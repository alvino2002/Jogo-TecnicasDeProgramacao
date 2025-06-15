#include "ObservadorMenu.h"
#include "GerenciadorEstado.h"
#include "GerenciadorTempo.h"
#include "EstadoSelecaoPrim.h"
#include "EstadoSelecaoSeg.h"
#include "EstadoRanking.h"


using namespace Masmorra::Observadores;


ObservadorMenu::ObservadorMenu():
	Observador(),
	pMenu()
{
}


ObservadorMenu::~ObservadorMenu()
{
}

void ObservadorMenu::setMenu(Masmorra::Interfaces::Menu* pM)
{
	if (pM)
	{
		pMenu = pM;
	}
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
		Estados::EstadoRanking* ranking = new Estados::EstadoRanking();
		pGEs->adicionarEstado(ranking);
	}
}


