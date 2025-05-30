#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades
{
	class Fogo: public Entidade
	{
	private:
		int dano;
		Personagens::Jogador* pJogador;

	public:
		Fogo(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel);
		~Fogo();
		void executar();
		void interagir(Personagens::Jogador* pJ);
		void setJogador(Personagens::Jogador* pJ);
	};
}
