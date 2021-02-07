/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcs.h"


#define FUNCIONARIOS "funcionarios.txt"
#define TOTALFUNCS "SaveTotalFunc.txt"
#define CONTADORFUNCS "ContadorFunc.txt"

#define TIMESHEETS "Timesheets.txt"
#define TOTALTIMESHEETS "SaveTotalTimesheet.txt"
#define CONTADORTIMESHEETS "ContadorTimesheet.txt"
#define TIMESHEETSDIAS "Timesheetsdias.txt"

void escreverFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    
    FILE *fp = fopen(FUNCIONARIOS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fwrite((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    //printf("Total funcs %d \n", *totalFuncionarios);
    //fwrite(totalFuncionarios, sizeof (int), (*totalFuncionarios), fp);
    fclose(fp);
    //return 0;
    
}

void escreverTotalFunc(int *totalFuncionarios){
    
    //*totalFuncionarios = 2;
    
    FILE *fp = fopen(TOTALFUNCS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    //fwrite((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    //printf("Total funcs %d \n", *totalFuncionarios);
    fwrite(&(*totalFuncionarios), sizeof (int), 1, fp);
    printf("Total funcs %d \n", *totalFuncionarios);
    fclose(fp);
    //return 0;

}

void escreverContadorFunc(int *contadorFuncionarios){
    FILE *fp = fopen(CONTADORFUNCS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    
    fwrite(&(*contadorFuncionarios), sizeof (int), 1, fp);
    printf("Total funcs %d \n", *contadorFuncionarios);
    fclose(fp);
    //return 0;
}


//
//TIMESHEETS ---------ESCRITA
//



void escreverTimesheets(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalTimesheets){
    
    FILE *fp = fopen(TIMESHEETS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fwrite((*arrTimesheet), sizeof (Timesheet), (*totalTimesheets), fp);
    //printf("Total funcs %d \n", *totalFuncionarios);
    //fwrite(totalFuncionarios, sizeof (int), (*totalFuncionarios), fp);
    fclose(fp);
    //return 0;
    
}

void escreverTotalTimesheets(int *totalTimesheets){
    
    //*totalFuncionarios = 2;
    
    FILE *fp = fopen(TOTALTIMESHEETS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    //fwrite((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    //printf("Total funcs %d \n", *totalFuncionarios);
    fwrite(&(*totalTimesheets), sizeof (int), 1, fp);
    printf("Total funcs %d \n", *totalTimesheets);
    fclose(fp);
    //return 0;

}

void escreverContadorTimesheets(int *contadorTimesheets){
    FILE *fp = fopen(CONTADORTIMESHEETS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    
    fwrite(&(*contadorTimesheets), sizeof (int), 1, fp);
    printf("Total funcs %d \n", *contadorTimesheets);
    fclose(fp);
   
}

void escreverDias(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *contadorTimesheets){
    
    //(*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias*) calloc(dias, sizeof(Dias) * dias);
    
     FILE *fp = fopen(TIMESHEETSDIAS, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
     
     for(int i = 0; i < *contadorTimesheets; i++){
         for(int k = 0; k < 32; k++){
             fwrite(&(*arrTimesheet)[i].dias_scope[k], sizeof (Dias),1, fp);
         }
             
         //fwrite(&(*arrTimesheet)[i].dias_scope, sizeof (Dias),1, fp);
         
     }
    //fwrite(&(*arrTimesheet)[*contadorTimesheets].dias_scope, sizeof (Dias), 31, fp);

    
    
    fclose(fp);
    //return 0;
    
    
    
}




/*void LerFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    int num_alunos;
    FILE *fp = fopen(FUNCIONARIOS, "rb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    printf("Total funcs %d \n", *totalFuncionarios);
    num_alunos = fread((*arrPessoa), sizeof (Pessoa), 10, fp);
    for(int i = 0; i < num_alunos; i++){
        printf("nfunc %d nome func %s",(*arrPessoa)[i].funcNumbr, (*arrPessoa)[i].funcNome );
    }
    
    fclose(fp);
    return 0;
    
    
}*/

void PosicionarFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    //int num_alunos;
    Pessoa *novo;
    
    FILE *fp = fopen(FUNCIONARIOS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    
    
    novo = realloc(*arrPessoa, *totalFuncionarios * sizeof(Pessoa));
            
            if (novo == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }else{
                
                *arrPessoa = novo;
                
                for(int i = 0; i < *totalFuncionarios ; i++){
                    //fread(&totalFuncionarios, sizeof (int), 1, fp);
                    //printf("Total funcs %d \n", *totalFuncionarios);
                    fread(&(*arrPessoa)[i], sizeof (Pessoa), 1, fp);
                    
                
            }
    //arrPessoa = (Pessoa *) malloc(5 * sizeof (Pessoa));
    //printf("total f %d \n ", *totalFuncionarios);
    
    
    
    //num_alunos = fread((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    //for(int i = 0; i < num_alunos; i++){
      //  printf("nfunc %d nome func %s",(*arrPessoa)[i].funcNumbr, (*arrPessoa)[i].funcNome );
    //}
    
    fclose(fp);
    //return 0;
    
    }
}


void posicionarioTotalFunc(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    FILE *fp = fopen(TOTALFUNCS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    
    //*totalFuncionarios = malloc(sizeof (int));
    fread(&(*totalFuncionarios), sizeof (int), 1, fp);
    printf("totalFUNCSDEPOISPOSICIONAR %d ", *totalFuncionarios);    
    
    //PosicionarFuncionarios(arrPessoa, arrTimesheet, totalFuncionarios);
    
   
    
}

void posicionarContadorFunc(int *contadorFuncionarios){
    FILE *fp = fopen(CONTADORFUNCS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    //*contadorFuncionarios = malloc(sizeof (int));
    fread(&(*contadorFuncionarios), sizeof (int), 1, fp);
    printf("contadorFUNCS %d ", *contadorFuncionarios);
     //*contadorFuncionarios = malloc(sizeof (int));
}




void PosicionarTimesheets(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalTimesheets){
    //int num_alunos;
    Timesheet *novo;
    
    FILE *fp = fopen(TIMESHEETS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Recomendado Reiniciar \n");
        exit(EXIT_FAILURE);
    }
    
    
    novo = realloc(*arrTimesheet, *totalTimesheets * sizeof(Timesheet));
            
            if (novo == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }else{
                
                *arrTimesheet = novo;
                
                for(int i = 0; i < *totalTimesheets ; i++){
                    
                    
                    fread(&(*arrTimesheet)[i], sizeof (Timesheet), 1, fp);
                }
    
    fclose(fp);
    //return 0;
    
    }
}


void posicionarioTotalTimesheets(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalTimesheets){
    FILE *fp = fopen(TOTALTIMESHEETS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    
    //*totalFuncionarios = malloc(sizeof (int));
    fread(&(*totalTimesheets), sizeof (int), 1, fp);
    printf("totalTS %d ", *totalTimesheets);    
    
    //PosicionarFuncionarios(arrPessoa, arrTimesheet, totalFuncionarios);
    
   
    
}

void posicionarContadorTimesheets(int *contadorTimesheets){
    FILE *fp = fopen(CONTADORTIMESHEETS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    //*contadorFuncionarios = malloc(sizeof (int));
    fread(&(*contadorTimesheets), sizeof (int), 1, fp);
    printf("contadorTimesheets %d ", *contadorTimesheets);
     //*contadorFuncionarios = malloc(sizeof (int));
}


void posicionarDias(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *contadorTimesheets){
    FILE *fp = fopen(TIMESHEETSDIAS, "r");
    
    if(fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
 
/*
    for(int i = 0; i < *contadorTimesheets; i++){
         fwrite(&(*arrTimesheet)[i].dias_scope, sizeof (Dias), 31, fp);
     }
*/
    
    //realloc((*arrTimesheet)[*].dias_scope, *totalFuncionarios * sizeof(Pessoa));
    
    
    printf("contador TIMESHEETS posicionar Dias %d \n", *contadorTimesheets);
/*
    for(int i = 0; i < *contadorTimesheets+1 ; i++){
            
                (*arrTimesheet)[i].dias_scope = (Dias*) calloc(31,sizeof(Dias));
                    
                    fread(&(*arrTimesheet)[i].dias_scope, sizeof (Dias), 1, fp);
 *  
*/  
    for(int i = 0; i < *contadorTimesheets ; i++){
        (*arrTimesheet)[i].dias_scope = (Dias*) calloc(32,sizeof(Dias));            
        for(int k = 0; k < 32 ; k++){
                        
                        fread(&(*arrTimesheet)[i].dias_scope[k], sizeof (Dias), 1, fp);
                    }
                    
                    //fread(&(*arrTimesheet)[i], sizeof (Timesheet), 1, fp);
                }
                
        
}
    










void escreverTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets){
    escreverTotalFunc(totalFuncionarios);
    escreverFuncionarios(arrPessoa, arrTimesheet, totalFuncionarios);
    
    escreverContadorFunc(contadorFuncionarios);
    
    escreverTotalTimesheets(totalTimesheets);
    escreverTimesheets(arrPessoa, arrTimesheet, totalTimesheets);
    escreverContadorTimesheets(contadorTimesheets);
    
    escreverDias(arrPessoa, arrTimesheet, contadorTimesheets);
}


void carregarTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets ){
    posicionarioTotalFunc(arrPessoa, arrTimesheet, totalFuncionarios);
    
    PosicionarFuncionarios(arrPessoa, arrTimesheet, totalFuncionarios);
    //posicionarioTotalFunc(arrPessoa, arrTimesheet, totalFuncionarios);
    posicionarContadorFunc(contadorFuncionarios);
    
    
    posicionarioTotalTimesheets(arrPessoa, arrTimesheet, totalTimesheets);
    PosicionarTimesheets(arrPessoa, arrTimesheet, totalTimesheets);
    posicionarContadorTimesheets(contadorTimesheets);
    posicionarDias(arrPessoa, arrTimesheet,contadorTimesheets);
    
    
    
}