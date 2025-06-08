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
			Menu* pMenu;
		public:
			ObservadorMenu();
			~ObservadorMenu();
			void setMenu(Menu* pM);
			void notificarEvento(const std::string& evento);
		};
	}
}
