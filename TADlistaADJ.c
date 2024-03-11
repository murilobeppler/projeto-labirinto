#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "TADmatrizADJ.h"
#include "TADlistaADJ.h"
#include "TADordenacao.h"

/*entram aqui os operadores FLVazia, Vazia, Insere, Retira e imprime*/

/*do TAD Lista de Apontadores do programa 3.4   ???*/

void FGVazio (TipoGrafo *Grafo) {
    int i;
    for (i = 0; i < Grafo->NumVertices; i++) {
        FLVazia(&Grafo->Adj[i]);
    }
}

void InsereAresta (TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo) {
    TipoItem x;
    x.Vertice = *V2;
    x.Peso = *Peso;
    Insere (&x, &Grafo->Adj[*V1]);
}

int ExisteAresta (TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo) {
    TipoApontador Aux;
    int EncontrouAresta = false;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
    while (Aux != NULL && EncontrouAresta == false) {
        if (Vertice2 == Aux->Item.Vertice) EncontrouAresta = true;
        else Aux = Aux->Prox;
    }
    return EncontrouAresta;
}

/*operadores para obter a lista de adjacentes*/
int ListaAdjVazia (TipoValorVertice *Vertice, TipoGrafo *Grafo) {
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo) {
    return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

/*operadores para obter a lista de adjacentes*/
void ProxAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, int *FimListaAdj) {
    //retorna Adj e Peso do Item apontado por Prox
    *Adj = (*Prox)->Item.Vertice;
    *Peso = (*Prox)->Item.Peso;
    *Prox = (*Prox)->Prox;
    if (*Prox == NULL) *FimListaAdj = true;
}

void LiberaGrafo (TipoGrafo *Grafo) {
    TipoApontador AuxAnterior, Aux;
    int i;
    for (i=0;i<Grafo->NumVertices;i++) {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro);
        //libera celula cabeca
        Grafo->Adj[i].Primeiro = NULL;
        while (Aux != NULL) {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            free(AuxAnterior);
        }
    }
}

void ImprimeGrafo (TipoGrafo *Grafo) {
    int i;
    TipoApontador Aux;
    for (i = 0; i < Grafo->NumVertices; i++) {
        printf("Vertice %2d: ", i);
        if (!Vazia (Grafo->Adj[i])) {
            Aux = Grafo->Adj[i].Primeiro->Prox;
            while (Aux != NULL) {
                printf("%3d (%d) ", Aux->Item.Vertice,Aux->Item.Peso);
                Aux = Aux ->Prox;
            }
        }
        printf("\n");
    }
}