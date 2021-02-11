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
#include "Menu_TS_header.h"


/**
 * Função de menu que executa as funções referentes às timesheets
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @return 
 */
int menu_timesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios){
    setlocale(LC_ALL,"");
    int opcao;
    
    do {
        
        printf("\n --Gestão do Trabalho realizado (Timesheets)------------------");
        printf("\n1 - Inserir nova timesheet");
        printf("\n2 - Verificar Timesheets incompletas");
        printf("\n3 - Consultar Timesheet por código de funcionário(listar dias)");
        printf("\n4 - Recriar Timesheet/Apagar Timesheet");
        printf("\n5 - Listar Timesheets");
        printf("\n0 -- Voltar atrás --");
        printf("\n--------------------------------------------------------------");

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarTimesheet(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets, totalFuncionarios);
                break;
            case 2:
                timesheetsIncompletas(arrTimesheet, totalTimesheets);
                break;
            case 3:
                consultarTSutilizador(arrTimesheet,totalTimesheets);
                break;
            case 4:
                refazerTimesheet(arrTimesheet,arrPessoa,totalTimesheets,contadorTimesheets,totalFuncionarios);
                break;
            case 5:
               listarTimesheets(arrTimesheet,totalTimesheets);
               break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
    

    return 0;
}