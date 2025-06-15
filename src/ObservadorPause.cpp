#include "ObservadorPause.h"
#include "SFML/Graphics.hpp"
#include "EstadoPause.h"
#include "GerenciadorEstado.h"
#include "Fase.h"
#include "PrimeiraFase.h"


using namespace Masmorra::Observadores;


ObservadorPause::ObservadorPause():
	Observador(),
	pPause()
{
}


ObservadorPause::~ObservadorPause()
{
}


void ObservadorPause::setPause(Masmorra::Interfaces::Pause* pP)
{
	if (pP)
	{
		pPause = pP;
	}
}

void ObservadorPause::notificarEvento(const std::string& evento)
{
	if (evento == "DESPAUSE")
	{
		pGEs->removerEstado(); // Remover o topo
	}

	if (evento == "SAIR")
	{
		/*Voltar ao menu*/
		pGEs->removerEstado(); // Removendo o estado atual (Estado Pause)
		pGEs->removerEstado(); // Removendo o proximo estado da pilha (Estado Fase)
		pGEs->removerEstado(); // Removendo o proximo estado da pilha (Estado Selecao)
	}

}
