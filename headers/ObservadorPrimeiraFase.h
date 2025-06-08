#pragma once
#include "Ente.h"
#include "Observador.h"
#include "PrimeiraFase.h"
#include "GerenciadorEstado.h"


namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorPrimeiraFase : public Observador
		{
		public:
			ObservadorPrimeiraFase();
			~ObservadorPrimeiraFase();
			void notificarEvento(const std::string& evento);
		};
	}
}
