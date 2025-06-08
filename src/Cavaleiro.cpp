#include "Cavaleiro.h"
#include <iostream>

using namespace Masmorra::Entidades::Personagens;


Cavaleiro::Cavaleiro(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
	                 sf::Texture* texture, sf::Vector2u imageCount):
	Jogador(tamanho, posicaoInicial, velocidade, vida),
	estaAtacando(false),
	dano(2),
	pulo(80.0f),
	energia(20),
	tempoRecuperar(),
	duracaoRecuperacao(3.0f),
	tempoAtaque(),
	recargaAtaque(0.5f),
	ataquePronto(true)
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(texture);
	pGA->pegarAnimacao(texture, imageCount);

}

Cavaleiro::~Cavaleiro()
{
	pGA = nullptr;
}

void Cavaleiro::executar()
{

	std::cout << inimigosEliminados << std::endl;

	velAtual.x = 0.0f;

	/*Movimento do cavaleiro*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velAtual.x -= velocidade.x;
		olhandoDireita = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velAtual.x += velocidade.x;
		olhandoDireita = true;
	}

	/*Pulo do cavaleiro*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (naSuperficie))
	{
		velAtual.y = -sqrtf(2.0f * gravidade * pulo);

		if (naSuperficie) // Em cima da plataforma
		{
			naSuperficie = false;
		}
	}

	float deltaTime = pGT->getDeltaTempo();

	if (naSuperficie)
	{
		velAtual.y = 0;
	}
	else
	{
		velAtual.y += gravidade * deltaTime;
	}

	/*Ataque do jogador*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && ataquePronto && energia)
	{
		setEstaAtacando(true);
		ataquePronto = false;
		tempoAtaque.restart();
		operator--();
	}

	else if (tempoAtaque.getElapsedTime().asSeconds() >= recargaAtaque)
	{
		ataquePronto = true;     // Libera o próximo ataque
		setEstaAtacando(false); // Desativa o estado de ataque
	}

	if (energia == 0 && tempoRecuperar.getElapsedTime().asSeconds() >= duracaoRecuperacao)
	{
		recuperar();
	}

	corpo.move(velAtual * deltaTime);

	/*Invulnerabilizar*/
	if (invulneravel && tempoInvulneravel.getElapsedTime().asSeconds() >= duracaoInvulneravel)
	{
		setInvulneravel(false); // Desativa a invulnerabilidade
	}

	if (invulneravel)
	{
		/*Piscar o sprite*/
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

	/*Atualizar a animacao*/
	unsigned int linha = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		linha = 2; // Atacando
	}

	else if (velAtual.x != 0.0f)
	{
		linha = 1; // Correndo
	}

	else
	{
		linha = 0; // Parado
	}

	pGA->atualizar(linha, olhandoDireita);

	corpo.setTextureRect(pGA->getFrameAtual());
}

bool Cavaleiro::getEstaAtacando()const
{
	return estaAtacando;
}

void Cavaleiro::setEstaAtacando(bool atacando)
{
	estaAtacando = atacando;
}

int Cavaleiro::getDano()const
{
	return dano;
}

void Cavaleiro::operator--()
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

void Cavaleiro::recuperar()
{
	energia = 10;
}

void Cavaleiro::operator++()
{
	inimigosEliminados++;
}

int Cavaleiro::getInimigosEliminados()
{
	return inimigosEliminados;
}

void Cavaleiro::setInimigosEliminados(int numeroInimigos)
{
	inimigosEliminados = numeroInimigos;
}

void Cavaleiro::zerarInimigosEliminados()
{
	inimigosEliminados = 0;
}

int Masmorra::Entidades::Personagens::Cavaleiro::inimigosEliminados = 0;
