#include <stdio.h> 
#include <math.h> // biblioteca de matemática
#include <locale.h> // biblioteca de idiomas

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese"); // colocar a linguagem em português para validar os acentos e cedilha

int dia, mes, mes2, ano, dsem, csec, sec, sec2; 

    printf("Digite o dia (1-31): ");    
    scanf("%i", &dia);

// nas seções while vou validar as entradas do usuário e repetir a pergunta no caso de entradas inválidas
    while( dia < 1 || dia > 31 ){
        printf("Entrada inválida! Digite o dia (1-31): ");
        scanf("%i", &dia);
    }

    printf("Digite o mês (1-12): ");    
    scanf("%i", &mes);

    while( mes < 1 || mes > 12 ){
        printf("Entrada inválida! Digite o dia do mês (1-12): ");
        scanf("%i", &mes);
    }

    printf("Digite o ano: ");    
    scanf("%i", &ano);

    while( ano < 1800 || ano > 2199 ){
        printf("Ano fora do intervalo permitido! Digite o ano: ");
        scanf("%i", &ano);
    }

// identifico os 2 últimos algoritmos do mês e divido por 4 
    sec = ano % 100; 
    sec2 = sec / 4;


// na seção if identifico os anos não-bisextos e uso o switch-case para identificar os meses conforme a tabela do enunciado
    if (ano % 400 != 0) {
        switch (mes) {
            case 1:
                mes2 = 1;
            break;
            case 2:
                mes2 = 4;
            break;
            case 3:
                mes2 = 4;
            break;
            case 4:
                mes2 = 0;
            break;
            case 5:
                mes2 = 2;
            break;
            case 6:
                mes2 = 5;
            break;
            case 7:
                mes2 = 0;
            break;
            case 8:
                mes2 = 3;
            break;
            case 9:
                mes2 = 6;
            break;
            case 10:
                mes2 = 1;
            break;
            case 11: 
                mes2 = 4;
            break;
            case 12:
                mes2 = 6;
            break;
        } 

    } else { // em else seleciono os anos bisextos e novamente switch-case para identificar os meses conforme tabela
        switch (mes) {
            case 1:
                mes2 = 0;
            break;
            case 2:
                mes2 = 3;
            break;
        }
    }

// nas seções if identifico os intervalos dos anos conforme tabela do enunciado
    if(1800 < ano && ano < 1899){
        csec = 2;
    }
    if(1900 < ano && ano < 1999){
        csec = 0;
    }
    if (2000 < ano && ano < 2099){
        csec = 6;
    }
    if (2100 < ano && ano < 2199){
        csec = 4;
    }

    dsem = ( (sec + sec2 + mes2 + csec + dia) % 7 ); // fórmula para chegarmos ao número do dia da semana

    switch(dsem) { // seções switch-case para relacionar o número ao respectivo dia da semana e printar na tela o resultado para o usuário
        case 1:
            printf("Dia %d do %d de %d é Domingo\n", dia, mes, ano);
            break;
        case 2:
            printf("Dia %d do %d de %d é Segunda-feira\n", dia, mes, ano);
            break;
        case 3:
            printf("Dia %d do %d de %d é Terça-feira\n", dia, mes, ano);
            break;
        case 4:
            printf("Dia %d do %d de %d é Quarta-feira\n", dia, mes, ano);
            break;
        case 5:
            printf("Dia %d do %d de %d é Quinta-feira\n", dia, mes, ano);
            break;
        case 6:
            printf("Dia %d do %d de %d é Sexta-feira\n", dia, mes, ano);
            break;
        case 0:
            printf("Dia %d do %d de %d é Sábado\n", dia, mes, ano);
            break;
        
    }
    
    return 0; 
}
