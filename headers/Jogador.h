#pragma once
#include "Personagem.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Jogador : public Personagem
			{
			protected:
				sf::Clock tempoInvulneravel;
				float duracaoInvulneravel;
				bool invulneravel;
				sf::Vector2f velAtual;
				static int pontuacao;
				float pulo;

			public:
				Jogador(
					int id, 
					sf::Vector2f tamanho, 
					sf::Vector2f posicao,
					sf::Vector2f velocidade, 
					int vida, 
					float pulo
				);
				~Jogador();
				virtual void executar() = 0;;
				void sofrerDano(int d);
				void invulnerabilizar();
				void setInvulneravel(bool imune);
				bool getInvulneravel();
				void setPosicao(sf::Vector2f pos);
				float getVelocidadeAtualX();
				void setVelocidadeAtualX(float vX);
				static void derrotarAranha(); // Metodo para definir a pontuacao
				static void derrotarEsqueleto();
				static void derrotarMago();
				static void perderPonto();
				static int getPontuacao();
				static void setPontuacao(int pontos);
			};
		}
	}
}
