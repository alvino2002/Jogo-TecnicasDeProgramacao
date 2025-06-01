#include "Aranha.h"


using namespace Masmorra::Entidades::Personagens;

Aranha::Aranha(
	sf::Vector2f tamanho,
	sf::Vector2f posicaoInicial,
	sf::Vector2f velocidade,
	int vida,
	sf::Vector2f alcance,
	sf::Texture* textura,
	sf::Vector2u imageCount
) :
	Inimigo(tamanho, posicaoInicial, velocidade, vida, alcance),
	mordida(2),
	veneno(1)
{
	pGA = new Masmorra::Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(textura);
	pGA->pegarAnimacao(textura, imageCount);
}

Aranha::~Aranha()
{
	pGA = nullptr;
}

void Aranha::executar()
{
	if (!naSuperficie)
	{
		float deltaTime = pGT->getDeltaTime();
		aplicarGravidade(deltaTime);
	}

	perseguir(); // Persegue o jogador

	pGA->atualizar(2, olhandoDireita);

	corpo.setTextureRect(pGA->getRetanguloTextura());

	if (vida <= 0) // Aranha eliminada
	{
		setVivo(false);
	}
}

void Aranha::morder(Jogador* pJ)
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(mordida);

		sf::Vector2f deslocamento = pJ->getCorpo().getPosition() - corpo.getPosition();

		if (deslocamento.x > 0)
		{
			pJ->getCorpo().move(30.f, 0.f); // Empurra para a direita
		}
		else
		{
			pJ->getCorpo().move(-30.f, 0.f); // Empurra para a esquerda
		}

		pJ->invulnerabilizar();
	}
}

void Aranha::aplicarVeneno()
{
	pCavaleiro->sofrerDano(veneno);
}

void Aranha::interagir(Jogador* pJ) // Ocorreu a colisao com o jogador
{
	Cavaleiro* cavaleiro = dynamic_cast<Cavaleiro*>(pJ);

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		aplicarVeneno(); // Ao tomar dano, aplica veneno ao atacante, no caso ao cavaleiro
		cavaleiro->setEstaAtacando(false);
	}

	else
	{
		morder(pJ);
	}
}
