#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "GerenciadorTempo.h"

namespace Gerenciadores
{
	class GerenciadorColisao
	{
	private:
		static GerenciadorColisao* pGerenciadorColisao;
		Listas::ListaEntidades lista_obst;
		Listas::ListaEntidades lista_ini;
		Listas::ListaEntidades lista_plataf;
		Entidades::Personagens::Jogador* pJogador;
		Gerenciadores::GerenciadorTempo* pGT;
		GerenciadorColisao();
		float delta_x;
		float delta_y;
		float intersect_x;
		float intersect_y;
		sf::Vector2f direcao;

	public:
		~GerenciadorColisao();
		static GerenciadorColisao* getGerenciadorColisao();
		bool verificarColisao(Entidades::Entidade* e1, Entidades::Entidade* e2);
		void colisaoJogadorInimigo();
		void colisaoJogadorObstaculo();
		void colisaoJogadorPlataforma();
		void colisaoPlataformaEntidades();
		void setJogador(Entidades::Personagens::Jogador* pJ);
		void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
		void incluirInimigo(Entidades::Personagens::Inimigo* pI);
		void incluirPlataforma(Entidades::Obstaculos::Plataforma* pP);
		void executar();
		float getDeltaX();
		float getDeltaY();
		float getIntersectX();
		float getIntersectY();
		void removerEntidade(Entidades::Entidade* pE);
	};
}