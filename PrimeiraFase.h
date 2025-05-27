#pragma once
#include "Fase.h"
#include "ListaEntidades.h"
#include "time.h"
#include "Aranha.h"
#include "Jogador.h"
#include "Caixa.h"
#include "Lava.h"


class PrimeiraFase : public Fase
{
private:
	Listas::ListaEntidades listaEntidades;
public:
	PrimeiraFase();
	~PrimeiraFase();
	int numeroInimigos;
	int numeroObstaculos;
	void criarJogador();
	void criarCenario();
	void criarInimigos();
	void criarObstaculos();
	void executar();
};

