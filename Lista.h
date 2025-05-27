#pragma once

namespace Listas
{
    template <class TipoLista> class Lista
    {
    public:
        template <class TipoElemento> class Elemento
        {
        private:
            Elemento <TipoElemento>* pProx;
            TipoElemento* pInfo;

        public:
            Elemento()
            {
                pProx = nullptr;
                pInfo = nullptr;
            }
            ~Elemento()
            {
                pProx = nullptr;
                pInfo = nullptr;
            }
            void setProx(Elemento <TipoElemento>* pProx)
            {
                this->pProx = pProx;
            }
            Elemento <TipoElemento>* getProx()
            {
                return pProx;
            }
            void setInfo(TipoElemento* pInfo)  // Corrigido para receber ponteiro
            {
                this->pInfo = pInfo;
            }
            TipoElemento* getInfo()  // Corrigido nome e retorno de ponteiro
            {
                return pInfo;
            }
        };

    private:
        unsigned int tam;
        Elemento <TipoLista>* pPrim;
        Elemento <TipoLista>* pUlt;

    public:
        Lista();
        ~Lista();
        void clear();
        unsigned int getTam();
        void push(TipoLista* pInfo);
        void pop(TipoLista* pInfo);
        TipoLista* remove(TipoLista* pInfo);  // Corrigido retorno para ponteiro
        TipoLista* getpInfo(int posicao);
    };

    template <class TipoLista>
    Lista<TipoLista>::Lista() :
        tam(0)
    {
        pPrim = nullptr;
        pUlt = nullptr;
    }

    template <class TipoLista>
    Lista<TipoLista>::~Lista()
    {
        clear();
        pPrim = nullptr;
        pUlt = nullptr;
    }

    template <class TipoLista>
    unsigned int Lista<TipoLista>::getTam()
    {
        return tam;
    }

    template <class TipoLista>
    void Lista<TipoLista>::clear()
    {
        /*Elemento<TipoLista>* pAux1 = pPrim;
        Elemento<TipoLista>* pAux2 = nullptr;

        while (pAux1 != nullptr)
        {
            delete pAux1->getInfo();  // Corrigido para getInfo()
            pAux2 = pAux1->getProx();
            delete pAux1;
            pAux1 = pAux2;
            tam--;
        }

        pPrim = nullptr;
        pUlt = nullptr;*/
        Elemento<TipoLista>* pAux1 = pPrim;
        Elemento<TipoLista>* pAux2 = nullptr;

        while (pAux1 != nullptr)
        {
            pAux2 = pAux1->getProx();

            if (pAux1->getInfo())
            {
                delete pAux1->getInfo();  // Deleta o dado armazenado
                pAux1->setInfo(nullptr);  // Evita dangling pointer
            }

            delete pAux1;                 // Deleta o elemento da lista
            pAux1 = pAux2;
        }

        pPrim = nullptr;
        pUlt = nullptr;
        tam = 0;
    }

    template <class TipoLista>
    void Lista<TipoLista>::push(TipoLista* pInfo)
    {
        if (pPrim == nullptr)
        {
            pPrim = new Elemento<TipoLista>;
            pPrim->setInfo(pInfo);  // Corrigido para setInfo()
            pUlt = pPrim;
        }
        else
        {
            Elemento<TipoLista>* temp = new Elemento<TipoLista>;
            temp->setInfo(pInfo);  // Corrigido para setInfo()
            pUlt->setProx(temp);
            pUlt = temp;
        }
        tam++;
    }

    template <class TipoLista>
    void Lista<TipoLista>::pop(TipoLista* pInfo)
    {
        Elemento<TipoLista>* aux1 = pPrim;
        Elemento<TipoLista>* aux2 = nullptr;

        while (aux1->getInfo() != pInfo)  // Corrigido para getInfo()
        {
            aux2 = aux1;
            aux1 = aux1->getProx();
        }
        if (aux1 == pPrim)
        {
            pPrim = aux1->getProx();
        }
        else if (aux1 == pUlt)
        {
            aux2->setProx(nullptr);
            pUlt = aux2;
        }
        else
        {
            aux2->setProx(aux1->getProx());
        }
        delete aux1;
  
        tam--;
    }

    template <class TipoLista>
    TipoLista* Lista<TipoLista>::remove(TipoLista* pInfo)
    {
        Elemento<TipoLista>* aux1 = pPrim;
        Elemento<TipoLista>* aux2 = nullptr;

        while (aux1->getInfo() != pInfo) 
        {
            aux2 = aux1;
            aux1 = aux1->getProx();
        }
        if (aux1 == pPrim)
        {
            pPrim = aux1->getProx();
        }
        else if (aux1 == pUlt)
        {
            aux2->setProx(nullptr);
            pUlt = aux2;
        }
        else
        {
            aux2->setProx(aux1->getProx());
        }

        TipoLista* retorno = aux1->getInfo();  // Salva o valor antes de deletar
        delete aux1;
        tam--;
        return retorno;  
    }

    template <class TipoLista>
    TipoLista* Lista<TipoLista>::getpInfo(int posicao)
    {
        Elemento<TipoLista>* aux1 = pPrim;

        if (posicao == 0)
        {
            return aux1->getInfo();  // Corrigido para getInfo()
        }
        else
        {
            for (int i = 0; i < posicao; i++)
            {
                if (aux1)
                {
                    aux1 = aux1->getProx();
                }
            }
            return aux1->getInfo();  // Corrigido para getInfo()
        }
    }
}