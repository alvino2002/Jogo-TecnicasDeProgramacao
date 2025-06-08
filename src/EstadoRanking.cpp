#include "EstadoRanking.h"

#include <iostream>

using namespace Masmorra::Estados;

EstadoRanking::EstadoRanking(int pontuacao) :
	Estado()
{
	pR = new Ranking(pontuacao);
	pObs = new Observadores::ObservadorRanking();
}

EstadoRanking::~EstadoRanking()
{
	pR = nullptr;
	pObs = nullptr;
}

void EstadoRanking::executar()
{
	pR->executar();
}

void EstadoRanking::verificarEvento()
{
}
