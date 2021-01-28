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


void dias_total(Funcionario_st1 funcionarios, int number, int dias, int mes ){
    
    //funcionarios->contador = number;
    
    printf("[%d]  \n", number);
    //funcionarios->contador = number;
    printf("Funcionario em dias total:%d TESTE\n", funcionarios.funcNumbr);
    
    //number = funcionarios->meuST1[number].funcNumbr;
    
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

    
    
    char estadonoDia[10];
 
    while(primeirodia <= dias){
        ret = mktime(&info);
        if( ret == -1 ) {
            printf("Error: unable to make time using mktime\n");
        } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      printf(buffer);
        }
          
          
       puts("\nIntegral:A\nParcial:B\nfalta:C\nfolga:D:");
       scanf("%s", &estadonoDia);
       
       printf("%d number\n", number);
       funcionarios.meiaJorn++;
       
       
       
       
       printf("%d\n", funcionarios.meiaJorn);
       
       //printf("%d\n", funcionarios->meuST1[number].jornadaComp);
       
       //dia = dia+1;
       primeirodia = primeirodia +1;
       //info.tm_wday   = dia;
       info.tm_mday   = primeirodia;
       
       //listarFuncs(funcionarios);
       
       //https://www.tutorialspoint.com/c_standard_library/c_function_mktime.htm
       
    }
    
    printf("%d\n", funcionarios.meiaJorn);
}



void preenchermes(Funcionario_st2 *funcionarios){
    
    //setlocale(LC_ALL,"");
    printf("\n\n\nfuncMes\n");
    printf("pFuncs  %p \n", &funcionarios );
    printf("CONTADOR: %d\n",funcionarios->contador);
    printf("posiçao do contador: %p\n", &funcionarios->meuST1[funcionarios->contador]);
    printf("posiçao do funNumber: %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    //funcionarios->meuST1[funcionarios->contador].meiaJorn++;
    //funcionarios->meuST1[funcionarios->contador].meiaJorn++;
    
    
  /*
    printf("Funcionário Número: TESTE V2 %d  contador %d\n", funcionarios->meuST1[funcionarios->contador].funcNumbr, numero );

    funcionarios->meuST1[funcionarios->contador].meiaJorn++;
    
    printf("posiçao do contador: %p\n", &funcionarios->meuST1[0]);
    printf("posiçao do funNumber: %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    
    
    printf("Funcionário jornada+5 %d %d",(funcionarios->meuST1[funcionarios->contador].meiaJorn) , numero );
    */
   //struct tm t;
   int mes, nr;
   puts("Qual o mês em questão:");
   scanf("%d",&mes);
   
   

   
   
   switch(mes){
       case 1 :
           //dias_total(funcionarios->meuST1[funcionarios->contador], numero, 5, mes);
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

 
  