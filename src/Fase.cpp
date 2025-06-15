#include "Fase.h"
#include "GerenciadorColisao.h"


using namespace Masmorra::Fases;


Fase::Fase(int id, int qtdeJogadores):
	Ente(id),
	camera(),
	numeroInimigos(),
	fimDaFase(false),
	quantidadeJogadores(qtdeJogadores)
{
	if (quantidadeJogadores == 1)
	{
		sf::Texture* texturaJog1 = new sf::Texture();
		texturaJog1->loadFromFile("knight_Sprite.png");
		pCav = new Entidades::Personagens::Cavaleiro(1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(100.f, 4800.f),
			sf::Vector2f(200.f, 0.f),
			100, 80.0f, texturaJog1, sf::Vector2u(4, 4));

		pCur = nullptr;

		Entidades::Obstaculos::Obstaculo::setCavaleiro(pCav); // Inimigos conhecerem o cavaleiro
		Entidades::Personagens::Inimigo::setCavaleiro(pCav);

		pGC->incluirJogador(pCav);

	}

	else // quantidadeJogadores == 2;
	{
		sf::Texture* texturaJog1 = new sf::Texture();
		texturaJog1->loadFromFile("knight_Sprite.png");
		pCav = new Entidades::Personagens::Cavaleiro(1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(100.f, 4800.f),
			sf::Vector2f(200.f, 0.f),
			100, 80.0f, texturaJog1, sf::Vector2u(4, 4));
		sf::Texture* texturaJog2 = new sf::Texture();

		texturaJog2->loadFromFile("healer_Sprite.png");
		pCur = new Entidades::Personagens::Curandeira(1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(120.f, 4800.f),
			sf::Vector2f(200.f, 0.f),
			30, 80.0f, texturaJog2, sf::Vector2u(3, 4));

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

bool Fase::getFimDaFase()const
{
	return fimDaFase;
}

int Fase::getQtdeJogadores()const
{
	return quantidadeJogadores;
}

