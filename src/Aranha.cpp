#include "Aranha.h"
#include <iostream>

namespace Entidades
{
	namespace Personagens
	{
		Aranha::Aranha(
			sf::Vector2f tamanho,
			sf::Vector2f posicaoInicial,
			sf::Vector2f velocidade,
			int vida,
			sf::Vector2f alcance
		):
			Inimigo(tamanho, posicaoInicial, velocidade, vida, alcance),
			mordida(2),
			veneno(1)
		{
		}

		Aranha::~Aranha()
		{
		}

		void Aranha::executar()
		{
			if (!naSuperficie)
			{
				float deltaTime = pGT->getDeltaTime();
				aplicarGravidade(deltaTime);
			}

			perseguir(); // Persegue o jogador

			if (vida == 0) // Aranha eliminada
			{
				setVivo(false);
				std::cout << "Aranha morta" << std::endl;
			}
		}

		void Aranha::morder()
		{
			if (pJogador->getInvulneravel() == false)
			{
				pJogador->sofrerDano(mordida);

				sf::Vector2f deslocamento = pJogador->getCorpo().getPosition() - corpo.getPosition();

				if (deslocamento.x > 0)
				{
					pJogador->getCorpo().move(20.f, 0.f); // Empurra para a direita
				}
				else
				{
					pJogador->getCorpo().move(-20.f, 0.f); // Empurra para a esquerda
				}

				pJogador->invulnerabilizar();
			}
		}

		void Aranha::aplicarVeneno()
		{
			pJogador->sofrerDano(veneno);
		}

		void Aranha::interagir() // Ocorreu a colisao com o jogador
		{
			Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJogador);

			if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
			{
				setVida(vida - cavaleiro->getDano());
				aplicarVeneno(); // Ao tomar dano, aplica veneno ao atacante
				cavaleiro->setEstaAtacando(false);
			}

			else
			{
				morder();
			}
		}
	}
