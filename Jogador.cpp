#include "Jogador.h"
#include "GerenciadorTempo.h"
#include "GerenciadorEvento.h"
#include <iostream>
#include "GerenciadorAnimacao.h"

namespace Entidades
{
	namespace Personagens
	{
		Jogador::Jogador(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
			sf::Texture* texture, sf::Vector2u imageCount) :
			Personagem(tamanho, posicaoInicial, velocidade, vida),
			estaAtacando(false),
			dano(2),
			pulo(100.0f),
			tempoInvulneravel(),
			duracaoInvulneravel(2.0f),
			invulneravel(false),
			energia(10),
			tempoRecuperar(),
			duracaoRecuperacao(5.0f),
			velAtual(),
			naCaixa(false),
			naLava(false),
			tempoAtaque(),
			recargaAtaque(0.5f),
			ataquePronto(true),
			olhandoDireita(true)
		{
			corpo.setTexture(texture);
			pGA->pegarAnimacao(texture, imageCount);
		}

		Jogador::~Jogador()
		{
		}

		void Jogador::executar()
		{
			estaAtacando = false;

			velAtual.x = 0.0f;

			/*Movimento do jogador*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				velAtual.x -= velocidade.x;
				olhandoDireita = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				velAtual.x += velocidade.x;
				olhandoDireita = true;
			}

			pGA->atualizar(0, olhandoDireita); // '0' é a linha da animação

			corpo.setTextureRect(pGA->getUvRect());

			/*Pulo do jogador*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (naSuperficie || naCaixa || naLava))
			{
				velAtual.y = -sqrtf(2.0f * gravidade * pulo);

				if (naSuperficie) // Em cima da plataforma
				{
					naSuperficie = false;
				}

				if (naCaixa) // Em cima da caixa
				{
					naCaixa = false;
				}

				if (naLava) // Em cima da lava
				{
					naLava = false;
				}
			}

			float deltaTime = pGT->getDeltaTime();

			if (naSuperficie || naCaixa || naLava)
			{
				velAtual.y = 0;
			}
			else
			{
				velAtual.y += gravidade * deltaTime;
			}

			corpo.move(velAtual * deltaTime);

		


			/*Ataque do jogador*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ataquePronto && energia)
			{
				setEstaAtacando(true);
				ataquePronto = false;
				tempoAtaque.restart();
				operator--();
			}
			else if (tempoAtaque.getElapsedTime().asSeconds() >= recargaAtaque)
			{
				ataquePronto = true;                // Libera o próximo ataque
				setEstaAtacando(false);             // Desativa o estado de ataque
			}

			if (energia == 0 && tempoRecuperar.getElapsedTime().asSeconds() >= duracaoRecuperacao)
			{
				recuperar();
			}

			/*Invulnerabilizar*/
			if (invulneravel && tempoInvulneravel.getElapsedTime().asSeconds() >= duracaoInvulneravel)
			{
				setInvulneravel(false); // Desativa a invulnerabilidade
			}

			if (invulneravel)
			{
				// Piscar o sprite (ex.: alternar visibilidade a cada 0.1s)
				float tempoPiscar = tempoInvulneravel.getElapsedTime().asSeconds();
				bool visivel = static_cast<int>(tempoPiscar * 10) % 2 == 0; // Pisca rápido
				corpo.setFillColor(visivel ? sf::Color::White : sf::Color::Transparent);
			}
			else
			{
				corpo.setFillColor(sf::Color::White); // Volta ao normal
			}

			if (vida == 0)
			{
				setVivo(false);
			}
		}

		void Jogador::setNaCaixa(bool caixa)
		{
			naCaixa = caixa;
		}

		void Jogador::setNaLava(bool lava)
		{
			naLava = lava;
		}

		bool Jogador::getEstaAtacando()
		{
			return estaAtacando;
		}

		void Jogador::setEstaAtacando(bool atacando)
		{
			estaAtacando = atacando;
		}

		int Jogador::getDano()
		{
			return dano;
		}

		void Jogador::sofrerDano(int d)
		{
			vida -= d;
		}

		void Jogador::setInvulneravel(bool imune)
		{
			invulneravel = imune;
		}

		bool Jogador::getInvulneravel()
		{
			return invulneravel;
		}

		void Jogador::invulnerabilizar()
		{
			tempoInvulneravel.restart();
			setInvulneravel(true);
		}

		int Jogador::getEnergia()
		{
			return energia;
		}

		void Jogador::operator--()
		{
			if (energia > 0)
			{
				energia--;

				if (energia == 0)
				{
					tempoRecuperar.restart();
				}
			}
		}

		void Jogador::recuperar()
		{
			energia = 10;
		}
		void Jogador::setPosicao(sf::Vector2f pos)
		{
			corpo.setPosition(pos);
		}

		float Jogador::getVelocidadeAtualX()
		{
			return velAtual.x;
		}

		void Jogador::setVelocidadeAtualX(float vX)
		{
			velAtual.x = vX;
		}
	}
}