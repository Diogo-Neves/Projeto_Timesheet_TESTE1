/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "Menu_Funcs_header.h"
//#include "Menu_TS_header.h"
#include "funcs.h"
#include <locale.h>


void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios ) {
    
    Timesheet *PNovaTS_Realloc;
    int nfunc, indiceFuncao, contador1, preencherTS;
    
    printf("*contadorTimesheets %d\n", *contadorTimesheets);

        puts("Nr de func:");
        scanf("%d", &nfunc); 
        
        
        indiceFuncao = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
        
        contador1 = *contadorTimesheets;
        
        if(indiceFuncao > -1){
            *totalTimesheets += 1;
            
            PNovaTS_Realloc = realloc(*arrTimesheet, (*totalTimesheets) * sizeof(Timesheet)); 

            if (PNovaTS_Realloc == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }
            else //este else so esta aqui para facilitar a leitura
            {
                *arrTimesheet = PNovaTS_Realloc;
            }
            
            
            
            (*arrTimesheet)[contador1].funcCode = (*arrPessoa)[indiceFuncao].funcNumbr;
            (*arrTimesheet)[contador1].timesheetCode = contador1+1;
            printf("NrFuncTS %d\n", (*arrTimesheet)[contador1].funcCode);      
            printf("Timesheet nr %d\n", contador1);
            
            preencherTS = preenchermes(arrTimesheet, arrPessoa, contador1);
            
            if(preencherTS == -1){
                puts("Preenchimento irregular. Timesheet criada com valores 0.");
                (*arrTimesheet)[contador1].jornadaComp = 0;
                (*arrTimesheet)[contador1].jornadaCompFDS = 0;
                (*arrTimesheet)[contador1].meiaJorn = 0;
                (*arrTimesheet)[contador1].meiaJornFDS = 0;
                (*arrTimesheet)[contador1].folga = 0;
                (*arrTimesheet)[contador1].falta = 0;
            }else{
                puts("Timesheet Criada com sucesso.");
            }
            
            *contadorTimesheets += 1;
            
            
        }else{
            printf("Nao existe");
        }

};

void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets){

    
        for (int i = 0; i < *totalTimesheets; i++) {
             printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d JORNADACOMP: %d / MEIAJORN: %d /FOLGA: %d /FALTA: %d\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaComp+(*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].meiaJorn + (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].folga, (*arrTimesheet)[i].falta );
            
       
   }
}



int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int contador){
    
    //int contador3 = 0;
    int jornadaCompleta, meiaJornada, folga, falta, jornadaCompletaFDS, meiaJornadaFDS, total;
    
    //printf("[%d]  \n", contador);
    
    (*arrTimesheet)[contador].mesTS = mes;
    
    total = mes;

    //printf("alor do contador %d -", contador);
    printf("Funcionario:%d -", (*arrTimesheet)[contador].funcCode );
    printf("TimesheetCode:%d \n", (*arrTimesheet)[contador].timesheetCode );
    
    
    puts("Indique quantos dias uteis com Jornada Completa:");
    //scanf("%d", &jornadaCompleta);
    do{
        scanf("%d", &jornadaCompleta);
    }while(jornadaCompleta > 24);//max uteis 24 //maxFDS 10
    
    (*arrTimesheet)[contador].jornadaComp = jornadaCompleta;
    
    puts("Indique quantos dias uteis com meia jornada:");
    //scanf("%d", &meiaJornada);
    
    do{
        scanf("%d", &meiaJornada);
    }while(meiaJornada > 24);
    
    (*arrTimesheet)[contador].meiaJorn = meiaJornada;
    
    if(jornadaCompleta + meiaJornada > 24){
        puts("Irregular");
        return -1;
    }
    
    puts("Indique quantos dias de fim de semana com Jornada Completa:");
    //scanf("%d", &jornadaCompletaFDS);
    
     do{
        scanf("%d", &jornadaCompletaFDS);
    }while(jornadaCompletaFDS > 10);
    
    (*arrTimesheet)[contador].jornadaCompFDS = jornadaCompletaFDS;
    
    puts("Indique quantos dias de fim de semana com meia jornada:");
    //scanf("%d", &meiaJornadaFDS);
    
    do{
        scanf("%d", &meiaJornadaFDS);
    }while(meiaJornadaFDS > 10);

    (*arrTimesheet)[contador].meiaJornFDS = meiaJornadaFDS;
    
    if(jornadaCompletaFDS + meiaJornadaFDS > 10 || jornadaCompletaFDS + meiaJornadaFDS + jornadaCompleta + meiaJornada > dias){
        puts("Irregular");
        return -1;
    }
    
    puts("Indique quantas folgas:");
    //scanf("%d", &folga);
    
    do{
        scanf("%d", &folga);
    }while(folga > 20);
    
    (*arrTimesheet)[contador].folga = folga;
    
    puts("Indique quantas faltas:");
    //scanf("%d", &falta);
    
    do{
        scanf("%d", &falta);
    }while(folga > 20);
    
    (*arrTimesheet)[contador].falta = falta;

    if( (jornadaCompleta + meiaJornada + jornadaCompletaFDS + meiaJornadaFDS + folga + falta) > dias){
        printf("Mês irregular");
        return -1;
        
    }     
       
       //timesheets->timesheets[timesheets->contadorTS].funTS[fixo].jornadaComp++;
       
       //printf("%d number\n", contador2);

       
       

       
       //https://www.tutorialspoint.com/c_standard_library/c_function_mktime.htm
     //timesheets->contadorTS++;  
 }
    //timesheets->contadorTS++;




