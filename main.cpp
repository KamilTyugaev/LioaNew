
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <queue>
using namespace std;

int* NUM;
int num;
int** matrix;
void BFSD(int num);

void BFSD(int v) {
//    int s;
    queue<int> q;
    NUM[v] = 0;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        printf("%4i", v);
        for (int i = 0; i < num; i++) {
            if (matrix[v][i] > 0 && NUM[i] > (matrix[v][i] + NUM[v])) {
                q.push(i);
                NUM[i] = matrix[v][i] + NUM[v];
            }
        }
    }
    printf("\nРасстояние до вершин: ");
    for (int i = 0; i < num; i++) {
        printf("%4i", NUM[i]);
    }

}

int main()
{
    setlocale(LC_ALL, "Rus");
    int generate;
    int c;
    printf("Введите размер массива: ");
    scanf("%i", &num);
    matrix = new int* [num];
    for (int i = 0; i < num; i++) {
        matrix[i] = new int[num];
    }
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                matrix[i][j] = 0;
            }
            else if (j > i) {
                generate = rand() % 110;
                if (generate >= 50) {
                    matrix[i][j] = rand() % 10;
                }
                else {
                    matrix[i][j] = 0;
                }
            }
            else {
                matrix[i][j] = matrix[j][i];
            }
        }
    }
    //вывод массива
    printf("Массив:");
    for (int i = 0; i < num; i++) {
        printf("\n");
        for (int j = 0; j < num; j++) {
            printf("%4i", matrix[i][j]);
        }
    }
    NUM = new int[num];
    for (int i = 0; i < num; i++) {
        NUM[i] = 10000;
    }
    printf("\nВведите вершину начала обхода: ");
    scanf("%i", &c);
    printf("\n");
    BFSD(c);
}
