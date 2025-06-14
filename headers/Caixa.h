#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
#include "GerenciadorColisao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Caixa : public Obstaculo
			{
			private:
				float lentidao;

			public:
				Caixa(
					int id, 
					sf::Vector2f tam, 
					sf::Vector2f posicao, 
					sf::Texture* texture, 
					sf::Vector2u imageCount
				);
				~Caixa();
				void executar();
				void obstacularizar(Entidade* pE); 
			};
		}
	}
}
