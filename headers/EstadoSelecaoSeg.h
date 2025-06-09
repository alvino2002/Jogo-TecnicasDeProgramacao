#pragma once
#include "SelecaoSegunda.h"
#include "Estado.h"
#include "ObservadorSelecaoSeg.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoSelecaoSeg : public Estado
		{
		private:
			SelecaoSegunda* pSelecaoSegunda;
			Observadores::ObservadorSelecaoSeg* pObs;

		public:
			EstadoSelecaoSeg();
			~EstadoSelecaoSeg();
			void executar();
			void verificarEvento();
		};
	}
}
