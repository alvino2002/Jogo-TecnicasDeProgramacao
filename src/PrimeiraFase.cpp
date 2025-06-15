#include "PrimeiraFase.h"
#include <iostream>


using namespace Masmorra::Fases;


PrimeiraFase::PrimeiraFase(int id, int qtdeJogadores) :
	Fase(id, qtdeJogadores),
	avance(false)
{
	listaEntidades.clearLista();

	listaEntidades.incluirEntidade(pCav);
	listaEntidades.incluirEntidade(pCur);

	camera.setSize(sf::Vector2f(800.f, 600.f));
	srand(time(NULL));
	criarCenario();
	criarInimigos();
	criarObstaculos();
}
PrimeiraFase::~PrimeiraFase()
{
	//listaEntidades.clearLista();
}

void PrimeiraFase::criarInimigos()
{
	int numeroEsqueletos = rand() % 3 + 3;
	int numeroAranhas = rand() % 3 + 3;

	numeroInimigos = numeroAranhas + numeroEsqueletos;

	sf::Texture* spiderTexture = new sf::Texture();
	spiderTexture->loadFromFile("spider_Sprite.png");

	sf::Texture* skullTexture = new sf::Texture();
	skullTexture->loadFromFile("skull.sprite.png");

	/*Esqueleto 1*/
	Entidades::Personagens::Esqueleto* pE = new Entidades::Personagens::Esqueleto
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(700.f, 4800.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		sf::Vector2f(200.f, 0.f),
		skullTexture, sf::Vector2u(3, 4)
	);
	pGC->incluirInimigo(pE);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE));

	/*Esqueleto 2*/
	Entidades::Personagens::Esqueleto* pE2 = new Entidades::Personagens::Esqueleto
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(3500.f, 4800.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		sf::Vector2f(100.f, 0.f),
		skullTexture, sf::Vector2u(3, 4)
	);
	pGC->incluirInimigo(pE2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE2));

	/*Esqueleto 3*/
	Entidades::Personagens::Esqueleto* pE3 = new Entidades::Personagens::Esqueleto
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(3700.f, 2000.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		sf::Vector2f(100.f, 0.f),
		skullTexture, sf::Vector2u(3, 4)
	);
	pGC->incluirInimigo(pE3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE3));

	/*Aranha 1*/
	Entidades::Personagens::Aranha* pA1 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(300.f, 4800.f),
		sf::Vector2f(50.f, 0.f),
		10, 1,
		sf::Vector2f(300.f, 0.f),
		spiderTexture, sf::Vector2u(3, 4)
	);
	pGC->incluirInimigo(pA1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA1));

	/*Aranha 2*/
	Entidades::Personagens::Aranha* pA2 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(1000.f, 4700.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		sf::Vector2f(300.f, 0.f),
		spiderTexture, sf::Vector2u(3, 4)
	);
	pGC->incluirInimigo(pA2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA2));

	/*Aranha 3*/
	Entidades::Personagens::Aranha* pA3 = new Entidades::Personagens::Aranha
	(
		1,
		sf::Vector2f(50.f, 70.f),
		sf::Vector2f(4000.f, 4600.f),
		sf::Vector2f(50.f, 0.f),
		10, 2,
		sf::Vector2f(300.f, 0.f),
		spiderTexture, sf::Vector2u(3, 4)
	);
	pGC->incluirInimigo(pA3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA3));


	if (numeroAranhas > 3)
	{
		/*Aranha 4*/
		Entidades::Personagens::Aranha* pA4 = new Entidades::Personagens::Aranha
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(2500.f, 4500.f),
			sf::Vector2f(50.f, 0.f),
			10, 1,
			sf::Vector2f(300.f, 0.f),
			spiderTexture, sf::Vector2u(3, 4)
		);

		pGC->incluirInimigo(pA4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA4));
	}

	if (numeroAranhas > 4)
	{
		/*Aranha 5*/
		Entidades::Personagens::Aranha* pA5 = new Entidades::Personagens::Aranha
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(3300.f, 4600.f),
			sf::Vector2f(50.f, 0.f),
			10, 2,
			sf::Vector2f(300.f, 0.f),
			spiderTexture, sf::Vector2u(3, 4)
		);
		pGC->incluirInimigo(pA5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pA5));
	}

	if (numeroEsqueletos > 3)
	{
		/*Esqueleto 4*/
		Entidades::Personagens::Esqueleto* pE4 = new Entidades::Personagens::Esqueleto
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(4700.f, 3900.f),
			sf::Vector2f(50.f, 0.f),
			10, 1,
			sf::Vector2f(100.f, 0.f),
			skullTexture, sf::Vector2u(3, 4)
		);

		pGC->incluirInimigo(pE4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE4));
	}

	if (numeroEsqueletos > 4)
	{
		/*Esqueleto 5*/
		Entidades::Personagens::Esqueleto* pE5 = new Entidades::Personagens::Esqueleto
		(
			1,
			sf::Vector2f(50.f, 70.f),
			sf::Vector2f(3900.f, 3900.f),
			sf::Vector2f(50.f, 0.f),
			10, 2,
			sf::Vector2f(100.f, 0.f),
			skullTexture, sf::Vector2u(3, 4)
		);

		pGC->incluirInimigo(pE5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pE5));
	}

}

