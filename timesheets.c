/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "Menu_Funcs_header.h"
#include "Menu_TS_header.h"
#include "funcs.h"
#include <locale.h>

void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios) {

    Timesheet *PNovaTS_Realloc;
    int nfunc, indiceFuncao, preencherTS;


    printf("\nQuantidade prévia de Timesheets: %d\n", *totalTimesheets);
    puts("Nr de funcionário:");
    scanf("%d", &nfunc);


    indiceFuncao = verificarExistenciaFuncs2(arrPessoa, totalFuncionarios, nfunc);


    if (indiceFuncao > -1 && nfunc != 0) {
        *totalTimesheets += 1;
        //printf("*TotalTimesheets ANTES DE REALOCAR %d\n", *totalTimesheets);

        PNovaTS_Realloc = realloc(*arrTimesheet, (*totalTimesheets) * sizeof (Timesheet));



        if (PNovaTS_Realloc == NULL) //verificar se foi bem ou mal sucedido
        {
            printf("Erro\n");
            exit(0);
        } else //este else so esta aqui para facilitar a leitura
        {
            *arrTimesheet = PNovaTS_Realloc;
        }

        //printf("*contadorTS ANTES DE alocar x1 %d\n", *contadorTimesheets);
        //(*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias*) malloc (sizeof(Dias)) ;

        (*arrTimesheet)[*contadorTimesheets].funcCode = (*arrPessoa)[indiceFuncao].funcNumbr;

        (*arrTimesheet)[*contadorTimesheets].timesheetCode = *totalTimesheets;

        //printf("NrFuncTS %d\n", (*arrTimesheet)[*contadorTimesheets].funcCode);

        //printf("Timesheet Nº:%d\n", *contadorTimesheets);

        //*contadorTimesheets += 1;
        //printf("*contadorTimesheets antes de chamar PREENCHER %d\n", *contadorTimesheets);

        preencherTS = preenchermes(arrTimesheet, contadorTimesheets); //TEM QUE PASSAR A LEVAR CONTADORTIMESHEETS





    } else {
        printf(" Funcionário inexistente;");
    }

};

