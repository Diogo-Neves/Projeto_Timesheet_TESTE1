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

#ifndef FUNCS_H
#define FUNCS_H


#define MSG_OBTER_NOME              "Insira o nome do aluno: "

//int *saver2;





/*
typedef struct {
    Pessoa *Pessoas;
    int contador;
} Funcionarios ;
*/






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

//saver2 = &(*arrPessoa)[].funcNumbr;
//(*arrTimesheet)[].funcCode = *saver2;


/*typedef struct {
    Timesheet timesheets[10];
    int contadorTS;
} Timesheet_st2 ;
*/



void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios );
void listarTimesheets(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets);

int menu_funcionarios(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);
int menu_timesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *Total_Funcionarios, int *contadorFuncionarios );
//void criarFunc(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);
//void listarFuncs(Funcionario_st2 funcionarios);
//void listTimesheets(Timesheet_st2 timesheets);
//void preenchermes(Funcionario_st2 *funcionarios, Timesheet_st2 *timesheets, int contador2 );
//void dias_total(Funcionario_st2 *funcionarios, int number, int dias, int mes, Timesheet_st2 *timesheets );

//void lerString(char *string, unsigned int tamanho, char *msg);5

void criarFunc(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);
int verificarExistenciaFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr);
void listarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios);
void atualizarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);    
int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr);    
int eliminarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);    
    
    
int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int contador);    
int preenchermes(Timesheet **arrTimesheet, Pessoa **arrPessoa, int contador);    



void atualizarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios );
int verificarExistenciaTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets,int *Total_Funcionarios, int *contadorFuncionarios, int nrTS );

void exportarMes(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *Total_Timesheets);
void escreverFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios);
void LerFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios);
void PosicionarFuncionarios(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios);
void escreverTotalFunc(int *totalFuncionarios);


void carregarTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets );
void posicionarioTotalFunc(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios);
void escreverTudo(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalFuncionarios, int *contadorFuncionarios, int *totalTimesheets, int *contadorTimesheets);

void escreverContadorFunc(int *contadorFuncionarios);
void posicionarContadorFunc(int *contadorFuncionarios);

void escreverTimesheets(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalTimesheets);
void escreverTotalTimesheets(int *totalTimesheets);
void escreverContadorTimesheets(int *contadorTimesheets);

void PosicionarTimesheets(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalTimesheets);
void posicionarioTotalTimesheets(Pessoa **arrPessoa, Timesheet **arrTimesheet, int *totalTimesheets);
void posicionarContadorTimesheets(int *contadorTimesheets);



////////// testes //////////

int contagemDias(Timesheet **arrTimesheet, int dia, int contador, int dias);
int retornarquantosdias(Timesheet **arrTimesheet, int dia, int contador, int dias);
int zerardias(Timesheet **arrTimesheet, int contador, int dias);
int diaPorDia(Timesheet **arrTimesheet, int contador, int dias, int mes, int contadorDias, int dia);


#endif /* FUNCS_H */

