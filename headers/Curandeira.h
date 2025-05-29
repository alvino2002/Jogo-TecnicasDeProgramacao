#pragma once
#include "Cavaleiro.h"
#include "Jogador.h"
#include "GerenciadorAnimacao.h"

namespace Entidades
{
	namespace Personagens
	{
		class Curandeira : public Jogador
		{
		private:
			float pulo;
			sf::Vector2f velAtual;
			bool olhandoDireita;
			sf::Clock tempoCura;  // Temporizador para a cura
			float recargaCura;  // Tempo de espera entre curas
			bool curaPronta;
			bool curaAliado;
			Gerenciadores::GerenciadorAnimacao* pGa;
			Cavaleiro* pCavaleiro;

		public:
			Curandeira(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
				sf::Texture* texture, sf::Vector2u imageCount);
			~Curandeira();
			void setCavaleiro(Cavaleiro* pCa);
			void executar();
			void curar();
			void curarAliado();
		};
	}
}
