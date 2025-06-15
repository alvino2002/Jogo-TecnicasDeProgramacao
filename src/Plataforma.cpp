#include "Plataforma.h"
#include "GerenciadorColisao.h"


using namespace Masmorra::Entidades::Obstaculos;


Plataforma::Plataforma(int id, sf::Vector2f tam, sf::Vector2f posicao, sf::Texture* texture, sf::Vector2u imageCount, bool arm) :
	Obstaculo(id, tam, posicao),
	armadilha(arm)
{
	corpo.setTexture(texture);
	corpo.setTextureRect(sf::IntRect(0, 0, tam.x, tam.y));
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar()
{
	float deltaTempo = pGT->getDeltaTempo();
	aplicarGravidade(deltaTempo);
	flutuar(deltaTempo);
}


void Plataforma::obstacularizar(Entidade* pE)
{
	sf::Vector2f posicao_Entidade = pE->getCorpo().getPosition();
	sf::Vector2f tamanho_Entidade = pE->getCorpo().getSize();
	sf::Vector2f posicao_Plataforma = getCorpo().getPosition();
	sf::Vector2f tamanho_Plataforma = getCorpo().getSize();

	if (pGC->getIntersectX() > pGC->getIntersectY())
	{
		if (posicao_Entidade.x < posicao_Plataforma.x)
		{
			posicao_Entidade.x += pGC->getIntersectX();
		}
		else
		{
			posicao_Entidade.x -= pGC->getIntersectX();
		}
	}

	else
	{
		if (posicao_Entidade.y < posicao_Plataforma.y)
		{
			if (armadilha)
			{
				Personagens::Jogador* pJ = static_cast<Personagens::Jogador*>(pE);
				if (pJ->getInvulneravel() == false)
				{
					pJ->sofrerDano(1);
					pJ->invulnerabilizar();
				}
			}
			posicao_Entidade.y = posicao_Plataforma.y - tamanho_Entidade.y;
			pE->setNaSuperficie(true);
		}
		else
		{
			posicao_Entidade.y = posicao_Plataforma.y + tamanho_Plataforma.y;
		}
		pE->setVelocidadeY(0.0f);
	}

	pE->setPosicao(posicao_Entidade);
}


void Plataforma::flutuar(float deltaTempo)
{
	corpo.move(0.0f, -velocidade.y * deltaTempo);
}
