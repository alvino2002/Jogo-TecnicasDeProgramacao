#pragma once
#include "Inimigo.h"
#include "GerenciadorAnimacao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Esqueleto : public Inimigo
			{
			private:
				int batida;

			public:
				Esqueleto(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelMaldade,
					sf::Vector2f range,
					sf::Texture* textura,
					sf::Vector2u imageCount
				);
				~Esqueleto();
				void executar();
				void danificar(Jogador* pJ);
				void bater(Jogador* pJ);
			};
		}
	}
}
