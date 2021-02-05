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
    printf("*Total tms %d\n", *totalTimesheets);
        puts("Nr de func:");
        scanf("%d", &nfunc); 
        
        
        indiceFuncao = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
        
        //contador1 = *contadorTimesheets;
        
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
            
            
            (*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias *) malloc (sizeof (Dias) * 31);
            
            (*arrTimesheet)[*contadorTimesheets].funcCode = (*arrPessoa)[indiceFuncao].funcNumbr;
            
            (*arrTimesheet)[*contadorTimesheets].timesheetCode = *contadorTimesheets+1;
            
            printf("NrFuncTS %d\n", (*arrTimesheet)[*contadorTimesheets].funcCode);      
            printf("Timesheet nr %d\n", *contadorTimesheets);
            
            //*contadorTimesheets += 1;
            printf("*contadorTimesheets antes de chamar PREENCHER %d\n", *contadorTimesheets);
            
            preencherTS = preenchermes(arrTimesheet, arrPessoa, contadorTimesheets);   //TEM QUE PASSAR A LEVAR CONTADORTIMESHEETS
            
            /*if(preencherTS == -1){
                puts("Preenchimento irregular. Timesheet criada com valores 0.");
                (*arrTimesheet)[contador1].jornadaComp = 0;
                (*arrTimesheet)[contador1].jornadaCompFDS = 0;
                (*arrTimesheet)[contador1].meiaJorn = 0;
                (*arrTimesheet)[contador1].meiaJornFDS = 0;
                (*arrTimesheet)[contador1].folga = 0;
                (*arrTimesheet)[contador1].falta = 0;
            }else{
                puts("Timesheet Criada com sucesso.");
            }*/
            
            
            
            
        }else{
            printf("Nao existe");
        }

};


