#include "Aranha.h"

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

			if (vida <= 0) // Aranha eliminada
			{
				setVivo(false);
			}
		}

		void Aranha::morder(Jogador* pJ)
		{
			if (pJ->getInvulneravel() == false)
			{
				pJ->sofrerDano(mordida);

				sf::Vector2f deslocamento = pJ->getCorpo().getPosition() - corpo.getPosition();

				if (deslocamento.x > 0)
				{
					pJ->getCorpo().move(30.f, 0.f); // Empurra para a direita
				}
				else
				{
					pJ->getCorpo().move(-30.f, 0.f); // Empurra para a esquerda
				}

				pJ->invulnerabilizar();
			}
		}

		void Aranha::aplicarVeneno()
		{
			pCavaleiro->sofrerDano(veneno);
		}

		void Aranha::interagir(Jogador* pJ) // Ocorreu a colisao com o jogador
		{
			Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJ);

			if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
			{
				setVida(vida - cavaleiro->getDano());
				aplicarVeneno(); // Ao tomar dano, aplica veneno ao atacante, no caso o cavaleiro
				cavaleiro->setEstaAtacando(false);
			}

			else
			{
				morder(pJ);
			}
		}
	}
