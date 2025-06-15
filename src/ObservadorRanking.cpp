#include "ObservadorRanking.h"
#include "GerenciadorEstado.h"


using namespace Masmorra::Observadores;


ObservadorRanking::ObservadorRanking() :
	Observador()
{
}

ObservadorRanking::~ObservadorRanking()
{
}

void ObservadorRanking::notificarEvento(const std::string& evento)
{
	if (evento == "VOLTAR")
	{
		pGEs->removerEstado();
	}
}


