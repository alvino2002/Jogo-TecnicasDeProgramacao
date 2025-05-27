#pragma once
#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Lava : public Obstaculo
		{
		private:
			int dano;

		public:
			Lava(const sf::Vector2f tam, sf::Vector2f posIni);
			~Lava();
			void executar();
			void interagir();
		};
	}
}



