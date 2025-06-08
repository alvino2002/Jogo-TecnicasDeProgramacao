#pragma once
#include "Jogador.h"
#include "GerenciadorAnimacao.h"
#include "GerenciadorTempo.h"

namespace Masmorra
{
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
				sf::Clock tempoRecuperar; // Temporalizador para a energia
				float duracaoRecuperacao; // Tempo para recuperar energia
				sf::Clock tempoAtaque;  // Temporizador para o ataque
				float recargaAtaque;  // Tempo de espera entre ataques
				bool ataquePronto;
				static int inimigosEliminados; // Apenas cavaleiro consegue eliminar 
				Gerenciadores::GerenciadorAnimacao* pGA;

			public:
				Cavaleiro(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
					sf::Texture* texture, sf::Vector2u imageCount);
				~Cavaleiro();
				void executar();
				bool getEstaAtacando()const;
				void setEstaAtacando(bool atacando);
				int getDano()const;
				void operator--(); // Decrementar energia
				void recuperar();
				void operator++(); // Incrementar numero de inimigos eliminados
				static int getInimigosEliminados();
				static void setInimigosEliminados(int numeroInimigos);
				static void zerarInimigosEliminados();
			};
		}
	}
}
