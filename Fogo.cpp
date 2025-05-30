#include "Fogo.h"
#include "GerenciadorTempo.h"
#include "GerenciadorColisao.h"

namespace Entidades
{
	Fogo::Fogo(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel):
		Entidade(tam, posIni, vel),
		dano(3),
		pJogador()
	{
	}

	Fogo::~Fogo()
	{
	}

	void Fogo::executar()
	{
		float deltaTime = pGT->getDeltaTime();
		corpo.move(velocidade * deltaTime);
	}

	void Fogo::setJogador(Personagens::Jogador* pJ)
	{
		if (pJ)
		{
			pJogador = pJ;
		}
	}

	void Fogo::interagir(Personagens::Jogador* pJ)
	{
		if (pJ->getInvulneravel() == false)
		{
			pJ->sofrerDano(dano);
			pJ->invulnerabilizar();
		}
	
		setAtivo(false);
	}
}