void PrimeiraFase::criarCenario()
{
	sf::Texture* texturaPlat = new sf::Texture();
	texturaPlat->loadFromFile("plataforma_Sprite.png");

	/*Plataforma 1*/
	Entidades::Obstaculos::Plataforma* p1 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(6000.f, 80.f),
		sf::Vector2f(0.f, 5000.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		false
	);

	pGC->incluirObstaculo(p1);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(p1));

	/*Plataforma 2*/
	Entidades::Obstaculos::Plataforma* pP2 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(650.f, 40.f),
		sf::Vector2f(1000.f, 4850.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		true
	);

	pGC->incluirObstaculo(pP2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP2));

	/*Plataforma 3*/
	Entidades::Obstaculos::Plataforma* pP3 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 40.f),
		sf::Vector2f(1750.f, 4800.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		false
	);

	/*Plataforma 4*/
	pGC->incluirObstaculo(pP3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP3));

	Entidades::Obstaculos::Plataforma* pP4 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 40.f),
		sf::Vector2f(2300.f, 4750.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		false
	);

	pGC->incluirObstaculo(pP4);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP4));

	/*Plataforma 5*/
	Entidades::Obstaculos::Plataforma* pP5 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 40.f),
		sf::Vector2f(3000.f, 4700.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		true
	);

	pGC->incluirObstaculo(pP5);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP5));
	
	/*Plataforma 6*/
	Entidades::Obstaculos::Plataforma* pP6 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 40.f),
		sf::Vector2f(3650.f, 4600.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		true
	);

	pGC->incluirObstaculo(pP6);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP6));

	/*Plataforma 7*/
	Entidades::Obstaculos::Plataforma* pP7 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 40.f),
		sf::Vector2f(4200.f, 4650.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		false
	);

	pGC->incluirObstaculo(pP7);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP7));

	/*Plataforma 8*/
	Entidades::Obstaculos::Plataforma* pP8 = new Entidades::Obstaculos::Plataforma(
		1,
		sf::Vector2f(500.f, 40.f),
		sf::Vector2f(4850.f, 4750.f),
		texturaPlat,
		sf::Vector2u(4, 4),
		false
	);

	pGC->incluirObstaculo(pP8);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pP8));
}

