/**
 * 
 * @file escrever_binarios.c
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief Funções de escrita em ficheiros e reposição no programa de dados (escritos em binario)
 * 
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "maindata.h"


#define FUNCIONARIOS "funcionarios.txt"
#define TOTALFUNCS "SaveTotalFunc.txt"
#define CONTADORFUNCS "ContadorFunc.txt"

#define TIMESHEETS "Timesheets.txt"
#define TOTALTIMESHEETS "SaveTotalTimesheet.txt"
#define CONTADORTIMESHEETS "ContadorTimesheet.txt"
#define TIMESHEETSDIAS "Timesheetsdias.txt"

/**
 * Função que escre os dados dos funcionários num documento .txt.
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void escreverFuncionarios(Pessoa **arrPessoa, int *totalFuncionarios) {

    FILE *fp = fopen(FUNCIONARIOS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite((*arrPessoa), sizeof (Pessoa), (*totalFuncionarios), fp);

    fclose(fp);


}

/**
 * Função que escreve o valor do Total de Funcionários noutro documento
 * 
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void escreverTotalFunc(int *totalFuncionarios) {

    //*totalFuncionarios = 2;

    FILE *fp = fopen(TOTALFUNCS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    fwrite(&(*totalFuncionarios), sizeof (int), 1, fp);
    fclose(fp);

}

/**
 * Função que escreve o contador de funcionários noutro documento
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void escreverContadorFunc(int *contadorFuncionarios) {
    FILE *fp = fopen(CONTADORFUNCS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    fwrite(&(*contadorFuncionarios), sizeof (int), 1, fp);
    fclose(fp);

}

/**
 * Função que escreve os dados referentes ás Timesheets num documento
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void escreverTimesheets(Timesheet **arrTimesheet, int *totalTimesheets) {

    FILE *fp = fopen(TIMESHEETS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite((*arrTimesheet), sizeof (Timesheet), (*totalTimesheets), fp);

    fclose(fp);


}

/**
 * Função que escreve o valor total de timesheets preenchidas num documento
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void escreverTotalTimesheets(int *totalTimesheets) {



    FILE *fp = fopen(TOTALTIMESHEETS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    fwrite(&(*totalTimesheets), sizeof (int), 1, fp);
    fclose(fp);

}

/**
 * Função que escreve o contador de timesheets num documento
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void escreverContadorTimesheets(int *contadorTimesheets) {
    FILE *fp = fopen(CONTADORTIMESHEETS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    fwrite(&(*contadorTimesheets), sizeof (int), 1, fp);
    fclose(fp);
    printf("\nSalvo com sucesso;");
}

/**
 * Função que escreve num documento os dados das timesheets que correspondem ao escopo de dias,
 * ou seja, da estrutura 'Dias'.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void escreverDias(Timesheet **arrTimesheet, int *contadorTimesheets) {

    FILE *fp = fopen(TIMESHEETSDIAS, "wb+");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < *contadorTimesheets; i++) {
        for (int k = 0; k < 32; k++) {
            fwrite(&(*arrTimesheet)[i].dias_scope[k], sizeof (Dias), 1, fp);
        }


    }



    fclose(fp);




}

/**
 * Função para importar do ficheiro, os funcionarios
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void PosicionarFuncionarios(Pessoa **arrPessoa, int *totalFuncionarios) {

    Pessoa *novo;

    FILE *fp = fopen(FUNCIONARIOS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }


    novo = realloc(*arrPessoa, *totalFuncionarios * sizeof (Pessoa));

    if (novo == NULL) //verificar se foi bem ou mal sucedido
    {
        printf("Erro\n");
        exit(0);
    } else {

        *arrPessoa = novo;

        for (int i = 0; i < *totalFuncionarios; i++) {
            fread(&(*arrPessoa)[i], sizeof (Pessoa), 1, fp);


        }


        fclose(fp);

    }
}

/**
 * Função que importa do ficheiro o total de funcionarios
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void posicionarioTotalFunc(int *totalFuncionarios) {
    FILE *fp = fopen(TOTALFUNCS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    fread(&(*totalFuncionarios), sizeof (int), 1, fp);



}

/**
 * Função para importar do ficheiro o volar contador de funcionarios
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void posicionarContadorFunc(int *contadorFuncionarios) {
    FILE *fp = fopen(CONTADORFUNCS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }

    fread(&(*contadorFuncionarios), sizeof (int), 1, fp);

}

/**
 * Função para importar do ficheiro os dados das timesheets e posiciona-los. 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void PosicionarTimesheets(Timesheet **arrTimesheet, int *totalTimesheets) {
    //int num_alunos;
    Timesheet *novo;

    FILE *fp = fopen(TIMESHEETS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Recomendado Reiniciar \n");
        exit(EXIT_FAILURE);
    }


    novo = realloc(*arrTimesheet, *totalTimesheets * sizeof (Timesheet));

    if (novo == NULL) //verificar se foi bem ou mal sucedido
    {
        printf("Erro\n");
        exit(0);
    } else {

        *arrTimesheet = novo;

        for (int i = 0; i < *totalTimesheets; i++) {


            fread(&(*arrTimesheet)[i], sizeof (Timesheet), 1, fp);
        }

        fclose(fp);


    }
}

/**
 * Função para importar dos ficheiros o valor total de timesheets
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void posicionarioTotalTimesheets(int *totalTimesheets) {
    FILE *fp = fopen(TOTALTIMESHEETS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }

    fread(&(*totalTimesheets), sizeof (int), 1, fp);




}

/**
 * Função para importar dos ficheiros o valor do contador de timesheets
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void posicionarContadorTimesheets(int *contadorTimesheets) {
    FILE *fp = fopen(CONTADORTIMESHEETS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }
    //*contadorFuncionarios = malloc(sizeof (int));
    fread(&(*contadorTimesheets), sizeof (int), 1, fp);

}

/**
 * Função para realocar e posicionar os dias que estavam guardados nas suas determinadas posições, nos ficheiros
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void posicionarDias(Timesheet **arrTimesheet, int *contadorTimesheets) {
    FILE *fp = fopen(TIMESHEETSDIAS, "r");

    if (fp == NULL) {
        printf("Sem dados guardados - Volte a ligar o programa. \n");
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < *contadorTimesheets; i++) {
        (*arrTimesheet)[i].dias_scope = (Dias*) calloc(32, sizeof (Dias));
        for (int k = 0; k < 32; k++) {

            fread(&(*arrTimesheet)[i].dias_scope[k], sizeof (Dias), 1, fp);
        }

        //fread(&(*arrTimesheet)[i], sizeof (Timesheet), 1, fp);
    }

    puts("");
    puts("*****************************");
    puts("Dados carregados com Sucesso");
    puts("*****************************");
    puts("");
}

/**
 * Função para executar todas as funções de escrita em ficheiros, na sua ordem correta.
 * 
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void escreverTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets) {
    escreverTotalFunc(totalFuncionarios);
    escreverFuncionarios(arrPessoa, totalFuncionarios);
    escreverContadorFunc(contadorFuncionarios);
    escreverTotalTimesheets(totalTimesheets);
    escreverTimesheets(arrTimesheet, totalTimesheets);
    escreverContadorTimesheets(contadorTimesheets);
    escreverDias(arrTimesheet, contadorTimesheets);
}

/**
 * Função para escrever no programa os dados lidos de todos os ficheiros previamente preenchdos.
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param contadorFuncionarios argumento que trás o valor apontado deste contador dinâmico
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void carregarTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets) {
    posicionarioTotalFunc(totalFuncionarios);
    PosicionarFuncionarios(arrPessoa, totalFuncionarios);
    posicionarContadorFunc(contadorFuncionarios);
    posicionarioTotalTimesheets(totalTimesheets);
    PosicionarTimesheets(arrTimesheet, totalTimesheets);
    posicionarContadorTimesheets(contadorTimesheets);
    posicionarDias(arrTimesheet, contadorTimesheets);



}