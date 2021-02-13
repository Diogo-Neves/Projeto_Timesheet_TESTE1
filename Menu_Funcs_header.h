
/**
 * 
 * @file Menu_Funcs_header.h
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief header com a invocação das funções apenas do escopo dos Funcionarios
 * 
 * 
 */

#include "maindata.h"

#ifndef MENU_FUNCS_HEADER_H
#define MENU_FUNCS_HEADER_H




//Funções de 'funcionários.c' sem dependência com outros menus
void criarFunc(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios);
int verificarExistenciaFuncs(Pessoa **arrPessoa, int *totalFuncionarios, int *contadorFuncionarios, int FuncNmbr);
void listarFuncs(Pessoa **arrPessoa, int *totalFuncionarios);
void atualizarFuncs(Pessoa **arrPessoa, int *totalFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets);
int eliminarFuncs(Pessoa **arrPessoa, int *totalFuncionarios, Timesheet **arrTimesheet, int *totalTimesheets);






#endif /* MENU_FUNCS_HEADER_H */

