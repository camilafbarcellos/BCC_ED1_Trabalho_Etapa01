#ifndef _HPP_ESTRUTURAS_
#define _HPP_ESTRUTURAS_


struct OrdemPF
{
	string CPF;
	string placa;
	bool vip;
};

struct OrdemPJ
{
	string CNPJ;
	string placa;
};

struct FichaPF
{
	OrdemPF ordempf;
	float valor;
	int nPecas;
};

struct FichaPJ
{
	OrdemPJ ordempj;
	float valor;
	int nPecas;
};

#endif // _HPP_ESTRUTURAS_
