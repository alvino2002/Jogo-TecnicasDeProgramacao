#pragma once
#include <SFML/Graphics.hpp>

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
			void desenharElementos(sf::Drawable& elemento);
			void mostrarElementos();
			const bool verificaJanelaAberta();
		};
	}
}
