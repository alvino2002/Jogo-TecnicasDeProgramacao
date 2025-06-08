#pragma once
#include "Ente.h"
#include "Observador.h"
#include "Ranking.h"
#include "GerenciadorEstado.h"

namespace Masmorra
{
	namespace Observadores
	{
		class ObservadorRanking : public Observador
		{
		public:
			ObservadorRanking();
			~ObservadorRanking();
			void notificarEvento(const std::string& evento);
		};
	}
}


