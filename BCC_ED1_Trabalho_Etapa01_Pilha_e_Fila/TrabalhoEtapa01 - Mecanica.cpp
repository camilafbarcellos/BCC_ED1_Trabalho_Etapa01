#include <iostream>
#include <cstring>
#include <cctype>

//Camila Florao Barcellos

using namespace std;

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"

bool validador(string str)
{
    int tam = str.size();
    for(int i=0; i<tam; i++)
    {
        if(!isdigit(str[i])) //invalida dígito que não seja numérico
            return false;
    }

    return true;
}

bool validaPlaca(string str)
{
    int tam = str.size();
    if(tam!=7) //placas brasileiras assumem sempre 7 dígitos
        return false;
    for(int i=0; i<tam; i++)
    {
        if(!isalnum(str[i])) //invalida caractere especial
            return false;
    }

    return true;
}

int main()
{
    setlocale (LC_ALL, "Portuguese");

    //declaração das estruturas
    FilaPF pesFisVIP, pesFis;
    FilaPJ pesJur;
    PilhaPF carroPF;
    PilhaPJ carroPJ;
    OrdemPF opf;
    OrdemPJ opj;
    FichaPF fpf;
    FichaPJ fpj;
    //declaração das variáveis utilizadas no maind
    char op;
    //inicialização de todas as filas dinâmicas
    inicializaF(&pesFisVIP);
    inicializaF(&pesFis);
    inicializaF(&pesJur);

    do
    {
        system("cls");
        cout << "--------------------------------------------------------" << endl;
        cout << "               -- MECÂNICA PASSO FUNDO --               " << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "  a- Criar ordem de serviço e adicionar na fila" << endl;
        cout << "  b- Atender cliente da fila" << endl;
        cout << "  c- Mostrar ordens de serviço de todas as filas" << endl;
        cout << "  d- Listar informações sobre as filas de PF" << endl;
        cout << "  e- Listar atendimentos de PF em ordem" << endl;
        cout << "  f- Mostrar soma de todos os serviços PF realizados" << endl;
        cout << "  g- Mostrar o CPF da PF com a revisão de maior valor" << endl;
        cout << "  h- Mostrar o CNPJ da PJ com a revisão de menor valor" << endl;
        cout << "  i- Mostrar placa do carro com maior núm. de peças" << endl;
        cout << "\n  z- Sair" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Sua opção: ";
        cin >> op;
        fflush(stdin);
        op = toupper(op); //transforma o char em maiúsculo para validar no switch...case

        switch(op)
        {
        case 'A':
        {
            char cliente;
            bool valido = true; //variável booleana para verificar validade de CPF/CNPJ e placa
            do
            {
                cout << "\nO cliente é pessoa física ou jurídica (F-física ou J-jurídica)? ";
                cin >> cliente;
                cliente = toupper(cliente);

                if(cliente!='F' && cliente!='J') //valida o tipo de cliente
                    cout << "\nInserção inválida! Digite apenas F ou J!" << endl;
            }
            while(cliente!='F' && cliente!='J');  //do...while para forçar inserção correta do tipo de cliente

            switch(cliente) //switch...case para enfileirar o cliente por tipo
            {
            case 'F':
                char pacote;
                do
                {
                    cout << "O cliente aderiu ao pacote de revisões programadas (S-sim ou N-não)? ";
                    cin >> pacote;
                    pacote = toupper(pacote);

                    if(pacote!='S' && pacote!='N') //valida a resposta do pacote
                        cout << "\nInserção inválida! Digite apenas S ou N!" << endl;
                }
                while(pacote!='S' && pacote!='N'); //do...while para forçar inserção correta do pacote

                if(pacote=='S') //caso o cliente possua o pacote, será inserido na fila prioritária
                {
                    system("cls");
                    cout << "--------------------------------------------------------" << endl;
                    cout << "            -- CLIENTE PESSOA FÍSICA VIP --             " << endl;
                    cout << "--------------------------------------------------------" << endl;
                    do
                    {
                        cout << "Insira o CPF: ";
                        cin >> opf.CPF;

                        valido = validador(opf.CPF); //utiliza função para verificar se CPF é válido
                        if((opf.CPF.size())!=11 || valido==false)
                            cout << "\nCPF inválido! Digite novamente!\n" << endl;
                    }
                    while((opf.CPF.size())!=11 || valido==false);  //do...while para forçar digitação válida de CPF
                    do
                    {
                        cout << "Insira a placa: ";
                        cin >> opf.placa;

                        valido = validaPlaca(opf.placa); //utiliza função para verificar se placa é válida
                        if(valido==false)
                            cout << "\nPlaca inválida! Digite novamente!\n" << endl;
                    }
                    while(valido==false); //do...while para forçar digitação válida de placa
                    opf.vip = true;
                    cout << "--------------------------------------------------------" << endl;
                    enfileiraF(&pesFisVIP, opf);
                    cout << "\nCliente adicionado com sucesso!" << endl;
                }

                else
                {
                    system("cls");
                    cout << "--------------------------------------------------------" << endl;
                    cout << "              -- CLIENTE PESSOA FÍSICA --               " << endl;
                    cout << "--------------------------------------------------------" << endl;
                    do
                    {
                        cout << "Insira o CPF: ";
                        cin >> opf.CPF;

                        valido = validador(opf.CPF); //utiliza função para verificar se CPF é válido
                        if((opf.CPF.size())!=11 || valido==false)
                            cout << "\nCPF inválido! Digite novamente!\n" << endl;
                    }
                    while((opf.CPF.size())!=11 || valido==false);  //do...while para forçar digitação válida de CPF
                    do
                    {
                        cout << "Insira a placa: ";
                        cin >> opf.placa;

                        valido = validaPlaca(opf.placa); //utiliza função para verificar se placa é válida
                        if(valido==false)
                            cout << "\nPlaca inválida! Digite novamente!\n" << endl;
                    }
                    while(valido==false); //do...while para forçar digitação válida de placa
                    opf.vip = false;
                    cout << "--------------------------------------------------------" << endl;
                    enfileiraF(&pesFis, opf);
                    cout << "\nCliente adicionado com sucesso!" << endl;
                }
                break;

            case 'J':
                system("cls");
                cout << "--------------------------------------------------------" << endl;
                cout << "             -- CLIENTE PESSOA JURÍDICA --              " << endl;
                cout << "--------------------------------------------------------" << endl;

                do
                {
                    cout << "Insira o CNPJ: ";
                    cin >> opj.CNPJ;

                    valido = validador(opj.CNPJ); //utiliza função para verificar se CNPJ é válido
                    if((opj.CNPJ.size())!=14 || valido==false)
                        cout << "\nCNPJ inválido! Digite novamente!\n" << endl;
                }
                while((opj.CNPJ.size())!=14 || valido==false);  //do...while para forçar digitação válida de CNPJ
                do
                {
                    cout << "Insira a placa: ";
                    cin >> opj.placa;

                    valido = validaPlaca(opj.placa); //utiliza função para verificar se placa é válida
                    if(valido==false)
                        cout << "\nPlaca inválida! Digite novamente!\n" << endl;
                }
                while(valido==false); //do...while para forçar digitação válida de placa
                cout << "--------------------------------------------------------" << endl;
                enfileiraF(&pesJur, opj);
                cout << "\nCliente adicionado com sucesso!" << endl;
                break;
            }
        }
        break;

        case 'B':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "         -- ATENDIMENTO DE CLIENTES EM FILA --          " << endl;
            cout << "--------------------------------------------------------" << endl;
            if(!vaziaF(&pesFisVIP)) //verifica se há alguém na fila prioritária para atender
            {
                cout << "Fila: Pessoa Física VIP" << endl;
                desenfileiraF(&pesFisVIP, &opf); //desenfileira a fila PF VIP para capturar ordem de serviço
                fpf.ordempf = opf; //insere a ordem de serviço desenfileirada na ficha
                cout << "CPF do cliente: " << opf.CPF << endl;
                cout << "Placa do carro: " << opf.placa << endl;
                cout << "Valor do serviço: R$ ";
                cin >> fpf.valor;
                cout << "Número de peças trocadas: ";
                cin >> fpf.nPecas;
                empilhaP(&carroPF, fpf); //empilha a ficha preenchida na pilha de carro PF
                cout << "--------------------------------------------------------" << endl;
                cout << "\nCliente atendido com sucesso! Ficha inserida à pilha carroPF" << endl;
            }

            else if(vaziaF(&pesFisVIP) && !vaziaF(&pesJur)) //verifica se a fila PF VIP está vazia e se há alguém na fila PJ
            {
                cout << "Fila: Pessoa Jurídica" << endl;
                desenfileiraF(&pesJur, &opj); //desenfileira a fila PJ para capturar ordem de serviço
                fpj.ordempj = opj; //insere a ordem de serviço desenfileirada na ficha
                cout << "CNPJ do cliente: " << opj.CNPJ << endl;
                cout << "Placa do carro: " << opj.placa << endl;
                cout << "Valor do serviço: R$ ";
                cin >> fpj.valor;
                cout << "Número de peças trocadas: ";
                cin >> fpj.nPecas;
                empilhaP(&carroPJ, fpj); //empilha a ficha preenchida na pilha de carro PJ
                cout << "--------------------------------------------------------" << endl;
                cout << "\nCliente atendido com sucesso! Ficha inserida à pilha carroPJ" << endl;
            }

            else if(vaziaF(&pesFisVIP) && vaziaF(&pesJur) && !vaziaF(&pesFis)) //verifica se ambas as filas PF VIP e PJ estão vazias
            {
                cout << "Fila: Pessoa Física" << endl;
                desenfileiraF(&pesFis, &opf); //desenfileira a fila PF para capturar ordem de serviço
                fpf.ordempf = opf; //insere a ordem de serviço desenfileirada na ficha
                cout << "CPF do cliente: " << opf.CPF << endl;
                cout << "Placa do carro: " << opf.placa << endl;
                cout << "Valor do serviço: R$ ";
                cin >> fpf.valor;
                cout << "Número de peças trocadas: ";
                cin >> fpf.nPecas;
                empilhaP(&carroPF, fpf); //empilha a ficha preenchida na pilha de carro PF
                cout << "--------------------------------------------------------" << endl;
                cout << "\nCliente atendido com sucesso! Ficha inserida à pilha carroPF" << endl;
            }

            else
                cout << "Todas as filas de atendimento estão VAZIAS! \nAdicione clientes pela opção (a)!" << endl;
        }
        break;

        case 'C':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "         -- ORDENS DE SERVIÇO DA FILA PF VIP --         " << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesFisVIP);
            cout << "--------------------------------------------------------" << endl;
            getchar();

            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "           -- ORDENS DE SERVIÇO DA FILA PJ --           " << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesJur);
            cout << "--------------------------------------------------------" << endl;
            getchar();

            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "           -- ORDENS DE SERVIÇO DA FILA PF --           " << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesFis);
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'D':
        {
            //declarar e inicializar a fila para unificar PF
            FilaPF pesFisUnif;
            inicializaF(&pesFisUnif);
            concatenaF(&pesFisVIP, &pesFis, &pesFisUnif); //concatenar as filas de PF em uma fila unificada
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "         -- FILA UNIFICADA DE PESSOA FÍSICA --          " << endl;
            cout << "--------------------------------------------------------" << endl;
            int tamPF = tamF(&pesFisUnif); //capturar tamanho da fila -> quantidade de clientes PF
            cout << "Total de pessoas: " << tamPF << endl;
            int quantVIP = quantFVIP(&pesFisUnif); //capturar quantidade de clientes PF VIP
            cout << "Núm. de pessoas que aderiram ao pacote VIP: " << quantVIP << endl;
            int quantPF = tamPF - quantVIP; //quantidade de clientes PF sem VIP é a o restante de clientes PF
            cout << "Núm. de pessoas que não aderiram ao pacote VIP: " << quantPF << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesFisUnif); //mostrar fila unificada
            cout << "--------------------------------------------------------" << endl;
            destroiF(&pesFisUnif); //após uso, destrói fila
        }
        break;

        case 'E':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "       -- ATENDIMENTOS DE CLIENTE PF POR ORDEM --       " << endl;
            cout << "--------------------------------------------------------" << endl;
            PilhaPF carroPFInvert; //declarar pilha invertida
            inverteP(&carroPF, &carroPFInvert); //inverter usando a função
            mostraP(&carroPFInvert); //mostrar pilha invertida
            cout << "--------------------------------------------------------" << endl;
            destroiP(&carroPFInvert); //após uso, destrói pilha
        }
        break;

        case 'F':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "      -- VALOR TOTAL DE SERVIÇOS PF REALIZADOS --       " << endl;
            cout << "--------------------------------------------------------" << endl;
            float somaPF = somaValP(&carroPF); //capturar soma dos valores pela função
            cout << "Soma de todos os serviços: R$ " << somaPF << endl;
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'G':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "   -- CPF DO CLIENTE COM A REVISÃO DE MAIOR VALOR --    " << endl;
            cout << "--------------------------------------------------------" << endl;
            maiorValCPF(&carroPF); //função utilizada para tal
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'H':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "   -- CNPJ DO CLIENTE COM A REVISÃO DE MENOR VALOR --   " << endl;
            cout << "--------------------------------------------------------" << endl;
            menorValCNPJ(&carroPJ); //função utilizada para tal
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'I':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "    -- REVISÃO COM MAIOR NÚMERO DE PEÇAS TROCADAS --    " << endl;
            cout << "--------------------------------------------------------" << endl;
            //declaração das variáveis para apoio
            int pecasPF, pecasPJ;
            string placaPF, placaPJ;
            //utilizar funções para retornar valores desejados
            placaNPecas(&carroPF, &placaPF, &pecasPF);
            placaNPecas(&carroPJ, &placaPJ, &pecasPJ);
            //após capturar valores, comparamos e mostramos o maior
            if(pecasPF>pecasPJ)
            {
                cout << "Placa do carro: " << placaPF << endl;
                cout << "Número de peças trocadas: " << pecasPF << endl;
            }
            else if(pecasPJ>pecasPF)
            {
                cout << "Placa do carro: " << placaPJ << endl;
                cout << "Número de peças trocadas: " << pecasPJ << endl;
            }
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'Z':
        {
            cout << "\nSaindo do programa...";
            getchar();
            //destruição das estruturas de fila e pilha utilizadas
            destroiF(&pesFisVIP);
            destroiF(&pesFis);
            destroiF(&pesJur);
            destroiP(&carroPF);
            destroiP(&carroPJ);
            exit(0);
        }

        default:
            cout << "\nOpção inválida\n";
            break;
        }


        cout << endl;
        system("pause");
        system("cls");

    }
    while(op!='Z');

}
