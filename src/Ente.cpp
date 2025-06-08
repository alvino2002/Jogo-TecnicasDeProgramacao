#include "Ente.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "GerenciadorTempo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"


using namespace Masmorra;

Ente::Ente() 
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

Gerenciadores::GerenciadorGrafico* Ente::pGG = nullptr;
Gerenciadores::GerenciadorEvento* Ente::pGE = nullptr;
Gerenciadores::GerenciadorColisao* Ente::pGC = nullptr;
Gerenciadores::GerenciadorTempo* Ente::pGT = nullptr;
Gerenciadores::GerenciadorEstado* Ente::pGEs = nullptr;


