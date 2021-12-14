#define _CRT_SECURE_NO_WARNINGS
#include "locale"
#include "stdio.h"
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;


int NUM[] = {};


void BFS(int v, int **matrix,int size){
//    int s;
    queue<int> q;
    NUM[v] = 1;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        printf("%4i", v);
        for (int i = 0; i < size; i++) {
            if (matrix[v][i] == 1 && NUM[i] == 0) {
                q.push(i);
                NUM[i] = 1;
            }
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
    //сгенерирование матрицы
    printf("Сгенерированные матрицы:");
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = rand() % 2;
            printf("%3d,", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Введите вершину, с которой будет начинаться обход:  ");
    scanf("%d", &v);

    printf("\n");
    printf("\n""Результат:  ");

    while (NUM[v] != 1)
    {
        BFS(v,M,n);
    }
    printf("\n");

}
