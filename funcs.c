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
#include "Menu_Funcs_header.h"
#include <locale.h>











void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}





void criarFunc(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios) {
    
    //int nrFunc, *pContador;
    int nrFunc;
    Pessoa *pNovo_Realloc;
    char nomeFunc[25];

    *Total_Funcionarios +=1;
    printf("indiceFuncsCRIAR %d \n", *contadorFuncionarios);
    printf("indiceTOTAL EM CRIAR %d \n", *Total_Funcionarios);

    pNovo_Realloc = realloc(*arrPessoa, (*Total_Funcionarios) * sizeof(Pessoa));  
    
    
    
    
    if (pNovo_Realloc == NULL) //verificar se foi bem ou mal sucedido
        {
            printf("Erro\n");
            //exit(0);
        }
        else //este else so esta aqui para facilitar a leitura
        {
            *arrPessoa = pNovo_Realloc;
        }
    
    
    if( *contadorFuncionarios < 1){
        puts("Nr de func:");
        scanf("%d", &nrFunc);  
        
        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
        printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
        printf("totalFuncs CRIADO %d\n", *Total_Funcionarios);


        printf("Nome de func:\n");   
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);    




        
    }else{
        //printf("São mais");
        puts("Nr de func:");
        scanf("%d", &nrFunc); 
        
        
        nrFunc = verificarExistenciaFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios, nrFunc);
        
        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
        printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
        printf("totalFuncs CRIADO %d\n", *Total_Funcionarios);


        printf("Nome de func:\n");   
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);
        
        
        
    }
    *contadorFuncionarios += 1;

   
}


int verificarExistenciaFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr){
    
    int i, retornador, novoNumero;
    
    retornador = FuncNmbr;
    
    
    for(i = 0; i < *Total_Funcionarios; i++){
        if((*arrPessoa)[i].funcNumbr == FuncNmbr){
            printf("Funcionário %d já existe.\n", (*arrPessoa)[i].funcNumbr);
            puts("NOVO* Nr de func:");
            scanf("%d", &novoNumero);
            retornador = verificarExistenciaFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios, novoNumero);

        
        
        }
     
        
    }
    
    return retornador;
}




void listarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios) {
    int i;

    for (i = 0; i < *Total_Funcionarios; i++) {
        if((*arrPessoa)[i].funcNumbr != NULL) {
            printf("ID %d i: %d ---- ",(*arrPessoa)[i].funcNumbr, i);     
            printf("Nome %s i: %d  \n",(*arrPessoa)[i].funcNome, i);  
        }
        //printf("ID %d i: %d ---- ",(*arrPessoa)[i].funcNumbr, i);     
        //printf("Nome %s i: %d  \n",(*arrPessoa)[i].funcNome, i);
    }
    
        
}





void atualizarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets){
    int escolha, nfunc, existenciaIndice = -1, existenciaIndice2 = -1;
    char nomeFunc[25];
    
    puts("Pretende alterar: Nº (1) Nome (2)");
    scanf("%d", &escolha);
    puts("Nr de funcionário:");
    scanf("%d", &nfunc);
    
    existenciaIndice = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
    
    if(existenciaIndice >= 0 ){    
            switch(escolha){
        case 1:
            puts("Novo Nr:");
            scanf("%d", &nfunc);
            
            
            existenciaIndice2 = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
            printf("\nexistIndice %d \n", existenciaIndice);
            if(existenciaIndice2 >= 0 ){

                printf("Já existe \n");
            }else{
  
                
                for(int i = 0; i < *totalTimesheets; i++){
                    if((*arrTimesheet)[i].funcCode == (*arrPessoa)[existenciaIndice].funcNumbr){
                        (*arrTimesheet)[i].funcCode = nfunc;
                    }
                }
                (*arrPessoa)[existenciaIndice].funcNumbr = nfunc;
                
                
                
            }
           
            break;
        case 2:
            puts("Novo Nome:");
            scanf(" %[^\n]s", nomeFunc);
            strcpy((*arrPessoa)[existenciaIndice].funcNome, nomeFunc);
            break;
        default:
            printf("escolha errada");
    }
    }else{
        printf("\nfuncionario nao existe");
    }
    
    //free(*arrPessoa);
    //*arrPessoa = NULL;
    
}

int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr){
    
    int i;
    

    for(i = 0; i < *Total_Funcionarios; i++){
        if((*arrPessoa)[i].funcNumbr == FuncNmbr){

            return i;
        }
    }
    return -1;
    

}


int eliminarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets){
    
    int apagado = -1 ;
    int idapagar;
    puts("Utilizador a apagar: ");
    scanf("%d", &idapagar);
    
    for(int i=0; i < *Total_Funcionarios; i++){
        if((*arrPessoa)[i].funcNumbr == idapagar){
            
            for(int i = 0; i < *totalTimesheets; i++){
                    if((*arrTimesheet)[i].funcCode == idapagar){
                        (*arrTimesheet)[i].funcCode = NULL;
                    }
                }
                
            
            
            (*arrPessoa)[i].funcNumbr = NULL;
            strcpy((*arrPessoa)[i].funcNome, "");
            apagado = 1;
        }
        
    }
    if(apagado == 1){
        puts("Apagado Com sucesso;");
    }else{
        puts("Impossível apagar Funcionário identificado;");
        puts("Erro;");
    }
  
}



void funcsSemTimesheet(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets){
    
    
    for(int i=0; i < *Total_Funcionarios; i++){
        for(int k=0; k < *totalTimesheets; k++){
            if((*arrPessoa)[i].funcNumbr != (*arrTimesheet)[k].funcCode){
                puts("Funcionário existe");
            }else{
                printf("Funcionário %d sem Timesheet.",(*arrPessoa)[i].funcNumbr );        
            }
        }
        
        if(*totalTimesheets == 0){
            puts("Sem timesheets criadas");
        }
    }
    if(*Total_Funcionarios == 0){
            puts("Sem funcionarios criados");
    }
    
    
    
}









    
  
    
    
    
    


