#include "ObservadorSelecaoSeg.h"
#include "GerenciadorEstado.h"
#include "GerenciadorTempo.h"
#include "EstadoSegundaFase.h"


using namespace Masmorra::Observadores;


ObservadorSelecaoSeg::ObservadorSelecaoSeg() :
	Observador()
{
}


ObservadorSelecaoSeg::~ObservadorSelecaoSeg()
{
}


void ObservadorSelecaoSeg::notificarEvento(const std::string& evento)
{
	if (evento == "1 JOGADOR")
	{
		Estados::EstadoSegundaFase* estado = new Estados::EstadoSegundaFase(1);
		pGEs->adicionarEstado(estado);
	}

	if (evento == "2 JOGADOR")
	{
		Estados::EstadoSegundaFase* estado = new Estados::EstadoSegundaFase(2);
		pGEs->adicionarEstado(estado);
	}

	if (evento == "VOLTAR")
	{
		pGEs->removerEstado(); // Voltar ao Menu, removendo o estado atual, no caso SelecaoSeg
	}
}


