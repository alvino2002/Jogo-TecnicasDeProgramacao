#pragma once
#include "Observador.h"
#include "Fim.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorFim : public Observador
		{
		private:
			Masmorra::Interfaces::Fim* pFim;

		public:
			ObservadorFim();
			~ObservadorFim();
			void setFim(Masmorra::Interfaces::Fim* pF);
			void notificarEvento(const std::string& evento);
		};
	}
}


