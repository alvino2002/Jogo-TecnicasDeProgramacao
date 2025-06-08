#include "Principal.h"
#include "EstadoMenu.h"


using namespace Masmorra;


Principal::Principal()
{
	pGEs = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();
	pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	pGE = Gerenciadores::GerenciadorEvento::getGerenciadorEvento();
}

Principal::~Principal()
{
	pGEs = nullptr;
	pGG = nullptr;
	pGE = nullptr;
}

void Principal::rodarJogo()
{
	Estados::EstadoMenu* estado = new Estados::EstadoMenu();
	pGEs->adicionarEstado(estado);

	while (pGG->verificaJanelaAberta())
	{
		pGE->executar();
		pGEs->executar();
	}
}