void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets){

    
        for (int i = 0; i < *totalTimesheets; i++) {
             //printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d JORNADACOMP: %d / MEIAJORN: %d /FOLGA: %d /FALTA: %d\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaComp+(*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].meiaJorn + (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].folga, (*arrTimesheet)[i].falta );
            printf("Timesheet ID: %d Mes: %d FuncID: %d  i: %d JORNADACOMPFDS: %d  jornada COMP %d Meia FDS %d Meia %d falta %d folga %d\n",(*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);
       
   }
}



//(*arrTimesheet)[contador].meiaJornFDS, (*arrTimesheet)[contador].meiaJorn, (*arrTimesheet)[contador].falta, (*arrTimesheet)[contador].folga

/*
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
*/



int preenchermes(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *contadorTimesheets){
    
    
    //CONTADOR2 == CONTADOR DA POSIÇÃO DO FUNCIONÁRIO EM QUESTÃO

    printf("\n\n\nfuncMes\n");

    printf("valor do contador depois de receber: %d\n", *contadorTimesheets);
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
///ola pessoal



///////////          TESTES BY DIOGOOOO        //////

int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int *contadorTimesheets){
    
    int dia, verificar, contadorDias = 0, k, dia2, mes2;
    Dias *pNovo_realloc_dias;
    
    //(*arrTimesheet)[contador].dias_scope = 0;
    
    
    //zerardias(arrTimesheet, contador, dias);
    printf("contadorts %d \n", *contadorTimesheets);
    
    
    
    do{
    puts("Insira o dia(1) a preencher:");
    scanf("%d", &dia);    
    }while(dia < 1 || dia > dias);
    
    
    pNovo_realloc_dias = realloc((*arrTimesheet)[*contadorTimesheets].dias_scope, dias * sizeof(Dias)); 
            
            

            if (pNovo_realloc_dias == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }
            else //este else so esta aqui para facilitar a leitura
            {
                (*arrTimesheet)[*contadorTimesheets].dias_scope = pNovo_realloc_dias;
            }
    
    for(int k = 0; k < dias; k++){
            printf(" Dias preenchidos depois de zerar: %d  i: %d \n", (*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, k );
        }
    
    
    if(contadorDias == 0){
        
        //(*arrTimesheet)[contador].dias_scope ;
                
                


/*
            
*/


        puts("Timesheet Inicializada:");
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
            
            
        
        verificar = contagemDias(arrTimesheet, dia, contadorTimesheets, dias);        //
        if(verificar != -1 && dia > 0){
            (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia;
            diaPorDia(arrTimesheet, contadorTimesheets,dias,mes,contadorDias,dia);
/*
            dia2 = dia;
            mes2 = mes;
            
            int ret;
            struct tm info;
            char buffer[80];

            info.tm_year = 2021 - 1900;
            info.tm_mon = mes2-1;              // 1 a 12 (meses)
            info.tm_mday = dia2;     // dia di mes '1 2 3 /  31
            info.tm_hour = 0;
            info.tm_min = 0;
            info.tm_sec = 1;
            info.tm_isdst = -1;
            //info.tm_mon = 0          
            //info.tm_wday = 0 - 6;    // 0 domingo 1 Mon  6 sat 


            int estadonoDia;

            //while(primeirodia <= dias){
                ret = mktime(&info);
                if( ret == -1 ) {
                    printf("Error: unable to make time using mktime\n");
                } else {
              strftime(buffer, sizeof(buffer), "%c", &info );
              printf(buffer);
                }
                
                

               puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:");
               puts("Insira estado:");
               scanf("%d", &estadonoDia);

               switch(estadonoDia){
                   case 1:
                       if(info.tm_wday == 0|| info.tm_wday == 6){
                           //(*arrTimesheet)[contador].dias_scope[contadorDias].jornadaCompFDS++;
                           (*arrTimesheet)[contador].jornadaCompFDS++;
                           printf(" dia da semana %d \n ", info.tm_wday);
                       }else{
                           //(*arrTimesheet)[contador].dias_scope[contadorDias].jornadaComp++;
                           (*arrTimesheet)[contador].jornadaComp++;
                       }
                       break;
                   default:
                       break;

               }
*/
            
            //*contadorTimesheets += 1;
            printf("*contadorTimesheets antes de chamar PREENCHER %d\n", *contadorTimesheets);
            contadorDias +=1 ;
        }
        }while(dia != 0 && contadorDias < dias);
        //devolve se já está preenchido
        //*contadorTimesheets += 1;
        
    }
    
    
    /*do{
        
        puts("Insira o dia(2+) a preencher:");
        scanf("%d", &dia);
        


        //(*arrTimesheet)[contador].dias_scope[contadorDias].dia = dia;


        //printf("dia %d",(*arrTimesheet)[contador].dias_scope[contadorDias].dia);
        //contadorDias += 1;

        (*arrTimesheet)[contador].mesTS = mes;
        puts("hello");
        verificar = contagemDias(arrTimesheet, dia, contador, dias);
        //devolve se já está preenchido
        printf("verificar: %d", verificar);
        puts("hello");
        //AGORA PRECISO DE VERIFICAR QUANTOS DIAS TEM
        //contadorDias = retornarquantosdias(arrTimesheet, dia, contador, dias);
        printf("contar dias: %d", contadorDias);
        puts("hello");
        
        
        if(verificar == -1){
            printf("JA ESTA RPEENCHIDOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            //diaPorDia(arrTimesheet,contador,dias,mes,contadorDias,dia);
            //contadorDias += 1;
        
        }else if (dia != 0) {
            diaPorDia(arrTimesheet,contador,dias,mes,contadorDias,dia);
            
            (*arrTimesheet)[contador].dias_scope[contadorDias].dia = dia;
            
            printf("dia  TESTE %d \n",(*arrTimesheet)[contador].dias_scope[contadorDias].dia);
            
            contadorDias +=1 ;
            
            pNovo_realloc_dias = realloc((*arrTimesheet)[contador].dias_scope, (contadorDias) * sizeof(Timesheet)); 
            
            

            if (pNovo_realloc_dias == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }
            else //este else so esta aqui para facilitar a leitura
            {
                (*arrTimesheet)[contador].dias_scope = pNovo_realloc_dias;
            }
        }*/
        
        
        /////////////////////////////////////////////////////////////////////
        //for(int k = 0; k < contadorDias)
        //printf("dia  TESTE %d \n",(*arrTimesheet)[contador].dias_scope[contadorDias].dia);
        printf("________________---__---__---___\n");
        //(*arrTimesheet)[contador].dias_scope[contadorDias].dia = dia;

        //total = mes;

        /*mes--;
        int primeirodia = 1;
        int ret;
        struct tm info;
        char buffer[80];

        info.tm_year = 2021 - 1900;
        info.tm_mon = mes;              // 1 a 12 (meses)
        info.tm_mday = dia;     // dia di mes '1 2 3 /  31
        info.tm_hour = 0;
        info.tm_min = 0;
        info.tm_sec = 1;
        info.tm_isdst = -1;
        //info.tm_mon = 0          // 7 domingo 1 segunda



        int estadonoDia;

        //while(primeirodia <= dias){
            ret = mktime(&info);
            if( ret == -1 ) {
                printf("Error: unable to make time using mktime\n");
            } else {
          strftime(buffer, sizeof(buffer), "%c", &info );
          printf(buffer);
            }


           puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:");
           
           switch(estadonoDia){
               case 1:
                   if(info.tm_mon == 6|| info.tm_mon == 7){
                       (*arrTimesheet)[contador].dias_scope[contadorDias].jornadaCompFDS++;
                   }else{
                       (*arrTimesheet)[contador].dias_scope[contadorDias].jornadaComp++;
                   }
                   break;
               default:
                   break;
                       
           }

           //contadorDias += 1;*/
        //////////////////////////////////////////////////
        //}while(dia != 0); 
    for(int k = 0; k < dias; k++){
            printf(" Dias preenchidos: %d  i: %d    status: %s \n", (*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, k ,(*arrTimesheet)[*contadorTimesheets].dias_scope[k].status );
    }
        //for(int k = 0; k < dias; k++){
          //  printf(" Dias preenchidos: %d  i: %d", (*arrTimesheet)[contador].dias_scope[k].dia, k );
        *contadorTimesheets += 1;
}
   //}


int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias){
    
    for(int i = 0; i < dias; i++){
        if ((*arrTimesheet)[*contadorTimesheets].dias_scope[i].dia == dia){
            puts("Dia já preenchido");
            return -1;
        }
    }
    return 0;
    
    
}

/*
int retornarquantosdias(Timesheet **arrTimesheet, int dia, int contador, int dias){
    
    int k;
    
    //k = -1;
    
    for(int i = 0; i < dias; i++){
        
        if ((*arrTimesheet)[contador].dias_scope[i].dia > 0 && (*arrTimesheet)[contador].dias_scope[i].dia < dias ){
            puts("Dia ");
            printf("contadordiasRetor %d \n", (*arrTimesheet)[contador].dias_scope[i].dia);
            k = k+1;
        }
    }
    printf("k %d \n", k);
    return k;
    
}
*/

/*
int zerardias(Timesheet **arrTimesheet, int contador, int dias){
    
    //int k = -1;
    
    for(int i = 0; i < dias; i++){
        (*arrTimesheet)[contador].dias_scope[i].dia = 0 ;
            
    
    }
}
*/


int diaPorDia(Timesheet **arrTimesheet, int *contadorTimesheets, int dias, int mes, int contadorDias, int dia){
    
    //int *pNovo_realloc_dias;
    
/*
     pNovo_realloc_dias = realloc((*arrTimesheet)[contador].dias_scope, (contadorDias) * sizeof(Timesheet)); 
            
            

            if (pNovo_realloc_dias == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }
            else //este else so esta aqui para facilitar a leitura
            {
                (*arrTimesheet)[contador].dias_scope = pNovo_realloc_dias;
            }
*/
    
    
    
    
    //*mes--;
        //int primeirodia = 1;
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

        //while(primeirodia <= dias){

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
    int userCode;
    puts("Indique o nr de Utilizador");
    scanf("%d", &userCode);
    
    for(int j = 0; j < *totalTimesheets; j++){
        if((*arrTimesheet)[j].funcCode == userCode){
            //printf("Timesheet Nr: %d\n", (*arrTimesheet)[j].timesheetCode);
            for(int k = 0; k < 31; k++){
                //if((*arrTimesheet)[j].dias_scope[k].dia != 0 && (*arrTimesheet)[j].dias_scope[k].dia < 32){
                    //puts("Timesheet preenchida:");
                    printf("Timesheet Nº: %d - Dia: %d/%d/2021  i: %d    status: %s \n",(*arrTimesheet)[j].timesheetCode, (*arrTimesheet)[j].dias_scope[k].dia,(*arrTimesheet)[j].mesTS , k ,(*arrTimesheet)[j].dias_scope[k].status );
                //}
            
            }
        }
    }
    
   
    
    
    
}