void listarTimesheets(Timesheet **arrTimesheet, int *totalTimesheets) {
    puts("Lista de Timesheets:");
    puts("");


    for (int i = 0; i < *totalTimesheets; i++) {
        if ((*arrTimesheet)[i].timesheetCode > 0 && (*arrTimesheet)[i].funcCode > 0) {
            printf("Timesheet ID: %d Mes: %d FuncID: %d \nJornada Comp. F.semana: %d / Jornada Comp.: %d \nMeia Jornada F.semana: %d / Meia Jornada: %d \nFaltas: %d / Folgas: %d\n\n\n", (*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);
            puts("----------------------------------------------------------------------");
        }
    }
    puts("----------------------------------------------------------------------");
}

int preenchermes(Timesheet **arrTimesheet, int *contadorTimesheets) {
    //printf("\n\n\nfuncMes\n");

    //printf("valor do contador depois de receber: %d\n", *contadorTimesheets);


    int mes, mes2;

    do {
        puts("Qual o mês em questão:");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    mes2 = mes;

    //verificar se utilizador da timesheet ja tem mes

    for (int s = 0; s < *contadorTimesheets + 1; s++) {
        if ((*arrTimesheet)[s].funcCode == (*arrTimesheet)[*contadorTimesheets].funcCode) {
            if ((*arrTimesheet)[s].mesTS == mes2) {
                do {
                    puts("Mês já preenchido pelo Funcionário\nInsira o mês que deseja preencher:");
                    scanf("%d", &mes);
                } while (mes < 1 || mes > 12 || mes == mes2);
                
            }
        }

    }

    switch (mes) {
        case 1:
            //Funcionario_st2 *funcionarios, int number, int dias, int mes 
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            
            //return executardias;
            break;
        case 2:
            dias_total(28, arrTimesheet, mes, contadorTimesheets);
            
            //return executardias;
            break;
        case 3:
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            
            //return executardias;
            break;
        case 4:
            dias_total(30, arrTimesheet, mes, contadorTimesheets);
            
            //return executardias;
            break;
        case 5:
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            
            //return executardias;
            break;
        case 6:
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            
            //return executardias;
            break;
        case 7:
            dias_total(30, arrTimesheet, mes, contadorTimesheets);
            

            break;
        case 8:
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            

            break;
        case 9:
            dias_total(30, arrTimesheet, mes, contadorTimesheets);
            

            break;
        case 10:
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            

            break;
        case 11:
            dias_total(30, arrTimesheet, mes, contadorTimesheets);
            

            break;
        case 12:
            dias_total(31, arrTimesheet, mes, contadorTimesheets);
            

            break;
        default:
            printf("Erro");
            break;
    }
}







///////////          TESTES BY DIOGOOOO        //////

int dias_total(int dias, Timesheet **arrTimesheet, int mes, int *contadorTimesheets) {

    int dia, verificar, contadorDias = 0;
    //Dias *pNovo_realloc_dias;
    //Timesheet *PNovaTS_Realloc;

    //(*arrTimesheet)[contador].dias_scope = 0;


    //zerardias(arrTimesheet, contador, dias);
    //printf("contadorts %d \n", *contadorTimesheets);



    do {
        puts("Insira o dia(1) a preencher:");
        scanf("%d", &dia);
    } while (dia < 1 || dia > dias);


    //printf("*contadorTS ANTES DE REALOCAR %d\n", *contadorTimesheets);
    //printf("Total de dias a alocar %d  \n", dias);

    (*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias*) calloc(32, sizeof (Dias));


/*
    for (int k = 0; k < dias; k++) {
        printf(" Dias preenchidos depois de zerar: %d  i: %d \n", (*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, k);
    }
*/



    //puts("Timesheet Inicializada TESTE SEGUNDA RODADA:");
    //printf("contador de timesheets (indice): %d \n", *contadorTimesheets);
    (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia;
    (*arrTimesheet)[*contadorTimesheets].jornadaCompFDS = 0;
    (*arrTimesheet)[*contadorTimesheets].jornadaComp = 0;
    (*arrTimesheet)[*contadorTimesheets].meiaJornFDS = 0;
    (*arrTimesheet)[*contadorTimesheets].meiaJorn = 0;
    (*arrTimesheet)[*contadorTimesheets].falta = 0;
    (*arrTimesheet)[*contadorTimesheets].folga = 0;
    (*arrTimesheet)[*contadorTimesheets].mesTS = mes;
    diaPorDia(arrTimesheet, contadorTimesheets, mes, contadorDias, dia);

    contadorDias += 1;

    do {

        do {
            puts("");
            puts("Preencher Novo Dia:   (0 = Sair)");
            scanf("%d", &dia);
        } while (dia < 0 || dia > dias);



        verificar = contagemDias(arrTimesheet, dia, contadorTimesheets, dias);
        //printf("Verificar %d \n", verificar);
        if (verificar != -1 && dia > 0) {

            (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia;
            diaPorDia(arrTimesheet, contadorTimesheets, mes, contadorDias, dia);


            
            contadorDias += 1;
        }

    } while (dia != 0 && contadorDias < dias);
    if(dia == 0){
        puts("Timesheet preenchida, mas incompleta.");
    }



    for (int k = 0; k < dias; k++) {
        printf(" %d - Dias preenchidos: %d  ,    status: %s \n",k,(*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, (*arrTimesheet)[*contadorTimesheets].dias_scope[k].status);
    }


    *contadorTimesheets += 1;
}

int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias) {

    for (int i = 0; i < dias; i++) {
        if ((*arrTimesheet)[*contadorTimesheets].dias_scope[i].dia == dia) {
            puts("");
            puts("");
            puts("");
            return -1;
        }
    }
    return 0;


}

int diaPorDia(Timesheet **arrTimesheet, int *contadorTimesheets, int mes, int contadorDias, int dia) {


    int ret;
    struct tm info;
    char buffer[80];

    info.tm_year = 2021 - 1900;
    info.tm_mon = mes - 1; // 1 a 12 (meses)
    info.tm_mday = dia; // dia di mes '1 2 3 /  31
    info.tm_hour = 0;
    info.tm_min = 0;
    info.tm_sec = 1;
    info.tm_isdst = -1;
    //info.tm_mon = 0          
    //info.tm_wday = 0 - 6;    // 0 domingo 1 Mon  6 sat 


    int estadonoDia;



    ret = mktime(&info);
    if (ret == -1) {
        printf("Error: unable to make time using mktime\n");
    } else {
        strftime(buffer, sizeof (buffer), "%c", &info);
        printf(buffer);
    }

    char nome[15] = "Integral";
    char nome2[15] = "Parcial";
    char nome3[15] = "Falta";
    char nome4[15] = "Folga";
    puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:");

    do {
        puts("Insira estado(1->4):");
        scanf("%d", &estadonoDia);
    } while (estadonoDia < 1 || estadonoDia > 4);


    switch (estadonoDia) {
        case 1:
            if (info.tm_wday == 0 || info.tm_wday == 6) {

                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome);
                //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Integral';
                (*arrTimesheet)[*contadorTimesheets].jornadaCompFDS++;
                puts("Jornada Completa - Fim de semana");
            } else {

                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome);
                //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Integral';
                (*arrTimesheet)[*contadorTimesheets].jornadaComp++;
                puts("Jornada Completa");
            }
            break;
        case 2:

            if (info.tm_wday == 0 || info.tm_wday == 6) {
                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome2);
                //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Parcial';
                (*arrTimesheet)[*contadorTimesheets].meiaJornFDS++;
                puts("Meia jornada - Fim de semana");
            } else {

                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome2);
                //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Parcial';
                (*arrTimesheet)[*contadorTimesheets].meiaJorn++;
                puts("Meia jornada");
            }
            break;
        case 3:

            (*arrTimesheet)[*contadorTimesheets].falta++;
            strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome3);
            //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Falta';
            puts("Falta");
            break;
        case 4:

            (*arrTimesheet)[*contadorTimesheets].folga++;
            strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome4);
            //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Folga';
            puts("Folga");
            break;
        default:
            break;

    }

}

