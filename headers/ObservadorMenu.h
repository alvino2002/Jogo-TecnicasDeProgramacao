#pragma once
#include "Observador.h"
#include "Menu.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorMenu : public Observador
		{
		private:
			Masmorra::Interfaces::Menu* pMenu;

		public:
			ObservadorMenu();
			~ObservadorMenu();
			void setMenu(Masmorra::Interfaces::Menu* pM);
			void notificarEvento(const std::string& evento);
		};
	}
}
