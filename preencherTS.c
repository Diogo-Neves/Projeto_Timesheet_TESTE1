/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




/*int dias_total(int dias, Timesheet **arrTimesheet, Pessoa **arrPessoa, int mes, int contador){
    
    int dia;
    puts("Insira o dia a preencher:");
    scanf("%d", dia);
    
    (*arrTimesheet)[contador].mesTS = mes;
    
    (*arrTimesheet)[contador].dias_scope[0].dia = dia;
    
    //total = mes;

    mes--;
    int primeirodia = 1;
    int ret;
    struct tm info;
    char buffer[80];

    info.tm_year = 2021 - 1900;
    info.tm_mon = mes;              // 1 a 12 (meses)
    info.tm_mday = primeirodia;     // dia di mes '1 2 3 /  31
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
       //scanf("%s", &estadonoDia);
       
       //funcionarios->meuST1[contador2].meiaJorn++;
       //CRIAR CICLO PARA JORNADAS ESPECIFICAS
       
       
       //scanf("%d", &estadonoDia);
           
       
       /*do{
            printf("Introduza uma opcao: ");
            scanf("%d",&estadonoDia);
            //scanf("%*[^\n]"); scanf("%*c"); //limpar buffer do teclado
         }while (estadonoDia <0 || estadonoDia>4);
           
          switch(estadonoDia){
               case 1:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].jornadaComp++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 2:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].meiaJorn++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 3:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].falta++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               case 4:
                   timesheets->timesheets[timesheets->contadorTS].funTS[fixo].folga++;
                   primeirodia = primeirodia +1;
                   info.tm_mday   = primeirodia;
                   break;
               default:
                   break;
        } */
  //  }
    
//}

//int contagemDias(Timesheet **arrTimesheet){
    
//}*/