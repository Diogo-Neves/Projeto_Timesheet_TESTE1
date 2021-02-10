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
    int mes, mes2 = 0;
    
    do{
        puts("Insira o mês a imprimir:");
        scanf("%d", &mes);
    }while(mes<1 && mes >12);
    
    
    for(int k = 0; k < *Total_Timesheets; k++){
        if((*arrTimesheet)[k].mesTS == mes){
            mes2=mes;
        }
      
    }

    
    if(mes2 > 0){
        sprintf(buffer,"%s%d%s",PalavraMes,mes,tipoFicheiro);



        FILE *fp = fopen(buffer, "w");

        if (fp == NULL){
            exit(EXIT_FAILURE);
        }
        fprintf(fp, "Funcionários com tempo exercido em %d/2021 \n", mes );
        fprintf(fp, "ID Funcionários, Jornada Completa, Meia Jornada, Total Trabalhado F/semana, Falta  \n");
        
        for(int i=0; i < *Total_Timesheets; i++){
            if((*arrTimesheet)[i].mesTS ==  mes && (*arrTimesheet)[i].funcCode != 0){
                fprintf(fp, "       %d       ,       %d         ,      %d      ,               %d          ,   %d \n",(*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].jornadaCompFDS+(*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].falta );
            }
        }
        printf("\nExportado com Sucesso;");

        fclose(fp);        
    }
    
    if(mes2 == 0){
        puts("*****************************");
        puts("Sem sucesso na exportação;");
        puts("Mês possívelmente inexistente;");
        puts("*****************************");
    }

    //return 0;
    
    
    
}