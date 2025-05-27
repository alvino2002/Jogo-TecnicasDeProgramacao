#pragma once
#include <SFML/Graphics.hpp>


namespace Gerenciadores
{
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* window;
		static GerenciadorGrafico* pGerenciadorGrafico;
		GerenciadorGrafico();

	public:
		~GerenciadorGrafico();
		sf::RenderWindow* getWindow();
		static GerenciadorGrafico* getGerenciadorGrafico();
		void limparJanela();
		void fecharJanela();
		void desenharElementos(sf::RectangleShape corpo);
		void mostrarElementos();
		const bool verificaJanelaAberta();
	};
}