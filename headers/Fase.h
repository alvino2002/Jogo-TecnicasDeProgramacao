#pragma once
#include "Ente.h"
#include "Entidade.h"
#include "Cavaleiro.h"
#include "Curandeira.h"
#include "ListaEntidades.h"

namespace Masmorra
{
	namespace Fases
	{
		class Fase : public Ente
		{
		protected:
			Entidades::Personagens::Cavaleiro* pCav;
			Entidades::Personagens::Curandeira* pCur;
			Listas::ListaEntidades listaEntidades;
			sf::View camera;
			int numeroInimigos;
			bool fimDaFase;

		public:
			Fase(int qtdeJogadores);
			~Fase();
			virtual void criarCenario() = 0;
			virtual void criarInimigos() = 0;
			virtual void executar() = 0;
			void setFimDaFase(bool fim); // Fase acaba quando todos os inimigos forem derrotados
			bool getFimDaFase();
		};
	}
}
