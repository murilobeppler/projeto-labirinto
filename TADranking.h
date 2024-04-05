#ifndef TADRANKING_H_INCLUDED
#define TADRANKING_H_INCLUDED

typedef struct {
    char nome[50];
    double area[10];
    double tempo_total;
    int pontuacao;
} Ranking;

int lerArquivo(char *nomeArquivo, Ranking *r);
void escreverArquivo(char *nomeArquivo, Ranking r);
void mostrarRanking();

#endif // TADRANKING_H_INCLUDED
