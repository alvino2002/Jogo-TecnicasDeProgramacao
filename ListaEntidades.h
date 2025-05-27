#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidades::Entidade> listaDeEntidades;

	public:
		ListaEntidades();
		~ListaEntidades();
		void incluiEntidade(Entidades::Entidade* pEntidade);
		void deleteEntidade(Entidades::Entidade* pEntidade);
		Entidades::Entidade* getEntidade(int pos);
		unsigned int getTam();
		void clearLista();
	};
}
