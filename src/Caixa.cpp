#include "Caixa.h"


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
		float deltaTime = pGT->getDeltaTime();
		aplicarGravidade(deltaTime);
	}
}

void Caixa::interagir(Personagens::Jogador* pJ)
{
	sf::Vector2f posicao_Jogador = pJ->getCorpo().getPosition();
	sf::Vector2f tamanho_Jogador = pJ->getCorpo().getSize();
	sf::Vector2f posicao_Caixa = getCorpo().getPosition();
	sf::Vector2f tamanho_Caixa = getCorpo().getSize();

	bool ehCavaleiro = dynamic_cast<Personagens::Cavaleiro*>(pJ) != nullptr;

	if (pGC->getIntersectX() > pGC->getIntersectY())
	{
		if (ehCavaleiro) // Apenas o cavaleiro consegue empurrar a caixa
		{
			float deltaTime = pGT->getDeltaTime();
			float velocidadeX = pCavaleiro->getVelocidadeX();
			float deslocamentoCaixa = velocidadeX * 0.5f * deltaTime; // Ha uma desaceleracao ao empurrar

			if (posicao_Jogador.x < posicao_Caixa.x) // Empurra para direita
			{
				posicao_Jogador.x = posicao_Caixa.x - tamanho_Jogador.x;
				posicao_Caixa.x += deslocamentoCaixa;
			}
			else  // Empurra para esquerda
			{
				posicao_Jogador.x = posicao_Caixa.x + tamanho_Caixa.x;
				posicao_Caixa.x -= deslocamentoCaixa;
			}

			getCorpo().setPosition(posicao_Caixa);
		}

		else // Curandeira
		{
			if (posicao_Jogador.x < posicao_Caixa.x)
			{
				posicao_Jogador.x += pGC->getIntersectX();
			}
			else
			{
				posicao_Jogador.x -= pGC->getIntersectX();
			}
		}
	}
	else // Colisão vertical
	{
		if (posicao_Jogador.y < posicao_Caixa.y)
		{
			posicao_Jogador.y = posicao_Caixa.y - tamanho_Jogador.y;

			pJ->setNaCaixa(true);
		}
		else
		{
			posicao_Jogador.y = posicao_Caixa.y + tamanho_Caixa.y;
		}
	}

	pJ->setPosicao(posicao_Jogador);
}




