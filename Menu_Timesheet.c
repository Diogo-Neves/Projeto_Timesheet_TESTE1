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
    //Pessoa *arrPessoa;
    //Funcionario_st2 funcionarios = {.contador = 0};
    //Timesheet_st2 timesheets = {.contadorTS = 0};
    //int totalFuncionarios = 0;
    //int contadorFuncionarios = 0;
    
    
    //arrPessoa = (Pessoa *) malloc(1 * sizeof (Pessoa));

    do {
        
        printf("\nTimesheets------------------------------------------------------");
        printf("\n1 - Inserir nova timesheet");
        printf("\n2 - Atualizar timesheet");
        printf("\n3 ");
        printf("\n4 - ");
        printf("\n5 - Listar Timesheets");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        //printf("\nFuncionários: %d/%d", alunos.contador, MAX_ALUNOS);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                //preenchermes(&funcionarios, &timesheets, &timesheets);
                break;
            case 1:
                criarTimesheet(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets, Total_Funcionarios, contadorFuncionarios);
                break;
            /*case 2:
                atualizarFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios);
                break;
            case 3:
                eliminarFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios);
                break;
            //case 4:
              //  removerAlunos(&alunos);
                //break;*/
            case 5:
               listarTimesheets(arrTimesheet, arrPessoa, totalTimesheets);
               break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
    

    return 0;
}