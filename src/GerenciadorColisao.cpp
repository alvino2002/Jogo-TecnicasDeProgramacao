#include "GerenciadorColisao.h"
#include "Fogo.h"


using namespace Masmorra::Gerenciadores;


GerenciadorColisao::GerenciadorColisao() :
	lista_jogadores(),
	lista_ini(),
	lista_obst(),
	delta_x(),
	delta_y(),
	intersect_x(),
	intersect_y()
{
	pGT = GerenciadorTempo::getGerenciadorTempo();
	lista_ini.clearLista();
	lista_obst.clearLista();
	lista_jogadores.clearLista();
	lista_projeteis.clearLista();
}

GerenciadorColisao::~GerenciadorColisao()
{
	lista_ini.clearLista();
	lista_obst.clearLista();
	lista_jogadores.clearLista();
	lista_projeteis.clearLista();
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
	colisaoObstaculosEntidades();
	colisaoJogadorProjetil();
}

bool GerenciadorColisao::verificarColisao(Entidades::Entidade* e1, Entidades::Entidade* e2) //colisao do tipo AABB
{
	sf::Vector2f e1_Position = e1->getCorpo().getPosition();
	sf::Vector2f e2_Position = e2->getCorpo().getPosition();
	sf::Vector2f e1_size = e1->getCorpo().getSize();
	sf::Vector2f e1_HalfSize(e1_size.x / 2.0f, e1_size.y / 2.0f);
	sf::Vector2f e2_size = e2->getCorpo().getSize();
	sf::Vector2f e2_HalfSize(e2_size.x / 2.0f, e2_size.y / 2.0f);

	delta_x = fabs((e1_Position.x + e1_HalfSize.x) - (e2_Position.x + e2_HalfSize.x));
	delta_y = fabs((e1_Position.y + e1_HalfSize.y) - (e2_Position.y + e2_HalfSize.y));
	intersect_x = (delta_x) - (e2_HalfSize.x + e1_HalfSize.x);
	intersect_y = (delta_y) - (e2_HalfSize.y + e1_HalfSize.y);

	if (intersect_x < 0.0f && intersect_y < 0.0f) // Houve colisao
	{
		return true; 
	}

	return false;
}


void GerenciadorColisao::incluirProjetil(Entidades::Entidade* pF)
{
	if (pF)
	{
		lista_projeteis.incluirEntidade(static_cast<Entidades::Entidade*>(pF));
	}
}

void GerenciadorColisao::incluirJogador(Entidades::Personagens::Jogador* pJ)
{
	if (pJ)
	{
		lista_jogadores.incluirEntidade(static_cast<Entidades::Entidade*>(pJ));
	}
}

void GerenciadorColisao::incluirInimigo(Entidades::Personagens::Inimigo* pI)
{
	if (pI)
	{
		lista_ini.incluirEntidade(static_cast<Entidades::Entidade*> (pI));
	}
}

void GerenciadorColisao::incluirObstaculo(Entidades::Obstaculos::Obstaculo* pO)
{
	if (pO)
	{
		lista_obst.incluirEntidade(static_cast<Entidades::Entidade*> (pO));
	}
}

void GerenciadorColisao::colisaoJogadorInimigo()
{
	for (int i = 0; i < lista_ini.getTam(); i++)
	{
		Entidades::Personagens::Inimigo* ini = static_cast<Entidades::Personagens::Inimigo*>(lista_ini.getEntidade(i));
		for (int j = 0; j < lista_jogadores.getTam(); j++)
		{
			Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*>(lista_jogadores.getEntidade(j));
			if (verificarColisao(static_cast<Entidades::Entidade*>(ini), static_cast<Entidades::Entidade*>(jog)) && jog->getAtivo() && ini->getAtivo())
			{
				ini->danificar(jog);
			}
		}
	}
}

void GerenciadorColisao::colisaoJogadorProjetil()
{
	for (int i = 0; i < lista_projeteis.getTam(); i++)
	{
		Entidades::Entidade* fog = static_cast<Entidades::Entidade*>(lista_projeteis.getEntidade(i));
		for (int j = 0; j < lista_jogadores.getTam(); j++)
		{
			Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*>(lista_jogadores.getEntidade(j));
			if (verificarColisao(static_cast<Entidades::Entidade*>(fog), static_cast<Entidades::Entidade*>(jog)) && jog->getAtivo() && fog->getAtivo())
			{
				Entidades::Fogo* fogo = static_cast<Entidades::Fogo*>(fog);
				fogo->atingir(jog);
			}
		}
	}
}

void GerenciadorColisao::colisaoObstaculosEntidades()
{
	for (int j = 0; j < lista_ini.getTam(); j++) // Inimigos
	{
		Entidades::Personagens::Inimigo* ini = static_cast<Entidades::Personagens::Inimigo*>(lista_ini.getEntidade(j));
		bool colidiu = false;

		for (int i = 0; i < lista_obst.getTam(); i++)
		{
			Entidades::Obstaculos::Obstaculo* obst = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(i));
			if (verificarColisao(ini, obst) && ini->getAtivo())
			{
				obst->obstacularizar(ini);
				colidiu = true;
			}
		}
		if (!colidiu)
		{
			ini->setNaSuperficie(false);
		}
	}


	for (int j = 0; j < lista_jogadores.getTam(); j++) // Jogadores
	{
		Entidades::Personagens::Jogador* jog = static_cast<Entidades::Personagens::Jogador*>(lista_jogadores.getEntidade(j));
		bool colidiu = false;

		for (int i = 0; i < lista_obst.getTam(); i++)
		{
			Entidades::Obstaculos::Obstaculo* obst = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(i));
			if (verificarColisao(jog, obst) && jog->getAtivo())
			{

				obst->obstacularizar(jog);
				colidiu = true;
			}
		}
		if (!colidiu)
		{
			jog->setNaSuperficie(false);
		}
	}

	for (int i = 0; i < lista_obst.getTam(); i++) // Obstaculos
	{
		Entidades::Obstaculos::Obstaculo* obst1 = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(i));
		bool colidiu = false;

		// Verifica colisão com todos os outros obstáculos 
		for (int j = 0; j < lista_obst.getTam(); j++)
		{
			if (i == j)
			{
				continue; // Não verificar colisão consigo mesmo
			}
			Entidades::Obstaculos::Obstaculo* obst2 = static_cast<Entidades::Obstaculos::Obstaculo*>(lista_obst.getEntidade(j));

			if (verificarColisao(obst1, obst2))
			{
				obst1->obstacularizar(obst2);
				colidiu = true;
			}
			if (!colidiu)
			{
				obst2->setNaSuperficie(false);
			}
		}
	}
}

float GerenciadorColisao::getDeltaX()const
{
	return delta_x;
}

float GerenciadorColisao::getDeltaY()const
{
	return delta_y;
}

float GerenciadorColisao::getIntersectX()const
{
	return intersect_x;
}

float GerenciadorColisao::getIntersectY()const
{
	return intersect_y;
}

void GerenciadorColisao::limparListas()
{
	lista_obst.clearLista();
	lista_ini.clearLista();
}

Masmorra::Listas::ListaEntidades& GerenciadorColisao::getListaProjeteis()
{
	return lista_projeteis;
}

GerenciadorColisao* GerenciadorColisao::pGerenciadorColisao = nullptr;
