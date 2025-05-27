#include "ListaEntidades.h"


using namespace Entidades;

namespace Listas
{

	ListaEntidades::ListaEntidades()
	{
	}

	ListaEntidades::~ListaEntidades()
	{
		listaDeEntidades.clear();
	}

	void ListaEntidades::incluiEntidade(Entidade* pEntidade)
	{
		listaDeEntidades.push(pEntidade);
	}

	void ListaEntidades::deleteEntidade(Entidade* pEntidade) //remove e deleta o conteudo apontado pelo ponteiro
	{
		listaDeEntidades.pop(pEntidade);
	}

	unsigned int ListaEntidades::getTam()
	{
		return listaDeEntidades.getTam();
	}

	void ListaEntidades::clearLista()
	{
		listaDeEntidades.clear();
	}

	Entidade* ListaEntidades::getEntidade(int pos)
	{
		return listaDeEntidades.getpInfo(pos);
	}

}