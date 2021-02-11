/**
 * 
 * @file timesheets.c
 * @author Diogo Neves
 * @date 11 Fevereiro 2021
 * @brief Funções do escopo das Timesheets
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "Menu_Funcs_header.h"
#include "Menu_TS_header.h"
#include "maindata.h"
#include <locale.h>

/**
 * Função para criar Timesheets para determinados funcionários, caso estes existam.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void criarTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios) {

    Timesheet *PNovaTS_Realloc;
    int nfunc, indiceFuncao, preencherTS;


    printf("\nQuantidade prévia de Timesheets: %d\n", *totalTimesheets);
    puts("Nr de funcionário:");
    scanf("%d", &nfunc);


    indiceFuncao = verificarExistenciaFuncs2(arrPessoa, totalFuncionarios, nfunc); //teste de existencia de funcionário com base no seu indice


    if (indiceFuncao > -1 && nfunc != 0) { //todo o tratamento será feito caso o funcionário exista

        *totalTimesheets += 1;

        PNovaTS_Realloc = realloc(*arrTimesheet, (*totalTimesheets) * sizeof (Timesheet)); //realocação com +1 tamanho



        if (PNovaTS_Realloc == NULL) //verificar sucesso da alocação
        {
            printf("Erro\n");
            exit(0);
        } else {
            *arrTimesheet = PNovaTS_Realloc;
        }


        (*arrTimesheet)[*contadorTimesheets].funcCode = (*arrPessoa)[indiceFuncao].funcNumbr; //como funcionario existe, posiciono o mesmo ID do arrPessoa no arrTimesheet

        (*arrTimesheet)[*contadorTimesheets].timesheetCode = *totalTimesheets;


        preencherTS = preenchermes(arrTimesheet, contadorTimesheets); //Timesheet já tem id e nr de funcionário. Continua chamando uma outra função cuja testa o mês a preencher





    } else {
        printf(" Funcionário inexistente;");
    }

};

/**
 * Função que lista as timesheets criadas, com excepção das que ficaram
 * com ID's '0' derivado da eliminação de utilizadores. Mostra lista e detalhes
 * em formato de somatório.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void listarTimesheets(Timesheet **arrTimesheet, int *totalTimesheets) {
    puts("Lista de Timesheets:");
    puts("");


    for (int i = 0; i < *totalTimesheets; i++) {
        if ((*arrTimesheet)[i].timesheetCode > 0 && (*arrTimesheet)[i].funcCode > 0) {
            printf("Timesheet ID: %d Mes: %d FuncID: %d \nJornada Comp. F.semana: %d / Jornada Comp.: %d \nMeia Jornada F.semana: %d / Meia Jornada: %d \nFaltas: %d / Folgas: %d\n\n\n", (*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);
            puts("----------------------------------------------------------------------");
        }
    }
    puts("----------------------------------------------------------------------");
}

/**
 * Função chamada pela 'criarTimesheet', com o objetivo de determinar o mês a preencher
 * e respetiva composição de dias do mês.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 *   
 */
