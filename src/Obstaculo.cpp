#include "Obstaculo.h"



using namespace Masmorra::Entidades::Obstaculos;


Obstaculo::Obstaculo(const sf::Vector2f tam, sf::Vector2f posIni) :
	Entidade(tam, posIni)
{
}
Obstaculo::~Obstaculo()
{
}

void Obstaculo::setCavaleiro(Personagens::Cavaleiro* pCa)
{
	if (pCa)
	{
		pCavaleiro = pCa;
	}
}

void Obstaculo::setCurandeira(Personagens::Curandeira* pCu)
{
	if (pCu)
	{
		pCurandeira = pCu;
	}
}

Masmorra::Entidades::Personagens::Cavaleiro* Obstaculo::pCavaleiro = nullptr;
Masmorra::Entidades::Personagens::Curandeira* Obstaculo::pCurandeira = nullptr;
