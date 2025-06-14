#pragma once
#include "Observador.h"
#include "Pause.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorPause : public Observador
		{
		private:
			Masmorra::Interfaces::Pause* pPause;

		public:
			ObservadorPause();
			~ObservadorPause();
			void setPause(Masmorra::Interfaces::Pause* pP);
			void notificarEvento(const std::string& evento);
		};
	}
}
