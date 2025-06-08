#include "EstadoPause.h"
#include "GerenciadorGrafico.h"


using namespace Masmorra::Estados;


EstadoPause::EstadoPause() :
	Estado()
{
	pPause = new Pause();
	pObs = new Observadores::ObservadorPause();
}

EstadoPause::~EstadoPause()
{
	pPause = nullptr;
	pObs = nullptr;
}

void EstadoPause::executar()
{
	pPause->executar();
}

void EstadoPause::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (pObs)
		{
			pObs->notificarEvento("DESPAUSE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (pObs)
		{
			pObs->notificarEvento("SAIR");
		}
	}

}
