#pragma once
#include "Jogador.h"
#include "GerenciadorAnimacao.h"

namespace Entidades
{
	namespace Personagens
	{
		class Cavaleiro : public Jogador
		{
		private:
			bool estaAtacando;
			int dano;
			float pulo;
			int energia;
			sf::Clock tempoRecuperar; // Tempo para recuperar energia
			float duracaoRecuperacao;
			sf::Clock tempoAtaque;  // Temporizador para o ataque
			float recargaAtaque;  // Tempo de espera entre ataques
			bool ataquePronto;
			Gerenciadores::GerenciadorAnimacao* pGA;

		public:
			Cavaleiro(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
				sf::Texture* texture, sf::Vector2u imageCount);
			~Cavaleiro();
			void executar();
			bool getEstaAtacando();
			void setEstaAtacando(bool atacando);
			int getDano();
			void operator--();
			void recuperar();
		};
	}
}

