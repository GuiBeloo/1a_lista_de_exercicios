#include <stdio.h>
#include <stdlib.h>
int comparacoes, trocas;

void limparTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

typedef struct metrics{
    long long comparacoes;
    long long trocas;
} Metrics;


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


void bubble_sort(){

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

    void bubbleSortOptimizadoFloat(float v[],int n){
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

    float calcula_media(float v[], int n){
        int i, soma = 0;
        float media;
        for (i = 0; i <n ;i++){
            soma += v[i];
        }
        media = soma / n;
        return media;
    }

    int ordenado[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int ordenado2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int reverso[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int reverso2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int aleatorio[] = {14, 2, 19, 8, 1, 17, 5, 11, 20, 3, 7, 13, 16, 4, 9, 12, 18, 6, 10, 15};
    int aleatorio2[] = {14, 2, 19, 8, 1, 17, 5, 11, 20, 3, 7, 13, 16, 4, 9, 12, 18, 6, 10, 15};
    printf("===========TESTE===========\n\n");
    //QUESTAO 2
    printf("VETOR ORDENADO ANTES: ");
    imprimirVetor(ordenado, 20, 0);
    bubbleSort(ordenado, 20);
    printf("\n\nVETOR ORDENADO APOS BUBBLE SORT SIMPLES: ");
    imprimirVetor(ordenado,20,1);
    printf("\nVETOR ORDENADO APOS BUBBLE SORT OPTIMIZADO: ");
    bubbleSortOptimizado(ordenado2, 20);
    imprimirVetor(ordenado2,20,1);
    printf("\n");
    printf("VETOR REVERSO ANTES: ");
    imprimirVetor(reverso, 20, 0);
    bubbleSort(reverso, 20);
    printf("\n\nVETOR REVERSO APOS BUBBLE SORT SIMPLES: ");
    imprimirVetor(reverso,20,1);
    printf("\nVETOR REVERSO APOS BUBBLE SORT OPTIMIZADO: ");
    bubbleSortOptimizado(reverso2, 20);
    imprimirVetor(reverso2,20,1);
    printf("\n");
    printf("VETOR ALEATORIO ANTES: ");
    imprimirVetor(aleatorio, 20, 0);
    bubbleSort(aleatorio, 20);
    printf("\n\nVETOR ALEATORIO APOS BUBBLE SORT SIMPLES: ");
    imprimirVetor(aleatorio,20,1);
    printf("\nVETOR ALEATORIO APOS BUBBLE SORT OPTIMIZADO: ");
    bubbleSortOptimizado(aleatorio2, 20);
    imprimirVetor(aleatorio2,20,1);
    printf("\n");
    printf("DISCUSSAO: O CASO QUE GEROU MENOS COMPARACOES FOI O VETOR ORDENADO COM APOS SER APLICADO O BUBBLE SORT COM EARLY STOP!\n\n");

    //QUESTÃO 3
    float notas[50] = {8.5, 7.0, 4.5, 9.2, 3.1, 6.8, 5.5, 10.0, 2.4, 7.8, 6.0, 4.2, 8.9, 9.5, 5.0, 3.7, 7.3, 8.1, 1.5, 6.4, 9.0, 5.8, 4.9, 7.7, 8.3, 2.9, 6.1, 5.4, 9.8, 4.0, 7.2, 3.5, 8.8, 6.6, 5.1, 1.0, 7.9, 9.3, 4.7, 6.2, 8.0, 5.5, 3.3, 7.5, 9.1, 4.4, 6.9, 8.7, 2.2, 10.0};
    bubbleSortOptimizadoFloat(notas, 50);
    printf("TOP 3 NOTAS:\n1- %.1f\n2- %.1f\n3- %.1f\n ", notas[49], notas[48], notas[47]);
    float media = calcula_media(notas, 50);
    printf("Media: %.2f\n", media);

    //QUESTÃO 4
    int D[] = {};// n = 0
    int E[] = {1};// n = 1
    int F[] = {5,21,5,53,21,4,1,21}; // Repetidos
    int G[] = {3,-1,5,2,-6,1,-13, 4}; // Inteiros
    printf("\nVETOR n = 0 ANTES: ");
    imprimirVetor(D, 0, 0);
    printf("\nDEPOIS: ");
    bubbleSortOrdem(D, 0, 1);
    imprimirVetor(D, 0, 0);
    printf("\nVETOR n = 1 ANTES: ");
    imprimirVetor(E, 1, 0);
    printf("\nDEPOIS: ");
    bubbleSortOrdem(E, 1, -1);
    imprimirVetor(E, 1, 0);
    printf("\nVETOR COM REPETIDOS ANTES: ");
    imprimirVetor(F, 8, 0);
    printf("\nDEPOIS: ");
    bubbleSortOrdem(F, 8, 1);
    imprimirVetor(F, 8, 0);
    printf("\nVETOR DE INTEIROS ANTES: ");
    imprimirVetor(G, 8, 0);
    printf("\nDEPOIS: ");
    bubbleSortOrdem(G, 8, -1);
    imprimirVetor(G, 8, 0);

}


void selection_sort(){
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


    int vazio[] = {};
    int unico[] = {7};
    int ordenado[] = {1,2,3,4,5};
    int inverso[] = {5,4,3,2,1};
    int repetidos[] = {3,1,3,2,3};

    printf("===========TESTE===========\n\n");
    printf("\nVETOR n = 0 ANTES: ");
    imprimirVetor(vazio, 0, 0);
    printf("\nDEPOIS: ");
    selectionSort(vazio, 0);
    imprimirVetor(vazio, 0, 0);
    printf("\nVETOR n = 1 ANTES: ");
    imprimirVetor(unico, 1, 0);
    printf("\nDEPOIS: ");
    selectionSort(unico, 1);
    imprimirVetor(unico, 1, 0);
    printf("\nVETOR ORDENADO ANTES: ");
    imprimirVetor(ordenado, 5, 0);
    printf("\nDEPOIS: ");
    selectionSort(ordenado, 5);
    imprimirVetor(ordenado, 5, 0);
    printf("\nVETOR INVERSO ANTES: ");
    imprimirVetor(inverso, 5, 0);
    printf("\nDEPOIS: ");
    selectionSort(inverso, 5);
    imprimirVetor(inverso, 5, 0);
     printf("\nVETOR COM INVERSO ANTES: ");
    imprimirVetor(repetidos, 5, 0);
    printf("\nDEPOIS: ");
    selectionSort(repetidos, 5);
    imprimirVetor(repetidos, 5, 0);

    int teste[] = {23,54,2,1,43,35,9,21,15,20};
    int teste1[] = {23,54,2,1,43,35,9,21,15,20};
    printf("\n\nQUESTAO 2:\nVETOR TESTE ANTES: ");
    imprimirVetor(teste, 10, 0);
    bubbleSortOptimizado(teste, 10);
    printf("\nVETOR APOS BUBBLE SORT OPTIMIZADO: ");
    imprimirVetor(teste, 10, 1);
    selectionSort(teste1, 10);
    printf("VETOR APOS SELECTION SORT: ");
    imprimirVetor(teste1, 10, 1);
    printf("\nMenos trocas: Selection Sort. Ele so troca uma vez por rodada. O Bubble troca a cada par errado\n");
    printf("Mais comparacoes: Selection Sort. Ele sempre olha o vetor todo. O Bubble com early stop para assim que percebe que ja esta ordenado\n");





}

void insertion_sort(){
    void insertionSort(int *v, int n){
        int i,j;
        int chave;

        for(i = 1; i < n; i++){

            chave = v[i];
            j = i;
            while( j > 0 && chave < v[j-1]){
                v[j] = v[j-1];
                j--;
            }

            v[j] = chave;
        }
    }

    void insertionSortPassoAPasso(int *v, int n){
        int i,j;
        int chave;

        for(i = 1; i < n; i++){

            chave = v[i];
            j = i;
            printf("\ni=%d, chave=%d | antes: ", i, chave);
            imprimirVetor(v, n, 0);
            while( j > 0 && chave < v[j-1]){
                v[j] = v[j-1];
                j--;
            }
            v[j] = chave;
            printf("\ni=%d, chave=%d | depois: ", i, chave);
            imprimirVetor(v, n, 0);
        }
    }


     void insertionSortMetrics(int *v, int n, Metrics* m){
            int i,j;
            int chave;
            m->comparacoes = 0;
            m->trocas = 0;

            for(i = 1; i < n; i++){

                chave = v[i];
                j = i;

                m->comparacoes++;
                while( j > 0 && chave < v[j-1]){
                    v[j] = v[j-1];
                    m->trocas++;
                    j--;
                }

                v[j] = chave;
                m->trocas++;
            }
        }



    printf("===========TESTE===========\n\n");
    int A[] = {5, 2, 4, 6, 1, 3};
    int B[] = {1, 2, 3, 4, 5, 6};
    int C[] = {6, 5, 4, 3, 2, 1};

    printf("\nVetor A antes: ");
    imprimirVetor(A, 6, 0);
    printf("\nVetor A ordenado: ");
    insertionSort(A, 6);
    imprimirVetor(A, 6, 0);
    printf("\nVetor B antes: ");
    imprimirVetor(B, 6, 0);
    printf("\nVetor B ordenado: ");
    insertionSort(B, 6);
    imprimirVetor(B, 6, 0);

    printf("\nVetor C antes: ");
    imprimirVetor(C, 6, 0);
    printf("\nVetor C ordenado: ");
    insertionSort(C, 6);
    imprimirVetor(C, 6, 0);

    int D[] = {5, 2, 4, 6, 1, 3};

    printf("\n\nVetor D:");
    insertionSortPassoAPasso(D, 6);

    int E[] = {5, 2, 4, 6, 1, 3};
    int F[] = {1, 2, 3, 4, 5, 6};
    int G[] = {6, 5, 4, 3, 2, 1};
    Metrics metrica;

    insertionSortMetrics(E, 6, &metrica);
    printf("\n\nCaso A: comparacoes = %d, movimentacao = %d\n", metrica.comparacoes, metrica.trocas);

    insertionSortMetrics(F, 6, &metrica);
    printf("Caso B: comparacoes = %d, movimentacao = %d\n", metrica.comparacoes, metrica.trocas);

    insertionSortMetrics(G, 6, &metrica);
    printf("Caso C: comparacoes = %d, movimentacao = %d\n", metrica.comparacoes, metrica.trocas);

}

int main(){
    int x;
    while (1)
    {
        printf("======BEM VINDO A EXECUCAO DAS 3 ATIVIDADES SEMANAIS( BUBBLE, SELECTION, INSERTION )======\nSelecione qual deseja executrar:\n1- Bubble sort\n2- Selection sort\n3- Insertion Sort\n4- Sair\n");
        scanf("%d", &x);

        limparTerminal();
        switch (x)
        {
        case 1:
            bubble_sort();
            system("PAUSE");
            limparTerminal();
            break;

        case 2:
            selection_sort();
            system("PAUSE");
            limparTerminal();
            break;

        case 3:
            insertion_sort();
            system("PAUSE");
            limparTerminal();
            break;
        case 4:
            exit(0);
        default:
            limparTerminal();
            break;
        }

    }



    return 0;
}
