/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Diogo
 *
 * Created on 26 de janeiro de 2021, 11:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcs.h"

/*
 * 
 */
int main() {
    setlocale(LC_ALL,"");
    int opcao;
    Pessoa *arrPessoa;
    Timesheet *arrTimesheet;
    //Funcionario_st2 funcionarios = {.contador = 0};
    //Timesheet_st2 timesheets = {.contadorTS = 0};
    //int *totalFUNCS = NULL;
    //int *contadorFUNCS = NULL;
    
    int* totalFuncionarios = malloc(sizeof (int));
    int* contadorFuncionarios = malloc(sizeof (int));
    
    int totalFUNCS = 0;
    int contadorFUNCS = 0;
    *totalFuncionarios = totalFUNCS;
    *contadorFuncionarios = contadorFUNCS;
    
    int* totalTimesheets = malloc(sizeof (int));
    int* contadorTimesheets = malloc(sizeof (int));
    //totalFUNCS
    //contadorFUNCS
     
    
    int totalTS = 0;
    int contadorTS = 0;

    
    printf("%d", *totalFuncionarios);
    
    arrPessoa = (Pessoa *) malloc(1 * sizeof (Pessoa));
    arrTimesheet = (Timesheet *) malloc(1 * sizeof (Timesheet));
    *totalTimesheets = totalTS;
    *contadorTimesheets = contadorTS; 

    do {
        
        printf("\nMenu Inicial------------------------------------------------------");
        printf("\n1 - Funcionarios");
        printf("\n2 - Timesheets");
        printf("\n3 - Exportar por mês");
        printf("\n4 - Guardar tudo");
        printf("\n5 - Carregar ultimo Guardado");
        printf("\n6 - ");
        printf("\n7 - ");
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
                menu_funcionarios(&arrPessoa, totalFuncionarios, contadorFuncionarios);
                break;
            case 2:
                menu_timesheet(&arrTimesheet, &arrPessoa, totalTimesheets, contadorTimesheets, totalFuncionarios, contadorFuncionarios);
                break;
            case 3:
                exportarMes(&arrPessoa, &arrTimesheet, totalTimesheets);
                break;
            case 4:
                //escreverFuncionarios(&arrPessoa, &arrTimesheet, totalFuncionarios);
                escreverTudo(&arrPessoa, &arrTimesheet,totalFuncionarios,contadorFuncionarios, totalTimesheets, contadorTimesheets);
                break;
            case 5:
               //LerFuncionarios(&arrPessoa, &arrTimesheet, totalFuncionarios);
               carregarTudo(&arrPessoa, &arrTimesheet,totalFuncionarios, contadorFuncionarios, totalTimesheets, contadorTimesheets);
               break;
            /*case 6:
                //PosicionarFuncionarios(&arrPessoa, &arrTimesheet, totalFuncionarios);
                //carregarTudo(&arrPessoa, &arrTimesheet,totalFuncionarios);
                //posicionarioTotalFunc(totalFuncionarios);
                break;*/
            //case 7:
              //  escreverTotalFunc(totalFuncionarios);
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
    
    free(arrPessoa);
    arrPessoa = NULL;
    free(arrTimesheet);
    arrTimesheet = NULL;
    return 0;
}

