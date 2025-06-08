#pragma once
#include "SFML/Graphics.hpp"

namespace Masmorra
{
	namespace Gerenciadores
	{
		class GerenciadorGrafico;
		class GerenciadorEvento;
		class GerenciadorColisao;
		class GerenciadorTempo;
		class GerenciadorEstado;
	}
}

namespace Masmorra
{
	class Ente
	{
	protected:
		static Gerenciadores::GerenciadorEstado* pGEs;
		static Gerenciadores::GerenciadorGrafico* pGG;
		static Gerenciadores::GerenciadorEvento* pGE;
		static Gerenciadores::GerenciadorColisao* pGC;
		static Gerenciadores::GerenciadorTempo* pGT;

	public:
		Ente();
		virtual ~Ente();
	};
}
