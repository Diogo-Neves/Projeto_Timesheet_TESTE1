/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "funcs.h"
#include "Menu_Funcs_header.h"
#include <locale.h>

/**
 * Função com o objetivo de criar funcionários
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void criarFunc(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios) {

    int nrFunc;
    Pessoa *pNovo_Realloc;
    char nomeFunc[25];

    *totalFuncionarios += 1; //antes de realocar aumentar sempre 1 para garantir espaço suficiente

    pNovo_Realloc = realloc(*arrPessoa, (*totalFuncionarios) * sizeof (Pessoa));




    if (pNovo_Realloc == NULL) //verificar sucesso
    {
        printf("Erro\n");
        exit(0);
    } else {
        *arrPessoa = pNovo_Realloc;
    }


    if (*contadorFuncionarios < 1) { //pedidos ao primeiro utilizador (contadorFuncionarios = 0)
        puts("Nº de funcionário:");
        scanf("%d", &nrFunc); //pode ser qualquer um

        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc; //no inidice do contador, atribuir o nr fornecido


        printf("Nome do funcionário:\n");
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);


        puts("\nFuncionário Criado.");




    } else { //Quando o contador de funcionário é mais que 0

        puts("Nº de funcionário:");
        scanf("%d", &nrFunc);


        nrFunc = verificarExistenciaFuncs(arrPessoa, totalFuncionarios, contadorFuncionarios, nrFunc); //Função testa a existencia deste funcionário e de outros,  
        //quando for novo retorna para nrFunc o novo e vai ser utilizado de seguida
        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
        //printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
        //printf("totalFuncs CRIADO %d\n", *totalFuncionarios);


        printf("Nome do funcionário:\n");
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);

        puts("\nFuncionário Criado.");

    }
    *contadorFuncionarios += 1; //quando se cria novo funcionário, ou no indice 0 ou posteriores, o indice aumenta 1.


}

/**
 * Função que testa existencia de funcionário na lista de funcionários.
 * Tem recursividade, e só pára quando o funcionário for novo na lista.
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param FuncNmbr trás o funcNumbr de outras funções e testa a sua existencia
 * @return Retorna o retornador, que vai ser o nr de funcionário que não existe na lista.
 */
int verificarExistenciaFuncs(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios, int FuncNmbr) {

    int i, retornador, novoNumero;

    retornador = FuncNmbr;


    for (i = 0; i < *totalFuncionarios; i++) {
        if ((*arrPessoa)[i].funcNumbr == FuncNmbr) {
            printf("Funcionário %d já existe.\n", (*arrPessoa)[i].funcNumbr);
            puts("NOVO* Nr de funcionário:");
            scanf("%d", &novoNumero);
            retornador = verificarExistenciaFuncs(arrPessoa, totalFuncionarios, contadorFuncionarios, novoNumero);
        }
    }
    return retornador; //se o retornador retornar o mesmo valor recebido, é porque o funcionário era novo de origem
}

