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
		public:
			ObservadorSegundaFase();
			~ObservadorSegundaFase();
			void notificarEvento(const std::string& evento);
		};
	}
}
