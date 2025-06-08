#include "Entidade.h"
#include "Plataforma.h"


using namespace Masmorra::Entidades;


Entidade::Entidade(const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel) :
	Ente(),
	tamanho(),
	posicaoInicial(),
	corpo(),
	gravidade(980.f),
	naSuperficie(false),
	ativo(true)
{
	corpo.setSize(tam);
	corpo.setPosition(posIni);
	velocidade = vel;
}

Entidade::~Entidade()
{
}

/*Estamos retornando uma referencia, ja que alteraçoes feitas
no corpo devem feitas no proprio atributo e nao em uma copia*/
sf::RectangleShape& Entidade::getCorpo()
{
	return corpo;
}

void Entidade::aplicarGravidade(float deltaTime)
{
	if (dynamic_cast<Obstaculos::Plataforma*>(this) == nullptr) // Plataforma nao pode sofrer acao da gravidade
	{
		velocidade.y += gravidade * deltaTime;
		corpo.move(0.0f, velocidade.y * deltaTime);
	}
}

float Entidade::getVelocidadeX()const
{
	return velocidade.x;
}

float Entidade::getVelocidadeY()const
{
	return velocidade.y;
}

void Entidade::setVelocidadeX(float vX)
{
	velocidade.x = vX;
}

void Entidade::setVelocidadeY(float vY)
{
	velocidade.y = vY;
}

bool Entidade::getNaSuperficie()const
{
	return naSuperficie;
}

void Entidade::setNaSuperficie(bool superficie)
{
	naSuperficie = superficie;
}

void Entidade::setPosicao(sf::Vector2f pos)
{
	if (this) // Verificar se nao é nulo
	{
		corpo.setPosition(pos);
	}
}

void Entidade::setAtivo(bool at)
{
	ativo = at;
}

bool Entidade::getAtivo()const
{
	return ativo;
}

