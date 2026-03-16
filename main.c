#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparacoes, trocas, movimentações;

void imprimirVetor(int v[], int n, int x){
    printf("[");
    for(int i = 0; i<n; i++){
        printf("%d", v[i]);
        if(i != n-1) printf(",");
    }
    printf("]");
    //x = 1: imprime metricas || x = 0: não imprime métricas
    if(x == 1){
        printf("\nComparacoes: %d\nTrocas: %d\n", comparacoes, trocas);
    }
}
void bubbleSort(int v[], int n){
    comparacoes = 0;
    trocas = 0;
    int i, j, aux;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            comparacoes++;
            if(v[j] > v[j+1]){
                trocas++;
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}

void bubbleSortOptimizado(int v[],int n){
    comparacoes = 0;
    trocas = 0;
    int i, j, aux, houveTrocas;
    for(i = 0; i < n-1; i++){
        houveTrocas = 0;
        for(j = 0; j < n-i-1; j++){
            comparacoes++;
            if(v[j] > v[j+1]){
                trocas++;
                houveTrocas = 1;
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
        if(houveTrocas == 0){
            break;
        }
    }
}

void bubbleSortOrdem( int v[], int n, int ordem){
    comparacoes = 0;
    trocas = 0;
    int i,j,aux,houveTrocas;

    for(i = 0; i < n-1; i++){
        houveTrocas = 0;
        for(j = 0; j < n-i-1; j++){
            comparacoes++;
            if(ordem == 1){
                if(v[j] > v[j+1]){
                trocas++;
                houveTrocas = 1;
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
            }
            else if(ordem == -1){
                if(v[j] < v[j+1]){
                trocas++;
                houveTrocas = 1;
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
                }
            }
        }
    }
}

void selectionSort(int v[], int n){
    comparacoes = 0;
    trocas = 0;
    int i, j, menor, aux;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j<n; j++){
            comparacoes++;
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            trocas++;
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

void selectionSortOrdem(int v[], int n, int ordem){
    int i,j, menor, maior, aux;
    if(!v || n <= 1) return;
    if(ordem == 1){
        for(i = 0; i < n-1; i++){
            menor = i;
            for(j = i+1; j<n; j++){
                comparacoes++;
                if(v[j] < v[menor]){
                    menor = j;
                }
            }
            if(i != menor){
                trocas++;
                aux = v[i];
                v[i] = v[menor];
                v[menor] = aux;
            }
        }
    }
    else if(ordem == -1){
            for(i = 0; i < n-1; i++){
                maior = i;
                for(j = i+1; j<n; j++){
                    comparacoes++;
                    if(v[j] > v[maior]){
                        maior = j;
                    }
                }
                if(i != maior){
                    trocas++;
                    aux = v[i];
                    v[i] = v[maior];
                    v[maior] = aux;
                }
            }
    }
}

void selectionSortTracado(int v[], int n){
    comparacoes = 0;
    trocas = 0;
    int i, j, menor, aux;
    printf("\nVetor inicial: ");
    imprimirVetor(v, n, 0);
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j<n; j++){
            comparacoes++;
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            trocas++;
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
        printf("\nEstado Atual do Vetor: ");
        imprimirVetor(v, n, 0);
        printf("    i = %d\n", i);
    }
}

void insertionSort(int *v, int n){
    comparacoes = 0;
    trocas = 0;
    int i, j, chave;
    for(i = 1; i<n;i++){
        chave = v[i];
        j = i;
        while (j > 0 && chave < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        if(j != i){
            movimentações++;
            v[j] = chave;
        }
    }
}

void insertionSortTracado(int *v, int n){
    comparacoes = 0;
    trocas = 0;
    int i, j, chave;
    printf("\nVetor inicial: ");
    imprimirVetor(v, n, 0);
    for(i = 1; i<n;i++){
        chave = v[i];
        j = i;
        while (j > 0 && chave < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        if(j != i){
            movimentações++;
            v[j] = chave;
        }
        printf("\nEstado Atual do Vetor: ");
        imprimirVetor(v, n, 0);
        printf("    i = %d\n", i);
    }
}

void insertionSortInstrumentado(int *v, int n){
    comparacoes = 0;
    movimentações = 0;
    int i, j, chave;
    
    printf("\nVETOR ANTES:");
    imprimirVetor(v, n, 0);
    for(i = 1; i<n;i++){
        chave = v[i];
        j = i;
        comparacoes++;
        while (j > 0 && chave < v[j-1]){
            movimentações++;
            v[j] = v[j-1];
            j--;
        }
        if(j != i){
            movimentações++;
            v[j] = chave;
        }
    }

    printf("\nVETOR DEPOIS: ");
    imprimirVetor(v, n, 0);
    printf("\nComparacoes: %d\nMovimentacoes: %d\n", comparacoes, movimentações);
}

void testarVetorBubble(int v[], int n, char nome, int x, int ordem){
    printf("\nVetor %c:\n", nome);
    imprimirVetor(v, n, 0);

    switch (x)
    {
    case 0:
        printf("\nBubble Sort Normal: ");
        bubbleSort(v, n);
        break;
    case 1:
        printf("\nBubble Sort Optimizado: ");
        bubbleSortOptimizado(v, n);
        break;
    case 2:
        if(ordem == 1) printf("\nBubble Sort Com Ordem (CRESCENTE): ");
        if(ordem == -1) printf("\nBubble Sort Com Ordem (DECRESCENTE): ");
        bubbleSortOrdem(v, n, ordem);
        break;   
    default:
        break;
    }
    printf("\n");
    imprimirVetor(v, n, 1);
}

int main(){

    int A[] = {1,4,7,12,15,21,25,32,44,47,50,52,59,61,63,67,74,79,84,95};//já ordenado
    int A2[] = {1,4,7,12,15,21,25,32,44,47,50,52,59,61,63,67,74,79,84,95};
    int B[] = {95,84,79,74,67,63,61,59,52,50,47,44,32,25,21,15,12,7,4,1};//Reverso
    int B2[] = {95,84,79,74,67,63,61,59,52,50,47,44,32,25,21,15,12,7,4,1};
    int C[] = {44,7,95,21,50,12,67,4,59,32,84,1,63,47,79,25,74,15,52,61};//Aleatório
    int C2[] = {44,7,95,21,50,12,67,4,59,32,84,1,63,47,79,25,74,15,52,61};
    int D[] = {};// n = 0
    int E[] = {1};// n = 1
    int F[] = {5,21,5,53,21,4,1,21}; // Repetidos
    int G[] = {3,-1,5,2,-6,1,-13, 4}; // Inteiros
    int H[] = {64, 25, 12, 22, 11}; // Questão 7
    int I[] = {5, 3, 4, 1, 2}; // Questão 12
    int ordenado[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int reverso[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int aleatorio[] = {14, 2, 19, 8, 1, 17, 5, 11, 20, 3, 7, 13, 16, 4, 9, 12, 18, 6, 10, 15};
    int v1[] = {14, 2, 19, 8, 1, 17, 5, 11, 20, 3, 7, 13, 16, 4, 9, 12, 18, 6, 10, 15};
    int v2[] = {14, 2, 19, 8, 1, 17, 5, 11, 20, 3, 7, 13, 16, 4, 9, 12, 18, 6, 10, 15};
    int ordenado2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int reverso2[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int aleatorio2[] = {14,2,19,8,1,17,5,11,20,3,7,13,16,4,9,12,18,6,10,15};
    int quase[] = {1,10,3,4,5,6,7,8,9,2,11,12,13,14,15,16,17,18,19,20};

    //BUBBLE SORT
    /*
    printf("====================TESTES BUBBLE SORT====================");
    testarVetorBubble(A, 20, 'A', 0, 1);
    testarVetorBubble(A2, 20, 'A', 1, 1);
    testarVetorBubble(B, 20, 'B', 0, 1);
    testarVetorBubble(B2, 20, 'B', 1, 1);
    testarVetorBubble(C, 20, 'C', 0, 1);
    testarVetorBubble(C2, 20, 'C', 1, 1);
    testarVetorBubble(D, 0, 'D', 2, 1);
    testarVetorBubble(E, 1, 'E', 2, -1);
    testarVetorBubble(F, 8, 'F', 2, 1);
    testarVetorBubble(G, 8, 'G', 2, -1);
    */

    //SELECTION SORT
    /*
    printf("====================TESTES SELECTION SORT====================");
    printf("\n### TESTE: SELECTION SORT TRAÇADO ###");
    selectionSortTracado(H, 5);
    printf("\n### TESTE: VETOR ORDENADO ###\n");
    selectionSort(ordenado, 20);
    imprimirVetor(ordenado, 20, 1);
    
    printf("### TESTE: VETOR REVERSO ###\n");
    selectionSort(reverso, 20);
    imprimirVetor(reverso, 20, 1);
    
    printf("### TESTE: VETOR ALEATÓRIO ###\n");
    selectionSort(aleatorio, 20);
    imprimirVetor(aleatorio, 20, 1);
    
    printf("\n### TESTE: ORDEM CRESCENTE (ordem = 1) ###\n");
    selectionSortOrdem(v1, 20, 1);
    imprimirVetor(v1, 20, 0);
    
    printf("\n\n### TESTE: ORDEM DECRESCENTE (ordem = -1) ###\n");
    selectionSortOrdem(v2, 20, -1);
    imprimirVetor(v2, 20, 0);
    */
    
    //INSERTION SORT
    /* 
    printf("\n### TESTE: INSERTION SORT TRAÇADO ###");
    insertionSortTracado(H, 5);
    printf("### TESTE 1: ORDENADO ###");
    insertionSortInstrumentado(ordenado2, 20);
    
    printf("\n### TESTE 2: REVERSO ###");
    insertionSortInstrumentado(reverso2, 20);
    
    printf("\n### TESTE 3: ALEATÓRIO ###");
    insertionSortInstrumentado(aleatorio2, 20);
    
    printf("\n### TESTE 4: QUASE ORDENADO ###");
    insertionSortInstrumentado(quase, 20);
    */
    return 0;
}