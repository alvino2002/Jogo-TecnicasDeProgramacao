#include "Plataforma.h"
#include "GerenciadorColisao.h"


using namespace Masmorra::Entidades::Obstaculos;


Plataforma::Plataforma(const sf::Vector2f tam, sf::Vector2f posIni, sf::Texture* texture, sf::Vector2u imageCount) :
	Obstaculo(tam, posIni)
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(texture);
	corpo.setTextureRect(sf::IntRect(0, 0, tam.x, tam.y));
	pGG->desenharElementos(corpo);
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar()
{
	aplicarGravidade(pGT->getDeltaTempo());
}


void Plataforma::interagir(Entidade* pE)
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
				posicao_Entidade.y += pGC->getIntersectY();
				pE->setNaSuperficie(true);
		}
		else
		{
			posicao_Entidade.y -= pGC->getIntersectY();
		}
		pE->setVelocidadeY(0.0f);
	}

	pE->setPosicao(posicao_Entidade);
}
