#ifndef TAD_MATRIZADJ_H
#define TAD_MATRIZADJ_H
//constantes
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
//typedefs
typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoGrafo {
    TipoPeso Mat [MAXNUMVERTICES] [MAXNUMVERTICES];
    int NumVertices;
    int NumArestas;
} TipoGrafo;

//funções
void FGVazio(TipoGrafo *Grafo);

void InsereAresta (TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);

int ExisteAresta (TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo);

/*operadores para obter a lista de adjacentes*/
int ListaAdjVazia (TipoValorVertice *Vertice, TipoGrafo *Grafo);

TipoApontador PrimeiroListaAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo);

void ProxAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, int *FimListaAdj);

//função de imprimir lista de adjacentes -- ex. Lista adjacentes de: 1   4 (1)

void RetiraAresta (TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);

void LiberaGrafo (TipoGrafo *Grafo);

void ImprimeGrafo (TipoGrafo *Grafo);

#endif // TAD_MATRIZADJ_H