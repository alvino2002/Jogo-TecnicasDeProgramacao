#include "Fogo.h"
#include "GerenciadorTempo.h"
#include "GerenciadorColisao.h"
#include "GerenciadorAnimacao.h"


using namespace Masmorra::Entidades;


Fogo::Fogo(int id, sf::Vector2f tam, sf::Vector2f posicao, sf::Vector2f vel,
	sf::Texture* textura,
	sf::Vector2u imageCount, bool direita) :
	Entidade(id, tam, posicao, vel),
	dano(3),
	sentido(direita)
{
	corpo.setTexture(textura);
	pGA->pegarAnimacao(textura, imageCount);
}

Fogo::~Fogo()
{
}

void Fogo::executar()
{
	float deltaTime = pGT->getDeltaTempo();
	corpo.move(velocidade * deltaTime);
	aplicarGravidade(deltaTime * 0.005f);

	pGA->atualizar(0, sentido);
	corpo.setTextureRect(pGA->getFrameAtual());
}


void Fogo::atingir(Personagens::Jogador* pJ)
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(dano);
		pJ->invulnerabilizar();
	}

	setAtivo(false); // Na colisao, é automaticamente excluido
}

void Fogo::setSentido(bool sent)
{
	sentido = sent;
}
