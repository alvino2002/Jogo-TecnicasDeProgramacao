#pragma once
#include "Obstaculo.h"
#include "GerenciadorAnimacao.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Lava : public Obstaculo
			{
			private:
				int dano;
				Gerenciadores::GerenciadorAnimacao* pGA;
			public:
				Lava(const sf::Vector2f tam, sf::Vector2f posIni, sf::Texture* texture, sf::Vector2u imageCount);
				~Lava();
				void executar();
				void interagir(Entidade* pE);
			};
		}
	}
}


