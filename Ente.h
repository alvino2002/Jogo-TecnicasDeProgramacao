#pragma once

namespace Gerenciadores
{
	class GerenciadorGrafico;
	class GerenciadorEvento;
	class GerenciadorColisao;
	class GerenciadorTempo;
	class GerenciadorAnimacao;
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
		Gerenciadores::GerenciadorAnimacao* pGA;

	public:
		Ente();
		virtual ~Ente();
	};
}
