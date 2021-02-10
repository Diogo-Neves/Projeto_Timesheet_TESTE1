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
    
    int* totalTimesheets = malloc(sizeof (int));
    int* contadorTimesheets = malloc(sizeof (int));
    
    int totalFUNCS = 0;
    int contadorFUNCS = 0;

     
    
    int totalTS = 0;
    int contadorTS = 0;
    
    *totalFuncionarios = totalFUNCS;
    *contadorFuncionarios = contadorFUNCS;

    
    //printf("%d", *totalFuncionarios);
    
    arrPessoa = (Pessoa *) malloc(1 * sizeof (Pessoa));
    arrTimesheet = (Timesheet *) malloc(1 * sizeof (Timesheet));
    
    
    *totalTimesheets = totalTS;
    *contadorTimesheets = contadorTS; 

    do {
        
        printf("\n ---Menu Inicial-Gestão de Trabalho dos Funcionários---2021---");
        printf("\n1 - Funcionarios");
        printf("\n2 - Timesheets");
        printf("\n3 - Exportar por mês");
        printf("\n4 - Funcionários com Compensação");
        puts("");
        printf("\n------Dados da aplicação--------------------------------------");
        printf("\n5 - Guardar estado atual ---------------");
        printf("\n6 - Carregar ultimo estado guardado ----");
        printf("\n--------------------------------------------------------------");
        printf("\n");
        printf("\n0 - Fechar Aplicação");
        printf("\n--------------------------------------------------------------");

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_funcionarios(&arrPessoa, totalFuncionarios, contadorFuncionarios,&arrTimesheet, totalTimesheets);
                break;
            case 2:
                menu_timesheet(&arrTimesheet, &arrPessoa, totalTimesheets, contadorTimesheets, totalFuncionarios);
                break;
            case 3:
                exportarMes(&arrPessoa, &arrTimesheet, totalTimesheets);
                break;
            case 4:
                direitoCompensaçao(&arrTimesheet,totalTimesheets);   
                break;
            case 5:
                escreverTudo(&arrPessoa, &arrTimesheet,totalFuncionarios,contadorFuncionarios, totalTimesheets, contadorTimesheets);
               break;
            case 6:
                carregarTudo(&arrPessoa, &arrTimesheet,totalFuncionarios, contadorFuncionarios, totalTimesheets, contadorTimesheets);
                break;
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

