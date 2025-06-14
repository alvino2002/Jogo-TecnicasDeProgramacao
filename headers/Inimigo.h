#pragma once
#include "Jogador.h"
#include "Personagem.h"
#include "Cavaleiro.h"
#include "Curandeira.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Inimigo : public Personagem
			{
			protected:
				static Cavaleiro* pCavaleiro;
				static Curandeira* pCurandeira;
				sf::Vector2f alcance;
				int nivelDeMaldade;

			public:
				Inimigo(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelDeMal,
					sf::Vector2f alcance
				);
				~Inimigo();
				static void setCavaleiro(Cavaleiro* pCa);
				static void setCurandeira(Curandeira* pCu);
				Jogador* getMaisProximo();
				virtual void executar() = 0;
				void perseguir();
				void andarDir();
				void andarEsq();
				virtual void danificar(Jogador* pJ) = 0;
			};
		}
	}
}
