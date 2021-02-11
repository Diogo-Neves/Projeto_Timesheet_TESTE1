/**
 * 
 * @file exportar_meses.c
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief Função de exportação do mês selecionado
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "maindata.h"
#include <string.h>

/**
 * Função que imprime para um ficheiro .txt a lista de timesheets preenchidas no
 * determinado mês selecionado.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void exportarMes(Timesheet **arrTimesheet, int *totalTimesheets) {
    const char* PalavraMes = "2021mes";
    const char* tipoFicheiro = ".txt";
    char buffer[100];
    int mes, mes2 = 0;

    do {
        puts("Insira o mês a imprimir:");
        scanf("%d", &mes);
    } while (mes < 1 && mes > 12);


    for (int k = 0; k < *totalTimesheets; k++) { //verificador se algum mês está preenchido no selecionado
        if ((*arrTimesheet)[k].mesTS == mes) {
            mes2 = mes;
        }

    }


    if (mes2 > 0) { //se estiver preenchido, exporta tudo para o ficheiro
        sprintf(buffer, "%s%d%s", PalavraMes, mes, tipoFicheiro); //transformador do titulo do ficheiro



        FILE *fp = fopen(buffer, "a");

        if (fp == NULL) {
            exit(EXIT_FAILURE);
        }

        fprintf(fp, "Mes:%d-ID Func_os, Jornada Completa, Meia Jornada, Total Trabalhado F/semana, Falta  \n", mes);

        for (int i = 0; i < *totalTimesheets; i++) {
            if ((*arrTimesheet)[i].mesTS == mes && (*arrTimesheet)[i].funcCode != 0) {
                fprintf(fp, "%d,%d,%d,%d,%d \n", (*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].jornadaCompFDS + (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].falta);
            }
        }
        printf("\nExportado com Sucesso;");

        fclose(fp);
    }

    if (mes2 == 0) {
        puts("*****************************");
        puts("Sem sucesso na exportação;");
        puts("Mês possívelmente inexistente;");
        puts("*****************************");
    }

    //return 0;



}