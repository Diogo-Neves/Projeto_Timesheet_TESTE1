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
    int nfunc, indiceFuncao, contador1, contador2;
    
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
            *contadorTimesheets += 1;
            
            printf("ADICIONAR NA POSIÇÃO 'CONTADOR1' AS MEIAS JORNADAS ETC");
        }else{
            printf("Nao existe");
        }

};

void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets){

    
        for (int i = 0; i < *totalTimesheets; i++) {
             printf("Timesheet ID: %d FuncID: %d  i: %d\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].funcCode, i);
            
       
   }
}



void dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int contador){
    
    //int contador3 = 0;
    int fixo = 0;
    
    printf("[%d]  \n", contador);

    printf("valor do contador %d -", contador);
    printf("Funcionario:%d -", (*arrTimesheet)[contador].funcCode );
    printf("TimesheetCode:%d -", (*arrTimesheet)[contador].timesheetCode );
    
    //timesheets->timesheets[timesheets->contadorTS].funTS[fixo].funcNumbr = funcionarios->meuST1[contador2].funcNumbr;
    //printf("%d TIMESHEETID\n", timesheets->timesheets[timesheets->contadorTS].funTS[fixo].funcNumbr);
    //printf("%p apontador 1\n",);
    //printf("%p apontador 2\n",funcionarios->meuST1[contador2].funcNumbr);
    
    //timesheets->timesheets->timesheetCode++;
    
    mes--;
    int primeirodia = 1;
    int ret;
    struct tm info;
    char buffer[80];

    info.tm_year = 2021 - 1900;
    info.tm_mon = mes;
    info.tm_mday = primeirodia;
    info.tm_hour = 0;
    info.tm_min = 0;
    info.tm_sec = 1;
    info.tm_isdst = -1;

    
    
    int estadonoDia;
 
    while(primeirodia <= dias){
        ret = mktime(&info);
        if( ret == -1 ) {
            printf("Error: unable to make time using mktime\n");
        } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      printf(buffer);
        }
          
          
       puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:");
       //scanf("%s", &estadonoDia);
       
       //funcionarios->meuST1[contador2].meiaJorn++;
       //CRIAR CICLO PARA JORNADAS ESPECIFICAS
       
       
       //scanf("%d", &estadonoDia);
           
       
       /*do{
            printf("Introduza uma opcao: ");
            scanf("%d",&estadonoDia);
            //scanf("%*[^\n]"); scanf("%*c"); //limpar buffer do teclado
         }while (estadonoDia <0 || estadonoDia>4);
           
          switch(estadonoDia){
               case 1:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].jornadaComp++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 2:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].meiaJorn++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 3:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].falta++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 4:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].folga++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               default:
                   break;
        } */
    }
        
       
       
       
       
       
       //timesheets->timesheets[timesheets->contadorTS].funTS[fixo].jornadaComp++;
       
       printf("%d number\n", contador2);

       
       

       
       //https://www.tutorialspoint.com/c_standard_library/c_function_mktime.htm
     timesheets->contadorTS++;  
 }
    //timesheets->contadorTS++;




void preenchermes(Timesheet **arrTimesheet, Pessoa **arrPessoa, int contador){
    
    
    //CONTADOR2 == CONTADOR DA POSIÇÃO DO FUNCIONÁRIO EM QUESTÃO

    printf("\n\n\nfuncMes\n");

    printf("valor do contador FUNCMES: %d\n", contador);
    //funcionarios->contador = contador2;
    //printf("valor do contador FUNCMES: %d\n",funcionarios->contador);

   int mes;
   puts("Qual o mês em questão:");
   scanf("%d",&mes);
   
   

   
   
   switch(mes){
       case 1 :
           //Funcionario_st2 *funcionarios, int number, int dias, int mes 
           dias_total(31, arrTimesheet, arrPessoa, mes, contador);
           printf("teste1");
           break;
       /*case 2:
           dias_total(28, mes, funcionarios, nr);
           break;
       case 3:
           dias_total(31, mes, funcionarios, nr);
           break;
       case 4:
           dias_total(30, mes, funcionarios, nr);
           break;
       case 5:
           dias_total(31, mes, funcionarios, nr);
           break;
       case 6:
           dias_total(31, mes, funcionarios, nr);
           break;
       case 7:
           dias_total(30, mes, funcionarios, nr);
           break;
       case 8:
           dias_total(31, mes, funcionarios, nr);
           break;
       case 9:
           dias_total(30, mes, funcionarios, nr);
           break;
       case 10:
           dias_total(31, mes, funcionarios, nr);
           break;
       case 11:
           dias_total(30, mes, funcionarios, nr);
           break;
       case 12:
           dias_total(31, mes, funcionarios, nr);
           break;*/
       default:
           printf("Erro");
           break;
               
           
   }
   
}

 
///ola pessoal
