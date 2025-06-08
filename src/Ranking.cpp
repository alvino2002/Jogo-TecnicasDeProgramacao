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
	sf::RenderWindow* janela = pGG->getJanela();
	janela->setView(janela->getDefaultView());

	sf::Event event{};                // Evento usado para capturar entrada do usuário
	bool nomeConfirmado = false;   // Flag que indica se o jogador já apertou Enter

	// Loop principal: continua até o jogador confirmar o nome ou fechar a janela
	while (!nomeConfirmado)
	{
		if (event.type == sf::Event::TextEntered) 
		{
			// Se a tecla for Backspace, remove último caractere
			if (event.text.unicode == '\b' && !nomeJogador.empty()) 
			{
				nomeJogador.pop_back();
			}
			// Se for Enter (código 13 ou '\r'), confirma nome
			else if (event.text.unicode == '\r') 
			{
				nomeConfirmado = true;
			}
			// Se for caractere normal e o nome tiver menos de 12 letras
			else if (event.text.unicode < 128 && nomeJogador.size() < 12)
			{
				nomeJogador += static_cast<char>(event.text.unicode);
			}

			// Atualiza o texto que será mostrado na tela
			textoNome.setString("Nome: " + nomeJogador);
		}

		// Desenha a tela com o nome atual
		pGG->limparJanela();
		pGG->desenharElementos(textoNome);
		pGG->mostrarElementos();
	}
}
