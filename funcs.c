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











void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


/*
void lerString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}
*/

/*void imprimirFuncs(Funcionario_st1 funcionario){
    printf("Nr Func %d - Nome Func %-25s \n", funcionario.funcNumbr, funcionario.funcNome);
}*/
void criarFunc(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios) {
    
    //int nrFunc, *pContador;
    int nrFunc;
    Pessoa *pNovo_Realloc;
    char nomeFunc[25];
    //puts("Nr de func:");
    //scanf("%d", &nrFunc);  
    //contadorFuncionarios = *Total_Funcionarios;
    *Total_Funcionarios +=1;
    printf("indiceFuncsCRIAR %d \n", *contadorFuncionarios);
    pNovo_Realloc = realloc(*arrPessoa, (*Total_Funcionarios) * sizeof(Pessoa));  
    
    
    
    
    if (pNovo_Realloc == NULL) //verificar se foi bem ou mal sucedido
        {
            printf("Erro\n");
            exit(0);
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




        //*contadorFuncionarios += 1;
    }else{
        printf("São mais");
        puts("Nr de func:");
        scanf("%d", &nrFunc); 
        
        
        nrFunc = verificarExistenciaFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios, nrFunc);
        
        (*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
        printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
        printf("totalFuncs CRIADO %d\n", *Total_Funcionarios);


        printf("Nome de func:\n");   
        scanf(" %[^\n]s", nomeFunc);

        strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);
        
        //*contadorFuncionarios += 1;
        
    }
    *contadorFuncionarios += 1;
    //(*arrPessoa)[*contadorFuncionarios].funcNumbr = nrFunc;
    /*printf("valor func CRIADO %d\n",(*arrPessoa)[*contadorFuncionarios].funcNumbr);      
    printf("totalFuncs CRIADO %d\n", *Total_Funcionarios);
    
    
    printf("Nome de func:\n");   
    scanf(" %[^\n]s", nomeFunc);
  
    strcpy((*arrPessoa)[*contadorFuncionarios].funcNome, nomeFunc);    
    
 
    
    
    *contadorFuncionarios += 1;*/
   
}


int verificarExistenciaFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr){
    
    int i;
    
    printf("\n indiceVerificar : %d \n", *contadorFuncionarios);
    printf("\n FuncNumbrVerificar : %d \n", FuncNmbr);
    //*contadorFuncionarios = 0;

    
    
    int qqcoisa = FuncNmbr;
    
    
    for(i = 0; i < *Total_Funcionarios; i++){
        if((*arrPessoa)[i].funcNumbr == FuncNmbr){
            printf("Funcionário já existe %d i:%d\n", (*arrPessoa)[i].funcNumbr, i);
            puts("Novo user:");
            scanf("%d", &FuncNmbr);
            qqcoisa = verificarExistenciaFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios, FuncNmbr);

        
        
        }else{
            printf("\nFuncionário Não existe %d", i);
            printf("Return do else: %d", FuncNmbr);
            
            

        }
     
        
    }
    
    return qqcoisa;
}




void listarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios) {
    int i;
    
    for (i = 0; i < *Total_Funcionarios; i++) {
        printf("ID %d i: %d ---- ",(*arrPessoa)[i].funcNumbr, i);     
        printf("Nome %s i: %d  \n",(*arrPessoa)[i].funcNome, i);
        
}
}

/*
void imprimirTimesheets(Timesheet_st1 timesheets, int i){
    printf("Func Nr: %d Timesheet nr:%d/jornada completa:%d/Meia:%d/falta%d/folga:%d. \n", timesheets.funTS[0].funcNumbr, timesheets.timesheetCode, timesheets.funTS[0].jornadaComp, timesheets.funTS[0].meiaJorn, timesheets.funTS[0].falta, timesheets.funTS[0].folga );
}



void listTimesheets(Timesheet_st2 timesheets) {
    int i;
    for (i = 0; i < timesheets.contadorTS; i++) {
        printf("%d", i);        
        imprimirTimesheets(timesheets.timesheets[i], i);
        }
}*/













/*void preencherTS(Funcionario_st2 *funcionarios, Timesheet_st2 *timesheets){
    
    int nrFunc, i;
    
    puts("Indique o seu Nr de Funcionário:");
    scanf(" %d", &nrFunc);
    //verificar se existe com uma função que ainda falta
    //printf("\n\n\nfuncTIMESHEET\n");
    //printf("pFuncs  %p \n", &funcionarios );
    
    //printf("posiçao do contador: %p\n", &funcionarios->meuST1[funcionarios->contador]);
    //printf("posiçao do funNumber: %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    //funcionarios->contador--;
    printf("valor do contador %d\n",funcionarios->contador);
    //printf("posiçao do contador:-1 %p\n", &funcionarios->meuST1[funcionarios->contador]);
    //printf("posiçao do funNumber:-1 %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    
    
    
    //preenchermes(&funcionarios);
    //preenchermes(&funcionarios->meuST1[funcionarios->contador]);
    
    for (i = 0; i < funcionarios->contador; i++) {
        if(funcionarios->meuST1[i].funcNumbr == nrFunc){
            printf("Funcionário Existe. ");
            //printf("posiçao do contador: %d\n", funcionarios->meuST1[i]);
            //printf("posiçao do funNumber: %d\n", funcionarios->meuST1[i].funcNumbr);
    
            
            preenchermes(funcionarios, timesheets, i );
        }else{
            printf("Não existe" );
        }
      
        
        
}
}*/
    //funcionarios->meuST1[funcionarios->contador].funcNumbr = nrFunc;
    
    
  
    
    
    
    


