#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "TADmatrizADJ.h"
#include "TADlistaADJ.h"
#include "TADordenacao.h"

// funções comentadas que não funcionam ainda

/*double tempoTotal(funcaoSort Sort,int* v,int N){
time_t tempoInicio,tempoFinal;
double tempoTotal;

tempoInicio = clock();
Sort(v,N);
tempoFinal =clock();

tempoTotal=(double)(tempoFinal-tempoInicio)/CLOCKS_PER_SEC;
  return tempoTotal;
}*/

/*int **matrizCrescente(int linha, int coluna) {
  int i, j;

  int **v = (int **)malloc(linha * sizeof(int *));

  for (i = 0; i < linha; i++) {
    int j;
    int valorAtual = rand() % 10001;

    v[i] = (int *)malloc(coluna * sizeof(int));

    for (j = 0; j < coluna; j++) {
      v[i][j] = valorAtual;
      valorAtual +=
          rand() % 30; // Incremento aleatório para garantir ordem crescente
    }
  }
  return v;
}*/

/*int **matrizDecrescente(int linha, int coluna) {
  int i, j;

  int **v = (int **)malloc(linha * sizeof(int *));

  for (i = 0; i < linha; i++) {
    int valorAtual = rand() % 10001;
    v[i] = (int *)malloc(coluna * sizeof(int));

    for (j = 0; j < coluna; j++) {
      v[i][j] = valorAtual;
      valorAtual = valorAtual - (rand() % 30 + 1);
      // Incremento aleatório para garantir ordem decrescente
    }
  }
  return v;
}*/

// algoritimos de ordenação
// Heap Sort
void HeapSort(int arr[], int n) {
  // Constrói o heap (reorganiza o array)
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  // Extrai elementos do heap um por um
  for (int i = n - 1; i > 0; i--) {
    // Move a raiz (maior elemento) para o final do array
    swap(&arr[0], &arr[i]);

    // Chama heapify no heap reduzido
    heapify(arr, i, 0);
  }
}
void heapify(int arr[], int n, int i) {
  int maior = i;            // Inicializa o nó pai como o maior
  int esquerda = 2 * i + 1; // Índice da criança esquerda
  int direita = 2 * i + 2;  // Índice da criança direita

  // Se a criança esquerda é maior que o pai
  if (esquerda < n && arr[esquerda] > arr[maior]) {
    maior = esquerda;
  }

  // Se a criança direita é maior que o pai
  if (direita < n && arr[direita] > arr[maior]) {
    maior = direita;
  }

  // Se o maior não é o pai
  if (maior != i) {
    swap(&arr[i], &arr[maior]);
    // Chama recursivamente heapify para o subárvore afetada
    heapify(arr, n, maior);
  }
}

// Shell Sort
void ShellSort(int *v, int n) {
  int i, j, h = 1, aux;
  do
    h = h * 3 + 1;
  while (h < n);
  do {
    h /= 3;
    for (i = h; i < n; i++) {
      aux = v[i];
      j = i;
      while (v[j - h] > aux) {
        v[j] = v[j - h];
        j -= h;
        if (j < h)
          break;
      }

      v[j] = aux;
    }
  } while (h != 1);
}

// Insertion Sort
void InsertionSort(int *v, int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
    temp = v[i];
    for (j = i - 1; j >= 0 && v[j] > temp; j--) {
      v[j + 1] = v[j];
    }
    v[j + 1] = temp;
  }
}

// Selection Sort
void SelectionSort(int *v, int n) {
  int i, j, min, temp;

  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    temp = v[i];
    v[i] = v[min];
    v[min] = temp;
  }
}

// Merge Sort
void MergeSort(int vetor[], int n) {
  int aux[n];

  m_sort(vetor, aux, 0, n - 1);
}

void m_sort(int vetor[], int aux[], int esq, int dir) {
  int meio;
  if (dir > esq) {
    meio = (dir + esq) / 2;
    m_sort(vetor, aux, esq, meio);
    m_sort(vetor, aux, meio + 1, dir);
    merge(vetor, aux, esq, meio + 1, dir);
  }
}

void merge(int vetor[], int aux[], int esq, int meio, int dir) {
  int i, esq_fim, n;

  esq_fim = meio - 1;
  i = esq;
  n = dir - esq + 1;

  while (esq <= esq_fim && meio <= dir) {
    if (vetor[esq] <= vetor[meio])
      aux[i++] = vetor[esq++];
    else
      aux[i++] = vetor[meio++];
  }
  while (esq <= esq_fim)
    aux[i++] = vetor[esq++];
  while (meio <= dir)
    aux[i++] = vetor[meio++];
  for (i = 0; i < n; i++) {
    vetor[dir] = aux[dir];
    dir--;
  }
}

