/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcs.h"
#include "Menu_Funcs_header.h"

/*
 * 
 */
int menu_timesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *Total_Funcionarios, int *contadorFuncionarios ){
    setlocale(LC_ALL,"");
    int opcao;
    
    //(*arrPessoa)[*totalTimesheets].Timesheets_pessoa = malloc(*totalTimesheets *sizeof (Timesheet));
    //Pessoa *arrPessoa;
    //Funcionario_st2 funcionarios = {.contador = 0};
    //Timesheet_st2 timesheets = {.contadorTS = 0};
    //int totalFuncionarios = 0;
    //int contadorFuncionarios = 0;
    
    
    //arrPessoa = (Pessoa *) malloc(1 * sizeof (Pessoa));

    do {
        
        printf("\n --Gestão do Trabalho realizado (Timesheets)------------------");
        printf("\n1 - Inserir nova timesheet");
        printf("\n2 - Verificar Timesheets incompletas");
        printf("\n3 - Consultar Timesheet por código de funcionário(listar dias)");
        printf("\n4 - Recriar Timesheet");
        printf("\n5 - Listar Timesheets");
        printf("\n0 -- Voltar atrás --");
        printf("\n--------------------------------------------------------------");
        //printf("\nFuncionários: %d/%d", alunos.contador, MAX_ALUNOS);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarTimesheet(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets, Total_Funcionarios, contadorFuncionarios);
                break;
            case 2:
                timesheetsIncompletas(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets,Total_Funcionarios, contadorFuncionarios);
                break;
            case 3:
                consultarTSutilizador(arrTimesheet, arrPessoa,totalTimesheets, contadorTimesheets);
                break;
            case 4:
                refazerTimesheet(arrTimesheet,arrPessoa,totalTimesheets,contadorTimesheets,Total_Funcionarios,contadorFuncionarios);
                break;
            case 5:
               listarTimesheets(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets);
               break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
    

    return 0;
}