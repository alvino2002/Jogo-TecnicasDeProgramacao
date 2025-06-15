#include "Aranha.h"


using namespace Masmorra::Entidades::Personagens;


Aranha::Aranha(
	int id,
	sf::Vector2f tamanho,
	sf::Vector2f posicao,
	sf::Vector2f velocidade,
	int vida,
	int nivelMaldade,
	sf::Vector2f alcance,
	sf::Texture* textura,
	sf::Vector2u imageCount
) :
	Inimigo(id, tamanho, posicao, velocidade, vida, nivelMaldade, alcance)
{
	if (nivelDeMaldade == 1)
	{
		mordida = 2;
		veneno = 1;
	}

	else // nivelDeMaldade == 2
	{
		mordida = 3;
		veneno = 2;
	}
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
		float deltaTime = pGT->getDeltaTempo();
		aplicarGravidade(deltaTime);
	}

	perseguir(); // Persegue o jogador

	pGA->atualizar(2, olhandoDireita);

	corpo.setTextureRect(pGA->getFrameAtual());

	if (vida <= 0) // Aranha eliminada
	{
		setVivo(false);
		Jogador::derrotarAranha();
		pCavaleiro->operator++(); 
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

void Aranha::danificar(Jogador* pJ) // Ocorreu a colisao com o jogador
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


