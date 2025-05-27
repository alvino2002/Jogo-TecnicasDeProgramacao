#include "GerenciadorEvento.h"


using namespace Gerenciadores;

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

	while (pG->getWindow()->pollEvent(evento))
	{
		 if (evento.type == sf::Event::Closed)
		{
			pG->fecharJanela();
		}
	}
}

GerenciadorEvento* GerenciadorEvento::pGerenciadorEvento = nullptr;