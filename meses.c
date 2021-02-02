/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "Menu_TS_header.h"
#include "funcs.h"
#include <locale.h>


void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios ) {
    
    Timesheet *PNovaTS_Realloc;
    int nfunc, *saver, *saver2, existenciaIndice = -1;
    saver = (int *) malloc(1 * sizeof (int));
    saver2 = (int *) malloc(1 * sizeof (int));
    
    saver2 = &(*arrPessoa)[0].funcNumbr;
    (*arrTimesheet)[0].funcCode = *saver2;
    
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
    
    printf("*contadorTimesheets %d\n", *contadorTimesheets);
    puts("Indique o nr de func:");
    scanf("%d", &nfunc);
    

    existenciaIndice = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
    
    if(existenciaIndice >= 0 ){    
            
        printf("%d SAVERRRRRRR \n",(*arrTimesheet)[0].funcCode);
        //existenciaIndice2 = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
            
    }else{
        printf("\nfuncionario nao existe");
    }
    //&arrPessoa[0]->funcNumbr = &arrTimesheet[*contadorTimesheets]->arrPessoa[0].funcNumbr;
    
    //printf("%d SAVERRRRRRR \n",(*arrTimesheet)[0].funcCode);
    
    //(*arrTimesheet)[*contadorTimesheets].funcCode = (*arrPessoa)[0].funcNumbr;
    
    //(*arrTimesheet)[i]. = b
    
    //printf("*contadorTimesheets %d\n", *contadorTimesheets);
    
    //(*arrTimesheet)[0].arrPessoas->funcNumbr
    //saver = &(*arrPessoa)[0].funcNumbr.  ;
    //printf("saver %d \n", *saver);
    //saver2 = &(*arrTimesheet)[*contadorTimesheets].funCode;
    //(*arrTimesheet)[*contadorTimesheets].funCode = *saver;
    //printf("saver2 v1 %d \n", *saver2);
    //saver2 = *saver;
    //printf("saver2 v1 %d \n", *saver2);
    //nfunc = &(*arrPessoa)[0].funcNumbr);
    


};

void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets){
    int *saver2;
    
    saver2 = &(*arrPessoa)[0].funcNumbr;
    (*arrTimesheet)[0].funcCode = *saver2;
    printf("funcionario [0] %d", (*arrTimesheet)[0].funcCode);
}




/*void dias_total(Funcionario_st2 *funcionarios, int contador2, int dias, int mes, Timesheet_st2 *timesheets ){
    
    //int contador3 = 0;
    int fixo = 0;
    
    printf("[%d]  \n", contador2);

    printf("valor do contador %d\n", contador2);
    printf("Funcionario em dias total:%d TESTE\n", funcionarios->meuST1[contador2].funcNumbr );
    
    
    timesheets->timesheets[timesheets->contadorTS].funTS[fixo].funcNumbr = funcionarios->meuST1[contador2].funcNumbr;
    printf("%d TIMESHEETID\n", timesheets->timesheets[timesheets->contadorTS].funTS[fixo].funcNumbr);
    //printf("%p apontador 1\n",);
    //printf("%p apontador 2\n",funcionarios->meuST1[contador2].funcNumbr);
    
    timesheets->timesheets->timesheetCode++;
    
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
           
       
       do{
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
               default:S
                   break;
        } 
        }
        
       
       
       
       
       
       //timesheets->timesheets[timesheets->contadorTS].funTS[fixo].jornadaComp++;
       
       printf("%d number\n", contador2);

       
       

       
       //https://www.tutorialspoint.com/c_standard_library/c_function_mktime.htm
     timesheets->contadorTS++;  
 }
    //timesheets->contadorTS++;


*/

/*void preenchermes(Funcionario_st2 *funcionarios, Timesheet_st2 *timesheets, int contador2){
    
    
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
           break;*/
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
       /*default:
           printf("Erro");
           break;
               
           
   }
   
}*/

 
///ola pessoal
