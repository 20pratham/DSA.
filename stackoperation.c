

#include <stdio.h>

#define MAXN 100     


#define PUSH(stack, top, value)  do { stack[++(top)] = (value); } while (0)
#define POP(stack, top)          (stack[(top)--])
#define TOP(stack, top)          (stack[(top)])

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN) return 0;

    int st[MAXN];   
    int aux[MAXN];  
    int topSt  = -1;
    int topAux = -1;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        PUSH(st, topSt, x);
    }

    while (topSt >= 0) {
        int temp = POP(st, topSt);

        while (topAux >= 0 && TOP(aux, topAux) > temp)   
            PUSH(st, topSt, POP(aux, topAux));

        PUSH(aux, topAux, temp);
    }

    while (topAux >= 0)
        PUSH(st, topSt, POP(aux, topAux));

    int first = 1;
    while (topSt >= 0) {
        if (!first) putchar(' ');
        printf("%d", POP(st, topSt));
        first = 0;
    }
    putchar('\n');
    return 0;
}