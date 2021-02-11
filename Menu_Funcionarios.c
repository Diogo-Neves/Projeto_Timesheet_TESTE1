/**
 * 
 * @file Menu_Funcionarios.c
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief Função de menu de opções para os Funcionários
 * 
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "maindata.h"
#include "Menu_Funcs_header.h"

/**
 * Menu com o CRUD (Create, Read, Update, Delete) dos funcionários
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param Total_Funcionarios argumento que trás o valor apontado deste contador dinâmico
 * @param contadorFuncionarios  argumento que trás o valor apontado deste contador dinâmico
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico 
 */
int menu_funcionarios(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets) {
    setlocale(LC_ALL, "");
    int opcao;

    do {

        printf("\n--Gestão de Funcionários--------------------------------------");
        printf("\n1 - Inserir Funcionários");
        printf("\n2 - Atualizar dados");
        printf("\n3 - Eliminar");
        printf("\n4 - Listar");
        printf("\n0 -- Voltar atrás --");
        printf("\n--------------------------------------------------------------");

        do {
            printf("\nOpcão: ");
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 4);


        switch (opcao) {
            case 0:
                puts("---Voltar atrás---");
                break;
            case 1:
                criarFunc(arrPessoa, Total_Funcionarios, contadorFuncionarios);
                break;
            case 2:
                atualizarFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios, arrTimesheet, totalTimesheets);
                break;
            case 3:
                eliminarFuncs(arrPessoa, Total_Funcionarios, arrTimesheet, totalTimesheets);
                break;
            case 4:
                listarFuncs(arrPessoa, Total_Funcionarios);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);


    return 0;
}