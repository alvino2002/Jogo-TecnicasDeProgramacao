#pragma once
#include "Fase.h"
#include "ListaEntidades.h"
#include "time.h"
#include "Aranha.h"
#include "Jogador.h"
#include "Caixa.h"
#include "Lava.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEvento.h"
#include "GerenciadorTempo.h"
#include "Cavaleiro.h"
#include "Curandeira.h"
#include "Mago.h"
#include "Esqueleto.h"


namespace Masmorra
{
	namespace Fases
	{
		class PrimeiraFase : public Fase
		{
		private:
			bool avance;
		public:
			PrimeiraFase(int qtdeJogadores);
			~PrimeiraFase();
			void criarCenario();
			void criarInimigos();
			void criarObstaculos();
			void executar();
			void setAvance(bool avancar);
			bool getAvance();
		};
	}
}
