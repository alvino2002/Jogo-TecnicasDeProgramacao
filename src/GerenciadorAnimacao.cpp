#include "GerenciadorAnimacao.h"


namespace Gerenciadores
{
	GerenciadorAnimacao::GerenciadorAnimacao():
		numeroImgs(),
		imgAtual(),
		frameAtual(),
		duracaoFrame(0.3f),
		totalTime()
	{
		pGT = GerenciadorTempo::getGerenciadorTempo();
	}

	GerenciadorAnimacao::~GerenciadorAnimacao()
	{
	}


	void GerenciadorAnimacao::pegarAnimacao(sf::Texture* textura, sf::Vector2u imageCount)
	{
		numeroImgs = imageCount;
		totalTime = 0.0f;
		imgAtual.x = 0;

		frameAtual.width = textura->getSize().x / float(imageCount.x);
		frameAtual.height = textura->getSize().y / float(imageCount.y);
	}

	void GerenciadorAnimacao::atualizar(int linha, bool olhandoDireita)
	{
		float deltaTime = pGT->getDeltaTime();

		imgAtual.y = linha;
		totalTime += deltaTime;

		if (totalTime >= duracaoFrame)
		{
			totalTime -= duracaoFrame;
			imgAtual.x++;

			if (imgAtual.x >= numeroImgs.x)
			{
				imgAtual.x = 0;
			}
		}

		frameAtual.top = imgAtual.y * frameAtual.height;

		if (olhandoDireita)
		{
			frameAtual.left = imgAtual.x * frameAtual.width;
			frameAtual.width = abs(frameAtual.width);
		}
		else
		{
			frameAtual.left = (imgAtual.x + 1) * abs(frameAtual.width);
			frameAtual.width = -abs(frameAtual.width);
		}
	}

	const sf::IntRect& GerenciadorAnimacao::getRetanguloTextura() const
	{
		return frameAtual;
	}
}
