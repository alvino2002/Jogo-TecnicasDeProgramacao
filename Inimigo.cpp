#include "Inimigo.h"
#include "GerenciadorTempo.h"



namespace Entidades
{
	namespace Personagens
	{
		Inimigo::Inimigo(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, unsigned int vida, sf::Vector2f range):
			Personagem(tamanho, posicaoInicial, velocidade, vida),
			range(range)
		{

		}
		Inimigo::~Inimigo()
		{

		}
		void Inimigo::setJogador(Jogador* pJ)
		{
			if (pJ)
			{
				pJogador = pJ;
			}
		}

		void Inimigo::perseguir()
		{

			if (fabs(pJogador->getCorpo().getPosition().y - corpo.getPosition().y) < 10.0f)
			{
				if (pJogador->getCorpo().getPosition().x > corpo.getPosition().x &&
					fabs(pJogador->getCorpo().getPosition().x - getCorpo().getPosition().x) <= range.x)
				{
					andarDir();
				}
				else if (pJogador->getCorpo().getPosition().x < corpo.getPosition().x &&
					fabs(pJogador->getCorpo().getPosition().x - getCorpo().getPosition().x) <= range.x)
				{
					andarEsq();
				}

			}
		}

		void Inimigo::andarDir()
		{
			float deltaTime = pGT->getDeltaTime();
			corpo.move(velocidade.x * deltaTime, 0.f);
		}

		void Inimigo::andarEsq()
		{
			float deltaTime = pGT->getDeltaTime();
			getCorpo().move(-velocidade.x * deltaTime, 0.f);
		}

		void Inimigo:: operator--()
		{
			vida--;
		}

		Jogador* Inimigo::pJogador = nullptr;

	}
}