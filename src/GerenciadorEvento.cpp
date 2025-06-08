#include "GerenciadorEvento.h"


using namespace Masmorra::Gerenciadores;


GerenciadorEvento::GerenciadorEvento()
{
	pGT = GerenciadorTempo::getGerenciadorTempo();
	pG = GerenciadorGrafico::getGerenciadorGrafico();
}

GerenciadorEvento::~GerenciadorEvento()
{
	pG = nullptr;
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
{
	if (pGerenciadorEvento == nullptr)
	{
		pGerenciadorEvento = new GerenciadorEvento();
	}
	else
	{
		return pGerenciadorEvento;
	}
}

void GerenciadorEvento::executar()
{
	sf::Event evento;

	while (pG->getJanela()->pollEvent(evento))
	{
		 if (evento.type == sf::Event::Closed)
		{
			pG->fecharJanela();
		}
	}
}

GerenciadorEvento* GerenciadorEvento::pGerenciadorEvento = nullptr;
