#pragma once
#include <SFML/Graphics.hpp>

class GerenciadoGrafico
{
private:
	sf::RenderWindow* window;
	static GerenciadoGrafico* pGrafico;
	GerenciadoGrafico();

public:
	~GerenciadoGrafico();
	static GerenciadoGrafico* getGerenciadorGrafico();
	sf::RenderWindow* getWindow();
	void drawElements(sf::RectangleShape corpo);
	void displayElements();
	void closeWindow();
	const bool verificaJanelaAberta();
};

