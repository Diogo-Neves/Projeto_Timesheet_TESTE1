/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcs.h"

//#define buffer[100]


void exportarMes(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *Total_Timesheets){
    const char* PalavraMes = "mes";
    const char* tipoFicheiro = ".txt";
    char buffer[100];
    int mes;
    puts("Insira o mes:");
    
    
    scanf("%d", &mes);
    sprintf(buffer,"%s%d%s",PalavraMes,mes,tipoFicheiro);
    
    
    
    FILE *fp = fopen(buffer, "w");
    
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "Funcionários em %d \n", mes );
    for(int i=0; i < *Total_Timesheets; i++){
        if((*arrTimesheet)[i].mesTS ==  mes){
            fprintf(fp, "ID: User %d , Jornada Completa: %d , Meia Jornada: %d , Total Trabalhado F/semana: %d , Falta: %d \n",(*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].jornadaCompFDS+(*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].falta );
        }
    }
    
    fclose(fp);
    //return 0;
    
    
    
}