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
        if(!isdigit(str[i])) //invalida d�gito que n�o seja num�rico
            return false;
    }

    return true;
}

bool validaPlaca(string str)
{
    int tam = str.size();
    if(tam!=7) //placas brasileiras assumem sempre 7 d�gitos
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

    //declara��o das estruturas
    FilaPF pesFisVIP, pesFis;
    FilaPJ pesJur;
    PilhaPF carroPF;
    PilhaPJ carroPJ;
    OrdemPF opf;
    OrdemPJ opj;
    FichaPF fpf;
    FichaPJ fpj;
    //declara��o das vari�veis utilizadas no maind
    char op;
    //inicializa��o de todas as filas din�micas
    inicializaF(&pesFisVIP);
    inicializaF(&pesFis);
    inicializaF(&pesJur);

    do
    {
        system("cls");
        cout << "--------------------------------------------------------" << endl;
        cout << "               -- MEC�NICA PASSO FUNDO --               " << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "  a- Criar ordem de servi�o e adicionar na fila" << endl;
        cout << "  b- Atender cliente da fila" << endl;
        cout << "  c- Mostrar ordens de servi�o de todas as filas" << endl;
        cout << "  d- Listar informa��es sobre as filas de PF" << endl;
        cout << "  e- Listar atendimentos de PF em ordem" << endl;
        cout << "  f- Mostrar soma de todos os servi�os PF realizados" << endl;
        cout << "  g- Mostrar o CPF da PF com a revis�o de maior valor" << endl;
        cout << "  h- Mostrar o CNPJ da PJ com a revis�o de menor valor" << endl;
        cout << "  i- Mostrar placa do carro com maior n�m. de pe�as" << endl;
        cout << "\n  z- Sair" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Sua op��o: ";
        cin >> op;
        fflush(stdin);
        op = toupper(op); //transforma o char em mai�sculo para validar no switch...case

        switch(op)
        {
        case 'A':
        {
            char cliente;
            bool valido = true; //vari�vel booleana para verificar validade de CPF/CNPJ e placa
            do
            {
                cout << "\nO cliente � pessoa f�sica ou jur�dica (F-f�sica ou J-jur�dica)? ";
                cin >> cliente;
                cliente = toupper(cliente);

                if(cliente!='F' && cliente!='J') //valida o tipo de cliente
                    cout << "\nInser��o inv�lida! Digite apenas F ou J!" << endl;
            }
            while(cliente!='F' && cliente!='J');  //do...while para for�ar inser��o correta do tipo de cliente

            switch(cliente) //switch...case para enfileirar o cliente por tipo
            {
            case 'F':
                char pacote;
                do
                {
                    cout << "O cliente aderiu ao pacote de revis�es programadas (S-sim ou N-n�o)? ";
                    cin >> pacote;
                    pacote = toupper(pacote);

                    if(pacote!='S' && pacote!='N') //valida a resposta do pacote
                        cout << "\nInser��o inv�lida! Digite apenas S ou N!" << endl;
                }
                while(pacote!='S' && pacote!='N'); //do...while para for�ar inser��o correta do pacote

                if(pacote=='S') //caso o cliente possua o pacote, ser� inserido na fila priorit�ria
                {
                    system("cls");
                    cout << "--------------------------------------------------------" << endl;
                    cout << "            -- CLIENTE PESSOA F�SICA VIP --             " << endl;
                    cout << "--------------------------------------------------------" << endl;
                    do
                    {
                        cout << "Insira o CPF: ";
                        cin >> opf.CPF;

                        valido = validador(opf.CPF); //utiliza fun��o para verificar se CPF � v�lido
                        if((opf.CPF.size())!=11 || valido==false)
                            cout << "\nCPF inv�lido! Digite novamente!\n" << endl;
                    }
                    while((opf.CPF.size())!=11 || valido==false);  //do...while para for�ar digita��o v�lida de CPF
                    do
                    {
                        cout << "Insira a placa: ";
                        cin >> opf.placa;

                        valido = validaPlaca(opf.placa); //utiliza fun��o para verificar se placa � v�lida
                        if(valido==false)
                            cout << "\nPlaca inv�lida! Digite novamente!\n" << endl;
                    }
                    while(valido==false); //do...while para for�ar digita��o v�lida de placa
                    opf.vip = true;
                    cout << "--------------------------------------------------------" << endl;
                    enfileiraF(&pesFisVIP, opf);
                    cout << "\nCliente adicionado com sucesso!" << endl;
                }

                else
                {
                    system("cls");
                    cout << "--------------------------------------------------------" << endl;
                    cout << "              -- CLIENTE PESSOA F�SICA --               " << endl;
                    cout << "--------------------------------------------------------" << endl;
                    do
                    {
                        cout << "Insira o CPF: ";
                        cin >> opf.CPF;

                        valido = validador(opf.CPF); //utiliza fun��o para verificar se CPF � v�lido
                        if((opf.CPF.size())!=11 || valido==false)
                            cout << "\nCPF inv�lido! Digite novamente!\n" << endl;
                    }
                    while((opf.CPF.size())!=11 || valido==false);  //do...while para for�ar digita��o v�lida de CPF
                    do
                    {
                        cout << "Insira a placa: ";
                        cin >> opf.placa;

                        valido = validaPlaca(opf.placa); //utiliza fun��o para verificar se placa � v�lida
                        if(valido==false)
                            cout << "\nPlaca inv�lida! Digite novamente!\n" << endl;
                    }
                    while(valido==false); //do...while para for�ar digita��o v�lida de placa
                    opf.vip = false;
                    cout << "--------------------------------------------------------" << endl;
                    enfileiraF(&pesFis, opf);
                    cout << "\nCliente adicionado com sucesso!" << endl;
                }
                break;

            case 'J':
                system("cls");
                cout << "--------------------------------------------------------" << endl;
                cout << "             -- CLIENTE PESSOA JUR�DICA --              " << endl;
                cout << "--------------------------------------------------------" << endl;

                do
                {
                    cout << "Insira o CNPJ: ";
                    cin >> opj.CNPJ;

                    valido = validador(opj.CNPJ); //utiliza fun��o para verificar se CNPJ � v�lido
                    if((opj.CNPJ.size())!=14 || valido==false)
                        cout << "\nCNPJ inv�lido! Digite novamente!\n" << endl;
                }
                while((opj.CNPJ.size())!=14 || valido==false);  //do...while para for�ar digita��o v�lida de CNPJ
                do
                {
                    cout << "Insira a placa: ";
                    cin >> opj.placa;

                    valido = validaPlaca(opj.placa); //utiliza fun��o para verificar se placa � v�lida
                    if(valido==false)
                        cout << "\nPlaca inv�lida! Digite novamente!\n" << endl;
                }
                while(valido==false); //do...while para for�ar digita��o v�lida de placa
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
            if(!vaziaF(&pesFisVIP)) //verifica se h� algu�m na fila priorit�ria para atender
            {
                cout << "Fila: Pessoa F�sica VIP" << endl;
                desenfileiraF(&pesFisVIP, &opf); //desenfileira a fila PF VIP para capturar ordem de servi�o
                fpf.ordempf = opf; //insere a ordem de servi�o desenfileirada na ficha
                cout << "CPF do cliente: " << opf.CPF << endl;
                cout << "Placa do carro: " << opf.placa << endl;
                cout << "Valor do servi�o: R$ ";
                cin >> fpf.valor;
                cout << "N�mero de pe�as trocadas: ";
                cin >> fpf.nPecas;
                empilhaP(&carroPF, fpf); //empilha a ficha preenchida na pilha de carro PF
                cout << "--------------------------------------------------------" << endl;
                cout << "\nCliente atendido com sucesso! Ficha inserida � pilha carroPF" << endl;
            }

            else if(vaziaF(&pesFisVIP) && !vaziaF(&pesJur)) //verifica se a fila PF VIP est� vazia e se h� algu�m na fila PJ
            {
                cout << "Fila: Pessoa Jur�dica" << endl;
                desenfileiraF(&pesJur, &opj); //desenfileira a fila PJ para capturar ordem de servi�o
                fpj.ordempj = opj; //insere a ordem de servi�o desenfileirada na ficha
                cout << "CNPJ do cliente: " << opj.CNPJ << endl;
                cout << "Placa do carro: " << opj.placa << endl;
                cout << "Valor do servi�o: R$ ";
                cin >> fpj.valor;
                cout << "N�mero de pe�as trocadas: ";
                cin >> fpj.nPecas;
                empilhaP(&carroPJ, fpj); //empilha a ficha preenchida na pilha de carro PJ
                cout << "--------------------------------------------------------" << endl;
                cout << "\nCliente atendido com sucesso! Ficha inserida � pilha carroPJ" << endl;
            }

            else if(vaziaF(&pesFisVIP) && vaziaF(&pesJur) && !vaziaF(&pesFis)) //verifica se ambas as filas PF VIP e PJ est�o vazias
            {
                cout << "Fila: Pessoa F�sica" << endl;
                desenfileiraF(&pesFis, &opf); //desenfileira a fila PF para capturar ordem de servi�o
                fpf.ordempf = opf; //insere a ordem de servi�o desenfileirada na ficha
                cout << "CPF do cliente: " << opf.CPF << endl;
                cout << "Placa do carro: " << opf.placa << endl;
                cout << "Valor do servi�o: R$ ";
                cin >> fpf.valor;
                cout << "N�mero de pe�as trocadas: ";
                cin >> fpf.nPecas;
                empilhaP(&carroPF, fpf); //empilha a ficha preenchida na pilha de carro PF
                cout << "--------------------------------------------------------" << endl;
                cout << "\nCliente atendido com sucesso! Ficha inserida � pilha carroPF" << endl;
            }

            else
                cout << "Todas as filas de atendimento est�o VAZIAS! \nAdicione clientes pela op��o (a)!" << endl;
        }
        break;

        case 'C':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "         -- ORDENS DE SERVI�O DA FILA PF VIP --         " << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesFisVIP);
            cout << "--------------------------------------------------------" << endl;
            getchar();

            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "           -- ORDENS DE SERVI�O DA FILA PJ --           " << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesJur);
            cout << "--------------------------------------------------------" << endl;
            getchar();

            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "           -- ORDENS DE SERVI�O DA FILA PF --           " << endl;
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
            cout << "         -- FILA UNIFICADA DE PESSOA F�SICA --          " << endl;
            cout << "--------------------------------------------------------" << endl;
            int tamPF = tamF(&pesFisUnif); //capturar tamanho da fila -> quantidade de clientes PF
            cout << "Total de pessoas: " << tamPF << endl;
            int quantVIP = quantFVIP(&pesFisUnif); //capturar quantidade de clientes PF VIP
            cout << "N�m. de pessoas que aderiram ao pacote VIP: " << quantVIP << endl;
            int quantPF = tamPF - quantVIP; //quantidade de clientes PF sem VIP � a o restante de clientes PF
            cout << "N�m. de pessoas que n�o aderiram ao pacote VIP: " << quantPF << endl;
            cout << "--------------------------------------------------------" << endl;
            mostraF(&pesFisUnif); //mostrar fila unificada
            cout << "--------------------------------------------------------" << endl;
            destroiF(&pesFisUnif); //ap�s uso, destr�i fila
        }
        break;

        case 'E':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "       -- ATENDIMENTOS DE CLIENTE PF POR ORDEM --       " << endl;
            cout << "--------------------------------------------------------" << endl;
            PilhaPF carroPFInvert; //declarar pilha invertida
            inverteP(&carroPF, &carroPFInvert); //inverter usando a fun��o
            mostraP(&carroPFInvert); //mostrar pilha invertida
            cout << "--------------------------------------------------------" << endl;
            destroiP(&carroPFInvert); //ap�s uso, destr�i pilha
        }
        break;

        case 'F':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "      -- VALOR TOTAL DE SERVI�OS PF REALIZADOS --       " << endl;
            cout << "--------------------------------------------------------" << endl;
            float somaPF = somaValP(&carroPF); //capturar soma dos valores pela fun��o
            cout << "Soma de todos os servi�os: R$ " << somaPF << endl;
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'G':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "   -- CPF DO CLIENTE COM A REVIS�O DE MAIOR VALOR --    " << endl;
            cout << "--------------------------------------------------------" << endl;
            maiorValCPF(&carroPF); //fun��o utilizada para tal
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'H':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "   -- CNPJ DO CLIENTE COM A REVIS�O DE MENOR VALOR --   " << endl;
            cout << "--------------------------------------------------------" << endl;
            menorValCNPJ(&carroPJ); //fun��o utilizada para tal
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'I':
        {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "    -- REVIS�O COM MAIOR N�MERO DE PE�AS TROCADAS --    " << endl;
            cout << "--------------------------------------------------------" << endl;
            //declara��o das vari�veis para apoio
            int pecasPF, pecasPJ;
            string placaPF, placaPJ;
            //utilizar fun��es para retornar valores desejados
            placaNPecas(&carroPF, &placaPF, &pecasPF);
            placaNPecas(&carroPJ, &placaPJ, &pecasPJ);
            //ap�s capturar valores, comparamos e mostramos o maior
            if(pecasPF>pecasPJ)
            {
                cout << "Placa do carro: " << placaPF << endl;
                cout << "N�mero de pe�as trocadas: " << pecasPF << endl;
            }
            else if(pecasPJ>pecasPF)
            {
                cout << "Placa do carro: " << placaPJ << endl;
                cout << "N�mero de pe�as trocadas: " << pecasPJ << endl;
            }
            cout << "--------------------------------------------------------" << endl;
        }
        break;

        case 'Z':
        {
            cout << "\nSaindo do programa...";
            getchar();
            //destrui��o das estruturas de fila e pilha utilizadas
            destroiF(&pesFisVIP);
            destroiF(&pesFis);
            destroiF(&pesJur);
            destroiP(&carroPF);
            destroiP(&carroPJ);
            exit(0);
        }

        default:
            cout << "\nOp��o inv�lida\n";
            break;
        }


        cout << endl;
        system("pause");
        system("cls");

    }
    while(op!='Z');

}
