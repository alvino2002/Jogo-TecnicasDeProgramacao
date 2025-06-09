#include "Fase.h"
#include <iostream>
#include "GerenciadorColisao.h"


using namespace Masmorra::Fases;


Fase::Fase(int qtdeJogadores):
	Ente(),
	listaEntidades(),
	camera(),
	numeroInimigos(),
	fimDaFase(false),
	quantidadeJogadores(qtdeJogadores)
{
	if (qtdeJogadores == 1)
	{
		sf::Texture* texturaJog1 = new sf::Texture();
		texturaJog1->loadFromFile("knight_Sprite.png");
		pCav = new Entidades::Personagens::Cavaleiro(
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(100.f, 4800.f),
			sf::Vector2f(200.f, 0.f),
			10, texturaJog1, sf::Vector2u(4, 4));

		pCur = nullptr;

		pGC->incluirJogador(pCav);
		Entidades::Obstaculos::Obstaculo::setCavaleiro(pCav); // Inimigos conhecerem o cavaleiro
		Entidades::Personagens::Inimigo::setCavaleiro(pCav);
	
	}

	else // qtdeJogadores == 2;
	{
		sf::Texture* texturaJog1 = new sf::Texture();
		texturaJog1->loadFromFile("knight_Sprite.png");
		pCav = new Entidades::Personagens::Cavaleiro(
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(100.f, 4800.f),
			sf::Vector2f(200.f, 0.f),
			10, texturaJog1, sf::Vector2u(4, 4));
		sf::Texture* texturaJog2 = new sf::Texture();

		texturaJog2->loadFromFile("healer_Sprite.png");
		pCur = new Entidades::Personagens::Curandeira(
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(120.f, 4800.f),
			sf::Vector2f(200.f, 0.f),
			30, texturaJog2, sf::Vector2u(3, 4));

		Entidades::Obstaculos::Obstaculo::setCurandeira(pCur); // Obstaculos conhecerem a curandeira
		Entidades::Personagens::Inimigo::setCurandeira(pCur);

		Entidades::Obstaculos::Obstaculo::setCavaleiro(pCav); // Inimigos conhecerem o cavaleiro
		Entidades::Personagens::Inimigo::setCavaleiro(pCav);


		pCur->setCavaleiro(pCav);

		pGC->incluirJogador(pCav);
		pGC->incluirJogador(pCur);
	}

}

Fase::~Fase()
{
}

void Fase::setFimDaFase(bool fim)
{
	fimDaFase = fim;
}

bool Fase::getFimDaFase()
{
	return fimDaFase;
}

int Fase::getQtdeJogadores()
{
	return quantidadeJogadores;
}
