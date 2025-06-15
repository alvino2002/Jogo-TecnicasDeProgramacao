#include "Caixa.h"


using namespace Masmorra::Entidades::Obstaculos;


Caixa::Caixa(int id, sf::Vector2f tam, sf::Vector2f posicao, sf::Texture* texture, sf::Vector2u imageCount) :
	Obstaculo(id, tam, posicao),
	lentidao(0.5f)
{
	corpo.setTexture(texture);
	pGA->pegarAnimacao(texture, imageCount);
}

Caixa::~Caixa()
{
}

void Caixa::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}
}

void Caixa::obstacularizar(Entidade* pE)
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
			float deslocamentoCaixa = velocidadeX * lentidao * deltaTime; // Ha uma desaceleracao ao empurrar

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
		getCorpo().setPosition(posicao_Caixa);
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
		pE->setVelocidadeY(0.0f);
	}
	pE->setPosicao(posicao_Entidade);
}
