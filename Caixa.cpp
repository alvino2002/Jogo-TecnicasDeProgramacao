#include "Caixa.h"
#include "GerenciadorColisao.h"
#include <iostream>

namespace Entidades
{
	namespace Obstaculos
	{
		Caixa::Caixa(const sf::Vector2f tam, sf::Vector2f posIni) :
			Obstaculo(tam, posIni)
		{
		}
		Caixa::~Caixa()
		{
		}
		void Caixa::executar()
		{
			if (!naSuperficie)
			{
				float deltaTime = pGT->getDeltaTime();
				aplicarGravidade(deltaTime);
			}
		}

		void Caixa::interagir()
		{
			sf::Vector2f posicao_Jogador = pJogador->getCorpo().getPosition();
			sf::Vector2f tamanho_Jogador = pJogador->getCorpo().getSize();
			sf::Vector2f posicao_Caixa = getCorpo().getPosition();
			sf::Vector2f tamanho_Caixa = getCorpo().getSize();

			if (pGC->getIntersectX() > pGC->getIntersectY()) // Colisão horizontal
			{
				float deltaTime = pGT->getDeltaTime();
				float velocidadeX = pJogador->getVelocidadeX();

				float deslocamentoCaixa = (velocidadeX) * 0.5f * deltaTime; // Jogador vai ter sua velocidade reduzida pela metade

				if (posicao_Jogador.x < posicao_Caixa.x) // Jogador empurrando a caixa para a direita
				{
					posicao_Jogador.x = posicao_Caixa.x - tamanho_Jogador.x;
					posicao_Caixa.x += deslocamentoCaixa;

				}
				else // Jogador empurrando a caixa para a esquerda
				{
					posicao_Jogador.x = posicao_Caixa.x + tamanho_Caixa.x;
					posicao_Caixa.x -= deslocamentoCaixa;
				}

				getCorpo().setPosition(posicao_Caixa);
				pJogador->setPosicao(posicao_Jogador);
			}
			else // Colisão vertical 
			{
				if (posicao_Jogador.y < posicao_Caixa.y)
				{
					posicao_Jogador.y = posicao_Caixa.y - tamanho_Jogador.y;
					pJogador->setNaCaixa(true);
				}
				else
				{
					posicao_Jogador.y = posicao_Caixa.y + tamanho_Caixa.y;
				}

				pJogador->setPosicao(posicao_Jogador);
			}
		}

	}
}


