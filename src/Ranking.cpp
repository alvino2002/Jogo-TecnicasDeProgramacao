#include "Ranking.h"
#include <fstream>


using namespace Masmorra;


Ranking::Ranking(int pontuacao) :
	pontuacao(pontuacao)
{
	fonte.loadFromFile("Korcy.otf");
	textoNome.setFont(fonte);
	textoNome.setCharacterSize(32);
	textoNome.setFillColor(sf::Color::White);
	textoNome.setPosition(100.f, 100.f);
	textoNome.setString("Nome: ");
}

void Ranking::salvar(int pontuacao, const std::string& nome) 
{
	std::ofstream arquivo("ranking.txt", std::ios::app); // abre no modo append
	if (arquivo.is_open()) {
		arquivo << nome << " " << pontuacao << std::endl;
		arquivo.close();
	}
}

Ranking::~Ranking()
{
}




void Ranking::executar()
{
}
