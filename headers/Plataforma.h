#pragma once
#include "Obstaculo.h"
#include "Fogo.h"
#include "GerenciadorAnimacao.h"
#include "GerenciadorGrafico.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Plataforma : public Obstaculo
			{
			private:
				Gerenciadores::GerenciadorAnimacao* pGA;
			public:
				Plataforma(const sf::Vector2f tam, sf::Vector2f posIni, sf::Texture* texture, sf::Vector2u imageCount);
				~Plataforma();
				void executar();
				void interagir(Entidade* pE);
			};

		}
	}
}
