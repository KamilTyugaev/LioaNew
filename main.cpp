#define _CRT_SECURE_NO_WARNINGS
#include "locale"
#include "stdio.h"
#include <locale.h>
#include <stdlib.h>
#include <iostream>


int NUM[6] = { 0,0,0,0,0,0 };



void DFS(int v, int **matrix,int size) {

    NUM[v] = 1;
    printf("%d", v);
    
    for (int i = 0; i < size; i++) {
        
            if (matrix [v][i] == 1 && NUM[i] == 0)
            {
                DFS(i, matrix,size);
            }
    }
}



int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    int v,n;
    printf("Введите размерность матрицы:  ");
    scanf("%d", &n);
    
    
    int** M;
    M = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)  // цикл по строкам
    {
        M[i] = (int*)malloc(n * sizeof(int));
    }

    //int M[6][6];
    
    printf("Сгенерированные матрицы:");
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = rand() % 2;
            printf("%3d,", M[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    printf("Введите вершину, с которой будет начинаться обход:  ");
    scanf("%d", &v);

    printf("\n");
    printf("Результат:  ");
    while (NUM[v] != 1)
    {
        DFS(v,M,n);
    }

}
