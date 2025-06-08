#include "GerenciadorGrafico.h"


using namespace Masmorra::Gerenciadores;


GerenciadorGrafico::GerenciadorGrafico():
	janela (new sf::RenderWindow(sf::VideoMode(800.f, 600.f), "Masmorra"))
{
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela)
	{
		delete janela;
		janela = nullptr;
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

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
	return janela;
}

void GerenciadorGrafico::limparJanela()
{
	janela->clear();
}

void GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

void GerenciadorGrafico::desenharElementos(sf::Drawable& elemento)
{	
	janela->draw(elemento);
}

void GerenciadorGrafico::mostrarElementos()
{
	janela->display();
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
	return (janela->isOpen());
}

GerenciadorGrafico* GerenciadorGrafico::pGerenciadorGrafico = nullptr;
