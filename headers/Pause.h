#pragma once
#include "Ente.h"
#include <iostream>
#include "SFML/Graphics.hpp"

namespace Masmorra
{
	class Pause : public Ente
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
		Pause();
		~Pause();
		void executar();
		void desenhar();
	};
}
