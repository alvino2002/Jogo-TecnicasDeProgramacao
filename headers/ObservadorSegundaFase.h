#pragma once
#include "Ente.h"
#include "Observador.h"
#include "SegundaFase.h"
#include "GerenciadorEstado.h"


namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorSegundaFase : public Observador
		{
		private:
			Fases::SegundaFase* pSegFase;
		public:
			ObservadorSegundaFase();
			~ObservadorSegundaFase();
			void setSegundaFase(Fases::SegundaFase* pSF);
			void notificarEvento(const std::string& evento);
		};
	}
}
