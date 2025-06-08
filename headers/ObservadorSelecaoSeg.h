#pragma once
#include "Observador.h"
#include "SelecaoSegunda.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorSelecaoSeg : public Observador
		{
		public:
			ObservadorSelecaoSeg();
			~ObservadorSelecaoSeg();
			void notificarEvento(const std::string& evento);
		};
	}
}

