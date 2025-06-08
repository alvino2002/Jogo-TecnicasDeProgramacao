#pragma once
#include "Menu.h"
#include "Estado.h"
#include "ObservadorMenu.h"

namespace Masmorra
{
	namespace Estados
	{
		class EstadoMenu : public Estado
		{
		private:
			Menu* pMenu;
			Observadores::ObservadorMenu* pObs;

		public:
			EstadoMenu();
			~EstadoMenu();
			void executar();
			void verificarEvento();
		};
	}
}
