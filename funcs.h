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


typedef struct {
    int jornadaComp, meiaJorn, falta, folga;
    int funcNumbr;
    char funcNome[25];
} Pessoa;




typedef struct {
    Pessoa *Pessoas;
    int contador;
} Funcionarios ;





/*typedef struct {
    int jornadaComp, meiaJorn, falta, folga;
    int mesTS, anoTS, timesheetCode;
    Funcionario_st1 funTS[10];
} Timesheet_st1;

typedef struct {
    Timesheet_st1 timesheets[10];
    int contadorTS;
} Timesheet_st2 ;
*/





int menu_funcionarios(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);
//void criarFunc(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);
//void listarFuncs(Funcionario_st2 funcionarios);
//void listTimesheets(Timesheet_st2 timesheets);
//void preenchermes(Funcionario_st2 *funcionarios, Timesheet_st2 *timesheets, int contador2 );
//void dias_total(Funcionario_st2 *funcionarios, int number, int dias, int mes, Timesheet_st2 *timesheets );

//void lerString(char *string, unsigned int tamanho, char *msg);5





#endif /* FUNCS_H */

