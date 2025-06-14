#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "GerenciadorTempo.h"
#include "Plataforma.h"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorColisao
		{
		private:
			static GerenciadorColisao* pGerenciadorColisao;
			Listas::ListaEntidades lista_obst;
			Listas::ListaEntidades lista_ini;
			Listas::ListaEntidades lista_jogadores;
			Listas::ListaEntidades lista_projeteis;
			GerenciadorTempo* pGT;
			GerenciadorColisao();
			float delta_x;
			float delta_y;
			float intersect_x;
			float intersect_y;

		public:
			~GerenciadorColisao();
			static GerenciadorColisao* getGerenciadorColisao();
			bool verificarColisao(Entidades::Entidade* e1, Entidades::Entidade* e2);
			void colisaoJogadorInimigo();
			void colisaoJogadorProjetil();
			void colisaoObstaculosEntidades();
			void incluirJogador(Entidades::Personagens::Jogador* pJ);
			void incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO);
			void incluirInimigo(Entidades::Personagens::Inimigo* pI);
			void incluirProjetil(Entidades::Entidade* pF);
			void executar();
			float getDeltaX()const;
			float getDeltaY()const;
			float getIntersectX()const;
			float getIntersectY()const;
			Listas::ListaEntidades& getListaProjeteis();
			void limparListas();
		};
	}
}
