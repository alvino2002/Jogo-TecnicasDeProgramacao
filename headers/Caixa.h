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
				Gerenciadores::GerenciadorAnimacao* pGA;

			public:
				Caixa(const sf::Vector2f tam, sf::Vector2f posIni, sf::Texture* texture, sf::Vector2u imageCount);
				~Caixa();
				void executar();
				void interagir(Entidade* pE); // Obstacularizar;
			};
		}
	}
}
