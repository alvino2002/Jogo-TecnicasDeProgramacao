#include "Jogador.h"
#include "GerenciadorTempo.h"
#include <iostream>

using namespace Masmorra::Entidades::Personagens;

Jogador::Jogador(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida) :
	Personagem(tamanho, posicaoInicial, velocidade, vida),
	tempoInvulneravel(),
	duracaoInvulneravel(2.0f),
	invulneravel(false),
	velAtual()
{
}

Jogador::~Jogador()
{
}

void Jogador::sofrerDano(int d)
{
	vida -= d;
	perderPonto();
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

void Jogador::derrotarAranha()
{
	pontuacao += 50;
}

void Jogador::derrotarEsqueleto()
{
	pontuacao += 20;
}

void Jogador::derrotarMago()
{
	pontuacao += 300;
}

void Jogador::perderPonto()
{
	pontuacao -= 1;
}

void Jogador::setPosicao(sf::Vector2f pos)
{
	if (this)
	{
		corpo.setPosition(pos);
	}
}

float Jogador::getVelocidadeAtualX()
{
	return velAtual.x;
}

void Jogador::setVelocidadeAtualX(float vX)
{
	velAtual.x = vX;
}


int Jogador::getPontuacao()
{
	return pontuacao;
}

int Jogador::pontuacao = 0;

