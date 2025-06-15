#include "EstadoPause.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisao.h"
#include "PrimeiraFase.h"


using namespace Masmorra::Estados;

using namespace Masmorra::Interfaces;


EstadoPause::EstadoPause() :
	Estado()
{
	pPause = new Pause(2);
	pObs = new Observadores::ObservadorPause();
	pObs->setPause(pPause);
}

EstadoPause::~EstadoPause()
{
	pPause = nullptr;
	pObs = nullptr;
}

void EstadoPause::executar()
{
	pPause->executar();
	pGT->reiniciar(); // Devemos ressetar o relogio para que nao haja acumulo de velocidade 
}

void EstadoPause::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		if (pObs)
		{
			pObs->notificarEvento("DESPAUSE");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (pObs)
		{
			pObs->notificarEvento("SAIR");
		}
	}
}
