/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu_Funcs_header.h
 * Author: Diogo
 *
 * Created on 1 de fevereiro de 2021, 12:23
 */

#include "funcs.h"

#ifndef MENU_FUNCS_HEADER_H
#define MENU_FUNCS_HEADER_H




void criarFunc(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);
int verificarExistenciaFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr);
void listarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios);
void atualizarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets);    
int verificarExistenciaFuncs2(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios, int FuncNmbr);    
int eliminarFuncs(Pessoa **arrPessoa, int *Total_Funcionarios, int *contadorFuncionarios);   
    
    
    



#endif /* MENU_FUNCS_HEADER_H */

