#pragma once
#include "Ente.h"
#include "Cavaleiro.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include <string>

namespace Masmorra
{
    class Ranking : public Ente
    {
    private:
        std::string nomeJogador;
        sf::Font fonte;
        sf::Text textoNome;
        int pontuacao;


    public:
        Ranking(int pontuacao);
        ~Ranking();
        void executar();
        static void salvar(int pontuacao, const std::string& nome);

    };
}
