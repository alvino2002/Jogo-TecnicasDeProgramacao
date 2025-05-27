#pragma once
#include "Inimigo.h"


namespace Entidades
{
	namespace Personagens
	{
		class Mago: public Inimigo
		{
		private:

		public:
			Mago();
			~Mago();
			void executar();
			void atacar();
		};
	}
}