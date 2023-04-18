#include <stdio.h>
#define MAX 5
typedef struct{
   int valor;
} tdado;
//------------------------
typedef struct no {
    tdado dado;
    struct no* prox;
} tno;
//-----------------------
typedef struct{
	tno* inicio;
    tno* fim;
}tfila;
//------------------------
void inicializa(tfila *f){
	f->inicio = NULL;
	f->fim = NULL;
}
//------------------------
int enqueue(tfila *f, tdado item){	
	tno* novo;
    novo = malloc(sizeof(tno));
    if (novo == NULL)
        return 0;
    novo->dado = item;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    return 1;
}
//--------------------------
tdado dequeue(tfila *f){
	tdado removido = f->inicio->dado;
    tno* aux = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) 
        f->fim = NULL;
    free(aux);
    return removido;
}
//--------------------------
void mostraFila(tfila f){
	if(isEmpty(f) == 1)
		printf("Fila Vazia!");
	else{
		tno* atual = f.inicio;
		printf("Inicio:%d | Fim: %d\n",f.inicio,f.fim);
		while (atual != NULL) {
	        printf("%d | ", atual-> dado);
	        atual = atual->prox;
	    }	
		printf("\n");
	}
}
//-------------------------
int isEmpty(tfila f) {
    if (f.inicio == NULL)
        return 1;
    else
        return 0;
}
//------------------------
int ultimoValor(tfila f) {
    if (isEmpty(f) == 1) {
        printf("Fila vazia\n");
        return -1;
    }else {
        printf("%d ",f.fim->dado.valor);
        return 0;
    }
}
//------------------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I - Fila Estatica ****\n");
	printf("1-Enqueue (Inserir)\n");
	printf("2-Dequeue (Remover)\n");
	printf("3-Ultimo valor\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------
int main(){
	tfila f1;
	tdado x;
	int op, numero;
	inicializa(&f1);
	do{
		mostraFila(f1);
		op = menu();
		switch(op){
			case 1: printf("Entre com um valor:");
					scanf("%d",&x);
					enqueue(&f1,x); 
					printf("Dado inserido :)\n");
			break;
			case 2: if(!isEmpty(f1)) {
				       x = dequeue(&f1); 
			 		   printf("Dado removido:%s:%d\n",x);
				     }
				     else
				       printf("Fila vazia!:(\n");
				break;
			case 3:
				ultimoValor(f1);
			break;	
			case 0: printf("Saindo .... ;)\n");	    
		}
	    getch(); 
	    system("cls");
	}while(op!=0);

	return 0;
}
