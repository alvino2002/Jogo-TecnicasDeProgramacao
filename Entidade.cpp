#include "Entidade.h"
#include <iostream>

namespace Entidades
{
	Entidade::Entidade(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel):
		Ente(),
		gravidade(980.f),
		naSuperficie(true),
		tamanho(tam),
		ativo(true)
	{
		corpo.setSize(tam);
		corpo.setPosition(posIni);
		velocidade = vel;
	}

	Entidade::~Entidade()
	{
	}

	/*estamos retornando uma referencia, ja que alteraçoes feitas
	no corpo devem feitas no proprio atributo e nao em uma copia*/
	sf::RectangleShape& Entidade::getCorpo()
	{
		return corpo;
	}

	void Entidade::aplicarGravidade(float deltaTime)
	{
		velocidade.y += gravidade * deltaTime;
		corpo.move(0.0f, velocidade.y * deltaTime);
	}

	float Entidade::getVelocidadeY()
	{
		return velocidade.y;
	}

	void Entidade::setVelocidadeY(float vY)
	{
		velocidade.y = vY;
	}

	void Entidade::setVelocidadeX(float vX)
	{
		velocidade.x = vX;
	}

	float Entidade::getVelocidadeX()
	{
		return velocidade.x;
	}

	bool Entidade::getNaSuperficie()
	{
		return naSuperficie;
	}

	void Entidade::setNaSuperficie(bool superficie)
	{
		naSuperficie = superficie;
	}

	void Entidade::setPosicao(sf::Vector2f pos)
	{
		corpo.setPosition(pos);
	}

	void Entidade::setAtivo(bool at)
	{
		ativo = at;
	}

	bool Entidade::getAtivo()
	{
		return ativo;
	}
}