#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorGrafico
		{
		private:
			sf::RenderWindow* janela;
			static GerenciadorGrafico* pGerenciadorGrafico;
			GerenciadorGrafico();

		public:
			~GerenciadorGrafico();
			sf::RenderWindow* getJanela();
			static GerenciadorGrafico* getGerenciadorGrafico();
			void limparJanela();
			void fecharJanela();
			void desenharEnte(Ente* pE);
			void mostrarElementos();
			const bool verificaJanelaAberta();
		};
	}
}
