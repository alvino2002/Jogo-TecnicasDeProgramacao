#include "ObservadorSegundaFase.h"
#include "EstadoPause.h"
#include "EstadoRanking.h"
#include "EstadoFim.h"


using namespace Masmorra::Observadores;


ObservadorSegundaFase::ObservadorSegundaFase() :
	pSegFase(),
	Observador()
{

}

ObservadorSegundaFase::~ObservadorSegundaFase()
{

}

void ObservadorSegundaFase::notificarEvento(const std::string& evento)
{
	if (evento == "PAUSE")
	{
		Estados::EstadoPause* pause = new Estados::EstadoPause();
		pGEs->adicionarEstado(pause);
	}


    if (evento == "VENCEU")
    {
        pSegFase->escreverNome();

        pGEs->removerEstado(); // Remover o estado segunda fase
        pGEs->removerEstado(); // Remover o estado selecao
    }

	if (evento == "FIM")
	{
		Estados::EstadoFim* fim = new Estados::EstadoFim();
		pGEs->adicionarEstado(fim);
	}
}

void ObservadorSegundaFase::setSegundaFase(Fases::SegundaFase* pSF)
{
	if (pSF)
	{
		pSegFase = pSF;
	}
}
