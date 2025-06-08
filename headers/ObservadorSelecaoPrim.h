#pragma once
#include "Observador.h"
#include "SelecaoPrimeira.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorSelecaoPrim : public Observador
		{
		public:
			ObservadorSelecaoPrim();
			~ObservadorSelecaoPrim();
			void notificarEvento(const std::string& evento);
		};
	}
}

