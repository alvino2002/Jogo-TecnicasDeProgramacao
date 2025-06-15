#include "EstadoPrimeiraFase.h"
#include "GerenciadorColisao.h"


using namespace Masmorra::Estados;


EstadoPrimeiraFase::EstadoPrimeiraFase(int qtdeJogadores) :
	Estado()
{
	pPrimFase = new Fases::PrimeiraFase(2, qtdeJogadores);
	pObs = new Observadores::ObservadorPrimeiraFase();
	pObs->setPrimeiraFase(pPrimFase);
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

		if (pPrimFase->getFimDaFase()) 
		{
			pObs->notificarEvento("FIM");// Fim do jogo
		}

		if (pPrimFase->getAvance())
		{
			pObs->notificarEvento("AVANCAR"); // Avancar para a segunda fase
		}
	}
}
