/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu_TS_header.h
 * Author: Diogo
 *
 * Created on 2 de fevereiro de 2021, 11:13
 */

#include "funcs.h"

#ifndef MENU_TS_HEADER_H
#define MENU_TS_HEADER_H


void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios );
void listarTimesheets(Timesheet **arrTimesheet, int *totalTimesheets);

int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias);
//int retornarquantosdias(Timesheet **arrTimesheet, int dia, int contador, int dias);
//int zerardias(Timesheet **arrTimesheet, int contador, int dias);
int diaPorDia(Timesheet **arrTimesheet,int *contadorTimesheets, int mes, int contadorDias, int dia);
void consultarTSutilizador(Timesheet **arrTimesheet, int *totalTimesheets);

int preenchermes(Timesheet **arrTimesheet, int *contadorTimesheets); 

int dias_total(int dias, Timesheet **arrTimesheet, int mes, int *contadorTimesheets);

void refazerTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios);
int possivelTimesheet(Timesheet **arrTimesheet, int *totalTimesheets, int timesheetNo);
void timesheetsIncompletas(Timesheet **arrTimesheet, int *totalTimesheets);



#endif /* MENU_TS_HEADER_H */

