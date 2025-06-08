#pragma once
#include <stack>
#include "Estado.h"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorEstado
		{
		private:
			std::stack <Estados::Estado*> pilhaEstados;
			static GerenciadorEstado* pGerenciadorEstado;
			GerenciadorEstado();
		public:
			~GerenciadorEstado();
			static GerenciadorEstado* getGerenciadorEstado();
			void executar();
			void adicionarEstado(Estados::Estado* estado);
			void removerEstado();
			//Estado* getEstadoAtual();
		};
	}
}