void consultarTSutilizador(Timesheet **arrTimesheet, int *totalTimesheets) {
    int userCode, v1 = -1;
    puts("Indique o nr de Utilizador");
    scanf("%d", &userCode);


    for (int j = 0; j < *totalTimesheets; j++) {
        if ((*arrTimesheet)[j].funcCode == userCode) {
            v1 = 0;

            for (int k = 0; k < 31; k++) {

                if ((*arrTimesheet)[j].dias_scope[k].dia != 0) {
                    printf("Timesheet Nº: %d - Dia: %d/%d/2021  i: %d    status: %s \n", (*arrTimesheet)[j].timesheetCode, (*arrTimesheet)[j].dias_scope[k].dia, (*arrTimesheet)[j].mesTS, k, (*arrTimesheet)[j].dias_scope[k].status);
                }



            }
        }
    }

    if (v1 != 0) {
        puts("Erro; \n Funcionário não existe na lista;");
        puts("Erro; \n   ou sem Timesheet;");
    }

}

void direitoCompensaçao(Timesheet **arrTimesheet, int *totalTimesheets) {

    printf("O direito de Compensação reserva-se aos funcionários que exerceram\n");
    printf("funções ao fim de semana, estando estas divididas em compensações \n");
    printf("totais ou parciais mediante o exercido. \n");

    for (int i = 0; i < *totalTimesheets; i++) {
        if ((*arrTimesheet)[i].timesheetCode != 0 && (*arrTimesheet)[i].jornadaCompFDS > 0 || (*arrTimesheet)[i].meiaJornFDS > 0) {
            printf("\nTimesheet ID: %d Mes: %d FuncID: %d  i: %d \nCompensações Totais: %d / Compensações Parciais: %d .\n\n\n", (*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].meiaJornFDS);

        }
    }


}

void timesheetsIncompletas(Timesheet **arrTimesheet, int *totalTimesheets) {

    printf("Timesheets Incompletas (caso existam):\n");
    puts("");

    for (int i = 0; i < *totalTimesheets; i++) {
        if (((*arrTimesheet)[i].jornadaCompFDS + (*arrTimesheet)[i].jornadaComp + (*arrTimesheet)[i].meiaJornFDS + (*arrTimesheet)[i].meiaJorn + (*arrTimesheet)[i].falta + (*arrTimesheet)[i].folga) < 25 && (*arrTimesheet)[i].funcCode > 0) {
            printf("Timesheet ID: %d Mes: %d FuncID: %d \nJornada Comp. F.semana: %d / Jornada Comp.: %d \nMeia Jornada F.semana: %d / Meia Jornada: %d \nFaltas: %d / Folgas: %d\n\n\n", (*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);

        }
    }
    puts("");
    printf("--------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------\n");
    printf("No caso de existirem Timesheets incompletas, recomenda-se a sua \n");
    printf("reinserção no menu 'Gestão do Trabalho realizado (Timesheets)' \n");
    printf("Opção '4 - Recriar Timesheet', utilizando o código da Timesheet \n");
    printf("e respetivo código de funcionário. \n");
    printf("Timesheet é considerada completa com 25 ou mais dias preenchidos. \n");
    printf("--------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------\n");


}

void refazerTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios) {
    int timesheetNo, indiceTS;
    puts("Timesheet a recriar:");
    scanf("%d", &timesheetNo);

    indiceTS = possivelTimesheet(arrTimesheet, totalTimesheets, timesheetNo);

    if (indiceTS != -1 && (*arrTimesheet)[indiceTS].funcCode > 0) {
        puts("******");
        printf("Se pretende realmente recriar a Timesheet que se segue de seguida,\nutilize o número de Funcionário indicado e respetivo\nmês nos passos seguintes para o seu desenvolvimento.\n");
        printf("Se pretender apagar, Quando questionado pelo Nº de Funcionário indique 0.\n");
        puts("******");
        printf("Funcionário nº: %d || Mês : %d \n\nReformular nova Timesheet:\n", (*arrTimesheet)[indiceTS].funcCode, (*arrTimesheet)[indiceTS].mesTS);
        puts("");
        puts("");
        (*arrTimesheet)[indiceTS].timesheetCode = 0;
        (*arrTimesheet)[indiceTS].mesTS = 0;
        (*arrTimesheet)[indiceTS].funcCode = 0;
        criarTimesheet(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets, totalFuncionarios);
    } else {
        puts("Impossível recriar Timesheet;");
        puts("Possível razão: 1 - não existe;");
        puts("                2 - Funcionário apagado;");
    }

}

int possivelTimesheet(Timesheet **arrTimesheet, int *totalTimesheets, int timesheetNo) {

    //int timesheetNo;
    for (int i = 0; i < *totalTimesheets; i++) {
        if ((*arrTimesheet)[i].timesheetCode == timesheetNo) {

            return i;
        }
    }
    return -1;
}

