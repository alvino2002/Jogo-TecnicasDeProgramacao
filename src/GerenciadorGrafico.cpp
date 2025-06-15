#include "GerenciadorGrafico.h"
#include "Ente.h"
#include "Entidade.h"
#include "Interface.h"


using namespace Masmorra::Gerenciadores;

using namespace Masmorra::Interfaces;


GerenciadorGrafico::GerenciadorGrafico():
	janela (new sf::RenderWindow(sf::VideoMode(800.f, 600.f), "Masmorra"))
{
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela)
	{
		delete janela;
		janela = nullptr;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGerenciadorGrafico == nullptr)
	{
		pGerenciadorGrafico = new GerenciadorGrafico();
	}
	return pGerenciadorGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
	return janela;
}

void GerenciadorGrafico::limparJanela()
{
	janela->clear();
}

void GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

void GerenciadorGrafico::desenharEnte(Ente* pE)
{
	if (pE->getId() == 1) // Ente fisico (Personagem, Obstaculo,...)
	{
		Entidades::Entidade* pEnt = static_cast<Entidades::Entidade*>(pE);
		janela->draw(pEnt->getCorpo());
	}

	else // Ente nao fisico (Menu, Pause,...)
	{
		Interface* pInt = static_cast<Interface*> (pE);

		janela->draw(pInt->getFundo());

		const std::vector<sf::Text>& textos = pInt->getTextos();

		for (std::vector<sf::Text>::const_iterator it = textos.begin(); it != textos.end(); it++) 
		{
			janela->draw(*it);
		}
	}
}

void GerenciadorGrafico::mostrarElementos()
{
	janela->display();
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
	return (janela->isOpen());
}

GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico = nullptr;
