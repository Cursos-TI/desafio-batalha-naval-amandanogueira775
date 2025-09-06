#include <stdio.h>


////Definindo duas constantes
#define TAM 10 //tamnaho do tabuleiro
#define NAVIO 3 //tamanho do navio
#define HAB 5 //tamanho da matriz de habilidade
#define CONE_AGUA 7 //quando o cone passa em cima da água.
#define CONE_NAVIO 8 //quando o cone atinge um navio.

int main(){

    int tabuleiro [TAM][TAM] = {{0}};//inicializando tudo com 0
    int i, j;
    
    
    //o zero representa a água e o três representa o navio
     
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
    
    //Matriz de habilidade cone
    int cone[HAB][HAB] = {0};
    
    int origemC = 7; //topo do cone na coluna
    int origemL = 7; //topo está na linha 7
    //exibição do ponto de origem do cone
        printf("\nHABILIDADE CONE: ponto de origem [%d][%d]\n", origemL, origemC);

    int inicio, fim;//Declara variáveis que vão definir, para cada linha do cone, quais colunas são atingidas
    
    //construindo o cone
    for (i = 0; i < HAB; i++) {//loop externo percorre as linhas
        //Define a largura do cone
        inicio = origemC - i;
        fim = origemC + i;
        // garante que não sai dos limites do tabuleiro
        if (origemL + i >= TAM) break;
        
        for (j = 0; j < TAM; j++) {//loop interno percorre as colunas
            // a condição seleciona apenas as colunas que pertencem ao cone naquela linha, ignorando as demais.
            if (j >= inicio && j <= fim) {
                // e já tem navio, marcamos como atingido
                if (tabuleiro[origemL + i][j] == NAVIO) {
                    tabuleiro[origemL + i][j] = CONE_NAVIO; // navio atingido
                } else {
                    tabuleiro[origemL + i][j] = CONE_AGUA; // área do cone
                }
            }
        }
    }
    // Matriz de habilidade Cruz
    int origemL2 = 2;   // linha central da cruz
    int origemC2 = 3;  // coluna central da cruz
    int raio = 3;  // número de elemento para cada direção

    printf("\n*** HABILIDADE CRUZ (origem [%d][%d]) ***\n", origemL2, origemC2);

    // Linha horizontal limitada pelo raio
    for (j = origemC2 - raio; j <= origemC2 + raio; j++) {
        if (j >= 0 && j < TAM) {  // garante que não sai do tabuleiro
            if (tabuleiro[origemL2][j] == NAVIO)
                tabuleiro[origemL2][j] = CONE_NAVIO;
            else
                tabuleiro[origemL2][j] = CONE_AGUA;
        }
    }

    // Coluna vertical limitada pelo raio
    for (i = origemL2 - raio; i <= origemL2 + raio; i++) {
        if (i >= 0 && i < TAM) {  // garante que não sai do tabuleiro
            if (tabuleiro[i][origemC2] == NAVIO)
                tabuleiro[i][origemC2] = CONE_NAVIO;
            else
                tabuleiro[i][origemC2] = CONE_AGUA;
        }
    }
   // Matriz de habilidade Octaedro
    int origemL3 = 4;   // linha central 
    int origemC3 = 8;  // coluna central 
    int raio3 = 1;  // número de elemento para cada direção

    printf("\n*** HABILIDADE OCTAEDRO (origem [%d][%d]) ***\n", origemL3, origemC3);

    // Linha horizontal limitada pelo raio
    for (j = origemC3 - raio3; j <= origemC3 + raio3; j++) {
        if (j >= 0 && j < TAM) {  // garante que não sai do tabuleiro
            if (tabuleiro[origemL3][j] == NAVIO)
                tabuleiro[origemL3][j] = CONE_NAVIO;
            else
                tabuleiro[origemL3][j] = CONE_AGUA;
        }
    }

    // Coluna vertical limitada pelo raio
    for (i = origemL3 - raio3; i <= origemL3 + raio3; i++) {
        if (i >= 0 && i < TAM) {  // garante que não sai do tabuleiro
            if (tabuleiro[i][origemC3] == NAVIO)
                tabuleiro[i][origemC2] = CONE_NAVIO;
            else
                tabuleiro[i][origemC3] = CONE_AGUA;
        }
    }
    

    printf("\n*** TABULEIRO BATALHA NAVAL ***\n");
    
    //imprime cabeçalho das colunas
    printf("   "); 
    for(j=0; j < TAM; j++){
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < TAM; i++)//imprime os números da linhas 
    { printf("%2d ", i + 0);//imprime cabeçalho das linhas (1 a 10)
        for(j = 0; j < TAM; j++)//imprime os números das colunas
        {    if (tabuleiro[i][j] == CONE_AGUA)
                printf(" 5 "); // cone (acerto vazio)
            else if (tabuleiro[i][j] == CONE_NAVIO)
                printf(" 3 "); // cone (acerto em navio)
            else if (tabuleiro[i][j] == NAVIO)
                printf(" 3 "); // navio intacto
            else
                printf(" 0 "); // água
        
    }
        printf("\n"); // quebra de linha ao final de cada linha
}
       


    return 0;
}