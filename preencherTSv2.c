

/*int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int contador){
    
    int dia, verificar, contadorDias = 0;
    puts("Insira o dia a preencher:");
    scanf("%d", dia);
    
    //contadorDias += 1;
    
    (*arrTimesheet)[contador].mesTS = mes;
    
    verificar = contagemDias(arrTimesheet, dia, contador);
    //devolve se já está preenchido
    
    
    //AGORA PRECISO DE VERIFICAR QUANTOS DIAS TEM
    contadorDias = retornarquantosdias(arrTimesheet, dia, contador);
    
    if(verificar != -1){
        (*arrTimesheet)[contador].dias_scope[contadorDias+1].dia = dia;
    }
    
    //(*arrTimesheet)[contador].dias_scope[contadorDias].dia = dia;
    
    //total = mes;

    mes--;
    int primeirodia = 1;
    int ret;
    struct tm info;
    char buffer[80];

    info.tm_year = 2021 - 1900;
    info.tm_mon = mes;              // 1 a 12 (meses)
    info.tm_mday = dia;     // dia di mes '1 2 3 /  31
    info.tm_hour = 0;
    info.tm_min = 0;
    info.tm_sec = 1;
    info.tm_isdst = -1;
    //info.tm_mon = 0          // 7 domingo 1 segunda

    
    
    int estadonoDia;
 
    //while(primeirodia <= dias){
        ret = mktime(&info);
        if( ret == -1 ) {
            printf("Error: unable to make time using mktime\n");
        } else {
      strftime(buffer, sizeof(buffer), "%c", &info );
      printf(buffer);
        //}
          
          
       puts("\n1:Integral\n2:Parcial\n3:falta\n4:folga:");
       
       contadorDias += 1;
       
    }
    
}

int contagemDias(Timesheet **arrTimesheet, int dia, int contador){
    
    for(int i = 0; i < 32; i++){
        if ((*arrTimesheet)[contador].dias_scope[i].dia == dia){
            puts("Dia já preenchido");
            return -1;
        }
    }
    
    
}

int retornarquantosdias(Timesheet **arrTimesheet, int dia, int contador){
    
    for(int i; i < 32; i++){
        if ((*arrTimesheet)[contador].dias_scope[i].dia < 0 && (*arrTimesheet)[contador].dias_scope[i].dia > 32 ){
            puts("Dia já preenchido");
            return i;
        }
    }
    
    return -1;
    
}*/