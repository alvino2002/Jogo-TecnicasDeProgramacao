#include "Curandeira.h"


using namespace Masmorra::Entidades::Personagens;


Curandeira::Curandeira(sf::Vector2f tamanho, sf::Vector2f posicaoInicial, sf::Vector2f velocidade, int vida,
	sf::Texture* texture, sf::Vector2u imageCount) :
	Jogador(tamanho, posicaoInicial, velocidade, vida),
	pulo(80.0f),
	olhandoDireita(true),
	tempoCura(),
	recargaCura(30.0f),
	curaPronta(true),
	curaAliado(false),
	pCavaleiro()
{
	pGA = new Gerenciadores::GerenciadorAnimacao();
	corpo.setTexture(texture);
	pGA->pegarAnimacao(texture, imageCount);
}

Curandeira::~Curandeira()
{
	pGA = nullptr;
	pCavaleiro = nullptr;
}

void Curandeira::setCavaleiro(Cavaleiro* pCa)
{
	if (pCa)
	{
		pCavaleiro = pCa;
	}
}

void Curandeira::executar()
{
	velAtual.x = 0.0f;

	/*Movimento da curandeira*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velAtual.x -= velocidade.x;
		olhandoDireita = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velAtual.x += velocidade.x;
		olhandoDireita = true;
	}

	/*Atualizar animacao*/
	unsigned int linha = 0;

	corpo.setTextureRect(pGA->getFrameAtual());
	pGA->atualizar(2, olhandoDireita);

	/*Pulo da curandeira*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (naSuperficie))
	{
		velAtual.y = -sqrtf(2.0f * gravidade * pulo);

		if (naSuperficie) // Em cima da plataforma
		{
			naSuperficie = false;
		}
	}

	float deltaTime = pGT->getDeltaTempo();

	if (naSuperficie)
	{
		velAtual.y = 0;
	}
	else
	{
		velAtual.y += gravidade * deltaTime;
	}

	corpo.move(velAtual * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && curaPronta)
	{
		curaPronta = false;
		curar();
		tempoCura.restart();
	}

	else if (tempoCura.getElapsedTime().asSeconds() >= recargaCura)
	{
		curaPronta = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (!curaAliado) 
		{
			curarAliado();
			curaAliado = true;
		}
	}
	else
	{
		curaAliado = false;
	}


	if (invulneravel && tempoInvulneravel.getElapsedTime().asSeconds() >= duracaoInvulneravel)
	{
		setInvulneravel(false);
	}

	if (invulneravel)
	{
		float tempoPiscar = tempoInvulneravel.getElapsedTime().asSeconds();
		bool visivel = static_cast<int>(tempoPiscar * 10) % 2 == 0;
		corpo.setFillColor(visivel ? sf::Color::White : sf::Color::Transparent);
	}
	else
	{
		corpo.setFillColor(sf::Color::White);
	}

	if (vida <= 0)
	{
		setVivo(false);
	}

}
void Curandeira::curar() // Curar a si mesma
{
	vida += 5;
}

void Curandeira::curarAliado()
{
	if (pCavaleiro)
	{
		vida -= 10; // Fornece sua propria energia vital
		pCavaleiro->setVida(pCavaleiro->getVida() + 10);
	}
}
