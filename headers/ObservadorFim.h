#pragma once
#include "Ente.h"
#include "Observador.h"
#include "Fim.h"
#include "GerenciadorEstado.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorFim : public Observador
		{
	
		public:
			ObservadorFim();
			~ObservadorFim();
			void notificarEvento(const std::string& evento);

		};
	}
}


