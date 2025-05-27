#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(const sf::Vector2f tam, sf::Vector2f posIni) :
			Entidade(tam, posIni)
		{
		}
		Obstaculo::~Obstaculo()
		{
			pJogador = nullptr;
		}

		void Obstaculo::setJogador(Personagens::Jogador* pJ)
		{
			if (pJ)
			{
				pJogador = pJ;
			}
		}

		Personagens::Jogador* Obstaculo::pJogador = nullptr;

	}
}