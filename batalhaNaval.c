#include <stdio.h>

int main(){

    int tabuleiro [10][10] = {{0}};//inicializando tudo com 0
    int i, j;

      // adicionando navios (3)
    tabuleiro[0][5] = 3; // linha 0, coluna F
    tabuleiro[0][6] = 3; // linha 0, coluna G
    tabuleiro[0][7] = 3; // linha 0, coluna H

    tabuleiro[2][5] = 3; // linha 2, coluna F
    tabuleiro[3][5] = 3; // linha 3, coluna F
    tabuleiro[4][5] = 3; // linha 4, coluna F

    printf("*** TABULEIRO BATALHA NAVAL ***\n");
    
    //imprime cabeçalho das colunas
    printf("  "); 
    for(j=0; j < 10; j++){
        printf(" %C ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < 10; i++)//imprime os números da linhas 
    { printf("%2d ", i + 0);//imprime cabeçalho das linhas (1 a 10)
        for(j = 0; j < 10; j++)//imprime os números das colunas
        {
        printf(" %d ", tabuleiro[i][j]);
    }
        printf("\n"); // quebra de linha ao final de cada linha
}

    return 0;
}
