#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Personagem : public Entidade
			{
			protected:
				int vida;
				bool olhandoDireita;

			public:
				Personagem(sf::Vector2f tam, sf::Vector2f posInicial, sf::Vector2f velocidade, int v);
				~Personagem();
				void setVida(int v);
				int getVida();
				void setVivo(bool v);
				bool getOlhandoDireita();
				virtual void executar() = 0;
			};
		}
	}
}
