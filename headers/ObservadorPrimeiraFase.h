#pragma once
#include "Observador.h"
#include "PrimeiraFase.h"
#include "GerenciadorEstado.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorPrimeiraFase : public Observador
		{
		private:
			Fases::PrimeiraFase* pPrim;

		public:
			ObservadorPrimeiraFase();
			~ObservadorPrimeiraFase();
			void notificarEvento(const std::string& evento);
			void setPrimeiraFase(Fases::PrimeiraFase* pP);
		};
	}
}
