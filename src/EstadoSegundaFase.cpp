#include "EstadoSegundaFase.h"


using namespace Masmorra::Estados;

EstadoSegundaFase::EstadoSegundaFase(int qtdeJogadores):
	Estado()
{
	pSegFase = new Fases::SegundaFase(qtdeJogadores);
	pObs = new Observadores::ObservadorSegundaFase();
	//pObs->setSegundaFase(pSegFase);
}

EstadoSegundaFase::~EstadoSegundaFase()
{
	pSegFase = nullptr;
	pObs = nullptr;
}

void EstadoSegundaFase::executar()
{
	pSegFase->executar();
}

void EstadoSegundaFase::verificarEvento()
{
	if (pObs)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) // Pause
		{
			pObs->notificarEvento("PAUSE");
		}

		if (pSegFase->getFimDaFase()) // Fim do jogo
		{
			pObs->notificarEvento("FIM");
		}

		if (pSegFase->getVenceu()) // Fim do jogo
		{
			pObs->notificarEvento("VENCEU");
		}
	}

	

	
}
