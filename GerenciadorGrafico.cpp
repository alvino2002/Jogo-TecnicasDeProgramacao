#include "GerenciadorGrafico.h"
#include <iostream>

using namespace Gerenciadores;


GerenciadorGrafico::GerenciadorGrafico() :
	window(new sf::RenderWindow(sf::VideoMode(800.f, 600.f), "Tower"))
{
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window)
	{
		delete window;
		window = nullptr;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGerenciadorGrafico == nullptr)
	{
		pGerenciadorGrafico = new GerenciadorGrafico();
	}
	return pGerenciadorGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
	return window;
}

void GerenciadorGrafico::limparJanela()
{
	window->clear();
}

void GerenciadorGrafico::fecharJanela()
{
	window->close();
}

void GerenciadorGrafico::desenharElementos(sf::RectangleShape corpo)
{
	window->draw(corpo);
}

void GerenciadorGrafico::mostrarElementos()
{
	window->display();
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
	return (window->isOpen());
}

GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico = nullptr;