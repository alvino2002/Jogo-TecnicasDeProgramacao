#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorTempo.h"

namespace Gerenciadores
{
	class GerenciadorAnimacao
	{
	private:
		static GerenciadorAnimacao* pGerenciadorAnimacao;
		GerenciadorAnimacao();
		GerenciadorTempo* pGT;
		sf::Vector2u numeroImgs;
		sf::Vector2u imgAtual;
		sf::IntRect frameAtual;
		float duracaoFrame;
		float totalTime;

	public:
		~GerenciadorAnimacao();
		static GerenciadorAnimacao* getGerenciadorAnimacao();
		void pegarAnimacao(sf::Texture* texture, sf::Vector2u qtdeImgs);
		void atualizar(int linha, bool faceRight);
		const sf::IntRect& getUvRect() const;

	};
}