#pragma once
#include "Ente.h"
#include <string>

namespace Masmorra
{
	namespace Observadores
	{
		class Observador : public Ente
		{
		public:
			Observador();
			~Observador();
			virtual void notificarEvento(const std::string& evento) = 0;

		};
	}
}
