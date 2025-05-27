#include "GerenciadorAnimacao.h"

namespace Gerenciadores
{
	GerenciadorAnimacao::GerenciadorAnimacao() :
		totalTime(),
		duracaoFrame(0.3f),
		numeroImgs(),
		imgAtual(),
		frameAtual()
	{
		pGT = GerenciadorTempo::getGerenciadorTempo();
	}

	GerenciadorAnimacao::~GerenciadorAnimacao()
	{
	}

	GerenciadorAnimacao* GerenciadorAnimacao::getGerenciadorAnimacao()
	{
		if (pGerenciadorAnimacao == nullptr)
		{
			pGerenciadorAnimacao = new GerenciadorAnimacao();
		}
		else
		{
			return pGerenciadorAnimacao;
		}
	}

	void GerenciadorAnimacao::pegarAnimacao(sf::Texture* texture, sf::Vector2u imageCount)
	{
		this->numeroImgs = imageCount;
		totalTime = 0.0f;
		imgAtual.x = 0;

		frameAtual.width = texture->getSize().x / float(imageCount.x);
		frameAtual.height = texture->getSize().y / float(imageCount.y);
	}

	void GerenciadorAnimacao::atualizar(int linha, bool faceRight)
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

		if (faceRight)
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

	const sf::IntRect& GerenciadorAnimacao::getUvRect() const
	{
		return frameAtual;
	}

	GerenciadorAnimacao* GerenciadorAnimacao::pGerenciadorAnimacao = nullptr;
}