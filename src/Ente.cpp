#include "Ente.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "GerenciadorTempo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"


using namespace Masmorra;

Ente::Ente() :
	pGG(nullptr),
	pGE(nullptr),
	pGC(nullptr),
	pGT(nullptr),
	pGEs(nullptr)
{
	pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	pGE = Gerenciadores::GerenciadorEvento::getGerenciadorEvento();
	pGC = Gerenciadores::GerenciadorColisao::getGerenciadorColisao();
	pGT = Gerenciadores::GerenciadorTempo::getGerenciadorTempo();
	pGEs = Gerenciadores::GerenciadorEstado::getGerenciadorEstado();

}

Ente::~Ente()
{
}
