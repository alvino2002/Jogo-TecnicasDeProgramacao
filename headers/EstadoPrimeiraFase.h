#pragma once
#include "PrimeiraFase.h"
#include "Estado.h"
#include "ObservadorPrimeiraFase.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoPrimeiraFase : public Estado
		{
		private:
			Fases::PrimeiraFase* pPrimFase;
			Observadores::ObservadorPrimeiraFase* pObs;

		public:
			EstadoPrimeiraFase(int qtdeJogadores);
			~EstadoPrimeiraFase();
			void executar();
			void verificarEvento();
		};
	}
}
