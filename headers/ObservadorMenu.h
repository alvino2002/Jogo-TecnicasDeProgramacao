#pragma once
#include "Observador.h"
#include "Menu.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorMenu : public Observador
		{
		public:
			ObservadorMenu();
			~ObservadorMenu();
			void notificarEvento(const std::string& evento);
		};
	}
}
