#pragma once
#include "Ente.h"

namespace Masmorra
{
	class Menu : public Ente
	{
	private:
		sf::Font* fonte;
		sf::Texture* imagem;
		sf::Sprite* fundo;
		std::vector<const char*> opcoes;
		std::vector<sf::Vector2f> coordenadas;
		std::vector<sf::Text> textos;
		std::vector<std::size_t> tamanhos;
	public:
		Menu();
		~Menu();
		void desenhar();
		void executar();
	};
}

