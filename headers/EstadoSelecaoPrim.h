#pragma once
#include "SelecaoPrimeira.h"
#include "Estado.h"
#include "ObservadorSelecaoPrim.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoSelecaoPrim : public Estado
		{
		private:
			Masmorra::Interfaces::SelecaoPrimeira* pSelecaoPrim;
			Observadores::ObservadorSelecaoPrim* pObs;

		public:
			EstadoSelecaoPrim();
			~EstadoSelecaoPrim();
			void executar();
			void verificarEvento();
		};
	}
}
