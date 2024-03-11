#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "TADmatrizADJ.h"
#include "TADlistaADJ.h"
#include "TADordenacao.h"

//revisar o que era para ser o Mat "matriz" e como implementar

//funções
void FGVazio(TipoGrafo *Grafo) {
    int i, j;
    for (i = 0; i < Grafo->NumVertices; i++)
        for (j = 0; j < Grafo->NumVertices; j++)
            Grafo->Mat[i][j] = 0;
    //Grafo->NumArestas = 0;
}

void InsereAresta (TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo) {
    Grafo->Mat[*V1][*V2] = *Peso;
}

int ExisteAresta (TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo) {
    return (Grafo->Mat[Vertice1][Vertice2] > 0);
}

int ListaAdjVazia (TipoValorVertice *Vertice, TipoGrafo *Grafo) {
    TipoApontador Aux = 0;
    int ListaVazia = true;
    while (Aux < Grafo->NumVertices && ListaVazia)
        if (Grafo->Mat[*Vertice][Aux] > 0) ListaVazia = false;
        else Aux++;
    return (ListaVazia == true);
}

TipoApontador PrimeiroListaAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo) {
    TipoValorVertice Result;
    TipoApontador Aux = 0;
    int ListaVazia = true;
    while (Aux < Grafo->NumVertices && ListaVazia)
        if (Grafo->Mat[*Vertice][Aux] > 0) {
            Result = Aux;
            ListaVazia = false;
        } else Aux++;
    if (Aux == Grafo->NumVertices) {
        printf("Erro: Lista de Adjacencia Vazia (PrimeiroListaAdj)\n");
    } 
        return Result;
}

void ProxAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, int *FimListaAdj) {
    *Adj = *Prox;
    *Peso = Grafo->Mat[*Vertice][*Prox];
    (*Prox)++;
    while (*Prox < Grafo->NumVertices && Grafo->Mat[*Vertice][*Prox] == 0) (*Prox)++;
    if (*Prox == Grafo->NumVertices) *FimListaAdj = true;
}

//função de imprimir lista de adjacentes -- ex. Lista adjacentes de: 1   4 (1)

void RetiraAresta (TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo) {
   if (Grafo->Mat[*V1][*V2] == 0) {
         printf("Erro: Aresta nao existe\n");
    } else {
        *Peso = Grafo->Mat [*V1][*V2];
        Grafo->Mat[*V1][*V2] = 0;
   }
}

void LiberaGrafo (TipoGrafo *Grafo) {
//não faz nada no caso de matrizes de adjacencia
}

void ImprimeGrafo (TipoGrafo *Grafo) {
    int i, j;
    printf( " " );
    for (i = 0; i < Grafo->NumVertices; i++) 
        printf("%3d: ", i);
        printf("\n");
        for (i = 0; i < Grafo->NumVertices; i++) 
        { printf ("%3d",i);
            for (j = 0; j < Grafo->NumVertices; j++)
                printf("%3d", Grafo->Mat [i][j]);
            printf("\n");
        }
}