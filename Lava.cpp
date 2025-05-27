#include "Lava.h"
#include "GerenciadorColisao.h"

class Ente;

namespace Entidades
{
	namespace Obstaculos
	{
		Lava::Lava(const sf::Vector2f tam, sf::Vector2f posIni):
			Obstaculo(tam, posIni),
			dano(2)
		{
			corpo.setFillColor(sf::Color::Red);
		}
		Lava::~Lava()
		{
		}
		void Lava::executar()
		{
			if (!naSuperficie)
			{
				float deltaTime = pGT->getDeltaTime();
				aplicarGravidade(deltaTime);
			}

		}

		void Lava::interagir()
		{
			sf::Vector2f posicao_Jogador = pJogador->getCorpo().getPosition();
			sf::Vector2f tamanho_Jogador = pJogador->getCorpo().getSize();
			sf::Vector2f posicao_Lava = getCorpo().getPosition();
			sf::Vector2f tamanho_Lava = getCorpo().getSize();

			if (pGC->getIntersectX() > pGC->getIntersectY())
			{
				if (posicao_Jogador.x < posicao_Lava.x)
				{
					posicao_Jogador.x += pGC->getIntersectX();
				}
				else
				{
					posicao_Jogador.x -= pGC->getIntersectX();
				}
			}

			else
			{
				if (posicao_Jogador.y < posicao_Lava.y) // Jogador por cima
				{
					posicao_Jogador.y += pGC->getIntersectY();
					pJogador->setNaLava(true);
					if (pJogador->getInvulneravel() == false)
					{
						pJogador->sofrerDano(dano);
						pJogador->invulnerabilizar();
					}
				}
				else
				{
					posicao_Jogador.y -= pGC->getIntersectY();
				}
				
			}

			pJogador->setPosicao(posicao_Jogador);
		}
	}
}