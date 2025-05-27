#include "Plataforma.h"
#include "GerenciadorColisao.h"
#include <iostream>

namespace Entidades
{
	using namespace Obstaculos;

	Plataforma::Plataforma(const sf::Vector2f tam, sf::Vector2f posIni) :
		Obstaculo(tam, posIni)
	{
		pGC = Gerenciadores::GerenciadorColisao::getGerenciadorColisao();
	}

	Plataforma::~Plataforma()
	{
	}

	void Plataforma::executar()
	{
		float deltaTime = pGT->getDeltaTime();
		aplicarGravidade(deltaTime);
		flutuar();
	}

	void Plataforma::flutuar()
	{
		float deltaTime = pGT->getDeltaTime();
		velocidade.y -= gravidade * deltaTime;
		corpo.move(0.0f, velocidade.y * deltaTime);
	}

	void Plataforma::interagir()
	{
		sf::Vector2f posicao_Jogador = pJogador->getCorpo().getPosition();
		sf::Vector2f tamanho_Jogador = pJogador->getCorpo().getSize();
		sf::Vector2f posicao_Plataforma = getCorpo().getPosition();
		sf::Vector2f tamanho_Plataforma = getCorpo().getSize();


		if (pGC->getIntersectX() > pGC->getIntersectY())
		{
			if (posicao_Jogador.x < posicao_Plataforma.x)
			{
				posicao_Jogador.x += pGC->getIntersectX();
			}
			else
			{
				posicao_Jogador.x -= pGC->getIntersectX();
			}

			//pJogador->setVelocidadeX(0.0f);
		}

		else
		{
			if (posicao_Jogador.y < posicao_Plataforma.y)
			{
				posicao_Jogador.y += pGC->getIntersectY();
				pJogador->setNaSuperficie(true);
			}
			else
			{
				posicao_Jogador.y -= pGC->getIntersectY();
			}
			//pJogador->setVelocidadeY(0.0f);
		}

		pJogador->setPosicao(posicao_Jogador);

	}

	void Plataforma::interagirComEntidades(Entidade* pE)
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

			pE->setVelocidadeX(0.0f);
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
}