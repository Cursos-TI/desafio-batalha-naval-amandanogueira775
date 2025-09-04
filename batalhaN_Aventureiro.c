#include <stdio.h>

////Definindo duas constantes
#define TABULEIRO 10 //tamnaho do tabuleiro
#define NAVIO 3 //tamanho do navio

int main(){

    int tabuleiro [TABULEIRO][TABULEIRO] = {{0}};//inicializando tudo com 0
    int i, j;
    int soma ;
    
    //o zero representa a água e o três representa o navio

      // adicionando navios (3)
    
      
         // === POSICIONANDO 4 NAVIOS ===
    // Dois em linha reta
    // Horizontal (linha 0, colunas 5–7)
    for (j = 5; j < 8; j++) {
        tabuleiro[0][j] = NAVIO;
    }
    // Vertical (coluna 5, linhas 2–4)
    for (i = 2; i < 5; i++) {
        tabuleiro[i][5] = NAVIO;
    }

    // Dois em diagonal
    // Diagonal principal ↘ (começando em [1][1], tamanho 3)
    for (i = 0; i < 3; i++) {
        tabuleiro[1 + i][1 + i] = NAVIO;
    }
    // Diagonal secundária ↙ (começando em [7][2], tamanho 3)
    for (i = 0; i < 3; i++) {
        tabuleiro[7 + i][2 - i] = NAVIO;
    }

    printf("*** TABULEIRO BATALHA NAVAL ***\n");
    
    //imprime cabeçalho das colunas
    printf("   "); 
    for(j=0; j < TABULEIRO; j++){
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < TABULEIRO; i++)//imprime os números da linhas 
    { printf("%2d ", i + 1);//imprime cabeçalho das linhas (1 a 10)
        for(j = 0; j < TABULEIRO; j++)//imprime os números das colunas
        {
        printf(" %d ", tabuleiro[i][j]);//exibir o tabuleiro
    }
        printf("\n"); // quebra de linha ao final de cada linha
}
       
    

    return 0;
}