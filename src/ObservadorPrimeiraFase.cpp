#include "ObservadorPrimeiraFase.h"
#include "EstadoPause.h"
#include <iostream>
#include "EstadoSegundaFase.h"
#include "GerenciadorEstado.h"
#include "EstadoRanking.h"
#include "EstadoFim.h"
#include "Fase.h"


using namespace Masmorra::Observadores;


ObservadorPrimeiraFase::ObservadorPrimeiraFase() :
	Observador(),
	pPrim()
{
}

ObservadorPrimeiraFase::~ObservadorPrimeiraFase()
{

}

void ObservadorPrimeiraFase::notificarEvento(const std::string& evento)
{
	if (evento == "PAUSE")
	{
		Estados::EstadoPause* pause = new Estados::EstadoPause();
		pGEs->adicionarEstado(pause);
	}

	if (evento == "FIM")
	{
		Estados::EstadoFim* fim = new Estados::EstadoFim();
		pGEs->adicionarEstado(fim);
	}

	if (evento == "AVANCAR")
	{
		pGEs->removerEstado(); // Removendo o estado atual no topo, no caso EstadoPrimeiraFase
		if (pPrim->getQtdeJogadores() == 1)
		{
			Estados::EstadoSegundaFase* segundaFase = new Estados::EstadoSegundaFase(1);
			pGEs->adicionarEstado(segundaFase);
		}
		else
		{
			Estados::EstadoSegundaFase* segundaFase = new Estados::EstadoSegundaFase(2);
			pGEs->adicionarEstado(segundaFase);
		}
	}
}

void ObservadorPrimeiraFase::setPrimeiraFase(Fases::PrimeiraFase* pP)
{
	if (pP)
	{
		pPrim = pP;
	}
}
