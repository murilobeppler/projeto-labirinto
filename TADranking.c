#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADranking.h"

int lerArquivo(char *nomeArquivo, Ranking *r) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return 0;
    }
    int x = 0;
    while (fscanf(arquivo, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d",r[x].nome, &r[x].area[0], &r[x].area[1], &r[x].area[2], &r[x].area[3], &r[x].area[4], &r[x].area[5], &r[x].area[6], &r[x].area[7], &r[x].area[8], &r[x].area[9], &r[x].tempo_total, &r[x].pontuacao) != EOF) {
        x++;
    }
  fclose(arquivo);
  return x;
}


void bubbleSortArea(Ranking *r, int n, int a) {
    int i, j;
    Ranking temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (r[j].area[a-1] > r[j+1].area[a-1]) {
                troca(r, j, j+1);
            }
        }
    }
}

void bubbleSortTempoTotal(Ranking *r, int n) {
    int i, j;
    Ranking temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (r[j].tempo_total > r[j+1].tempo_total) {
                troca(r, j, j+1);
            }
        }
    }
}

void bubbleSortPontuacao(Ranking *r, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (r[j].pontuacao < r[j+1].pontuacao) {
                troca(r, j, j+1);
            }
        }
    }
}
void bubbleSortNome(Ranking *r, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if ((strcmp(r[j].nome,r[j+1].nome) > 0)) {
                troca(r, j, j+1);
            }
        }
    }
}
void troca(Ranking *r, int i, int j){
  Ranking temp;
  temp = r[i];
  r[i] = r[j];
  r[j] = temp;
}
void escreverArquivo(char *nomeArquivo, Ranking r) {
    Ranking ra[10];
    int tamanhoarquivo = lerArquivo(nomeArquivo,ra);
    //printf("%d\n",tamanhoarquivo);
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Não foi possível criar o arquivo %s.\n", nomeArquivo);
        return;
    }
    int i = 0;
    if(tamanhoarquivo == 10) i = 1;
    for(; i < tamanhoarquivo; i++){
        fprintf(arquivo,  "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d\n", ra[i].nome,ra[i].area[0],ra[i].area[1],ra[i].area[2],ra[i].area[3],ra[i].area[4],ra[i].area[5],ra[i].area[6],ra[i].area[7],ra[i].area[8],ra[i].area[9],ra[i].tempo_total,ra[i].pontuacao);
    }
    fprintf(arquivo,  "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d\n", r.nome,r.area[0],r.area[1],r.area[2],r.area[3],r.area[4],r.area[5],r.area[6],r.area[7],r.area[8],r.area[9],r.tempo_total,r.pontuacao);

    fclose(arquivo);
}
void mostrarRanking(){
    Ranking ranking[10];
    int op,a,tamanhoarquivo;
    tamanhoarquivo = lerArquivo("Ranking.txt",ranking);

    //escolha do tipo do ranking
    if(tamanhoarquivo != 0){
    do{
        printf("Escolha qual ranking voce deseja ver:\n");
        printf("1 - Area\n");
        printf("2 - Tempo Total\n");
        printf("3 - Pontuacao\n");
        printf("4 - Sair\n");
        scanf("%d",&op);
    }while(op < 1 || op > 4);

    //ordena e mostra o tipo escolhido
    switch(op){
        case 1:
            printf("Digite o numero da area:");
            scanf("%d",&a);
            bubbleSortArea(ranking,tamanhoarquivo,a);
            for(int i = 0; i < tamanhoarquivo; i++){
                printf("Nome:%s Tempo da Area %d:%f\n",ranking[i].nome,a,ranking[i].area[a-1]);
            }
            break;
        case 2:
            bubbleSortTempoTotal(ranking,tamanhoarquivo);
            for(int i = 0; i < tamanhoarquivo; i++){
                printf("Nome:%s Tempo Total:%f\n",ranking[i].nome,ranking[i].tempo_total);
            }
            break;
        case 3:
            bubbleSortPontuacao(ranking,tamanhoarquivo);
            for(int i = 0; i < tamanhoarquivo; i++){
                printf("Nome:%s Pontuacao:%d\n",ranking[i].nome,ranking[i].pontuacao);
            }

            break;
    }
    }
}
