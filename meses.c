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
#include "Menu_TS_header.h"
#include "funcs.h"
#include <locale.h>


void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios ) {
    
    Timesheet *PNovaTS_Realloc;
    int nfunc, indiceFuncao, contador1, preencherTS;
    
    
    printf("*Total tms %d\n", *totalTimesheets);
        puts("Nr de func:");
        scanf("%d", &nfunc); 
        
        
        indiceFuncao = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
        
        
        if(indiceFuncao > -1){
            *totalTimesheets += 1;
            printf("*TotalTimesheets ANTES DE REALOCAR %d\n", *totalTimesheets);

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
            
            printf("*contadorTS ANTES DE alocar x1 %d\n", *contadorTimesheets);
            //(*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias*) malloc (sizeof(Dias)) ;
            
            (*arrTimesheet)[*contadorTimesheets].funcCode = (*arrPessoa)[indiceFuncao].funcNumbr;
            
            (*arrTimesheet)[*contadorTimesheets].timesheetCode = *totalTimesheets;
            
            printf("NrFuncTS %d\n", (*arrTimesheet)[*contadorTimesheets].funcCode);      

            printf("Timesheet nr %d\n", *contadorTimesheets);
            
            //*contadorTimesheets += 1;
            printf("*contadorTimesheets antes de chamar PREENCHER %d\n", *contadorTimesheets);
            
            preencherTS = preenchermes(arrTimesheet, arrPessoa, contadorTimesheets);   //TEM QUE PASSAR A LEVAR CONTADORTIMESHEETS
            
            
            
            
            
        }else{
            printf("Nao existe");
        }

};


void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets){
 
    for (int i = 0; i < *totalTimesheets; i++) {
        if((*arrTimesheet)[i].timesheetCode > 0 && (*arrTimesheet)[i].funcCode > 0){
             printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d Jornada Comp. F/semana: %d / Jornada Comp.: %d Meia Jornada F/semana: %d / Meia Jornada: %d / Faltas: %d / Folgas: %d\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);       
        }
    }
}

