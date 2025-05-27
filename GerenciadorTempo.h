#pragma once
#include <SFML/Graphics.hpp>


namespace Gerenciadores
{
	class GerenciadorTempo
	{
	private:
		static GerenciadorTempo* pGerenciadorTempo;
		float deltaTempo;
		sf::Clock relogio;
		GerenciadorTempo();

	public:
		~GerenciadorTempo();
		static GerenciadorTempo* getGerenciadorTempo();
		void atualizar();
		float getDeltaTime() const;
	};
}
