/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funcs.h"
#include <locale.h>


void dias_total(Funcionario_st2 *funcionarios, int contador2, int dias, int mes, Timesheet_st2 *timesheets ){
    
    //int contador3 = 0;
    int fixo = 0;
    printf("valor do contador %d\n", contador2);
    printf("Funcionario em dias total:%d TESTE\n", funcionarios->meuST1[contador2].funcNumbr ); 
    timesheets->timesheets[timesheets->contadorTS].funTS[fixo].funcNumbr = funcionarios->meuST1[contador2].funcNumbr;
    printf("%d TIMESHEETID\n", timesheets->timesheets[timesheets->contadorTS].funTS[fixo].funcNumbr);
    timesheets->timesheets[timesheets->contadorTS].timesheetCode = timesheets->contadorTS+1;
    
    
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

           
       
       do{
            printf("Introduza uma opcao: ");
            scanf("%d",&estadonoDia);
            //scanf("%*[^\n]"); scanf("%*c"); //limpar buffer do teclado
         }while (estadonoDia <0 || estadonoDia>4);
           
          switch(estadonoDia){
               case 1:
                   timesheets->timesheets[timesheets->contadorTS].jornadaComp++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 2:
                   timesheets->timesheets[timesheets->contadorTS].meiaJorn++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 3:
                   timesheets->timesheets[timesheets->contadorTS].falta++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 4:
                   timesheets->timesheets[timesheets->contadorTS].folga++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               default:
                   break;
        } 
        }
           
       //https://www.tutorialspoint.com/c_standard_library/c_function_mktime.htm
     
       timesheets->contadorTS++;  
     
 }
    //timesheets->contadorTS++;




void preenchermes(Funcionario_st2 *funcionarios, Timesheet_st2 *timesheets, int contador2){
    
    
    //CONTADOR2 == CONTADOR DA POSIÇÃO DO FUNCIONÁRIO EM QUESTÃO

    printf("\n\n\nfuncMes\n");

    printf("valor do contador FUNCMES: %d\n",funcionarios->contador);
    //funcionarios->contador = contador2;
    //printf("valor do contador FUNCMES: %d\n",funcionarios->contador);

   int mes;
   puts("Qual o mês em questão:");
   scanf("%d",&mes);
   
   

   
   
   switch(mes){
       case 1 :
           //Funcionario_st2 *funcionarios, int number, int dias, int mes 
           dias_total(funcionarios, contador2, 31, mes, timesheets);
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
