#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Fogo.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Mago : public Inimigo
			{
			private:
				Listas::ListaEntidades listaDeProjeteis;
				sf::Clock tempoLancamento;  // Temporizador para lancar o projetil
				float recargaLancamento;  // Tempo de espera entre recargas
				bool lancamentoPronto;
				int chamas;

			public:
				Mago(
					int id,
					sf::Vector2f tamanho,
					sf::Vector2f posicao,
					sf::Vector2f velocidade,
					int vida,
					int nivelMaldade,
					sf::Vector2f alcance,
					sf::Texture* textura,
					sf::Vector2u imageCount
				);
				~Mago();
				void executar();
				void criarFogo();
				void danificar(Jogador* pJ);
				void queimar(Jogador* pJ);
			};
		}
	}
}
