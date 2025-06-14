#pragma once
#include "Ente.h"

namespace Masmorra
{
	namespace Interfaces
	{
		class Interface : public Ente
		{
		protected:
			sf::Font* fonte;
			sf::Texture* imagem;
			sf::Sprite* fundo;
			std::vector<std::string> opcoes;
			std::vector<sf::Vector2f> coordenadas;
			std::vector<sf::Text> textos;
			std::vector<std::size_t> tamanhos;

		public:
			Interface(int id);
			~Interface();
			const std::vector<sf::Text>& getTextos();
			const sf::Sprite& getFundo();
			virtual void inicializar() = 0;
			virtual void executar() = 0;
		};
	}
}