int preenchermes(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *contadorTimesheets){
    printf("\n\n\nfuncMes\n");

    printf("valor do contador depois de receber: %d\n", *contadorTimesheets);


   int mes, executardias, mes2;
   
   do{
        puts("Qual o mês em questão:");
        scanf("%d",&mes);  
   }while(mes < 1 || mes > 12);
   
   mes2 = mes;
   
   //verificar se utilizador da timesheet ja tem mes
      
   for(int s = 0; s < *contadorTimesheets+1; s++){
       if((*arrTimesheet)[s].funcCode == (*arrTimesheet)[*contadorTimesheets].funcCode){
           if((*arrTimesheet)[s].mesTS == mes2){
                do{
                            puts("Qual o mês em questão2:");
                            scanf("%d",&mes);  
                   }while(mes < 1 || mes > 12 || mes == mes2 );
               
           }
       }
       
   }
  
   switch(mes){
       case 1 :
           //Funcionario_st2 *funcionarios, int number, int dias, int mes 
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           //return executardias;
           break;
       case 2:
           dias_total(28, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           //return executardias;
           break;
       case 3:
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           //return executardias;
           break;
       case 4:
           dias_total(30, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           //return executardias;
           break;
       case 5:
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           //return executardias;
           break;
       case 6:
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           //return executardias;
           break;
       case 7:
           dias_total(30, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           
           break;
       case 8:
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           
           break;
       case 9:
           dias_total(30, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           
           break;
       case 10:
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           
           break;
       case 11:
           dias_total(30, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           
           break;
       case 12:
           dias_total(31, arrTimesheet, arrPessoa, mes, contadorTimesheets);
           printf("teste1");
           
           break;
       default:
           printf("Erro");
           break;
        }  
}


/*void atualizarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios ){
    
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
}*/


/*int verificarExistenciaTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios, int nrTS ){
    
    int i;
    

    for(i = 0; i < *totalTimesheets; i++){
        if((*arrTimesheet)[i].timesheetCode == nrTS){

            return i;

        }
    }
    return -1;
    

}*/




///////////          TESTES BY DIOGOOOO        //////

int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int *contadorTimesheets){
    
    int dia, verificar, contadorDias = 0, k, dia2, mes2;
    Dias *pNovo_realloc_dias;
    Timesheet *PNovaTS_Realloc;
    
    //(*arrTimesheet)[contador].dias_scope = 0;
    
    
    //zerardias(arrTimesheet, contador, dias);
    printf("contadorts %d \n", *contadorTimesheets);
    
    
    
    do{
    puts("Insira o dia(1) a preencher:");
    scanf("%d", &dia);    
    }while(dia < 1 || dia > dias);
    
    
    printf("*contadorTS ANTES DE REALOCAR %d\n", *contadorTimesheets);
    printf("Total de dias a alocar %d  \n", dias);
  
    (*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias*) calloc(32, sizeof(Dias));

    
    for(int k = 0; k < dias; k++){
            printf(" Dias preenchidos depois de zerar: %d  i: %d \n", (*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, k );
        }

        
        
        puts("Timesheet Inicializada TESTE SEGUNDA RODADA:");
        printf("contador de timesheets (indice): %d \n", *contadorTimesheets );
        (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia;
        (*arrTimesheet)[*contadorTimesheets].jornadaCompFDS = 0;
        (*arrTimesheet)[*contadorTimesheets].jornadaComp = 0;
        (*arrTimesheet)[*contadorTimesheets].meiaJornFDS = 0;
        (*arrTimesheet)[*contadorTimesheets].meiaJorn = 0;
        (*arrTimesheet)[*contadorTimesheets].falta = 0;
        (*arrTimesheet)[*contadorTimesheets].folga = 0;
        (*arrTimesheet)[*contadorTimesheets].mesTS = mes;
        diaPorDia(arrTimesheet, contadorTimesheets,dias,mes,contadorDias,dia);
        
        contadorDias +=1 ;
        
        do{
            
            do{
                puts("novo dia");
                scanf("%d", &dia);
            }while(dia < 0 || dia > dias);
            
            
        
        verificar = contagemDias(arrTimesheet, dia, contadorTimesheets, dias);
        printf("Verificar %d \n", verificar);
        if(verificar != -1 && dia > 0){
            
            (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia;
            diaPorDia(arrTimesheet, contadorTimesheets,dias,mes,contadorDias,dia);

            
           printf("IndiceNr2diasscope %d || ", contadorDias);
            printf("*contadorTimesheets antes de chamar PREENCHER %d\n", *contadorTimesheets);
            contadorDias +=1 ;
        }
        
        }while(dia != 0 && contadorDias < dias);


    for(int k = 0; k < dias; k++){
            printf(" Dias preenchidos: %d  i: %d    status: %s \n", (*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, k ,(*arrTimesheet)[*contadorTimesheets].dias_scope[k].status );
    }
        
        *contadorTimesheets += 1;
}



int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias){
    
    for(int i = 0; i < dias; i++){
        if ((*arrTimesheet)[*contadorTimesheets].dias_scope[i].dia == dia){
            puts("Dia já preenchido");
            return -1;
        }
    }
    return 0;
    
    
}


int diaPorDia(Timesheet **arrTimesheet, int *contadorTimesheets, int dias, int mes, int contadorDias, int dia){
    

        int ret;
        struct tm info;
        char buffer[80];

        info.tm_year = 2021 - 1900;
        info.tm_mon = mes-1;              // 1 a 12 (meses)
        info.tm_mday = dia;     // dia di mes '1 2 3 /  31
        info.tm_hour = 0;
        info.tm_min = 0;
        info.tm_sec = 1;
        info.tm_isdst = -1;
        //info.tm_mon = 0          
        //info.tm_wday = 0 - 6;    // 0 domingo 1 Mon  6 sat 


        int estadonoDia;

        

            ret = mktime(&info);
            if( ret == -1 ) {
                printf("Error: unable to make time using mktime\n");
            } else {
          strftime(buffer, sizeof(buffer), "%c", &info );
          printf(buffer);
            }

           char nome[15] = "Integral";
           char nome3[15] = "Parcial";
           char nome5[15] = "Falta";
           char nome6[15] = "Folga";
           puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:");
           puts("Insira estado:");
           scanf("%d", &estadonoDia);
           
           switch(estadonoDia){
               case 1:
                   if(info.tm_wday == 0|| info.tm_wday == 6){
                       
                       strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome);   
                       //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Integral';
                       (*arrTimesheet)[*contadorTimesheets].jornadaCompFDS++;
                       puts("Jornada Completa - Fim de semana");
                   }else{
                       
                       strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome);
                       //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Integral';
                       (*arrTimesheet)[*contadorTimesheets].jornadaComp++;
                       puts("Jornada Completa");
                   }
                   break;
               case 2:
                   
                   if(info.tm_wday == 0|| info.tm_wday == 6){
                       strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome3);
                       //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Parcial';
                       (*arrTimesheet)[*contadorTimesheets].meiaJornFDS++;
                       puts("Meia jornada - Fim de semana");
                   }else{
                       
                       strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome3);
                       //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Parcial';
                       (*arrTimesheet)[*contadorTimesheets].meiaJorn++;
                       puts("Meia jornada");
                   }
                   break;
               case 3:
                   
                   (*arrTimesheet)[*contadorTimesheets].falta++;
                   strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome5);
                   //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Falta';
                   puts("Falta");
                   break;
               case 4:
                   
                   (*arrTimesheet)[*contadorTimesheets].folga++;
                   strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome6);
                   //(*arrTimesheet)[contador].dias_scope[contadorDias].status = 'Folga';
                   puts("Folga");
                   break;
               default:
                   break;
                       
           }
    
}


void consultarTSutilizador(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets){
    int userCode, v1 = -1;
    puts("Indique o nr de Utilizador");
    scanf("%d", &userCode);
    
    
    for(int j = 0; j < *totalTimesheets; j++){
        if((*arrTimesheet)[j].funcCode == userCode){
            v1 = 0;
           
            for(int k = 0; k < 31; k++){

                if((*arrTimesheet)[j].dias_scope[k].dia != 0){
                    printf("Timesheet Nº: %d - Dia: %d/%d/2021  i: %d    status: %s \n",(*arrTimesheet)[j].timesheetCode, (*arrTimesheet)[j].dias_scope[k].dia,(*arrTimesheet)[j].mesTS , k ,(*arrTimesheet)[j].dias_scope[k].status );
                }    
                
            
            
            }
        }
    }
    
    if(v1 != 0){
        puts("Erro; \n Funcionário não existe na lista;");
    }
    
}  
    
void direitoCompensação(Timesheet **arrTimesheet,int *totalTimesheets, int *contadorTimesheets){

    printf("O direito de Compensação reserva-se aos funcionários que exerceram\n");
    printf("funções ao fim de semana, estando estas divididas em compensações \n");
    printf("totais ou parciais mediante o exercido. \n");
    
    for(int i = 0; i < *totalTimesheets; i++) {
        printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d Compensações Totais: %d / Compensações Parciais: %d .\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].meiaJornFDS);       
    }
    
        
}


