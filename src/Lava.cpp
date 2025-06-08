#include "Lava.h"
#include "GerenciadorColisao.h"


using namespace Masmorra::Entidades::Obstaculos;


Lava::Lava(const sf::Vector2f tam, sf::Vector2f posIni, sf::Texture* texture, sf::Vector2u imageCount):
	Obstaculo(tam, posIni),
	dano(2)
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(texture);
	corpo.setTextureRect(sf::IntRect(0, 0, tam.x, tam.y));
	pGG->desenharElementos(corpo);
}

Lava::~Lava()
{
}

void Lava::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}

}

void Lava::interagir(Entidade* pE)
{
	sf::Vector2f posicao_Jogador = pE->getCorpo().getPosition();
	sf::Vector2f tamanho_Jogador = pE->getCorpo().getSize();
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
			pE->setNaSuperficie(true);
			{
				Personagens::Jogador* pJ = static_cast<Personagens::Jogador*>(pE);
				if (pJ->getInvulneravel() == false)
				{
					pJ->sofrerDano(dano);
					pJ->invulnerabilizar();
				}
			}
		}
		else
		{
			posicao_Jogador.y -= pGC->getIntersectY();
		}
	}
	pE->setPosicao(posicao_Jogador);
}

