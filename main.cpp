
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <queue>
using namespace std;

int* vis;
int* exp1;
int* step;
int num;
int** m;
int rad = 10000;
int d = 0;
int a1;
void BFSD(int num);

void BFSD(int c) {
    int s;
    queue<int> q;
    vis[c] = 0;
    q.push(c);
    // printf("Порядок обхода: ");
    while (!q.empty()) {
        s = q.front();
        q.pop();
        //printf("%4i", s);
        for (int i = 0; i < num; i++) {
            if (m[s][i] > 0 && vis[i] > (m[s][i] + vis[s])) {
                q.push(i);
                vis[i] = m[s][i] + vis[s];
            }
        }
    }

    for (int i = 0; i < num; i++) {
        if (vis[i] > exp1[c]) {
            exp1[c] = vis[i];
        }
    }

    printf("\nРасстояние до вершин: ");
    for (int i = 0; i < num; i++) {
        printf("%4i", vis[i]);
    }

}

int main()
{
    setlocale(LC_ALL, "Rus");
    int generate;
    int c;
    printf("Введите размер массива: ");
    scanf("%i", &num);
    m = new int* [num];
    for (int i = 0; i < num; i++) {
        m[i] = new int[num];
    }
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                m[i][j] = 0;
            }
            else if (j > i) {
                generate = rand() % 100;
                if (generate >= 50) {
                    m[i][j] = rand() % 11;
                }
                else {
                    m[i][j] = 0;
                }
            }
            else {
                m[i][j] = m[j][i];
            }
        }
    }
    //вывод массива
    printf("Массив:");
    for (int i = 0; i < num; i++) {
        printf("\n");
        for (int j = 0; j < num; j++) {
            printf("%4i", m[i][j]);
        }
    }

    printf("\n\n");
    vis = new int[num];
    for (int i = 0; i < num; i++) {
        vis[i] = 10000;
    }

    exp1 = new int[num];
    for (int i = 0; i < num; i++) {
        exp1[i] = 0;
    }

    step = new int[num];
    for (int i = 0; i < num; i++) {
        step[i] = 0;
    }


    for (int i = 0; i < num; i++) {
        BFSD(i);
    }

    for (int i = 0; i < num; i++) {
        if (rad > exp1[i] && exp1[i] != 0) {
            rad = exp1[i];
        }
        if (d < exp1[i]) {
            d = exp1[i];
        }
    }
    printf("\n");

    printf("Диаметр = %4i\n", d);
    printf("Радиус = %4i\n", rad);

    printf("Переферийная вершина:\n");
    for (int i = 0; i < num; i++) {
        if (d = exp1[i]) {
            printf("%4i  ", i);
        }
    }
    printf("\n");

    printf("Центральная вершина:\n");
    for (int i = 0; i < num; i++) {
        if (rad = exp1[i]) {
            printf("%4i  ", i);
        }
    }
    printf("\n");

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (m[i][j] > 0) {
                step[i]++;
            }
        }
    }
    printf("\nИзолированная вершина:");
    for (int i = 0; i < num; i++) {
        if (step[i] == 0) {
            printf("%4i  ", i);
        }
    }

    printf("\nКонцевая вершина:");
    for (int i = 0; i < num; i++) {
        if (step[i] == 1) {
            printf("%4i  ", i);
        }
    }

    printf("\nДоминирующая вершина:");
    for (int i = 0; i < num; i++) {
        if (step[i] == (num-1)) {
            printf("%4i  ", i);
        }
    }
}
