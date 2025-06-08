#pragma once
#include "EstadoPrimeiraFase.h"
#include "EstadoPause.h"
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorEstado.h"


namespace Masmorra
{
	class Principal
	{
	private:
		Gerenciadores::GerenciadorEstado* pGEs;
		Gerenciadores::GerenciadorGrafico* pGG;
		Gerenciadores::GerenciadorEvento* pGE;
	public:
		Principal();
		~Principal();
		void rodarJogo();
	};
}