int preenchermes(Timesheet **arrTimesheet, int *contadorTimesheets) {
    //printf("\n\n\nfuncMes\n");

    //printf("valor do contador depois de receber: %d\n", *contadorTimesheets);


    int mes, mes2;

    do {
        puts("Qual o mês em questão:");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    mes2 = mes;



    for (int s = 0; s < *contadorTimesheets + 1; s++) { //teste de verificação de preenchimento do mês por parte do funcionário em questão
        if ((*arrTimesheet)[s].funcCode == (*arrTimesheet)[*contadorTimesheets].funcCode) {
            if ((*arrTimesheet)[s].mesTS == mes2) {
                do {
                    puts("Mês já preenchido pelo Funcionário\nInsira o mês que deseja preencher   (0 = sair):");
                    scanf("%d", &mes);
                } while (mes < 0 || mes > 12 || mes == mes2);

            }
        }

    }

    switch (mes) { //estando o mês por preencher, é chamada a função 'dias_total' com a totalidade de dias do mês em questão
        case 1:
            dias_total(JAN, arrTimesheet, mes, contadorTimesheets);

            break;
        case 2:
            dias_total(FEV, arrTimesheet, mes, contadorTimesheets);

            break;
        case 3:
            dias_total(MAR, arrTimesheet, mes, contadorTimesheets);

            break;
        case 4:
            dias_total(APR, arrTimesheet, mes, contadorTimesheets);

            break;
        case 5:
            dias_total(MAY, arrTimesheet, mes, contadorTimesheets);

            break;
        case 6:
            dias_total(JUN, arrTimesheet, mes, contadorTimesheets);

            break;
        case 7:
            dias_total(JUL, arrTimesheet, mes, contadorTimesheets);


            break;
        case 8:
            dias_total(AGO, arrTimesheet, mes, contadorTimesheets);


            break;
        case 9:
            dias_total(SEP, arrTimesheet, mes, contadorTimesheets);


            break;
        case 10:
            dias_total(OCT, arrTimesheet, mes, contadorTimesheets);


            break;
        case 11:
            dias_total(NOV, arrTimesheet, mes, contadorTimesheets);


            break;
        case 12:
            dias_total(DEC, arrTimesheet, mes, contadorTimesheets);


            break;
        default:
            printf("Sair");
            break;
    }
}

/**
 * Função que questiona de forma intermitente os dias a preencher até o total de dias
 * que completam o mês ou até o utilizador requisitar para parar de preencher a timesheet.
 * 
 * @param dias argumento que recebe o total de dias do mês em questão
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param mes argumento que indica o mês tratado
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 * 
 */
int dias_total(int dias, Timesheet **arrTimesheet, int mes, int *contadorTimesheets) {

    int dia, verificar, contadorDias = 0;

    do {
        puts("Insira o dia (1ªvez) a preencher:");
        scanf("%d", &dia);
    } while (dia < 1 || dia > dias); //inserção de dias entre o valor min e maximo do mês em questão. Primeira rodada pode ser qualquer um.


    (*arrTimesheet)[*contadorTimesheets].dias_scope = (Dias*) calloc(32, sizeof (Dias)); //alocação de espaço suficiente no heap para o total de dias do mês da estrutura 'Dias' para cada indice do arrTimesheet



    (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia; //valores default em cada indice da estrutura 'arrTimesheet'
    (*arrTimesheet)[*contadorTimesheets].jornadaCompFDS = 0;
    (*arrTimesheet)[*contadorTimesheets].jornadaComp = 0;
    (*arrTimesheet)[*contadorTimesheets].meiaJornFDS = 0;
    (*arrTimesheet)[*contadorTimesheets].meiaJorn = 0;
    (*arrTimesheet)[*contadorTimesheets].falta = 0;
    (*arrTimesheet)[*contadorTimesheets].folga = 0;
    (*arrTimesheet)[*contadorTimesheets].mesTS = mes;
    diaPorDia(arrTimesheet, contadorTimesheets, mes, contadorDias, dia); //chamada da função 'diaPorDia' que permite preencher para o dia em questão o seu Status de trabalho e ainda deteta o dia em especifico no calendario

    contadorDias += 1; //primeiro dia preenchido, adiciona +1 dia ao contador

    do { //proximas inserções

        do {
            puts("");
            puts("Preencher Novo Dia:   (0 = Sair)");
            scanf("%d", &dia);
        } while (dia < 0 || dia > dias);



        verificar = contagemDias(arrTimesheet, dia, contadorTimesheets, dias); //verificar recebe -1 ou 0 de 'contagemDias', conforme o dia já esteja ou não preenchido
        if (verificar != -1 && dia > 0) {

            (*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].dia = dia; //verificar recebendo 0, o dia é atribuido
            diaPorDia(arrTimesheet, contadorTimesheets, mes, contadorDias, dia); //novamente o status é preenchido



            contadorDias += 1; //novo dia adicionado
        }

    } while (dia != 0 && contadorDias < dias);

    if (dia == 0) { //mensagem de saída forçada pelo 0
        puts("Timesheet preenchida, mas incompleta.");
    }



    for (int k = 0; k < dias; k++) { //visualização final da timesheet, mostrando ainda que ficam a faltar dias caso não esteja totalmente preenchida 
        printf(" %d - Dias preenchidos: %d      status: %s \n", k, (*arrTimesheet)[*contadorTimesheets].dias_scope[k].dia, (*arrTimesheet)[*contadorTimesheets].dias_scope[k].status);
    }


    *contadorTimesheets += 1; //timesheet preenchida, novo indice adicionado
}

/**
 * Função que retorna existencia do dia perante a contagem do seu indice e sua verificação
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param dia argumento que indica o dia em questão a ser verificado
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param dias total de dias pelo qual o mês é composto, para verificação nesse mes
 */
int contagemDias(Timesheet **arrTimesheet, int dia, int *contadorTimesheets, int dias) {

    for (int i = 0; i < dias; i++) {
        if ((*arrTimesheet)[*contadorTimesheets].dias_scope[i].dia == dia) {
            puts("");
            puts("");
            puts("");
            return -1;
        }
    }
    return 0;


}

/**
 * Função que preenche o status para cada dia trabalhado, dia após dia selecionado
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param mes argumento que indica o mês em questão a ser tratado
 * @param contadorDias argumento que indica o indice de dias em que a contagem vai
 * @param dia argumento que indica o dia a ser preenchido com status
 */
int diaPorDia(Timesheet **arrTimesheet, int *contadorTimesheets, int mes, int contadorDias, int dia) {


    int ret;
    struct tm info; //a estrutura tm é uma estrutura pertencente á libraria time.h. Define detalhes de calendarização como os que se seguem.
    char buffer[80];

    info.tm_year = 2021 - 1900;
    info.tm_mon = mes - 1; //0 a 11 por isso retiro 1 - 1 a 12 (meses)
    info.tm_mday = dia; // dia di mes '1 2 3 /  31
    info.tm_hour = 0;
    info.tm_min = 0;
    info.tm_sec = 1;
    info.tm_isdst = -1;
    //info.tm_mon = 0          
    //info.tm_wday = 0 - 6;    // 0 domingo 1 Mon  6 sat 


    int estadonoDia;



    ret = mktime(&info); //a função mktime converte a estrutura que recebemos anteriormente (tm sobre o nome de info, com os nossos dados) para a nossa timezone. 
    if (ret == -1) { //como foram transformados dados, nao vai ser a timezone devolvida mas sim a data que definimos.
        printf("Error: unable to make time using mktime\n");
    } else {
        strftime(buffer, sizeof (buffer), "%c", &info);
        printf(buffer);
    }

    char nome[MAXNOME] = "Integral";
    char nome2[MAXNOME] = "Parcial";
    char nome3[MAXNOME] = "Falta";
    char nome4[MAXNOME] = "Folga";
    puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:"); //tipos de status a preencher no dia

    do {
        puts("Insira estado(1->4):");
        scanf("%d", &estadonoDia);
    } while (estadonoDia < 1 || estadonoDia > 4);


    switch (estadonoDia) {
        case 1:
            if (info.tm_wday == 0 || info.tm_wday == 6) { //se a opção for 1, integral e o 'week day' corresponder a 0 ou 6, insere no dados do fim de semana

                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome);
                (*arrTimesheet)[*contadorTimesheets].jornadaCompFDS++; //todos os dados são inseridos tanto nos detalhes de cada timesheet como nos detalhes do status do escopo de dias
                puts("Jornada Completa - Fim de semana");
            } else {

                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome); //senao integral normal
                (*arrTimesheet)[*contadorTimesheets].jornadaComp++;
                puts("Jornada Completa");
            }
            break;
        case 2:

            if (info.tm_wday == 0 || info.tm_wday == 6) { //se a opção for 2, parcial e o 'week day' corresponder a 0 ou 6, insere no dados do fim de semana
                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome2);
                (*arrTimesheet)[*contadorTimesheets].meiaJornFDS++;
                puts("Meia jornada - Fim de semana");
            } else {

                strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome2); //senao parcial normal
                (*arrTimesheet)[*contadorTimesheets].meiaJorn++;
                puts("Meia jornada");
            }
            break;
        case 3:

            (*arrTimesheet)[*contadorTimesheets].falta++;
            strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome3);
            puts("Falta");
            break;
        case 4:

            (*arrTimesheet)[*contadorTimesheets].folga++;
            strcpy((*arrTimesheet)[*contadorTimesheets].dias_scope[contadorDias].status, nome4);
            puts("Folga");
            break;
        default:
            break;

    }

}

