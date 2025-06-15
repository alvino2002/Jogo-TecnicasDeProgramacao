#include "GerenciadorEstado.h"


using namespace Masmorra::Gerenciadores;


GerenciadorEstado::GerenciadorEstado()
{
}

GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado()
{
	if (pGerenciadorEstado == nullptr)
	{
		pGerenciadorEstado = new GerenciadorEstado();
	}
	else
	{
		return pGerenciadorEstado;
	}
}

GerenciadorEstado::~GerenciadorEstado()
{
}

void GerenciadorEstado::adicionarEstado(Estados::Estado* estado)
{
	if (estado)
	{
		pilhaEstados.push(estado);
	}
}

void GerenciadorEstado::removerEstado()
{
	if (pilhaEstados.top() != nullptr)
	{
		delete (pilhaEstados.top());
		pilhaEstados.top() = nullptr;
		pilhaEstados.pop();
	}
}

void GerenciadorEstado::executar()
{
	if (!pilhaEstados.empty() && pilhaEstados.top() != nullptr)
	{
		pilhaEstados.top()->executar();
		pilhaEstados.top()->verificarEvento();
	}
}

/*Estado* GerenciadorEstado::getEstadoAtual() {
	if (!pilhaEstados.empty()) {
		return pilhaEstados.top();
	}
	return nullptr;
}*/


GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;