void PrimeiraFase::criarObstaculos()
{
	sf::Texture* texturaCaixa = new sf::Texture();
	texturaCaixa->loadFromFile("caixa_sprite.png");

	int numeroCaixas = rand() % 3 + 3;

	/*Caixa 1*/
	Entidades::Obstaculos::Caixa* pC = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
		sf::Vector2f(500.0f, 4500.0f), texturaCaixa, sf::Vector2u(4, 4));

	pGC->incluirObstaculo(pC);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC));

	/*Caixa 2*/
	Entidades::Obstaculos::Caixa* pC2 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
		sf::Vector2f(2350.0f, 4700.0f), texturaCaixa, sf::Vector2u(4, 4));

	pGC->incluirObstaculo(pC2);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC2));

	/*Caixa 3*/
	Entidades::Obstaculos::Caixa* pC3 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
		sf::Vector2f(2750.0f, 4600.0f), texturaCaixa, sf::Vector2u(4, 4));

	pGC->incluirObstaculo(pC3);
	listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC3));

	if (numeroCaixas > 3)
	{
		/*Caixa 4*/
		Entidades::Obstaculos::Caixa* pC4 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
			sf::Vector2f(3150.0f, 4700.0f), texturaCaixa, sf::Vector2u(4, 4));
		pGC->incluirObstaculo(pC4);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC4));
	}
	if (numeroCaixas > 4)
	{
		/*Caixa 5*/
		Entidades::Obstaculos::Caixa* pC5 = new Entidades::Obstaculos::Caixa(1, sf::Vector2f(60.0f, 70.0f),
			sf::Vector2f(3300.0f, 4600.0f), texturaCaixa, sf::Vector2u(4, 4));
		pGC->incluirObstaculo(pC5);
		listaEntidades.incluirEntidade(static_cast<Entidades::Entidade*>(pC5));
	}
}

void PrimeiraFase::setAvance(bool avancar)
{
	avance = avancar;
}

bool PrimeiraFase::getAvance()const
{
	return avance;
}

void PrimeiraFase::executar()
{
	/*Jogador principal morreu*/
	if (pCav->getVida() == 0)
	{
		setFimDaFase(true);
	}

	/*Jogador pode avancar para proxima fase*/
	else if (Entidades::Personagens::Cavaleiro::getInimigosEliminados() == numeroInimigos)
	{
		setAvance(true);
	}

	sf::RenderWindow* janela = pGG->getJanela();

	Entidades::Entidade* pC = listaEntidades.getEntidade(0);

	sf::Vector2f pos = (pC->getCorpo().getPosition());  // Posicao do jogador
	sf::Vector2f cameraPos = pos;

	/*Limites para manter a camera dentro do mundo*/
	float meiaLargura = camera.getSize().x / 2.f;
	float meiaAltura = camera.getSize().y / 2.f;

	if (pos.x < meiaLargura)
	{
		cameraPos.x = meiaLargura;
	}
	else if (pos.x > (10000 - meiaLargura))
	{
		cameraPos.x = 10000 - meiaLargura;
	}

	if (pos.y < meiaAltura)
	{
		cameraPos.y = meiaAltura;
	}
	else if (pos.y > (5050 - meiaAltura))
	{
		cameraPos.y = 5050 - meiaAltura;
	}

	// Atualiza a view com a posicao ajustada
	camera.setCenter(cameraPos);
	janela->setView(camera);

	pGG->limparJanela();
	pGT->reiniciar();
	pGC->executar();

	for (int i = listaEntidades.getTam() - 1; i >= 0; i--)
	{
		Entidades::Entidade* pE = listaEntidades.getEntidade(i);

		if (pE->getAtivo() == true)
		{
			std::cout << listaEntidades.getEntidade(0)->getPosicaoY() << std::endl;
			pE->desenhar();
			pE->executar();
		}
	}

	for (int i = 0; i < pGC->getListaProjeteis().getTam(); i++)
	{
		Entidades::Entidade* pF = pGC->getListaProjeteis().getEntidade(i);
		if (pF->getAtivo())
		{
			pF->executar();
			pF->desenhar();
		}
	}

	pGG->mostrarElementos();
}


