#include <stdio.h>

int main(){

    int tabuleiro [10][10] = {{0}};//inicializando tudo com 0
    int i, j;

      // adicionando navios (3)
    tabuleiro[1][1] = 3; // linha 2, coluna B
    tabuleiro[1][2] = 3; // linha 2, coluna C
    tabuleiro[1][3] = 3; // linha 2, coluna D

    tabuleiro[4][6] = 3; // linha 5, coluna G
    tabuleiro[5][6] = 3; // linha 6, coluna G
    tabuleiro[6][6] = 3; // linha 7, coluna G

    printf("*** TABULEIRO BATALHA NAVAL ***\n");
    
    //imprime cabeçalho das colunas
    printf("  "); 
    for(j=0; j < 10; j++){
        printf(" %C ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < 10; i++)//imprime os números da linhas 
    { printf("%2d ", i + 1);//imprime cabeçalho das linhas (1 a 10)
        for(j = 0; j < 10; j++)//imprime os números das colunas
        {
        printf(" %d ", tabuleiro[i][j]);
    }
        printf("\n"); // quebra de linha ao final de cada linha
}

    return 0;
}
