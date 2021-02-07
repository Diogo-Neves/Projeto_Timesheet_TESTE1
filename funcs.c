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




        //*contadorFuncionarios += 1;
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
    
    int i, retornador, novoNumero;
    
    //printf("\n indiceVerificar : %d \n", *contadorFuncionarios);
    //printf("\n FuncNumbrVerificar : %d \n", FuncNmbr);
    //*contadorFuncionarios = 0;

    
    
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
    
    //printf("%p apontador pessoa\n", arrPessoa);
    //printf("%p apontador funcs", Total_Funcionarios);
    
    //printf("total funcs antes de free: %d", *Total_Funcionarios);
    
    //Total_Funcionarios = (int *) malloc(sizeof (int));
    
 
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
            
            //existenciaIndice = -1;
            existenciaIndice2 = verificarExistenciaFuncs2(arrPessoa, Total_Funcionarios, contadorFuncionarios, nfunc);
            printf("\nexistIndice %d \n", existenciaIndice);
            if(existenciaIndice2 >= 0 ){
                //(*arrPessoa)[existenciaIndice].funcNumbr = nfunc;
                printf("Já existe \n");
            }else{
                //(*arrPessoa)[existenciaIndice].funcNumbr = nfunc;
                //Atualizar na Timesheet
                
                for(int i = 0; i < *totalTimesheets; i++){
                    if((*arrTimesheet)[i].funcCode == (*arrPessoa)[existenciaIndice].funcNumbr){
                        (*arrTimesheet)[i].funcCode = nfunc;
                    }
                }
                (*arrPessoa)[existenciaIndice].funcNumbr = nfunc;
                
                
                
            }
                //(*arrPessoa)[existenciaIndice].funcNumbr = nfunc;
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
    
    //printf("\n indiceVerificar : %d \n", *contadorFuncionarios);
    //printf("\n FuncNumbrVerificar : %d \n", FuncNmbr);
    //*contadorFuncionarios = 0;
    //int qqcoisa = FuncNmbr;  
    for(i = 0; i < *Total_Funcionarios; i++){
        if((*arrPessoa)[i].funcNumbr == FuncNmbr){
            //printf("Funcionário já existe %d i:%d\n", (*arrPessoa)[i].funcNumbr, i);
            //puts("Novo user:");
            //scanf("%d", &FuncNmbr);
            //qqcoisa = verificarExistenciaFuncs(arrPessoa, Total_Funcionarios, contadorFuncionarios, FuncNmbr);
            return i;
        
        
        }
    }
    return -1;
    

}


int eliminarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios){
    
    int idapagar;
    puts("Utilizador a apagar: ");
    scanf("%d", &idapagar);
    
    for(int i=0; i < * Total_Funcionarios; i++){
        if((*arrPessoa)[i].funcNumbr == idapagar){
            //(*arrPessoa)[i].funcNumbr = NULL;
            strcpy((*arrPessoa)[i].funcNome, "APAGADO");
        }
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
    
    
  
    
    
    
    


