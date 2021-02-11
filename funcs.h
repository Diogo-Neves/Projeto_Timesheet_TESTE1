/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcs.h
 * Author: Diogo
 *
 * Created on 26 de janeiro de 2021, 12:05
 */

//#include "Menu_TS_header.h"
//#include "Menu_Funcs_header.h"

#ifndef FUNCS_H
#define FUNCS_H


#define MSG_OBTER_NOME              "Insira o nome do aluno: "

//int *saver2;

typedef struct {
    //int jornadaComp, meiaJorn, falta, folga;
    int funcNumbr;
    char funcNome[25];
    //Timesheet * Timesheets_pessoa;
} Pessoa;

typedef struct {
    int dia;
    //int jornadaComp, meiaJorn, falta, folga, jornadaCompFDS, meiaJornFDS;
    char status[25];
} Dias;

typedef struct {
    int jornadaComp, meiaJorn, falta, folga, jornadaCompFDS, meiaJornFDS;
    int mesTS, anoTS, timesheetCode;
    //Pessoa * Pessoas;
    int funcCode;
    Dias * dias_scope;
} Timesheet;






void atualizarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *Total_Funcionarios, int *contadorFuncionarios);
int verificarExistenciaTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *Total_Funcionarios, int *contadorFuncionarios, int nrTS);

void exportarMes(Timesheet **arrTimesheet, int *Total_Timesheets);
void escreverFuncionarios(Pessoa **arrPessoa, int *totalFuncionarios);
void LerFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios);
void PosicionarFuncionarios(Pessoa **arrPessoa, int *totalFuncionarios);
void escreverTotalFunc(int *totalFuncionarios);


void carregarTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets);
void posicionarioTotalFunc(int *totalFuncionarios);
void escreverTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets);

void escreverContadorFunc(int *contadorFuncionarios);
void posicionarContadorFunc(int *contadorFuncionarios);

void escreverTimesheets(Timesheet **arrTimesheet, int *totalTimesheets);
void escreverTotalTimesheets(int *totalTimesheets);
void escreverContadorTimesheets(int *contadorTimesheets);

void PosicionarTimesheets(Timesheet **arrTimesheet, int *totalTimesheets);
void posicionarioTotalTimesheets(int *totalTimesheets);
void posicionarContadorTimesheets(int *contadorTimesheets);






void escreverDias(Timesheet **arrTimesheet, int *contadorTimesheets);
void posicionarDias(Timesheet **arrTimesheet, int *contadorTimesheets);

void funcsSemTimesheet(Pessoa **arrPessoa, int *Total_Funcionarios, Timesheet **arrTimesheet, int *totalTimesheets);

void direitoCompensaçao(Timesheet **arrTimesheet, int *totalTimesheets);



int menu_funcionarios(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets);
int menu_timesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios);

int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *totalFuncionarios, int FuncNmbr);
void freeCalloc(Timesheet **arrTimesheet, int *totalTimesheets);


#endif /* FUNCS_H */

