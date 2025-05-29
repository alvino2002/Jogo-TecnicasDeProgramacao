#pragma once

namespace Gerenciadores
{
	class GerenciadorGrafico;
	class GerenciadorEvento;
	class GerenciadorColisao;
	class GerenciadorTempo;
}

namespace Masmorra
{
	class Ente
	{
	protected:
		Gerenciadores::GerenciadorGrafico* pGG;
		Gerenciadores::GerenciadorEvento* pGE;
		Gerenciadores::GerenciadorColisao* pGC;
		Gerenciadores::GerenciadorTempo* pGT;

	public:
		Ente();
		virtual ~Ente();
	};
}
