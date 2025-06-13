#include "Ente.h"
#include "GerenciadorColisao.h"
#include "GerenciadorTempo.h"
#include "GerenciadorGrafico.h"
#include <iostream>


using namespace Masmorra;

Ente::Ente(int i) :
	id(i)
{
	pGG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	pGC = Gerenciadores::GerenciadorColisao::getGerenciadorColisao();
	pGT = Gerenciadores::GerenciadorTempo::getGerenciadorTempo();
	
	pGA = new Gerenciadores::GerenciadorAnimacao();
}

Ente::~Ente()
{
}

int Ente::getId()
{ 
	return id;
}

void Ente::desenhar()
{
	if (this)
	{
		pGG->desenharEnte(this);
	}
}

Gerenciadores::GerenciadorGrafico* Ente::pGG = nullptr;
Gerenciadores::GerenciadorColisao* Ente::pGC = nullptr;
Gerenciadores::GerenciadorTempo* Ente::pGT = nullptr;


