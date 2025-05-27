#include "PrimeiraFase.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "GerenciadorTempo.h"
#include <iostream>


	 PrimeiraFase::PrimeiraFase() :
		 numeroInimigos(1)
	 {
		 criarCenario();
		 //criarInimigos();
		 criarJogador();
		 criarObstaculos();
	 }
	 PrimeiraFase::~PrimeiraFase()
	 {
	 }

	 void PrimeiraFase::criarInimigos()
	 {
		 /*Entidades::Personagens::Aranha* pA = new Entidades::Personagens::Aranha
		 (
			 sf::Vector2f(50.f, 70.f),
			 sf::Vector2f(500.f, 300.f),
			 sf::Vector2f(50.f, 0.f),
			 10,
			 sf::Vector2f(300.f, 0.f)
		 );*/

		/* pGC->incluirInimigo(pA);
		 listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(pA));*/
	 }

	 void PrimeiraFase::criarJogador()
	 {
		 sf::Texture* playerTexture = new sf::Texture();
		 //playerTexture.loadFromFile("Sprite_NOBack.jpg");
		 playerTexture->loadFromFile("Sprite_NOBack.jpg");
			
		Entidades::Personagens:: Jogador* pJ = new Entidades::Personagens::Jogador(
			 sf::Vector2f(50.f, 70.f),
			 sf::Vector2f(400.f, 300.f),
			 sf::Vector2f(200.f, 0.f),
			 10, playerTexture, sf::Vector2u(4, 3));
		 pGC->setJogador(pJ);
		 Entidades::Personagens::Inimigo::setJogador(pJ);
		 Entidades::Obstaculos::Obstaculo::setJogador(pJ);
		 listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(pJ));
	 }

	 void PrimeiraFase::criarCenario()
	 {
		 Entidades::Obstaculos::Plataforma* pP = new Entidades::Obstaculos::Plataforma(
			 sf::Vector2f(1000.f, 40.f),
			 sf::Vector2f(200.f, 500.f)
		 );
		 pGC->incluirPlataforma(pP);
		 listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(pP));
	 }

	 void PrimeiraFase::criarObstaculos()
	 {
		Entidades::Obstaculos:: Caixa* pC = new Entidades::Obstaculos::Caixa(sf::Vector2f(60.0f, 70.0f),
			 sf::Vector2f(500.0f, 300.0f));
		 pGC->incluirObstaculo(pC);
		 listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(pC));

		 Entidades::Obstaculos::Lava* pL = new Entidades::Obstaculos::Lava(sf::Vector2f(200.f, 40.f),
			 sf::Vector2f(200.0f, 400.0f));
		 pGC->incluirObstaculo(pL);
		 listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(pL));
	 }

	 void PrimeiraFase::executar()
	 {
		 while (pGG->verificaJanelaAberta())
		 {
			 pGG->limparJanela();
			 pGE->executar();
			 pGT->atualizar();
			 pGC->executar();

			 for (int i = 0; i < listaEntidades.getTam(); i++)
			 {
	
				 Entidades::Entidade* pE = listaEntidades.getEntidade(i);
				 pE->executar();
				 pGG->desenharElementos(pE->getCorpo());
				 if (pE->getAtivo() == false) // Jogador ou inimigo morreu
				 {
					 listaEntidades.deleteEntidade(pE);
					 pGC->removerEntidade(pE);
				 }
			 }

			 pGG->mostrarElementos();
		 }
	 }
 
