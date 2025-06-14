#pragma once
#include "Inimigo.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Aranha : public Inimigo
			{
			private:
				int mordida;
				int veneno;

			public:
				Aranha(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelMaldade,
					sf::Vector2f alcance,
					sf::Texture* textura,
					sf::Vector2u imageCount
				);
				~Aranha();
				void executar();
				void morder(Jogador* pJ);
				void aplicarVeneno();
				void danificar(Jogador* pJ); 
			};
		}
	}
}
