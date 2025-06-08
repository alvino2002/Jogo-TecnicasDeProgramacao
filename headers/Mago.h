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
				Gerenciadores::GerenciadorAnimacao* pGA;
				Listas::ListaEntidades listaDeProjeteis;
				sf::Clock tempoLancamento;  // Temporizador para lancar o projetil
				float recargaLancamento;  // Tempo de espera entre recargas
				bool lancamentoPronto;

			public:
				Mago(
					sf::Vector2f tamanho,
					sf::Vector2f posicaoInicial,
					sf::Vector2f velocidade,
					int vida,
					sf::Vector2f alcance,
					sf::Texture* textura,
					sf::Vector2u imageCount
				);
				~Mago();
				void executar();
				void criarFogo();
				void interagir(Jogador* pJ);
			};
		}
	}
}
