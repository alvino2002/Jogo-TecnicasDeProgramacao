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

			public:
				Lava(
					int id, 
					sf::Vector2f tam, 
					sf::Vector2f posicao, 
					sf::Texture* textura, 
					sf::Vector2u imageCount
				);
				~Lava();
				void executar();
				void obstacularizar(Entidade* pE);
			};
		}
	}
}


