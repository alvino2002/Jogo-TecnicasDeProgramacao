#include "Fim.h"
#include "GerenciadorGrafico.h"


using namespace Masmorra;

Fim::Fim() 
{
    janela = pGG->getJanela();
}

Fim::~Fim() 
{
}

void Fim::desenhar()
{
    /*Fundo preto*/
    fundo.setSize(sf::Vector2f(janela->getSize()));
    fundo.setFillColor(sf::Color::Black);

    /*Carregar fonte*/
    fonte.loadFromFile("Korcy.otf");

    /*Texto principal*/
    texto.setFont(fonte);
    texto.setString("FIM DO JOGO");
    texto.setCharacterSize(60);
    texto.setFillColor(sf::Color::Red);

    /*Posicionar o texto na tela*/
    sf::FloatRect limites = texto.getLocalBounds();
    texto.setOrigin(limites.width / 2, limites.height / 2);
    texto.setPosition(janela->getSize().x / 2.0f, janela->getSize().y / 2.0f - 120);

    /*Instrucoes para sair*/
    sf::Text textoInstrucoes;
    textoInstrucoes.setFont(fonte);
    textoInstrucoes.setString("(Aperte ESC para sair)");
    textoInstrucoes.setCharacterSize(20); 
    textoInstrucoes.setFillColor(sf::Color::White);

    /*Posicionar*/
    sf::FloatRect limitesInst = textoInstrucoes.getLocalBounds();
    textoInstrucoes.setOrigin(limitesInst.width / 2, limitesInst.height / 2);
    textoInstrucoes.setPosition(janela->getSize().x / 2.0f, janela->getSize().y / 2.0f + 120);


    pGG->desenharElementos(fundo);
    pGG->desenharElementos(texto);
    pGG->desenharElementos(textoInstrucoes);
}

void Fim::executar()
{
    sf::RenderWindow* janela = pGG->getJanela();
    janela->setView(janela->getDefaultView());

    pGG->limparJanela();
   
    desenhar();

    pGG->mostrarElementos();
}

