#include "Menu.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorTempo.h"


using namespace Masmorra::Interfaces;


Menu::Menu(int id) :
	Interface(id)
{	
	inicializar();
}

Menu::~Menu()
{
}

void Menu::inicializar()
{
	/*Carregar fonte e textura*/
	fonte->loadFromFile("Korcy.otf");
	imagem->loadFromFile("menuInicial_Sprite.jpg");

	/*Aplicar textura ao fundo*/
	fundo->setTexture(*imagem);

	/*Ajuste da escala*/
	sf::Vector2u tamanho = imagem->getSize();
	float escalaX = 800.0f / tamanho.x;
	float escalaY = 600.0f / tamanho.y;
	fundo->setScale(escalaX, escalaY);
	fundo->setPosition(0.0f, 0.0f);

	/*Inicializar os textos*/
	opcoes.clear();
	opcoes.push_back("Menu");
	opcoes.push_back("Primeira Fase (P)");
	opcoes.push_back("Segunda Fase (S)");
	opcoes.push_back("Ranking (R)");

	textos.resize(4);

	coordenadas =
	{
		{305.f, 50.f},    // Título
		{260.f, 217.f},   // Botão 1
		{255.f, 296.f},   // Botão 2
		{305.f, 375.f}    // Botão 3
	};
	tamanhos = { 60, 36, 36, 36 };

	for (std::size_t i = 0; i < textos.size(); i++)
	{
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setPosition(coordenadas[i]);
		textos[i].setCharacterSize(tamanhos[i]);
		textos[i].setFillColor(sf::Color::Red);
		textos[i].setOutlineColor(sf::Color::Black);
		textos[i].setOutlineThickness(2);
	}
}

void Menu::executar()
{
	desenhar();
	pGG->mostrarElementos();
}
