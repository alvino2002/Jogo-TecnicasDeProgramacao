#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace Entidades
{
	class Entidade : public Masmorra::Ente
	{
	protected:
		const sf::Vector2f tamanho;
		sf::Vector2f posicaoInicial;
		sf::RectangleShape corpo;
		float gravidade;
		sf::Vector2f velocidade;
		bool naSuperficie;
		bool ativo;

	public:
		/*valor default para velocidade ja que nem todos as entidades terao velocidade*/
		Entidade(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
		virtual ~Entidade();
		virtual void executar() = 0;
		sf::RectangleShape& getCorpo();
		void aplicarGravidade(float delta);
		float getVelocidadeX();
		float getVelocidadeY();
		void setVelocidadeX(float vY);
		void setVelocidadeY(float vX);
		bool getNaSuperficie();
		void setNaSuperficie(bool superficie);
		void setPosicao(sf::Vector2f pos);
		void setAtivo(bool at);
		bool getAtivo();
	};
}
