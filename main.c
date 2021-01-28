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
    Funcionario_st2 funcionarios = {.contador = 0};
    Timesheet_st2 timesheets = {.contadorTS = 0};

    do {
        
        printf("\nFuncionários------------------------------------------------------");
        printf("\n1 - Inserir Funcionários");
        printf("\n2 - Preencher Timesheet");
        printf("\n3 - Listar Timesheets");
        printf("\n4 - Remover");
        printf("\n5 - Listar");
        printf("\n0 - Sair");
        printf("\npFuncs  %p \n", &funcionarios );
        printf("\n------------------------------------------------------------");
        //printf("\nFuncionários: %d/%d", alunos.contador, MAX_ALUNOS);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                //preenchermes(&funcionarios, &timesheets, &timesheets);
                break;
            case 1:
                criarFunc(&funcionarios);
                break;
            case 2:
                preencherTS(&funcionarios, &timesheets);
                break;
            //case 3:
              //  listTimesheets(&funcionarios);
                //break;
            //case 4:
              //  removerAlunos(&alunos);
                //break;
            case 5:
               listarFuncs(funcionarios);
               break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);
    

    return 0;
}

