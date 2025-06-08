#pragma once
#include "Inimigo.h"
#include "GerenciadorAnimacao.h"
#include "GerenciadorTempo.h"

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
				Gerenciadores::GerenciadorAnimacao* pGA;

			public:
				Esqueleto(
					sf::Vector2f tamanho,
					sf::Vector2f posicaoInicial,
					sf::Vector2f velocidade,
					int vida,
					sf::Vector2f range,
					sf::Texture* textura,
					sf::Vector2u imageCount
				);
				~Esqueleto();
				void executar();
				void interagir(Jogador* pJ);
				void bater(Jogador* pJ);
			};
		}
	}
}
