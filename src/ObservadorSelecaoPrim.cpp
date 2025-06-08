#include "ObservadorSelecaoPrim.h"
#include "GerenciadorEstado.h"
#include "GerenciadorTempo.h"
#include "EstadoPrimeiraFase.h"


using namespace Masmorra::Observadores;


ObservadorSelecaoPrim::ObservadorSelecaoPrim() :
	Observador()
{
}


ObservadorSelecaoPrim::~ObservadorSelecaoPrim()
{
}


void ObservadorSelecaoPrim::notificarEvento(const std::string& evento)
{
	if (evento == "1 JOGADOR")
	{
		Estados::EstadoPrimeiraFase* estado = new Estados::EstadoPrimeiraFase(1);
		pGEs->adicionarEstado(estado);
	}

	if (evento == "2 JOGADOR")
	{
		Estados::EstadoPrimeiraFase* estado = new Estados::EstadoPrimeiraFase(2);
		pGEs->adicionarEstado(estado);
	}

	if (evento == "VOLTAR")
	{
		pGEs->removerEstado(); // Voltar ao Menu, removendo o estado atual, no caso SelecaoPrim
	}
}