/**
 * Função para consultas de Timesheets individualmente por utilizador. Todas as timesheets
 * desse utilizador serão vistas, caso existam, assim como o dia em específico preenchido 
 * e mostra se há dias em falta.
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void consultarTSutilizador(Timesheet **arrTimesheet, int *totalTimesheets) {
    int userCode, funcExiste = -1;
    puts("Indique o nr de Utilizador");
    scanf("%d", &userCode);


    for (int j = 0; j < *totalTimesheets; j++) {
        if ((*arrTimesheet)[j].funcCode == userCode) {
            funcExiste = 0;

            for (int k = 0; k < 31; k++) {

                if ((*arrTimesheet)[j].dias_scope[k].dia != 0) {
                    printf("Timesheet Nº: %d - Dia: %d/%d/2021  i: %d    status: %s \n", (*arrTimesheet)[j].timesheetCode, (*arrTimesheet)[j].dias_scope[k].dia, (*arrTimesheet)[j].mesTS, k, (*arrTimesheet)[j].dias_scope[k].status);
                }



            }
        }
    }

    if (funcExiste != 0) {
        puts("Erro; \n Funcionário não existe na lista;");
        puts("Erro; \n   ou sem Timesheet;");
    }

}

/**
 * Função de listagem de funcionários com direito a compensação.
 * O direito a compensação toma por base os fins de semana preenchidos.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void direitoCompensaçao(Timesheet **arrTimesheet, int *totalTimesheets) {

    printf("O direito de Compensação reserva-se aos funcionários que exerceram\n");
    printf("funções ao fim de semana, estando estas divididas em compensações \n");
    printf("totais ou parciais mediante o exercido. \n");

    for (int i = 0; i < *totalTimesheets; i++) {
        if ((*arrTimesheet)[i].timesheetCode != 0 && (*arrTimesheet)[i].jornadaCompFDS > 0 || (*arrTimesheet)[i].meiaJornFDS > 0) {
            printf("\nTimesheet ID: %d Mes: %d FuncID: %d  i: %d \nCompensações Totais: %d / Compensações Parciais: %d .\n\n\n", (*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, i, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].meiaJornFDS);

        }
    }
}

/**
 * Função de listagem de timesheets incompletas. Toma por iniciativa que a partir
 * de 25 dias a timesheet se encontra completa.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void timesheetsIncompletas(Timesheet **arrTimesheet, int *totalTimesheets) {

    printf("Timesheets Incompletas (caso existam):\n");
    puts("");

    for (int i = 0; i < *totalTimesheets; i++) {
        if (((*arrTimesheet)[i].jornadaCompFDS + (*arrTimesheet)[i].jornadaComp + (*arrTimesheet)[i].meiaJornFDS + (*arrTimesheet)[i].meiaJorn + (*arrTimesheet)[i].falta + (*arrTimesheet)[i].folga) < 25 && (*arrTimesheet)[i].funcCode > 0) {
            printf("Timesheet ID: %d Mes: %d FuncID: %d \nJornada Comp. F.semana: %d / Jornada Comp.: %d \nMeia Jornada F.semana: %d / Meia Jornada: %d \nFaltas: %d / Folgas: %d\n\n\n", (*arrTimesheet)[i].timesheetCode, (*arrTimesheet)[i].mesTS, (*arrTimesheet)[i].funcCode, (*arrTimesheet)[i].jornadaCompFDS, (*arrTimesheet)[i].jornadaComp, (*arrTimesheet)[i].meiaJornFDS, (*arrTimesheet)[i].meiaJorn, (*arrTimesheet)[i].falta, (*arrTimesheet)[i].folga);

        }
    }
    puts("");
    printf("--------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------\n");
    printf("No caso de existirem Timesheets incompletas, recomenda-se a sua \n");
    printf("reinserção no menu 'Gestão do Trabalho realizado (Timesheets)' \n");
    printf("Opção '4 - Recriar Timesheet', utilizando o código da Timesheet \n");
    printf("e respetivo código de funcionário. \n");
    printf("Timesheet é considerada completa com 25 ou mais dias preenchidos. \n");
    printf("--------------------------------------------------------------------\n");
    printf("--------------------------------------------------------------------\n");


}

/**
 * Função de re-preenchimento de alguma timesheet, ou mesmo para a apagar a mesma.
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param arrPessoa argumento que trás o apontador do array dinamico de Pessoa
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param contadorTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param totalFuncionarios argumento que trás o valor apontado deste contador dinâmico
 */
