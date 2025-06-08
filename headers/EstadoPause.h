#pragma once
#include "Pause.h"
#include "Estado.h"
#include "ObservadorPause.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoPause : public Estado
		{
		private:
			Pause* pPause;
			Observadores::ObservadorPause* pObs;

		public:
			EstadoPause();
			~EstadoPause();
			void executar();
			void verificarEvento();
		};
	}
}
