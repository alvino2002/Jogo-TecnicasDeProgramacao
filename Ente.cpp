#include "Ente.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "GerenciadorTempo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAnimacao.h"

namespace Masmorra
{
	Ente::Ente() :
		pGG(nullptr),
		pGE(nullptr),
		pGC(nullptr),
		pGT(nullptr),
		pGA(nullptr)
	{
		pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
		pGE = Gerenciadores::GerenciadorEvento::getGerenciadorEvento();
		pGC = Gerenciadores::GerenciadorColisao::getGerenciadorColisao();
		pGT = Gerenciadores::GerenciadorTempo::getGerenciadorTempo();
		pGA = Gerenciadores::GerenciadorAnimacao::getGerenciadorAnimacao();
	}

	Ente:: ~Ente()
	{
		pGG = nullptr;
		pGE = nullptr;
		pGC = nullptr;
		pGT = nullptr;
		pGA = nullptr;
	}
}