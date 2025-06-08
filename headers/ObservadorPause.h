#pragma once
#include "Observador.h"
#include "Pause.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorPause : public Observador
		{
		public:
			ObservadorPause();
			~ObservadorPause();
			void notificarEvento(const std::string& evento);
		};
	}
}
