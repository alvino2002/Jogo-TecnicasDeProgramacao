#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include "GerenciadorAnimacao.h"

namespace Masmorra
{
	namespace Entidades
	{
		class Fogo : public Entidade
		{
		private:
			int dano;
			bool sentido;

		public:
			Fogo(
				int id, 
				const sf::Vector2f tam, 
				sf::Vector2f posicao, 
				sf::Vector2f vel,
				sf::Texture* textura,
				sf::Vector2u imageCount,
				bool direita
			);
			~Fogo();
			void executar();
			void atingir(Personagens::Jogador* pJ);
		};
	}
}
