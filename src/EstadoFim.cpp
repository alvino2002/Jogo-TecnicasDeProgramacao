#include "EstadoFim.h"


using namespace Masmorra::Estados;


EstadoFim::EstadoFim() :
	Estado()
{
	pFim = new Fim();
	pObs = new Observadores::ObservadorFim();
}

EstadoFim::~EstadoFim()
{
	pFim = nullptr;
	pObs = nullptr;
}

void EstadoFim::executar()
{
	pFim->executar();
}

void EstadoFim::verificarEvento()
{
	if (pObs)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			pObs->notificarEvento("SAIR");
		}
	}
}
