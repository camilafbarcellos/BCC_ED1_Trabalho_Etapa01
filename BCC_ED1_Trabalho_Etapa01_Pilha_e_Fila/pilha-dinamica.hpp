#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include "estruturas.hpp"
#include <iomanip>

/// PILHA PF

struct NoPilhaPF
{
    FichaPF dado;
    NoPilhaPF *prox;
};

struct PilhaPF
{
    NoPilhaPF *topo;

    PilhaPF()
    {
        topo = nullptr;
    }
};

bool vaziaP(PilhaPF *p)
{
    if (!p->topo)
        return true;
    else
        return false;
}

bool empilhaP(PilhaPF *p, FichaPF dado)
{
    NoPilhaPF *novo =  new NoPilhaPF();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool desempilhaP(PilhaPF *p, FichaPF *dado)
{
    if (!vaziaP(p))
    {
        *dado = p->topo->dado;
        NoPilhaPF *apagar = p->topo;
        p->topo = p->topo->prox;

        delete apagar;
        return true;
    }
    else
        return false;
}

void mostraP(PilhaPF *p)
{
    if(!vaziaP(p))
    {
        NoPilhaPF *no = p->topo;
        while (no != NULL)
        {
            cout << "\nCPF do cliente: " << no->dado.ordempf.CPF << endl;
            cout << "Placa do carro: " << no->dado.ordempf.placa << endl;
            if(no->dado.ordempf.vip==true)
                cout << "Cliente VIP: SIM" << endl;
            else
                cout << "Cliente VIP: N�O" << endl;
            cout << "Valor do servi�o: R$ " << no->dado.valor << endl;
            cout << "N�mero de pe�as trocadas: " << no->dado.nPecas << endl;

            no = no->prox;
        }
        cout << "\n";
    }

    else
        cout << "Pilha vazia!" << endl;
}

void destroiP(PilhaPF *p)
{
    FichaPF dado;
    while(!vaziaP(p))
        desempilhaP(p, &dado);
}

//fun��o de pilha implementada
int tamP(PilhaPF *p)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para iniciar contagem
    {
        NoPilhaPF *no = p->topo;
        int tam = 0;
        while(no!=NULL)
        {
            tam++;
            no = no->prox;
        }

        return tam;
    }

    else //caso esteja vazia, retorna zero
        return 0;
}

//fun��o de pilha implementada
void inverteP(PilhaPF *p, PilhaPF *novaP)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para invers�o
    {
        NoPilhaPF *no = p->topo;
        while(no!=NULL)
        {
            empilhaP(novaP, no->dado);
            no = no->prox;
        }
    }

    else //retorna erro caso esteja vazia
        cout << "Pilha vazia, imposs�vel inverter!" << endl;

    return;
}

//fun��o de pilha implementada
float somaValP(PilhaPF *p)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para iniciar soma
    {
        NoPilhaPF *no = p->topo;
        float soma = 0;
        while(no!=NULL)
        {
            soma += no->dado.valor;
            no = no->prox;
        }

        return soma;
    }

    else //caso esteja vazia, retorna zero
        return 0;
}

//fun��o de pilha implementada
void maiorValCPF(PilhaPF *p)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para iniciar busca
    {
        NoPilhaPF *no = p->topo;
        float maiorVal = no->dado.valor; //captura o valor do topo como compara��o para identificar o maior
        string CPF = no->dado.ordempf.CPF; //captura o CPF do topo (equivalente ao valor)
        while (no != NULL)
        {
            if(no->dado.valor > maiorVal) //verifica se o valor do n� � maior do que o maior valor atual
            {
                //caso seja maior, atualiza os dados
                maiorVal = no->dado.valor;
                CPF = no->dado.ordempf.CPF;
            }

            no = no->prox; //prossegue entre os n�s da pilha
        }

        //exibe o CPF conforme solicitado e o valor para ilustra��o ap�s verificar pilha
        cout << "CPF do cliente: " << CPF << endl;
        cout << "Valor do servi�o: R$ " << maiorVal << endl;
    }

    else //retorna erro caso esteja vazia
        cout << "Pilha vazia, imposs�vel localizar informa��o desejada!" << endl;

    return;
}

