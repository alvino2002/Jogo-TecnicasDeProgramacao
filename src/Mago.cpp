#include "Mago.h"
#include "GerenciadorColisao.h"
#include "GerenciadorGrafico.h"


using namespace Masmorra::Entidades::Personagens;


Mago::Mago(int id,
	sf::Vector2f tamanho,
	sf::Vector2f posicao,
	sf::Vector2f velocidade,
	int vida,
	int nivelDeMaldade,
	sf::Vector2f alcance,
	sf::Texture* textura,
	sf::Vector2u imageCount
) :
	Inimigo(id, tamanho, posicao, velocidade, vida,  nivelDeMaldade, alcance),

	tempoLancamento(),
	lancamentoPronto(false),
	chamas(1)
{
	if (nivelDeMaldade == 1)
	{
		olhandoDireita = true;
		recargaLancamento = 5.0f;
	}
	else
	{
		olhandoDireita = false;
		recargaLancamento = 3.0f;
	}

	listaDeProjeteis.clearLista();
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
	
	if (nivelDeMaldade == 1) 
	{
		pGA->atualizar(1, true);
	}
	else
	{
		pGA->atualizar(1, false); // Mago olhando para esquerda
	}

	if (tempoLancamento.getElapsedTime().asSeconds() >= recargaLancamento)
	{
		lancamentoPronto = true;
	}

	if (lancamentoPronto)
	{
		criarFogo();
		tempoLancamento.restart();
		lancamentoPronto = false;
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

	if (nivelDeMaldade == 1) // Olhando para direita
	{
		Fogo* fogo = new Fogo(1, sf::Vector2f(30.0f, 30.0f), corpo.getPosition(), 
			sf::Vector2f(100.0f, 0.0f), fogoTextura, sf::Vector2u(1, 1), true);
		pGC->incluirProjetil(fogo);
		fogo->executar();
	}

	else
	{
		Fogo* fogo = new Fogo(1, sf::Vector2f(30.0f, 30.0f), corpo.getPosition(), 
			sf::Vector2f(-100.0f, 0.0f), fogoTextura, sf::Vector2u(1, 1), false);
		pGC->incluirProjetil(fogo);
		fogo->executar();
	}
}


void Mago::danificar(Jogador* pJ)
{
	Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJ);

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		cavaleiro->setEstaAtacando(false);
	}

	else
	{
		queimar(pJ);
	}
}

void Mago::queimar(Jogador* pJ)
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(chamas);
		pJ->invulnerabilizar();
	}
}
