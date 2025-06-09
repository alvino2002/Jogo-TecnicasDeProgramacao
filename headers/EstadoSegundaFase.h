#pragma once
#include "SegundaFase.h"
#include "Estado.h"
#include "ObservadorSegundaFase.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoSegundaFase : public Estado
		{
		private:
			Fases::SegundaFase* pSegFase;
			Observadores::ObservadorSegundaFase* pObs;

		public:
			EstadoSegundaFase(int qtdeJogadores);
			~EstadoSegundaFase();
			void executar();
			void verificarEvento();
		};
	}
}
