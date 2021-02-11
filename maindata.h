/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * 
 * @file maindata.h 
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief header principal com todas as estruturas e invocação funções partilhadas
 * 
 * 
 */


#ifndef MAINDATA_H
#define MAINDATA_H



#define MAXNOME 25

typedef struct {
    int funcNumbr;
    char funcNome[25];
} Pessoa;

typedef struct {
    int dia;
    char status[25];
} Dias;

typedef struct {
    int jornadaComp, meiaJorn, falta, folga, jornadaCompFDS, meiaJornFDS;
    int mesTS, anoTS, timesheetCode;
    int funcCode;
    Dias * dias_scope;
} Timesheet;





//Funções de leitura, posicionamento na memoria e exportação para ficheiros
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


//Funções de utilização partilhada entre menus
void direitoCompensaçao(Timesheet **arrTimesheet, int *totalTimesheets);
int menu_funcionarios(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets);
int menu_timesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios);
int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *totalFuncionarios, int FuncNmbr);
void freeCalloc(Timesheet **arrTimesheet, int *totalTimesheets);


#endif /* MAINDATA_H */

