#include "ObservadorSegundaFase.h"
#include "EstadoPause.h"
#include "EstadoRanking.h"
#include "EstadoFim.h"


using namespace Masmorra::Observadores;


ObservadorSegundaFase::ObservadorSegundaFase() :
	pSegFase(),
	Observador()
{

}

ObservadorSegundaFase::~ObservadorSegundaFase()
{

}

void ObservadorSegundaFase::notificarEvento(const std::string& evento)
{
	if (evento == "PAUSE")
	{
		Estados::EstadoPause* pause = new Estados::EstadoPause();
		pGEs->adicionarEstado(pause);
	}


    if (evento == "VENCEU")
    {
        std::string nomeJogador;
        sf::Font fonte;
        sf::Text textoNome;
        sf::Text instrucoes;

        fonte.loadFromFile("Korcy.otf");

        textoNome.setFont(fonte);
        textoNome.setCharacterSize(32);
        textoNome.setFillColor(sf::Color::White);
        textoNome.setPosition(100.f, 100.f);
        textoNome.setString("Nome: ");


        instrucoes.setFont(fonte);
        instrucoes.setCharacterSize(20);
        instrucoes.setFillColor(sf::Color::White);
        instrucoes.setPosition(100.f, 200.f);
        instrucoes.setString("Pressione enter para salvar");


        sf::Event event{};
        bool nomeConfirmado = false;

        sf::RenderWindow* janela = pGG->getJanela();
        janela->setView(janela->getDefaultView());

        while (janela->isOpen() && !nomeConfirmado)
        {
            while (janela->pollEvent(event))
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    sf::Keyboard::Key tecla = event.key.code;

                    if (tecla == sf::Keyboard::Enter)
                    {
                        nomeConfirmado = true;
                        Ranking::salvar(pSegFase->getPontuacao(), nomeJogador);
                        pGEs->removerEstado();
                        pGEs->removerEstado();
                    }
                    else if (tecla == sf::Keyboard::Backspace && !nomeJogador.empty())
                    {
                        nomeJogador.pop_back();
                    }
                    else if (tecla >= sf::Keyboard::A && tecla <= sf::Keyboard::Z && nomeJogador.size() < 12)
                    {
                        nomeJogador += static_cast<char>('A' + (tecla - sf::Keyboard::A)); // sempre maiúscula
                    }
                    else if (tecla == sf::Keyboard::Space && nomeJogador.size() < 12)
                    {
                        nomeJogador += ' ';
                    }

                    textoNome.setString("Nome: " + nomeJogador);
                }
            }

            pGG->limparJanela();
            pGG->desenharElementos(instrucoes);
            pGG->desenharElementos(textoNome);
            pGG->mostrarElementos();
        }

    }

	if (evento == "FIM")
	{
		Estados::EstadoFim* fim = new Estados::EstadoFim();
		pGEs->adicionarEstado(fim);

	}
}

void ObservadorSegundaFase::setSegundaFase(Fases::SegundaFase* pSF)
{
	if (pSF)
	{
		pSegFase = pSF;
	}
}
