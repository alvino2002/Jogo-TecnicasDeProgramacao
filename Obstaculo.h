#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo : public Entidade
		{
		protected:
			static Personagens::Jogador* pJogador;
		public:
			Obstaculo(const sf::Vector2f tam, sf::Vector2f posIni);
			~Obstaculo();
			static void setJogador(Personagens::Jogador* pJ);
			virtual void executar() = 0;
			virtual void interagir() = 0; // Obstacularizar
		};
	}
}
