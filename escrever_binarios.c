/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcs.h"


#define FILENAME "escreverTeste.txt"
#define FILENAME2 "escreverVar2.txt"

void escreverFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    
    FILE *fp = fopen(FILENAME, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fwrite((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    printf("Total funcs %d \n", *totalFuncionarios);
    fwrite(totalFuncionarios, sizeof (int), (*totalFuncionarios), fp);
    fclose(fp);
    return 0;
    
    
}

void LerFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    int num_alunos;
    FILE *fp = fopen(FILENAME, "rb+");
    
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
    
    
}

void PosicionarFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios){
    //int num_alunos;
    Pessoa *novo;
    
    FILE *fp = fopen(FILENAME, "r");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    //fseek(fp, sizeof (Pessoa) * 10, SEEK_SET);
    //fread(&totalFuncionarios, sizeof (int), 1, fp);
    novo = realloc(*arrPessoa, (*totalFuncionarios) * sizeof(Pessoa));
            
            if (novo == NULL) //verificar se foi bem ou mal sucedido
            {
                printf("Erro\n");
                exit(0);
            }else{
                
                *arrPessoa = novo;
                
                for(int i = 0; i < 3; i++){
                    //fread(&totalFuncionarios, sizeof (int), 1, fp);
                    printf("Total funcs %d \n", *totalFuncionarios);
                    fread(&(*arrPessoa)[i], sizeof (Pessoa), 1, fp);
                    printf("%d", (*arrPessoa)[0].funcNumbr);
                    
                }
    
                //fread(&(*arrPessoa)[i], sizeof (Pessoa), 1, fp);
                //printf("%d", (*arrPessoa)[0].funcNumbr);
                
            }
    
    
    
    
    //num_alunos = fread((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    //for(int i = 0; i < num_alunos; i++){
      //  printf("nfunc %d nome func %s",(*arrPessoa)[i].funcNumbr, (*arrPessoa)[i].funcNome );
    //}
    
    fclose(fp);
    return 0;
    
    
}

void escreverTotalFunc(int *totalFuncionarios){
    
    *totalFuncionarios = 2;
    
    FILE *fp = fopen(FILENAME2, "wb+");
    
    if(fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    //fwrite((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);
    printf("Total funcs %d \n", *totalFuncionarios);
    fwrite(totalFuncionarios, sizeof (int), (*totalFuncionarios), fp);
    fclose(fp);
    return 0;
    
    
}