#pragma once
#include "Ente.h"

namespace Masmorra
{
	namespace Estados
	{
		class Estado : public Ente
		{
		public:
			Estado();
			virtual ~Estado();
			virtual void executar() = 0;
			virtual void verificarEvento() = 0;
		};
	}
}
