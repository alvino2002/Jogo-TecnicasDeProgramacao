#pragma once
#include "Ente.h"
#include "Entidade.h"



	class Fase : public Masmorra::Ente
	{
	public:
		Fase();
		~Fase();
		virtual void criarJogador() = 0;
		virtual void criarCenario() = 0;
		virtual void criarInimigos() = 0;
		virtual void executar() = 0;
	};

