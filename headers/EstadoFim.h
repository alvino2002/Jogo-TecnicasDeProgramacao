#pragma once
#include "Fim.h"
#include "Estado.h"
#include "ObservadorFim.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoFim : public Estado
		{
		private:
			Fim* pFim;
			Observadores::ObservadorFim* pObs;

		public:
			EstadoFim();
			~EstadoFim();
			void executar();
			void verificarEvento();
		};
	}
}
