#pragma once
#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		class Ogro : public Inimigo
	{
	private:
		int batida;

	public:
		Ogro(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade,
			unsigned int vida, sf::Vector2f range, sf::Texture* textura);
		~Ogro();
		void interagir();
		void bater();
		void executar();
	};
}
}
