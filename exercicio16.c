#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int topo;
    int dados[MAX];
} tpilha;
//----------------------------
void inicializar(tpilha *p) {
    p->topo = -1;
}
//----------------------------
int isEmpty(tpilha *p) {
    return p->topo == -1;
}
//----------------------------
int push(tpilha*p, int dado) {
    if (p->topo == MAX - 1) {
        return 0;
    } else {
        p->topo++;
        p->dados[p->topo] = dado;
        return 1;
    }
}
//----------------------------
int pop(tpilha *p) {
    if (isEmpty(p)) {
        return -1;
    } else {
        int dado = p->dados[p->topo];
        p->topo--;
        return dado;
    }
}
//----------------------------
void converterParaBase(int num, int base) {
    tpilha p;
    inicializar(&p);
    while (num > 0) {
        int resto = num % base;
        push(&p, resto);
        num /= base;
    }
    printf("O numero na base %d: ", base);
    while (!isEmpty(&p)) {
        printf("%d", pop(&p));
    }
}
//----------------------------
int main() {
    int num, base;
    printf("Digite um numero decimal: ");
    scanf("%d", &num);
    printf("Digite uma base de 2 a 8: ");
    scanf("%d", &base);
    converterParaBase(num, base);
    printf("\n");
    return 0;
}
