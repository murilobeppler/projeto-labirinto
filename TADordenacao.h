#ifndef TAD_ORDENACAO_H
#define TAD_ORDENACAO_H

//funcao generica de algoritimo de ordenação usado para calcular tempo total - funções nao funcionando ainda

//typedef void (*funcaoSort)(int[], int);
//double tempoTotal(funcaoSort, int* v, int N);
//int **matrizCrescente(int linha, int coluna);
//int **matrizDecrescente(int linha, int coluna);


// algoritimos de ordenação
void MergeSort(int vetor[], int n);
void BubbleSort(int *v, int n);
void ShellSort(int *v, int n);
void InsertionSort(int *v, int n);
void SelectionSort(int *v, int n);
void HeapSort(int arr[], int n);
void QuickSortBasico(int v[], int esq, int dir);
void QuickSortAleatorio(int v[], int esq, int dir);
void QuickSortMedianaDeTres(int v[], int esq, int dir);
void QuickSortParticaoTres(int v[], int esq, int dir);

// algoritimo "auxiliares"
void swap(int *a, int *b);
void m_sort(int vetor[], int aux[], int esq, int dir);
void merge(int vetor[], int aux[], int esq, int meio, int dir);
void heapify(int arr[], int n, int i);
int partitionBasico(int v[], int esq, int dir);
int partitionAleatorio(int v[], int esq, int dir);
int encontrarMediana(int v[], int esq, int meio, int dir);
int partitionMediana(int v[], int esq, int dir);
void partition3(int v[], int esq, int dir, int *menor, int *maior);

// criações e exebição de vetor/matriz
int *vetorAleatorio(int n);
int **geraMatrizRand(int linha, int coluna);
void exibirMatriz(int **v, int linhas, int colunas);
void exibirVetor(int *v, int n);
int *vetorCrescente(int n);
int *vetorDecrescente(int n);
int *vetorRepeticoes(int n);


#endif // TAD_ORDENACAO_H