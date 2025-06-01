#pragma once


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
		Gerenciadores::GerenciadorEstado* pGEs;
		Gerenciadores::GerenciadorGrafico* pGG;
		Gerenciadores::GerenciadorEvento* pGE;
		Gerenciadores::GerenciadorColisao* pGC;
		Gerenciadores::GerenciadorTempo* pGT;

	public:
		Ente();
		virtual ~Ente();
	};
}
