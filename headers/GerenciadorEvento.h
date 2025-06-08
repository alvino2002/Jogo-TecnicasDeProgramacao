#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorTempo.h"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorEvento
		{
		private:
			static GerenciadorEvento* pGerenciadorEvento;
			GerenciadorGrafico* pG;
			GerenciadorTempo* pGT;
			GerenciadorEvento();

		public:
			~GerenciadorEvento();
			static GerenciadorEvento* getGerenciadorEvento();
			void executar();
		};
	}
}
