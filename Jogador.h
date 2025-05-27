#pragma once
#include "Personagem.h"

namespace Entidades
{
	namespace Personagens
	{
		class Jogador : public Personagem
		{
		private:
			bool estaAtacando;
			int dano;
			float pulo;
			sf::Clock tempoInvulneravel;
			float duracaoInvulneravel;
			bool invulneravel;
			sf::Clock tempoRecuperar;
			float duracaoRecuperacao;
			int energia;
			sf::Vector2f velAtual;
			bool naCaixa;
			bool naLava;
			bool olhandoDireita;

		public:
			Jogador(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
				    sf::Texture* texture, sf::Vector2u imageCount);
			~Jogador();
			void executar();
			bool getEstaAtacando();
			void setEstaAtacando(bool atacando);
			int getDano();
			void sofrerDano(int d);
			void invulnerabilizar();
			void setInvulneravel(bool imune);
			bool getInvulneravel();
			int getEnergia();
			void operator--();
			void recuperar();
			void setNaCaixa(bool caixa);
			void setNaLava(bool lava);
			void setPosicao(sf::Vector2f pos);
			float getVelocidadeAtualX();
			void setVelocidadeAtualX(float vX);
			sf::Clock tempoAtaque;  // Temporizador para o ataque
			float recargaAtaque;  // Tempo de espera entre ataques
			bool ataquePronto;
		};
	}
}