/**
 * Função que lista os funcionários criados(seu id e nome)
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void listarFuncs(Pessoa **arrPessoa, int *totalFuncionarios) {
    int i;
    puts("Lista de Funcionários:");
    for (i = 0; i < *totalFuncionarios; i++) {
        if ((*arrPessoa)[i].funcNumbr != 0) {
            printf("ID %d ---- ", (*arrPessoa)[i].funcNumbr);
            printf("Nome %s \n", (*arrPessoa)[i].funcNome);
        }
    }
}

/**
 * Função com o objetivo de atualizar funcionários e ainda, derivado da estrutura do código
 * atualiza também os id's dos funcionários na timesheet quando aqui alterados
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void atualizarFuncs(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets) {
    int escolha, nfunc, existenciaIndice = -1, existenciaIndice2 = -1;
    char nomeFunc[25];

    do {
        puts("Pretende alterar: Nº (1) Nome (2)");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 2);


    puts("Nº de funcionário:");
    scanf("%d", &nfunc);

    existenciaIndice = verificarExistenciaFuncs2(arrPessoa, totalFuncionarios, nfunc); //verificar se funcionario existe, pelo Indice (é retornado indice ou -1 caso não exista) 

    if (existenciaIndice >= 0) { //se o indice for igual ou superior a 0 é porque o funcionário existe
        switch (escolha) {
            case 1:
                puts("Novo Nº de Funcionário:");
                scanf("%d", &nfunc);


                existenciaIndice2 = verificarExistenciaFuncs2(arrPessoa, totalFuncionarios, nfunc); //novo teste para garantir que o novo também existe ou nao, se sim não aceita
                if (existenciaIndice2 >= 0) {

                    printf("Funcionário já existe; \n");
                } else {


                    for (int i = 0; i < *totalTimesheets; i++) {
                        if ((*arrTimesheet)[i].funcCode == (*arrPessoa)[existenciaIndice].funcNumbr) { //atribuição, caso existam, nas timesheets, o novo id
                            (*arrTimesheet)[i].funcCode = nfunc;
                        }
                    }
                    (*arrPessoa)[existenciaIndice].funcNumbr = nfunc; //atribuição do novo id ao utilizador em questão no indice em questão



                }

                break;
            case 2: //opção mudança de nome
                puts("Novo Nome:");
                scanf(" %[^\n]s", nomeFunc);
                strcpy((*arrPessoa)[existenciaIndice].funcNome, nomeFunc);
                break;
            default:
                printf("escolha errada;");
        }
    } else {
        printf("\nFuncionario não existe;");
    }
}

/**
 * Função de verificar se funcionário existe na sua estrutura, a partir do indice.
 * Retorna o indice se existir, ou -1 caso não exista. Testa com base no ultimo parametro
 * que recebe, FuncNmbr
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param FuncNmbr argumento que indica o nr de funcionário a testar existencia
 * @return retorna -1 caso funcionário não exista, ou o indice do funcionário, existindo.
 */
int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *totalFuncionarios, int FuncNmbr) {

    for (int i = 0; i < *totalFuncionarios; i++) {
        if ((*arrPessoa)[i].funcNumbr == FuncNmbr) {

            return i;
        }
    }
    return -1;
}

/**
 * Função de eliminar funcionários, cujas timesheets também são eliminadas
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @return 
 */
int eliminarFuncs(Pessoa **arrPessoa, int *totalFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets) {

    int apagado = -1;
    int idapagar;

    puts("Utilizador a apagar: ");
    scanf("%d", &idapagar);

    for (int i = 0; i < *totalFuncionarios; i++) { //teste de existencia e se existir...
        if ((*arrPessoa)[i].funcNumbr == idapagar) {

            for (int i = 0; i < *totalTimesheets; i++) {
                if ((*arrTimesheet)[i].funcCode == idapagar) {
                    (*arrTimesheet)[i].funcCode = 0; //...o id na timesheet é transformado em 0, caso exista
                }
            }



            (*arrPessoa)[i].funcNumbr = 0; //...o id do funcionario é transormado em 0.
            strcpy((*arrPessoa)[i].funcNome, "");
            apagado = 1;
        }

    }

    if (apagado == 1) {
        puts("Apagado Com sucesso;");
    } else {
        puts("Impossível apagar Funcionário identificado;");
        puts("Erro;");
    }

}

/*
void funcsSemTimesheet(Pessoa **arrPessoa, int *totalFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets) {


    for (int i = 0; i < *totalFuncionarios; i++) {
        for (int k = 0; k < *totalTimesheets; k++) {
            if ((*arrPessoa)[i].funcNumbr != (*arrTimesheet)[k].funcCode) {
                puts("Funcionário existe");
            } else {
                printf("Funcionário %d sem Timesheet.", (*arrPessoa)[i].funcNumbr);
            }
        }

        if (*totalTimesheets == 0) {
            puts("Sem timesheets criadas");
        }
    }
    if (*totalFuncionarios == 0) {
        puts("Sem funcionarios criados");
    }



}
 */

















