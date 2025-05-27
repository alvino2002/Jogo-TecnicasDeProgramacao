#pragma once
#include "Personagem.h"
#include "GerenciadorTempo.h"
#include "Inimigo.h"


namespace Entidades
{
	namespace Personagens
	{
		class Aranha : public Inimigo
		{
		private:
			short int mordida;
			short int veneno;

		public:
			Aranha(
				sf::Vector2f tamanho,
				sf::Vector2f posicaoInicial,
				sf::Vector2f velocidade,
				int vida,
				sf::Vector2f alcance
			);
			~Aranha();
			void executar();
			void morder();
			void aplicarVeneno();
			void interagir();
		};
	}
}
