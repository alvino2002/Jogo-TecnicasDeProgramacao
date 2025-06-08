#include "Fogo.h"
#include "GerenciadorTempo.h"
#include "GerenciadorColisao.h"
#include "GerenciadorAnimacao.h"


using namespace Masmorra::Entidades;


Fogo::Fogo(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel, 
	sf::Texture* textura,
	sf::Vector2u imageCount) :
	Entidade(tam, posIni, vel),
	dano(3)
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
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

	pGA->atualizar(0, false);
	corpo.setTextureRect(pGA->getFrameAtual());
}


void Fogo::interagir(Personagens::Jogador* pJ)
{
	if (pJ->getInvulneravel() == false)
	{
		pJ->sofrerDano(dano);
		pJ->invulnerabilizar();
	}

	setAtivo(false); // Na colisao, é automaticamente excluido
}
