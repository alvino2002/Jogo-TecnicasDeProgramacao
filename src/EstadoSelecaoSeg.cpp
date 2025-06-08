#include "EstadoSelecaoSeg.h"
#include "GerenciadorGrafico.h"


using namespace Masmorra::Estados;


EstadoSelecaoSeg::EstadoSelecaoSeg() :
	Estado()
{
	pSelecaoSegunda = new SelecaoSegunda();
	pObs = new Observadores::ObservadorSelecaoSeg();
}

EstadoSelecaoSeg::~EstadoSelecaoSeg()
{
	pSelecaoSegunda = nullptr;
	pObs = nullptr;
}

void EstadoSelecaoSeg::executar()
{
	pSelecaoSegunda->executar();
}

void EstadoSelecaoSeg::verificarEvento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		if (pObs)
		{
			pObs->notificarEvento("1 JOGADOR");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		if (pObs)
		{
			pObs->notificarEvento("2 JOGADOR");
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		if (pObs)
		{
			pObs->notificarEvento("VOLTAR");
		}
	}
}

