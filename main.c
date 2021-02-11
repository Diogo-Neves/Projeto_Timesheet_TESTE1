/**
 * 
 * @file main.c  
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief Menus de programa de preenchimento de funcionários e timesheets
 * 
 * 
 */




#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "maindata.h"

/**
 * Esta função é apenas a função inicial para aceder a menus secundários
 * Aqui são criados apontadores para estruturas criadas e contadores com apontadores
 */
int main() {
    setlocale(LC_ALL, "");
    int opcao;
    Pessoa *arrPessoa;
    Timesheet *arrTimesheet;

    arrPessoa = (Pessoa *) malloc(1 * sizeof (Pessoa)); //Alocação de array dinamico
    arrTimesheet = (Timesheet *) malloc(1 * sizeof (Timesheet)); //Alocação de array dinamico


    int* totalFuncionarios = malloc(sizeof (int)); //Alocação de um contador dinamicamente
    int* contadorFuncionarios = malloc(sizeof (int)); //Alocação de um contador dinamicamente

    int* totalTimesheets = malloc(sizeof (int)); //Alocação de um contador dinamicamente
    int* contadorTimesheets = malloc(sizeof (int)); //Alocação de um contador dinamicamente

    int totalFUNCS = 0;
    int contadorFUNCS = 0;



    int totalTS = 0;
    int contadorTS = 0;

    *totalFuncionarios = totalFUNCS;
    *contadorFuncionarios = contadorFUNCS;






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


        do {
            printf("\nOpcão: ");
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 6); //Loop de tentativas erro de opções do menu


        switch (opcao) {
            case 0:
                puts("\n");
                puts("\n...a fechar.");
                break;
            case 1:
                menu_funcionarios(&arrPessoa, totalFuncionarios, contadorFuncionarios, &arrTimesheet, totalTimesheets);
                break;
            case 2:
                menu_timesheet(&arrTimesheet, &arrPessoa, totalTimesheets, contadorTimesheets, totalFuncionarios);
                break;
            case 3:
                exportarMes(&arrTimesheet, totalTimesheets);
                break;
            case 4:
                direitoCompensaçao(&arrTimesheet, totalTimesheets);
                break;
            case 5:
                escreverTudo(&arrPessoa, &arrTimesheet, totalFuncionarios, contadorFuncionarios, totalTimesheets, contadorTimesheets);
                break;
            case 6:
                carregarTudo(&arrPessoa, &arrTimesheet, totalFuncionarios, contadorFuncionarios, totalTimesheets, contadorTimesheets);
                break;
            default:
                break;
        }

    } while (opcao != 0); //opção sair



    freeCalloc(&arrTimesheet, totalTimesheets); //libertar memoria apenas quando se faz sair

    free(arrPessoa); //libertar memoria apenas quando se faz sair

    free(arrTimesheet); //libertar memoria apenas quando se faz sair

    free(totalTimesheets); //libertar memoria apenas quando se faz sair

    free(contadorFuncionarios); //libertar memoria apenas quando se faz sair


    //puts("teste");
    return (EXIT_SUCCESS);
}

