

/**
 * 
 * @file Menu_TS_header.h
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief header com a invocação das funções apenas do escopo das Timesheets
 * 
 * 
 */

#include "maindata.h"

#ifndef MENU_TS_HEADER_H
#define MENU_TS_HEADER_H

#define JAN 31
#define FEV 28
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 31
#define JUL 30
#define AGO 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31




//Funções de 'timesheets.c' sem dependência com outros menus
void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *Total_Funcionarios);
void listarTimesheets(Timesheet **arrTimesheet, int *totalTimesheets);
int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias);
int diaPorDia(Timesheet **arrTimesheet, int *contadorTimesheets, int mes, int contadorDias, int dia);
void consultarTSutilizador(Timesheet **arrTimesheet, int *totalTimesheets);
int preenchermes(Timesheet **arrTimesheet, int *contadorTimesheets);
int dias_total(int dias, Timesheet **arrTimesheet, int mes, int *contadorTimesheets);
void refazerTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *Total_Funcionarios);
int possivelTimesheet(Timesheet **arrTimesheet, int *totalTimesheets, int timesheetNo);
void timesheetsIncompletas(Timesheet **arrTimesheet, int *totalTimesheets);



#endif /* MENU_TS_HEADER_H */