void timesheetsIncompletas(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios){
    
    printf("Timesheets Incompletas (caso existam):\n");
    puts("");
    
    for(int i = 0; i < *totalTimesheets; i++){
        if(  ((*arrTimesheet)[i].jornadaCompFDS + (*arrTimesheet)[i].jornadaComp + (*arrTimesheet)[i].meiaJornFDS +(*arrTimesheet)[i].meiaJorn + (*arrTimesheet)[i].falta + (*arrTimesheet)[i].folga) < 28 && (*arrTimesheet)[i].funcCode > 0){
             printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d Jornada Comp. F/semana: %d / Jornada Comp.: %d Meia Jornada F/semana: %d / Meia Jornada: %d / Faltas: %d / Folgas: %d\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);       

        }
    }
    puts("");
    printf("--------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------\n");
    printf("No caso de existirem Timesheets incompletas, recomenda-se a sua \n");
    printf("reinserção no menu 'Gestão do Trabalho realizado (Timesheets)' \n");
    printf("Opção '4 - Recriar Timesheet', utilizando o código da Timesheet \n");
    printf("e respetivo código de funcionário. \n");
    printf("--------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------\n");

    
}


    
void refazerTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios){
    int timesheetNo, indiceTS;
    puts("Timesheet a recriar:");
    scanf("%d", &timesheetNo);
    
    indiceTS = possivelTimesheet(arrTimesheet,arrPessoa,totalTimesheets,contadorTimesheets,Total_Funcionarios,contadorFuncionarios,timesheetNo);
    
    if(indiceTS != -1 && (*arrTimesheet)[indiceTS].funcCode > 0){
        printf("Funcionátios %d , Mês %d , Preencha uma nova Timesheet! \n\n\n", (*arrTimesheet)[indiceTS].funcCode, (*arrTimesheet)[indiceTS].mesTS);
        (*arrTimesheet)[indiceTS].timesheetCode = NULL;
        (*arrTimesheet)[indiceTS].mesTS = NULL;
        (*arrTimesheet)[indiceTS].funcCode = NULL;
        criarTimesheet(arrTimesheet,arrPessoa,totalTimesheets,contadorTimesheets,Total_Funcionarios,contadorFuncionarios );
    }else{
        puts("Impossível recriar Timesheet;");
        puts("Possível razão: 1 - não existe;");
        puts("                2 - Funcionário apagado;");
    }
    
}




int possivelTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios, int timesheetNo){
    
    //int timesheetNo;
    for(int i = 0; i < *totalTimesheets; i++){
        if((*arrTimesheet)[i].timesheetCode == timesheetNo){

            return i;
        }
    }
    return -1;
}

 