#include "EstadoMenu.h"

using namespace Masmorra::Estados;

using namespace Masmorra::Interfaces;



EstadoMenu::EstadoMenu():
	Estado()
{
	pMenu = new Menu(2);
	pObs = new Observadores::ObservadorMenu();
	pObs->setMenu(pMenu);
}

EstadoMenu::~EstadoMenu()
{
	pMenu = nullptr;
	pObs = nullptr;
}

void EstadoMenu::executar()
{
	pMenu->executar();
}

void EstadoMenu::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		if (pObs)
		{
			pObs->notificarEvento("PRIMEIRA FASE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (pObs)
		{
			pObs->notificarEvento("SEGUNDA FASE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		if (pObs)
		{
			pObs->notificarEvento("RANKING");
		}
	}
}