int preenchermes(Timesheet **arrTimesheet, Pessoa **arrPessoa, int contador){
    
    
    //CONTADOR2 == CONTADOR DA POSIÇÃO DO FUNCIONÁRIO EM QUESTÃO

    printf("\n\n\nfuncMes\n");

    printf("valor do contador FUNCMES: %d\n", contador);
    //funcionarios->contador = contador2;
    //printf("valor do contador FUNCMES: %d\n",funcionarios->contador);

   int mes, executardias;
   
   do{
        puts("Qual o mês em questão:");
        scanf("%d",&mes);  
   }while(mes < 1 || mes > 12);
   
   
   

   
   
   switch(mes){
       case 1 :
           //Funcionario_st2 *funcionarios, int number, int dias, int mes 
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 2:
           executardias = dias_total(28, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 3:
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 4:
           executardias = dias_total(30, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 5:
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 6:
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 7:
           executardias = dias_total(30, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 8:
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 9:
           executardias = dias_total(30, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 10:
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 11:
           executardias = dias_total(30, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       case 12:
           executardias = dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           return executardias;
           break;
       default:
           printf("Erro");
           break;
        }  
}


void atualizarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios ){
    
    int nrTimesheet, verificador;
    puts("Indique o Nr da Timesheet que pretende atualizar:");
    scanf("%d", &nrTimesheet);
    
    //verificar se timesheet EXISTE
    verificador = verificarExistenciaTimesheet(arrTimesheet,arrPessoa, totalTimesheets,contadorTimesheets, Total_Funcionarios, contadorFuncionarios, nrTimesheet);
    if(verificador > -1){
        puts("TimesheetExiste");
        printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d JORNADACOMP: %d / MEIAJORN: %d /FOLGA: %d /FALTA: %d / FdS Completo: %d / FdS Meia: %d \n",(*arrTimesheet)[verificador].timesheetCode, (*arrTimesheet)[verificador].mesTS, (*arrTimesheet)[verificador].funcCode, verificador, (*arrTimesheet)[verificador].jornadaComp, (*arrTimesheet)[verificador].meiaJorn, (*arrTimesheet)[verificador].folga, (*arrTimesheet)[verificador].falta, (*arrTimesheet)[verificador].jornadaCompFDS, (*arrTimesheet)[verificador].meiaJornFDS);
        //QUANDO EU TIVER PACIENCIA, CRIAR UM LOOP QUE ATUALIZE MEDIANTE ESCOLHA, TAL COMO NA INSERÇÃO
    
    }else{
        puts("TimesheetNaoExiste");
    }
}


int verificarExistenciaTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios, int nrTS ){
    
    int i;
    

    for(i = 0; i < *totalTimesheets; i++){
        if((*arrTimesheet)[i].timesheetCode == nrTS){

            return i;

        }
    }
    return -1;
    

}
///ola pessoal
