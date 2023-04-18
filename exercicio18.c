#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int valor;
} tdado;
//---------------------------------
typedef struct no{
	tdado dado;
	struct no *prox;
}tno;
//---------------------------------
typedef struct pilha{
	tno *topo;
}tPilha;
//---------------------------------
void inicializa(tPilha *p){
	p->topo = NULL;
}
//---------------------------------
int push(tPilha *p, tdado novoDado){
	tno *novo;
	novo = malloc(sizeof(tno));
	if(novo==NULL)
	   return 0;
	novo->dado = novoDado;// atribui o valor
	novo->prox = p->topo; // proximo é quem era o topo
	p->topo = novo;  
	return 1; 
}
//-----------------------------------
tdado pop(tPilha *p){
	tdado removido = p->topo->dado;
	tno *aux = p->topo; // guardar endereço para liberar memoria
	p->topo = p->topo->prox; // movendo topo para no de baixo
	free(aux); // libera area de memoria
	return removido;
}   
//-------------------------
int isEmpty(tPilha p){
	if(p.topo==NULL)
			return 1;
	else
			return 0;		
	//return p.topo==NULL?1:0;
}
//-------------------------
void mostraPilha(tPilha p){
	while(p.topo!=NULL){
		printf("| %d |",p.topo->dado.valor);
		p.topo = p.topo->prox;// desce para o prox				   
	}// fim while
	printf("\n");
}
//---------------------------
void mostraTopo(tPilha p){
	if(!isEmpty(p)){
		printf("Topo: %d",p.topo->dado.valor);
	}
}
//-------------------------------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I - Pilha Encadeada ****\n");
	printf("1-Push (Inserir)\n");
	printf("2-Pop (Remover)\n");
	printf("3-Peek (Olhar Topo)\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------------
int main(){
	tPilha p1;
	inicializa(&p1);
	tdado dado; // 
	int op;
	do{
		printf("Endereco do Topo:[%x]\n",p1.topo);
		mostraPilha(p1);
		op = menu();
		switch(op){
			case 1: printf("Valor para pilha:");
					scanf("%d",&dado.valor);
					push(&p1, dado );
			break;
			case 2:	if(!isEmpty(p1)){//se nao for vazio
						dado = pop(&p1);
						printf("Dado removido");
					}
					else
						printf("Pilha vazia\n");					
				break;
			case 3:	
					mostraTopo(p1);
				break;	
						
		}// fim switch
	    getch();// pausa
		system("cls");// limpa tela	
	}while(op!=0);
	return 0;                                
}


