#pragma once
#include "Interface.h"

namespace Masmorra
{
	namespace Interfaces
	{
		class Menu : public Interface
		{
		private:
			std::string menu;
			std::string fase1;
			std::string fase2;
			std::string ranking;

		public:
			Menu(int id);
			~Menu();
			void inicializar();
			void executar();
		};
	}
}

