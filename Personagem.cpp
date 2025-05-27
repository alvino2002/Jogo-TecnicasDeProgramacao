#include "Personagem.h"

namespace Entidades

{
	namespace Personagens
	{
		Personagem::Personagem(sf::Vector2f tam, sf::Vector2f posInicial, sf::Vector2f velocidade, int v) :
			Entidade(tam, posInicial, velocidade),
			vida(v)
		{
		}

		Personagem::~Personagem()
		{
		}

		void Personagem::setVida(int v)
		{
			vida = v;
		}

		int Personagem::getVida()
		{
			return vida;
		}

		void Personagem::setVivo(bool v)
		{
			if (v == false)
			{
				setAtivo(false); // Personagem nao esta mais ativo no jogo
			}
		}
	}
}