#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA

#include "estruturas.hpp"
#include <iomanip>

/// FILA PF

struct NoFilaPF
{
    OrdemPF dado;
    NoFilaPF *prox;
};

struct FilaPF
{
    NoFilaPF *inicio;
    NoFilaPF *fim;

    FilaPF()
    {
        inicio = nullptr;
        fim = nullptr;
    }
};

void inicializaF(FilaPF *f)
{
    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaF(FilaPF *f)
{
    if (!f->inicio)
        return true;
    else
        return false;
}

bool enfileiraF(FilaPF *f, OrdemPF dado)
{
    NoFilaPF *novo = new NoFilaPF();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

bool desenfileiraF(FilaPF *f, OrdemPF *dado)
{
    if (f->inicio)
    {
        *dado = f->inicio->dado;
        NoFilaPF *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;

        if (!f->inicio)
            f->fim = nullptr;

        return true;
    }
    else
        return false;
}

bool espiaF(FilaPF *f, OrdemPF *dado)
{
    if(f->inicio)
    {
        cout << "\nCPF do cliente: " << f->inicio->dado.CPF << endl;
        cout << "Placa do carro: " << f->inicio->dado.placa << endl;
        if(f->inicio->dado.vip==true)
            cout << "Cliente VIP: SIM" << endl;
        else
            cout << "Cliente VIP: NÃO" << endl;

        return true;
    }

    else
        return false;
}

void mostraF(FilaPF *f)
{
    if(f->inicio)
    {
        NoFilaPF *no = f->inicio;
        while (no)
        {
            cout << "\nCPF do cliente: " << no->dado.CPF << endl;
            cout << "Placa do carro: " << no->dado.placa << endl;
            if(no->dado.vip==true)
                cout << "Cliente VIP: SIM" << endl;
            else
                cout << "Cliente VIP: NÃO" << endl;
            cout << "\n";

            no = no->prox;
        }
    }
    else
        cout << "Fila vazia!" << endl;
}

void destroiF(FilaPF *f)
{

    NoFilaPF *no = f->inicio;
    while (no)
    {
        NoFilaPF *apagar = no;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

//função de fila implementada
void concatenaF (FilaPF  *f1, FilaPF  *f2, FilaPF *f3)
{
    if(!vaziaF(f1) && !vaziaF(f2)) //verificar se ambas as filas não estão vazias
    {
        NoFilaPF *no = f1->inicio;
        while(no)
        {
            enfileiraF(f3, no->dado);
            no = no->prox;
        }

        no = f2->inicio;
        while(no)
        {
            enfileiraF(f3, no->dado);
            no = no->prox;
        }
    }

    else //retorna erro caso estejam vazias
        cout << "Ambas as filas estão vazias, impossível concatenar!" << endl;

    return;
}

//função de fila implementada
int tamF(FilaPF *f)
{
    if(!vaziaF(f)) //verificar se a fila não está vazia para iniciar contagem
    {
        NoFilaPF *no = f->inicio;
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

//função de fila implementada
int quantFVIP(FilaPF *f)
{
    if(!vaziaF(f)) //verificar se a fila não está vazia para iniciar contagem
    {
        NoFilaPF *no = f->inicio;
        int quant = 0;
        while(no!=NULL)
        {
            if(no->dado.vip==true)
                quant++;
            no = no->prox;
        }

        return quant;
    }

    else //caso esteja vazia, retorna zero
        return 0;
}


/// FILA PJ

struct NoFilaPJ
{
    OrdemPJ dado;
    NoFilaPJ *prox;
};

struct FilaPJ
{
    NoFilaPJ *inicio;
    NoFilaPJ *fim;

    FilaPJ()
    {
        inicio = nullptr;
        fim = nullptr;
    }
};

void inicializaF(FilaPJ *f)
{
    f->inicio = nullptr;
    f->fim = nullptr;
}

bool vaziaF(FilaPJ *f)
{
    if (!f->inicio)
        return true;
    else
        return false;
}

bool enfileiraF(FilaPJ *f, OrdemPJ dado)
{
    NoFilaPJ *novo = new NoFilaPJ();
    if (!novo)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (!f->inicio)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

bool desenfileiraF(FilaPJ *f, OrdemPJ *dado)
{
    if (f->inicio)
    {
        *dado = f->inicio->dado;
        NoFilaPJ *apagar = f->inicio;
        f->inicio = f->inicio->prox;
        delete apagar;

        if (!f->inicio)
            f->fim = nullptr;

        return true;
    }
    else
        return false;
}

bool espiaF(FilaPJ *f, OrdemPF *dado)
{
    if(f->inicio)
    {
        cout << "\nCNPJ do cliente: " << f->inicio->dado.CNPJ << endl;
        cout << "Placa do carro: " << f->inicio->dado.placa << endl;

        return true;
    }

    else
        return false;
}

void mostraF(FilaPJ *f)
{
    if(f->inicio)
    {
        NoFilaPJ *no = f->inicio;
        while (no)
        {
            cout << "\nCNPJ do cliente: " << no->dado.CNPJ << endl;
            cout << "Placa do carro: " << no->dado.placa << endl;
            cout << "\n";
            no = no->prox;
        }
    }
    else
        cout << "Fila vazia!" << endl;
}

void destroiF(FilaPJ *f)
{

    NoFilaPJ *no = f->inicio;
    while (no)
    {
        NoFilaPJ *apagar = no;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

//função de fila implementada
int tamF(FilaPJ *f)
{
    if(!vaziaF(f)) //verificar se a fila não está vazia para iniciar contagem
    {
        NoFilaPJ *no = f->inicio;
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

#endif // _HPP_FILA_DINAMICA
