#include "ListaEntidades.h"


using namespace Masmorra::Entidades;


using namespace Masmorra::Listas;


ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
	listaDeEntidades.clear();
}

void ListaEntidades::incluirEntidade(Entidade* pEntidade)
{
	if (pEntidade)
	{
		listaDeEntidades.push(pEntidade);
	}
}

void ListaEntidades::deletarEntidade(Entidade* pEntidade)
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


