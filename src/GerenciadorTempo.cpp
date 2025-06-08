#include "GerenciadorTempo.h"


using namespace Masmorra::Gerenciadores;

	GerenciadorTempo::GerenciadorTempo():
		deltaTempo(),
		relogio()
	{
	}

	GerenciadorTempo::~GerenciadorTempo()
	{
	}

	GerenciadorTempo* GerenciadorTempo::getGerenciadorTempo()
	{
		if (pGerenciadorTempo == nullptr)
		{
			pGerenciadorTempo = new GerenciadorTempo();
		}
		else
		{
			return pGerenciadorTempo;
		}
	}

	void GerenciadorTempo::atualizar()
	{
		deltaTempo = relogio.restart().asSeconds();
	}

	float GerenciadorTempo::getDeltaTempo() const
	{
		return deltaTempo;
	}

	GerenciadorTempo* GerenciadorTempo::pGerenciadorTempo = nullptr;