// Bubble Sort
void BubbleSort(int *v, int n) {
  int i, j, temp;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (v[j + 1] < v[j]) {
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

// Quick Sort
// basico
int partitionBasico(int v[], int esq, int dir) {
  int pivo = v[esq];
  int i = esq + 1;

  for (int j = esq + 1; j <= dir; j++) {
    if (v[j] < pivo) {
      swap(&v[i], &v[j]);
      i++;
    }
  }

  swap(&v[esq], &v[i - 1]);
  return i - 1;
}

void QuickSortBasico(int v[], int esq, int dir) {
  if (esq < dir) {
    int indicePivo = partitionBasico(v, esq, dir);

    QuickSortBasico(v, esq, indicePivo - 1);
    QuickSortBasico(v, indicePivo + 1, dir);
  }
}

// aleatorio
int partitionAleatorio(int v[], int esq, int dir) {
  // Escolhe um índice aleatório como pivô
  int indicePivo = esq + rand() % (dir - esq + 1);
  int valorPivo = v[indicePivo];

  // Move o pivô para o final do array
  swap(&v[indicePivo], &v[dir]);

  // Índice para rastrear a posição correta do pivô
  int i = esq - 1;

  // Particiona o array
  for (int j = esq; j < dir; j++) {
    if (v[j] <= valorPivo) {
      i++;
      swap(&v[i], &v[j]);
    }
  }

  // Move o pivô para a posição correta
  swap(&v[i + 1], &v[dir]);

  return i + 1;
}

// Função Quicksort principal
void QuickSortAleatorio(int v[], int esq, int dir) {
  if (esq < dir) {
    // Encontra o pivô e coloca os elementos menores à esquerda e os maiores à
    // direita
    int indicePivo = partitionAleatorio(v, esq, dir);

    // Recursivamente ordena as submatrizes à esquerda e à direita do pivô
    QuickSortAleatorio(v, esq, indicePivo - 1);
    QuickSortAleatorio(v, indicePivo + 1, dir);
  }
}

// Quick Sort Mediana de 3
int encontrarMediana(int v[], int esq, int meio, int dir) {
  if ((v[esq] <= v[meio] && v[meio] <= v[dir]) ||
      (v[dir] <= v[meio] && v[meio] <= v[esq]))
    return meio;
  else if ((v[meio] <= v[esq] && v[esq] <= v[dir]) ||
           (v[dir] <= v[esq] && v[esq] <= v[meio]))
    return esq;
  else
    return dir;
}

// Função para escolher a mediana de três como pivô e particionar o array
int partitionMediana(int v[], int esq, int dir) {
  // Escolhe a mediana de três como pivô
  int indicePivo = encontrarMediana(v, esq, (esq + dir) / 2, dir);
  int valorPivo = v[indicePivo];

  // Move o pivô para o final do array
  swap(&v[indicePivo], &v[dir]);

  // Índice para rastrear a posição correta do pivô
  int i = esq - 1;

  // Particiona o array
  for (int j = esq; j < dir; j++) {
    if (v[j] <= valorPivo) {
      i++;
      swap(&v[i], &v[j]);
    }
  }

  // Move o pivô para a posição correta
  swap(&v[i + 1], &v[dir]);

  return i + 1;
}

// Função Quicksort principal
void QuickSortMedianaDeTres(int v[], int esq, int dir) {
  if (esq < dir) {
    // Encontra a mediana de três e coloca os elementos menores à esquerda e os
    // maiores à direita
    int indicePivo = partitionMediana(v, esq, dir);

    // Recursivamente ordena as submatrizes à esquerda e à direita do pivô
    QuickSortMedianaDeTres(v, esq, indicePivo - 1);
    QuickSortMedianaDeTres(v, indicePivo + 1, dir);
  }
}

// Quick Sort 3 Partes
void partition3(int v[], int esq, int dir, int *menor, int *maior) {
  int pivo = v[dir];
  int i = esq - 1;
  int j = esq - 1;
  int k = dir;

  while (j + 1 < k) {
    if (v[j + 1] < pivo) {
      swap(&v[i + 1], &v[j + 1]);
      i++;
      j++;
    } else if (v[j + 1] == pivo) {
      j++;
    } else {
      swap(&v[j + 1], &v[k]);
      k--;
    }
  }

  swap(&v[k], &v[dir]); // Move o pivo para a posição correta

  *menor = i + 1;
  *maior = j;
}

// Função Quicksort de partição em três vias
void QuickSortParticaoTres(int v[], int esq, int dir) {
  if (esq < dir) {
    int menor, maior;
    partition3(v, esq, dir, &menor, &maior);

    // Recursivamente ordena as submatrizes à esquerda e à direita do pivo
    QuickSortParticaoTres(v, esq, menor - 1);
    QuickSortParticaoTres(v, maior + 1, dir);
  }
}

// auxiliares e criação e exibição de vetores
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void exibirVetor(int *v, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("%6d ", v[i]);
  }
}

void exibirMatriz(int **v, int linhas, int colunas) {
  int i, j;

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      printf("%6d ", v[i][j]);
    }
    printf("\n");
  }
}


int **geraMatrizRand(int linha, int coluna) {
  int n, i, j;

  int **v = (int **)malloc(linha * sizeof(int *));

  for (i = 0; i < coluna; i++) {
    n = rand() % 10000;
    v[i] = (int *)malloc(coluna * sizeof(int));
    for (j = 0; j < linha; j++) {
      v[j][i] = n;
    }
  }
  return v;
}

int *vetorAleatorio(int n) {
  int i;
  int *v = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    v[i] = rand() % 100000;
  }
  return v;
}

int *vetorCrescente(int n){
  int i;
  int *v = (int *)malloc(n * sizeof(int));
  for (i=0;i<n;i++){
      v[i] = i+1;
  }
  return v; 
}

int *vetorDecrescente(int n){
  int i;
  int *v = (int *)malloc(n * sizeof(int));
  for (i=0;i<n;i++){
      v[i] = n-i;
  }
  return v; 
}

int *vetorRepeticoes(int n){
  int i;
  int *v = (int *)malloc(n * sizeof(int));
  for (i=0;i<n;i++) {
      v[i] = rand() % 50;
  }
  return v; 
}
