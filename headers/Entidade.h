#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>
#include <sstream>


namespace Masmorra
{
	namespace Entidades
	{
		class Entidade : public Ente
		{
		protected:
			sf::Vector2f tamanho;
			sf::Vector2f posicao;
			sf::RectangleShape corpo;
			float gravidade;
			sf::Vector2f velocidade;
			bool naSuperficie;
			bool ativo;
			
		public:
			/*Valor default para velocidade ja que nem todos as entidades terao velocidade*/
			Entidade(int id, const sf::Vector2f tam, sf::Vector2f posIni, sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f));
			virtual ~Entidade();
			virtual void executar() = 0;
			sf::RectangleShape& getCorpo();
			void aplicarGravidade(float delta);
			float getVelocidadeX()const;
			float getVelocidadeY()const;
			void setVelocidadeX(float vX);
			void setVelocidadeY(float vY);
			bool getNaSuperficie()const;
			void setNaSuperficie(bool superficie);
			void setPosicao(sf::Vector2f pos);
			void setAtivo(bool at);
			bool getAtivo()const;
			float getPosicaoX()const;
			float getPosicaoY()const;
		};
	}
}
