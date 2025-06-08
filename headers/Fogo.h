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
			Gerenciadores::GerenciadorAnimacao* pGA;
			int dano;

		public:
			Fogo(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel,
				sf::Texture* textura,
				sf::Vector2u imageCount);
			~Fogo();
			void executar();
			void interagir(Personagens::Jogador* pJ);
		};
	}
}
