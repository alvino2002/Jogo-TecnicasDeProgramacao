#include "ObservadorPause.h"
#include "SFML/Graphics.hpp"
#include "EstadoPause.h"
#include "GerenciadorEstado.h"


using namespace Masmorra::Observadores;


ObservadorPause::ObservadorPause():
	Observador()
{
}


ObservadorPause::~ObservadorPause()
{
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
		pGEs->removerEstado(); // Removendo o proximo estado (Estado Fase)
		pGEs->removerEstado(); // Removendo o proximo estado (Estado Selecao)

	}

}
