#pragma once
#include "Jogador.h"
#include "Personagem.h"
#include <math.h>

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo : public Personagem
		{
		protected:
			static Jogador* pJogador;
			sf::Vector2f range;

		public:
			Inimigo(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, unsigned int vida, sf::Vector2f range);
			~Inimigo();
			static void setJogador(Jogador* pJ);
			virtual void executar() = 0;
			void perseguir();
			void andarDir();
			void andarEsq();
			void operator--();
			virtual void interagir() = 0;
		};
	}
}