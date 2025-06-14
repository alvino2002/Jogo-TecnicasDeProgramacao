#pragma once
#include "Estado.h"
#include "Interface.h"

namespace Masmorra
{
    namespace Interfaces
    {
        class Fim : public Interface
        {
        private:
            std::string final;
            std::string sair;
            
        public:
            Fim(int id);
            ~Fim();
            void executar();
            void inicializar();
        };
    }
}