void refazerTimesheet(Timesheet **arrTimesheet, Pessoa **arrPessoa, int *totalTimesheets, int *contadorTimesheets, int *totalFuncionarios) {
    int timesheetNo, indiceTS;
    puts("Timesheet a recriar:");
    scanf("%d", &timesheetNo);

    indiceTS = possivelTimesheet(arrTimesheet, totalTimesheets, timesheetNo); //verifica a existencia da timesheet. Se existir recebe o seu indice no arrTimesheet.

    if (indiceTS != -1 && (*arrTimesheet)[indiceTS].funcCode > 0) {
        puts("******");
        printf("Se pretende realmente recriar a Timesheet que se segue de seguida,\nutilize o número de Funcionário indicado e respetivo\nmês nos passos seguintes para o seu desenvolvimento.\n");
        printf("Se pretender apagar, Quando questionado pelo Nº de Funcionário indique 0.\n");
        puts("******");
        printf("Funcionário nº: %d || Mês : %d \n\nReformular nova Timesheet:\n", (*arrTimesheet)[indiceTS].funcCode, (*arrTimesheet)[indiceTS].mesTS);
        puts("");
        puts("");
        (*arrTimesheet)[indiceTS].timesheetCode = 0;
        (*arrTimesheet)[indiceTS].mesTS = 0;
        (*arrTimesheet)[indiceTS].funcCode = 0;
        criarTimesheet(arrTimesheet, arrPessoa, totalTimesheets, contadorTimesheets, totalFuncionarios); //para refazer a timesheet, a antiga tomou valores '0' e é suposto criar uma nova utilizando os valores mostrados.
    } else {
        puts("Impossível recriar Timesheet;");
        puts("Possível razão: 1 - não existe;");
        puts("                2 - Funcionário apagado;");
    }

}

/**
 * Função de teste de existencia de timesheets, que se existindo, retorna o seu indice, senão,
 * retorna -1.
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 * @param timesheetNo nº da timesheet que a mesma recebe para por à prova.
 * @return indice da timesheet ou -1.
 */
int possivelTimesheet(Timesheet **arrTimesheet, int *totalTimesheets, int timesheetNo) {

    //int timesheetNo;
    for (int i = 0; i < *totalTimesheets; i++) {
        if ((*arrTimesheet)[i].timesheetCode == timesheetNo) {

            return i;
        }
    }
    return -1;
}

/**
 * Função para libertar o espaço ocupado no caso em questão
 * 
 * @param arrTimesheet argumento que trás o apontador do array dinamico de Timesheet
 * @param totalTimesheets argumento que trás o valor apontado deste contador dinâmico
 */
void freeCalloc(Timesheet **arrTimesheet, int *totalTimesheets) {
    for (int i = 0; i < *totalTimesheets; i++) {
        free((*arrTimesheet)[i].dias_scope);
        printf("livre %d \n", i);
    }
}