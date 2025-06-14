#pragma once
#include "Cavaleiro.h"
#include "Jogador.h"
#include "GerenciadorTempo.h"
#include "GerenciadorAnimacao.h"


namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Curandeira : public Jogador
			{
			private:
				bool olhandoDireita;
				sf::Clock tempoCura;  // Temporizador para a cura
				float recargaCura;  // Tempo de espera entre curas
				bool curaPronta;
				bool curaAliado;
				Cavaleiro* pCavaleiro;

			public:
				Curandeira(
					int id, 
					sf::Vector2f tamanho, 
					sf::Vector2f posicao, 
					sf::Vector2f velocidade, 
					int vida, 
					float pulo,
					sf::Texture* texture, 
					sf::Vector2u imageCount
				);
				~Curandeira();
				void setCavaleiro(Cavaleiro* pCa); // Conhecer o cavaleiro
				void executar();
				void curar(); // Curar a si mesma
				void curarAliado();
			};
		}
	}
}
