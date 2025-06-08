#include "Menu.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorTempo.h"


using namespace Masmorra;


Menu::Menu() :
	Ente()
{
	fonte = new sf::Font();
	imagem = new sf::Texture();
	fundo = new sf::Sprite();
}

Menu::~Menu()
{

}

void Menu::desenhar()
{
	/*Carregar fonte e textura*/
	fonte->loadFromFile("Korcy.otf");
	imagem->loadFromFile("menu_pause.png");

	/*Aplicar textura ao fundo*/
	fundo->setTexture(*imagem);

	/*Ajuste da escala*/
	sf::Vector2u tamanho = imagem->getSize();
	float escalaX = 800.0f / tamanho.x;
	float escalaY = 600.0f / tamanho.y;
	fundo->setScale(escalaX, escalaY);
	fundo->setPosition(0.0f, 0.0f);

	/*Inicializar os textos*/
	opcoes = { "Menu", "Primeira Fase (P)", "Segunda Fase (S)", "Ranking (R)" };
	textos.resize(4);
	coordenadas =
	{
		{300.f, 80.f},    // Título
		{310.f, 220.f},   // Botão 1
		{310.f, 300.f},   // Botão 2
		{310.f, 380.f}    // Botão 3
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

	sf::Sprite sprite;
	sf::Texture texture;

	pGG->desenharElementos(*fundo);

	pGT->atualizar();

	for (auto& t : textos)
	{
		pGG->desenharElementos(t);
	}
}

void Menu::executar()
{
	/*Centralizar a camera*/
	sf::RenderWindow* janela = pGG->getJanela();
	janela->setView(janela->getDefaultView());

	pGG->limparJanela();

	desenhar();

	pGG->mostrarElementos();
}
