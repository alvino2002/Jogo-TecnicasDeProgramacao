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




namespace Masmorra
{
	namespace Fases
	{
		class SegundaFase : public Fase
		{
		private:
			int numeroChefoes;
			int pontuacaoFinal;
			bool venceu;
		public:
			SegundaFase(int qtdeJogadores);
			~SegundaFase();
			void criarCenario();
			void criarInimigos();
			void criarObstaculos();
			void executar();
			int getPontuacao();
			void setVenceu(bool v);
			bool getVenceu();
		};
	}
}
