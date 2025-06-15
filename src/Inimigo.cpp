#include "Inimigo.h"
#include "GerenciadorTempo.h"


using namespace Masmorra::Entidades::Personagens;


Inimigo::Inimigo(
	int id,
	sf::Vector2f tamanho,
	sf::Vector2f posicao,
	sf::Vector2f velocidade,
	int vida,
	int nivelDeMal,
	sf::Vector2f alcance
) :
	Personagem(id, tamanho, posicao, velocidade, vida),
	alcance(alcance),
	nivelDeMaldade(nivelDeMal)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::setCavaleiro(Cavaleiro* pCa)
{
	if (pCa)
	{
		pCavaleiro = pCa;
	}
}

void Inimigo::setCurandeira(Curandeira* pCu)
{
	if (pCu)
	{
		pCurandeira = pCu;
	}
}

Jogador* Inimigo::getMaisProximo() // Jogador esta mais proximo
{
	if (pCavaleiro && pCurandeira)
	{
		float distancia_Cavaleiro = this->getCorpo().getPosition().x - pCavaleiro->getCorpo().getPosition().x;
		float distancia_Curandeira = this->getCorpo().getPosition().x - pCurandeira->getCorpo().getPosition().x;

		if (fabs(distancia_Cavaleiro) > fabs(distancia_Curandeira))
		{
			return pCurandeira;
		}
		else
		{
			return pCavaleiro;
		}
	}
	else // pCurandeira é nulo, ou seja, apenas um jogador na fase
	{
		return pCavaleiro;
	}
}


void Inimigo::perseguir()
{
	Jogador* pJogador = static_cast<Jogador*>(getMaisProximo()); // Inimigo persegue o jogador mais proximo

	if (fabs(pJogador->getCorpo().getPosition().y - corpo.getPosition().y) < 10.0f) // Começa a perseguir apenas se estiverem
		//em alturas proximas
	{
		if (pJogador->getCorpo().getPosition().x > corpo.getPosition().x &&
			fabs(pJogador->getCorpo().getPosition().x - getCorpo().getPosition().x) <= alcance.x)
		{
			andarDir();
		}
		else if (pJogador->getCorpo().getPosition().x < corpo.getPosition().x &&
			fabs(pJogador->getCorpo().getPosition().x - getCorpo().getPosition().x) <= alcance.x)
		{
			andarEsq();
		}
	}
}

void Inimigo::andarDir()
{
	float deltaTime = pGT->getDeltaTempo();
	corpo.move(velocidade.x * deltaTime, 0.f);
	olhandoDireita = true;
}

void Inimigo::andarEsq()
{
	float deltaTime = pGT->getDeltaTempo();
	getCorpo().move(-velocidade.x * deltaTime, 0.f);
	olhandoDireita = false;
}

Cavaleiro* Inimigo::pCavaleiro = nullptr;
Curandeira* Inimigo::pCurandeira = nullptr;
