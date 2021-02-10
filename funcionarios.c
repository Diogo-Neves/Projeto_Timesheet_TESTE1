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










//USAR QUANDO NECESSARIO, NAO ESQUECER

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void criarFunc(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios) {

    int nrFunc;
    Pessoa *pNovo_Realloc;
    char nomeFunc[25];

    *totalFuncionarios += 1;
    //printf("indiceFuncsCRIAR %d \n", *contadorFuncionarios);
    //printf("indiceTOTAL EM CRIAR %d \n", *totalFuncionarios);

    pNovo_Realloc = realloc(*arrPessoa, (*totalFuncionarios) * sizeof (Pessoa));




    if (pNovo_Realloc == NULL) //verificar se foi bem ou mal sucedido
    {
        printf("Erro\n");
        //exit(0);
    } else //este else so esta aqui para facilitar a leitura
    {
        *arrPessoa = pNovo_Realloc;
    }


    if (*contadorFuncionarios < 1) {
        puts("Nº de funcionário:");
        scanf("%d", &nrFunc);

        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
        //printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
        //printf("totalFuncs CRIADO %d\n", *totalFuncionarios);


        printf("Nome do funcionário:\n");
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);
        
        
        puts("\nFuncionário Criado.");




    } else {
        //printf("São mais");
        puts("Nº de funcionário:");
        scanf("%d", &nrFunc);


        nrFunc = verificarExistenciaFuncs(arrPessoa, totalFuncionarios, contadorFuncionarios, nrFunc);

        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
        //printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
        //printf("totalFuncs CRIADO %d\n", *totalFuncionarios);


        printf("Nome do funcionário:\n");
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);

        puts("\nFuncionário Criado.");

    }
    *contadorFuncionarios += 1;


}

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

    return retornador;
}

void listarFuncs(Pessoa **arrPessoa, int *totalFuncionarios) {
    int i;
    puts("Lista de Funcionários:");
    for (i = 0; i < *totalFuncionarios; i++) {
        if ((*arrPessoa)[i].funcNumbr != NULL) {
            printf("ID %d ---- ", (*arrPessoa)[i].funcNumbr);
            printf("Nome %s \n", (*arrPessoa)[i].funcNome);
        }
        //printf("ID %d i: %d ---- ",(*arrPessoa)[i].funcNumbr, i);     
        //printf("Nome %s i: %d  \n",(*arrPessoa)[i].funcNome, i);
    }


}

void atualizarFuncs(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets) {
    int escolha, nfunc, existenciaIndice = -1, existenciaIndice2 = -1;
    char nomeFunc[25];

    do {
        puts("Pretende alterar: Nº (1) Nome (2)");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 2);


    puts("Nº de funcionário:");
    scanf("%d", &nfunc);

    existenciaIndice = verificarExistenciaFuncs2(arrPessoa, totalFuncionarios, nfunc);

    if (existenciaIndice >= 0) {
        switch (escolha) {
            case 1:
                puts("Novo Nº de Funcionário:");
                scanf("%d", &nfunc);


                existenciaIndice2 = verificarExistenciaFuncs2(arrPessoa, totalFuncionarios, nfunc);
                //printf("\nexistIndice %d \n", existenciaIndice);
                if (existenciaIndice2 >= 0) {

                    printf("Funcionário já existe; \n");
                } else {


                    for (int i = 0; i < *totalTimesheets; i++) {
                        if ((*arrTimesheet)[i].funcCode == (*arrPessoa)[existenciaIndice].funcNumbr) {
                            (*arrTimesheet)[i].funcCode = nfunc;
                        }
                    }
                    (*arrPessoa)[existenciaIndice].funcNumbr = nfunc;



                }

                break;
            case 2:
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

    //free(*arrPessoa);
    //*arrPessoa = NULL;

}

int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *totalFuncionarios, int FuncNmbr) {

    int i;


    for (i = 0; i < *totalFuncionarios; i++) {
        if ((*arrPessoa)[i].funcNumbr == FuncNmbr) {

            return i;
        }
    }
    return -1;


}

int eliminarFuncs(Pessoa **arrPessoa, int *totalFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets) {

    int apagado = -1;
    int idapagar;

    puts("Utilizador a apagar: ");
    scanf("%d", &idapagar);

    for (int i = 0; i < *totalFuncionarios; i++) {
        if ((*arrPessoa)[i].funcNumbr == idapagar) {

            for (int i = 0; i < *totalTimesheets; i++) {
                if ((*arrTimesheet)[i].funcCode == idapagar) {
                    (*arrTimesheet)[i].funcCode = NULL;
                }
            }



            (*arrPessoa)[i].funcNumbr = NULL;
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

