//fun��o de pilha implementada
void placaNPecas(PilhaPF *p, string *placa, int *maiorNum)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para iniciar busca
    {
        NoPilhaPF *no = p->topo;
        *maiorNum = no->dado.nPecas; //captura o valor do topo da como compara��o para identificar o maior
        *placa = no->dado.ordempf.placa; //captura a placa do topo (equivalente ao valor)
        while (no != NULL)
        {
            if(no->dado.nPecas > *maiorNum) //verifica se o valor do n� � menor do que o menor valor atual
            {
                //caso seja maior, atualiza os dados
                *maiorNum = no->dado.nPecas;
                *placa = no->dado.ordempf.placa;
            }

            no = no->prox; //prossegue entre os n�s da pilha
        }
    }

    else //retorna zero caso esteja vazia
        *maiorNum = 0;

    return;

}

/// PILHA PJ

struct NoPilhaPJ
{
    FichaPJ dado;
    NoPilhaPJ *prox;
};

struct PilhaPJ
{
    NoPilhaPJ *topo;

    PilhaPJ()
    {
        topo = nullptr;
    }
};


bool vaziaP(PilhaPJ *p)
{
    if (!p->topo)
        return true;
    else
        return false;
}

bool empilhaP(PilhaPJ *p, FichaPJ dado)
{
    NoPilhaPJ *novo =  new NoPilhaPJ();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool desempilhaP(PilhaPJ *p, FichaPJ *dado)
{
    if (!vaziaP(p))
    {
        *dado = p->topo->dado;
        NoPilhaPJ *apagar = p->topo;
        p->topo = p->topo->prox;

        delete apagar;
        return true;
    }
    else
        return false;
}

bool espiaP(PilhaPJ *p, FichaPJ *dado)
{
    if (!vaziaP(p))
    {
        *dado= p->topo->dado;
        return true;
    }
    else
        return false;
}

void mostraP(PilhaPJ *p)
{
    if(!vaziaP(p))
    {
        NoPilhaPJ *no = p->topo;
        while (no != NULL)
        {
            cout << "\nCNPJ do cliente: " << no->dado.ordempj.CNPJ << endl;
            cout << "Placa do carro: " << no->dado.ordempj.placa << endl;
            cout << "Valor do servi�o: R$ " << no->dado.valor << endl;
            cout << "N�mero de pe�as trocadas: " << no->dado.nPecas << endl;

            no = no->prox;
        }
        cout << "\n";
    }

    else
        cout << "Pilha vazia!" << endl;
}

void destroiP(PilhaPJ *p)
{
    FichaPJ dado;
    while(!vaziaP(p))
        desempilhaP(p, &dado);
}

//fun��o de pilha implementada
void menorValCNPJ(PilhaPJ *p)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para iniciar busca
    {
        NoPilhaPJ *no = p->topo;
        float menorVal = no->dado.valor; //captura o valor do topo como compara��o para identificar o menor
        string CNPJ = no->dado.ordempj.CNPJ; //captura o CNPJ do topo (equivalente ao valor)
        while (no != NULL)
        {
            if(no->dado.valor < menorVal) //verifica se o valor do n� � menor do que o menor valor atual
            {
                //caso seja menor, atualiza os dados
                menorVal = no->dado.valor;
                CNPJ = no->dado.ordempj.CNPJ;
            }

            no = no->prox; //prossegue entre os n�s da pilha
        }

        //exibe o CNPJ conforme solicitado e o valor para ilustra��o ap�s verificar pilha
        cout << "CNPJ do cliente: " << CNPJ << endl;
        cout << "Valor do servi�o: R$ " << menorVal << endl;
    }

    else //retorna erro caso esteja vazia
        cout << "Pilha vazia, imposs�vel localizar informa��o desejada!" << endl;

    return;
}

//fun��o de pilha implementada
void placaNPecas(PilhaPJ *p, string *placa, int *maiorNum)
{
    if(!vaziaP(p)) //verificar se a pilha n�o est� vazia para iniciar busca
    {
        NoPilhaPJ *no = p->topo;
        *maiorNum = no->dado.nPecas; //captura o valor do topo da como compara��o para identificar o maior
        *placa = no->dado.ordempj.placa; //captura a placa do topo (equivalente ao valor)
        while (no != NULL)
        {
            if(no->dado.nPecas > *maiorNum) //verifica se o valor do n� � menor do que o menor valor atual
            {
                //caso seja maior, atualiza os dados
                *maiorNum = no->dado.nPecas;
                *placa = no->dado.ordempj.placa;
            }

            no = no->prox; //prossegue entre os n�s da pilha
        }
    }

    else //retorna zero caso esteja vazia
        *maiorNum = 0;

    return;
}

#endif // _HPP_PILHA
