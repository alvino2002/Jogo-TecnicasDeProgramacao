#include "Esqueleto.h"


using namespace Masmorra::Entidades::Personagens;


Esqueleto::Esqueleto(
	sf::Vector2f tamanho,
	sf::Vector2f posicaoInicial,
	sf::Vector2f velocidade,
	int vida,
	sf::Vector2f range,
	sf::Texture* textura,
	sf::Vector2u imageCount
):
	Inimigo(tamanho, posicaoInicial, velocidade, vida, range),
	batida(2)
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(textura);
	pGA->pegarAnimacao(textura, imageCount);
}

Esqueleto::~Esqueleto()
{
	pGA = nullptr;
}

void Esqueleto::executar()
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

	perseguir();

	pGA->atualizar(1, olhandoDireita);
	corpo.setTextureRect(pGA->getFrameAtual());

	if (vida <= 0) // Esqueleto eliminado
	{
		setVivo(false);
		Jogador::derrotarEsqueleto();
		pCavaleiro->operator++();
	}
}

void Esqueleto::bater(Jogador* pJ)
{
	if (pJ->getInvulneravel() == false) // Jogador nao esta invuneravel, pode receber dano;
	{
		pJ->sofrerDano(batida);

		sf::Vector2f deslocamento = pJ->getCorpo().getPosition() - corpo.getPosition();

		if (deslocamento.x > 0)
		{
			pJ->getCorpo().move(20.f, 0.f); // Empurra para a direita
		}
		else
		{
			pJ->getCorpo().move(-20.f, 0.f); // Empurra para a esquerda
		}
		pJ->invulnerabilizar();
	}
}
void Esqueleto::interagir(Jogador* pJ)
{
	Entidades::Personagens::Cavaleiro* cavaleiro = dynamic_cast<Entidades::Personagens::Cavaleiro*>(pJ);

	if (cavaleiro && cavaleiro->getEstaAtacando()) // Cavaleiro atacando??
	{
		vida -= cavaleiro->getDano();
		cavaleiro->setEstaAtacando(false);
	}

	else
	{
		bater(pJ);
	}
}
