#pragma once
#include "Inimigo.h"
#include "GerenciadorTempo.h"
#include "GerenciadorAnimacao.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Aranha : public Inimigo
			{
			private:
				short int mordida;
				short int veneno;
				Masmorra::Gerenciadores::GerenciadorAnimacao* pGA;

			public:
				Aranha(
					sf::Vector2f tamanho,
					sf::Vector2f posicaoInicial,
					sf::Vector2f velocidade,
					int vida,
					sf::Vector2f alcance,
					sf::Texture* textura,
					sf::Vector2u imageCount
				);
				~Aranha();
				void executar();
				void morder(Jogador* pJ);
				void aplicarVeneno();
				void interagir(Jogador* pJ);
			};
		}
	}
}
