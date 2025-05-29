#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
#include "GerenciadorTempo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Caixa : public Obstaculo
		{
		public:
			Caixa(const sf::Vector2f tam, sf::Vector2f posIni);
			~Caixa();
			void executar();
			void interagir(); // Obstacularizar
		};
	}
}
