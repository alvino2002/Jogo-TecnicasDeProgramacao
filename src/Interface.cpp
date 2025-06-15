#include "Interface.h"


using namespace Masmorra::Interfaces;


Interface::Interface(int id):
	Ente(id)
{ 
	fonte = new sf::Font();
	fundo = new sf::Sprite();
	imagem = new sf::Texture();
}

Interface::~Interface()
{
}

const std::vector<sf::Text>& Interface::getTextos()
{
	return textos;
}

const sf::Sprite& Interface::getFundo()
{
	return *fundo;
}
