#include "Mago.h"
#include "GerenciadorColisao.h"
#include "GerenciadorGrafico.h"


using namespace Masmorra::Entidades::Personagens;


Mago::Mago(
	sf::Vector2f tamanho,
	sf::Vector2f posicaoInicial,
	sf::Vector2f velocidade,
	int vida,
	sf::Vector2f alcance,
	sf::Texture* textura,
	sf::Vector2u imageCount
) :
	Inimigo(tamanho, posicaoInicial, velocidade, vida, alcance),
	tempoLancamento(),
	recargaLancamento(10.0f),
	lancamentoPronto(false)
{
	listaDeProjeteis.clearLista();
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(textura);
	pGA->pegarAnimacao(textura, imageCount);
}

Mago::~Mago()
{
}

void Mago::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}
	else
	{
		velocidade.y = 0;
	}

	pGA->atualizar(1, olhandoDireita);

	if (tempoLancamento.getElapsedTime().asSeconds() >= recargaLancamento)
	{
		lancamentoPronto = true;
	}

	if (lancamentoPronto)
	{
		criarFogo();
		tempoLancamento.restart();
		lancamentoPronto = false;
		pGA->atualizar(1, olhandoDireita);
	}

	corpo.setTextureRect(pGA->getFrameAtual());

	if (vida <= 0) 
	{
		setVivo(false);
		Jogador::derrotarMago();
		pCavaleiro->operator++();
	}

}

void Mago::criarFogo()
{
	sf::Texture* fogoTextura = new sf::Texture();
	fogoTextura->loadFromFile("fireball_Sprite.png");

	Fogo* fogo = new Fogo(sf::Vector2f(30.0f, 30.0f), corpo.getPosition(), sf::Vector2f(-100.0f, 0.0f), fogoTextura, sf::Vector2u(1, 1));
	pGC->incluirProjetil(fogo);
	fogo->executar();
}


void Mago::interagir(Jogador* pJ)
{
	Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJ);

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		cavaleiro->setEstaAtacando(false);
	}
}
