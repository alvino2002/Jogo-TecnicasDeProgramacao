#include "Ogro.h"
#include "GerenciadorTempo.h"

namespace Entidades
{
	namespace Personagens
	{

		Ogro::Ogro(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade,
			unsigned int vida, sf::Vector2f range, sf::Texture* textura) :
			Inimigo(tamanho, posicaoInicial, velocidade, vida, range),
			batida(2)
		{
		}
		Ogro::~Ogro()
		{
		}
		void Ogro::executar()
		{
			float deltaTime = pGT->getDeltaTime();
			aplicarGravidade(deltaTime);
			perseguir();
		}
		void Ogro::bater()
		{
			if (pJogador->getInvulneravel() == false) //jogador nao esta invuneravel, pode receber dano;
			{
				pJogador->sofrerDano(batida);

				sf::Vector2f deslocamento = pJogador->getCorpo().getPosition() - corpo.getPosition();
				//jogador eh empurrado para tras
				if (deslocamento.x > 0)
				{
					pJogador->getCorpo().move(20.f, 0.f); // empurra para a direita
				}
				else
				{
					pJogador->getCorpo().move(-20.f, 0.f); // empurra para a esquerda
				}
				pJogador->setInvulneravel(true);
				pJogador->invulnerabilizar();
			}
		}
		void Ogro::interagir()
		{
			if (pJogador->getEstaAtacando())
			{
				setVida(vida - pJogador->getDano());
			}
			else
			{
				bater();
			}
		}
	}
}