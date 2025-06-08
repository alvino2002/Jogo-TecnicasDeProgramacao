#include "Caixa.h"
#include <iostream>

using namespace Masmorra::Entidades::Obstaculos;


Caixa::Caixa(const sf::Vector2f tam, sf::Vector2f posIni, sf::Texture* texture, sf::Vector2u imageCount) :
	Obstaculo(tam, posIni)
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(texture);
	pGA->pegarAnimacao(texture, imageCount);
}

Caixa::~Caixa()
{
	pGA = nullptr;
}

void Caixa::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}
	naSuperficie = false;
}

void Caixa::interagir(Entidade* pE)
{
	sf::Vector2f posicao_Entidade = pE->getCorpo().getPosition();
	sf::Vector2f tamanho_Entidade = pE->getCorpo().getSize();
	sf::Vector2f posicao_Caixa = getCorpo().getPosition();
	sf::Vector2f tamanho_Caixa = getCorpo().getSize();

	bool ehCavaleiro = dynamic_cast<Personagens::Cavaleiro*>(pE) != nullptr;

	if (pGC->getIntersectX() > pGC->getIntersectY())
	{
		if (ehCavaleiro) // Apenas o cavaleiro consegue empurrar a caixa
		{
			float deltaTime = pGT->getDeltaTempo();
			float velocidadeX = pCavaleiro->getVelocidadeX();
			float deslocamentoCaixa = velocidadeX * 0.5f * deltaTime; // Ha uma desaceleracao ao empurrar

			if (posicao_Entidade.x < posicao_Caixa.x) // Empurra para direita
			{
				posicao_Entidade.x = posicao_Caixa.x - tamanho_Entidade.x;
				posicao_Caixa.x += deslocamentoCaixa;
			}
			else  // Empurra para esquerda
			{
				posicao_Entidade.x = posicao_Caixa.x + tamanho_Caixa.x;
				posicao_Caixa.x -= deslocamentoCaixa;
			}

			getCorpo().setPosition(posicao_Caixa);
		}

		else 
		{
			if (posicao_Entidade.x < posicao_Caixa.x)
			{
				posicao_Entidade.x += pGC->getIntersectX();
			}
			else
			{
				posicao_Entidade.x -= pGC->getIntersectX();
			}
		}
	}
	else // Colisão vertical
	{
		if (posicao_Entidade.y < posicao_Caixa.y)
		{
			posicao_Entidade.y = posicao_Caixa.y - tamanho_Entidade.y;

			pE->setNaSuperficie(true);
		}
		else
		{
			posicao_Entidade.y = posicao_Caixa.y + tamanho_Caixa.y;
		}
	}

	pE->setPosicao(posicao_Entidade);

}



