#pragma once
#include "Ranking.h"
#include "Estado.h"
#include "ObservadorRanking.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoRanking : public Estado
		{
		private:
			Ranking* pR;
			Observadores::ObservadorRanking* pObs;

		public:
			EstadoRanking();
			~EstadoRanking();
			void executar();
			void verificarEvento();
		};
	}
}
