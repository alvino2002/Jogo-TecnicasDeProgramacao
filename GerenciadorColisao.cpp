#include "GerenciadorColisao.h"
#include <iostream>

using namespace Entidades;

namespace Gerenciadores
{
	GerenciadorColisao::GerenciadorColisao() :
		pJogador(nullptr),
		lista_ini(),
		lista_obst(),
		lista_plataf(),
		delta_x(),
		delta_y(),
		intersect_x(),
		intersect_y(),
		direcao()
	{
		pGT = GerenciadorTempo::getGerenciadorTempo();
		lista_plataf.clearLista();
		lista_ini.clearLista();
		lista_obst.clearLista();
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
	}

	GerenciadorColisao* GerenciadorColisao::getGerenciadorColisao()
	{
		if (pGerenciadorColisao == nullptr)
		{
			pGerenciadorColisao = new GerenciadorColisao();
		}
		else
		{
			return pGerenciadorColisao;
		}
	}

	void GerenciadorColisao::executar()
	{
		colisaoJogadorInimigo();
		colisaoJogadorObstaculo();
		colisaoJogadorPlataforma();
		colisaoPlataformaEntidades();
	}

	bool GerenciadorColisao::verificarColisao(Entidade* e1, Entidade* e2) //colisao do tipo AABB
	{
		sf::Vector2f e1_Position = e1->getCorpo().getPosition();
		sf::Vector2f e2_Position = e2->getCorpo().getPosition();
		sf::Vector2f e1_size = e1->getCorpo().getSize();
		sf::Vector2f e1_HalfSize(e1_size.x / 2.0f, e1_size.y / 2.0f);
		sf::Vector2f e2_size = e2->getCorpo().getSize();
		sf::Vector2f e2_HalfSize(e2_size.x / 2.0f, e2_size.y / 2.0f);

		delta_x = fabs((e1_Position.x + e1_HalfSize.x) - (e2_Position.x + e2_HalfSize.x));
		delta_y = fabs((e1_Position.y + e1_HalfSize.y) - (e2_Position.y + e2_HalfSize.y));
		intersect_x = (delta_x)-(e2_HalfSize.x + e1_HalfSize.x);
		intersect_y = (delta_y)-(e2_HalfSize.y + e1_HalfSize.y);

		if (intersect_x < 0.0f && intersect_y < 0.0f)
		{
			return true;
		}

		return false;
	}

	void GerenciadorColisao::setJogador(Personagens::Jogador* pJ)
	{
		if (pJ)
		{
			pJogador = pJ;
		}
	}

	void GerenciadorColisao::incluirInimigo(Personagens::Inimigo* pI)
	{
		if (pI)
		{
			lista_ini.incluiEntidade(static_cast<Entidade*> (pI));
		}
	}

	void GerenciadorColisao::incluirPlataforma(Obstaculos::Plataforma* pP)
	{
		if (pP)
		{
			lista_plataf.incluiEntidade(static_cast<Entidade*> (pP));
		}
	}

	void GerenciadorColisao::incluirObstaculo(Obstaculos::Obstaculo* pO)
	{
		if (pO)
		{
			lista_obst.incluiEntidade(static_cast<Entidade*> (pO));
		}

	}

	void GerenciadorColisao::colisaoJogadorInimigo()
	{
		if (pJogador == nullptr) return; // Verifica se pJogador aponta para algo

		for (int i = 0; i < (int)lista_ini.getTam(); i++)
		{
			Personagens::Inimigo* inim = static_cast<Personagens::Inimigo*>(lista_ini.getEntidade(i));
			if (verificarColisao(static_cast<Entidade*>(inim), static_cast<Entidade*>(pJogador)))
			{
				inim->interagir();
			}
		}
	}

	void GerenciadorColisao::colisaoJogadorPlataforma()
	{
		if (pJogador == nullptr) return;

		bool colidiu = false;

		for (int i = 0; i < (int)lista_plataf.getTam(); i++)
		{
			Obstaculos::Plataforma* plat = static_cast<Obstaculos::Plataforma*>(lista_plataf.getEntidade(i));
			if (verificarColisao(static_cast<Entidade*>(plat), static_cast<Entidade*>(pJogador)))
			{
				plat->interagir();
				colidiu = true;
			}
		}
		if (!colidiu)
		{
			pJogador->setNaSuperficie(false);
		}
	}

	void GerenciadorColisao::colisaoJogadorObstaculo()
	{
		if (pJogador == nullptr) return;

		bool colidiu = false;
		for (int i = 0; i < lista_obst.getTam(); i++)
		{
			Obstaculos::Obstaculo* obst = static_cast<Obstaculos::Obstaculo*>(lista_obst.getEntidade(i));
			if (verificarColisao(static_cast<Entidade*>(obst), static_cast<Entidade*>(pJogador)))
			{
				obst->interagir();
				colidiu = true;
			}
		}
		if (!colidiu)
		{
			pJogador->setNaCaixa(false);
			pJogador->setNaLava(false);
		}
	}

	void GerenciadorColisao::colisaoPlataformaEntidades()
	{
		for (int i = 0; i < lista_plataf.getTam(); i++)
		{
			bool colidiu = false;
			Obstaculos::Plataforma* plat = static_cast<Obstaculos::Plataforma*>(lista_plataf.getEntidade(i));
			for (int j = 0; j < lista_obst.getTam(); j++)
			{
				Obstaculos::Obstaculo* obst = static_cast<Obstaculos::Obstaculo*>(lista_obst.getEntidade(j));
				if (verificarColisao(static_cast<Entidade*>(obst), static_cast<Entidade*>(plat)))
				{
					plat->interagirComEntidades(obst);
					colidiu = true;
				}
				if (!colidiu)
				{
					obst->setNaSuperficie(false);
				}
			}
		}

		for (int i = 0; i < lista_plataf.getTam(); i++)
		{
			bool colidiu = false;
			Obstaculos::Plataforma* plat = static_cast<Obstaculos::Plataforma*>(lista_plataf.getEntidade(i));
			for (int k = 0; k < lista_ini.getTam(); k++)
			{
				Personagens::Inimigo* ini = static_cast<Personagens::Inimigo*>(lista_ini.getEntidade(k));
				if (verificarColisao(static_cast<Entidade*>(ini), static_cast<Entidade*>(plat)))
				{
					plat->interagirComEntidades(ini);
					colidiu = true;
				}
				if (!colidiu)
				{
					ini->setNaSuperficie(false);
				}
			}

		}
	}

	float GerenciadorColisao::getDeltaX()
	{
		return delta_x;
	}

	float GerenciadorColisao::getDeltaY()
	{
		return delta_y;
	}

	float GerenciadorColisao::getIntersectX()
	{
		return intersect_x;
	}

	float GerenciadorColisao::getIntersectY()
	{
		return intersect_y;
	}

	void GerenciadorColisao::removerEntidade(Entidades::Entidade* pE)
	{
		if (dynamic_cast<Entidades::Personagens::Inimigo*>(pE))
		{
			lista_ini.deleteEntidade(pE);
		}
		else if (dynamic_cast<Entidades::Personagens::Jogador*>(pE))
		{
			delete pJogador;
			pJogador = nullptr;
		}
	}

	GerenciadorColisao* GerenciadorColisao::pGerenciadorColisao = nullptr;
}