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
} Funcionario_st1;

typedef struct {
    Funcionario_st1 meuST1[10];
    int contador;
} Funcionario_st2 ;



typedef struct {
    int jornadaComp, meiaJorn, falta, folga;
    int mesTS, anoTS, timesheetCode;
    int codFunc;
} Timesheet_st1;

typedef struct {
    Timesheet_st1 timesheets[10];
    int contadorTS;
} Timesheet_st2 ;







void criarFunc(Funcionario_st2 *funcionarios);
void listarFuncs(Funcionario_st2 funcionarios);
void preenchermes(Funcionario_st2 *funcionarios);
void dias_total(Funcionario_st1 funcionarios, int number, int dias, int mes );

//void lerString(char *string, unsigned int tamanho, char *msg);5





#endif /* FUNCS_H */

