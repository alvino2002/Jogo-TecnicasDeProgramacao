#pragma once
#include "Obstaculo.h"


class Gerenciadores::GerenciadorColisao;

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo
		{
		public:
			Plataforma(sf::Vector2f tam, sf::Vector2f posIni);
			~Plataforma();
			void flutuar();
			void executar();
			void interagir();
			void interagirComEntidades(Entidade* pE);
			Gerenciadores::GerenciadorColisao* pGC;
		};

	}
}