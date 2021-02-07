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


void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios );
void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets);

int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias);
//int retornarquantosdias(Timesheet **arrTimesheet, int dia, int contador, int dias);
//int zerardias(Timesheet **arrTimesheet, int contador, int dias);
int diaPorDia(Timesheet **arrTimesheet,int *contadorTimesheets, int dias, int mes, int contadorDias, int dia);
void consultarTSutilizador(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets);

int preenchermes(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *contadorTimesheets); 

int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int *contadorTimesheets);


#endif /* MENU_TS_HEADER_H */

