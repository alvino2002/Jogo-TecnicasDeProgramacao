#pragma once
#include "Obstaculo.h"
#include "GerenciadorAnimacao.h"
#include "GerenciadorGrafico.h"

namespace Masmorra
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Plataforma : public Obstaculo
			{
			private:
				bool armadilha; // Algumas plataformas têm armadilhas, provocando dano ao Jogador quando pisar nela

			public:
				Plataforma(
					int id, 
					sf::Vector2f tam, 
					sf::Vector2f posIni, 
					sf::Texture* texture, 
					sf::Vector2u imageCount, 
					bool arm);
				~Plataforma();
				void executar();
				void obstacularizar(Entidade* pE);
				void flutuar(float deltaTempo); // Funcao para "anular" a forca gravitacional
			};

		}
	}
}
