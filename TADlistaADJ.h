#ifndef TAD_LISTAADJ_H
#define TAD_LISTAADJ_H
//constantes
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
//typedefs
typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoGrafo {
    TipoLista Adj [MAXNUMVERTICES];
    int NumVertices;
    int NumArestas;
} TipoGrafo;
typedef int TipoApontador;

typedef struct TipoItem {
    TipoValorVertice Vertice;
    TipoPeso Peso;
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;
typedef struct TipoLista {
    TipoApontador Primeiro, Ultimo;
} TipoLista;

//funcoes

//revisar FGVazio -- nao tem FLVazia
void FGVazio (TipoGrafo *Grafo);

// tava no slide mas nao sei o que eh esse "Insere" -- revisar
void InsereAresta (TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);

int ExisteAresta (TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo);

/*operadores para obter a lista de adjacentes*/
int ListaAdjVazia (TipoValorVertice *Vertice, TipoGrafo *Grafo);

TipoApontador PrimeiroListaAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo);

/*operadores para obter a lista de adjacentes*/
void ProxAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, int *FimListaAdj);

void LiberaGrafo (TipoGrafo *Grafo);

void ImprimeGrafo (TipoGrafo *Grafo);

#endif // TAD_LISTAADJ_H