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

void imprimirFuncs(Funcionario_st1 funcionario){
    printf("Nr Func %d - Nome Func %-25s  \n", funcionario.funcNumbr, funcionario.funcNome);
}
void criarFunc(Funcionario_st2 *funcionarios) {
    
    int nrFunc, *pContador;
    char nomeFunc[25];
    puts("Nr de func:");
    scanf("%d", &nrFunc);  
    funcionarios->meuST1[funcionarios->contador].funcNumbr = nrFunc;  
    
    funcionarios->meuST1[funcionarios->contador].meiaJorn++;
    
    printf("posiçao do contador: %p\n", &funcionarios->meuST1[funcionarios->contador]);
    printf("posiçao do funNumber: %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    printf("Nome de func:\n");   
    scanf(" %[^\n]s", nomeFunc);
    
    
    //lerString(funcionarios->meuST1[funcionarios->contador].funcNome, 25, MSG_OBTER_NOME);
    
    
    strcpy(funcionarios->meuST1[funcionarios->contador].funcNome, nomeFunc);    
    
    pContador = &funcionarios->meuST1[funcionarios->contador]; 
    
    funcionarios->contador++;   
    printf("pFuncs  %f \n",funcionarios );
    printf("posiçao do contador: %p\n", &funcionarios->meuST1[funcionarios->contador]);
    printf("posiçao do funNumber: %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
}




void listarFuncs(Funcionario_st2 funcionarios) {
    int i;
    for (i = 0; i < funcionarios.contador; i++) {
        printf("%d", i);
        imprimirFuncs(funcionarios.meuST1[i]);
        }
    //printf("%d", funcionarios.meuST1[0].meiaJorn);
}














void preencherTS(Funcionario_st2 *funcionarios, Timesheet_st2 *timesheets){
    
    int nrFunc, i;
    
    puts("Indique o seu Nr de Funcionário:");
    scanf(" %d", &nrFunc);
    //verificar se existe com uma função que ainda falta
    printf("\n\n\nfuncTIMESHEET\n");
    printf("pFuncs  %p \n", &funcionarios );
    
    printf("posiçao do contador: %p\n", &funcionarios->meuST1[funcionarios->contador]);
    printf("posiçao do funNumber: %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    //funcionarios->contador--;
    printf("valor do contador %d", funcionarios->contador );
    printf("posiçao do contador:-1 %p\n", &funcionarios->meuST1[funcionarios->contador]);
    printf("posiçao do funNumber:-1 %p\n", &funcionarios->meuST1[funcionarios->contador].funcNumbr);
    
    
    
    //preenchermes(&funcionarios);
    //preenchermes(&funcionarios->meuST1[funcionarios->contador]);
    
    for (i = 0; i < funcionarios->contador; i++) {
        if(funcionarios->meuST1[i].funcNumbr == nrFunc){
            printf("Funcionário Existe. ");
            printf("posiçao do contador: %d\n", funcionarios->meuST1[i]);
            printf("posiçao do funNumber: %d\n", funcionarios->meuST1[i].funcNumbr);
    
            
            preenchermes(&funcionarios, &timesheets);
        }else{
            printf("Não existe" );
        }
      
        
        
}
}
    //funcionarios->meuST1[funcionarios->contador].funcNumbr = nrFunc;
    
    
  
    
    
    
    


