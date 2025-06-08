#pragma once
#include "Estado.h"

using namespace Masmorra;

class Fim : public Ente
{
private:
    sf::Font fonte;
    sf::Text texto;
    sf::RectangleShape fundo;
    sf::Window* janela;
public:
    Fim();
    ~Fim();
    void executar();
    void desenhar();
};
