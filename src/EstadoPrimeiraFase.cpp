#include "EstadoPrimeiraFase.h"
#include <iostream>

using namespace Masmorra::Estados;


EstadoPrimeiraFase::EstadoPrimeiraFase(int qtdeJogadores) :
	Estado()
{
	pPrimFase = new Fases::PrimeiraFase(qtdeJogadores);
	pObs = new Observadores::ObservadorPrimeiraFase();
}

EstadoPrimeiraFase::~EstadoPrimeiraFase()
{
	pPrimFase = nullptr;
	pObs = nullptr;
}

void EstadoPrimeiraFase::executar()
{
	pPrimFase->executar();
}

void EstadoPrimeiraFase::verificarEvento()
{
	if (pObs)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			pObs->notificarEvento("PAUSE");
		}

		if (pPrimFase->getFimDaFase()) // Fim do jogo
		{
			pObs->notificarEvento("FIM");
		}

		if (pPrimFase->getAvance())
		{
			pObs->notificarEvento("AVANCAR"); // Avancar para a segunda fase
		}
	}
}
