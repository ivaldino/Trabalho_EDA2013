#include <stdio.h>
#include <stdlib.h>

typedef struct _dados{
	int i;
}Dados;

typedef struct _tree{
	Dados *dados;
	struct _tree *esq;
	struct _tree *dir;
}Tree;

void inserir(Tree ** noh, Dados *reg);
unsigned short maiorNoh(register unsigned short esq, register unsigned short dir);
void mostrarUm(Tree * noh);
void pre_ordem(Tree * noh);
void in_ordem(Tree * noh);
void pos_ordem(Tree * noh);
unsigned short profundidade(Tree * noh);
unsigned int contar_folhas(Tree * noh);
void mostrar_folhas(Tree * noh);

void mostrar_folhas(Tree * noh){
	if(noh==NULL) return;
	if(noh->esq==NULL && noh->dir==NULL){
		return mostrarUm(noh);
	}else {
		if(noh->esq!=NULL){
			mostrar_folhas(noh->esq);
		}
		if(noh->dir!=NULL){
			mostrar_folhas(noh->dir);
		}
	}
}

unsigned int contar_folhas(Tree * noh){
	if(noh==NULL) return 0;
	if(noh->esq==NULL && noh->dir==NULL){
		return 1;
	}else {
		return ((noh->esq==NULL)?0:contar_folhas(noh->esq)) + ((noh->dir==NULL)?0:contar_folhas(noh->dir));
	}
	
}

unsigned short profundidade(Tree * noh){
	if(noh==NULL){
		return 0;
	}else{
		register short esquerda;
		register short direita;
		esquerda = 1+ profundidade(noh->esq);
		direita = 1+ profundidade(noh->dir);
			
		return (esquerda>direita) ? esquerda : direita;
	}
}

void pre_ordem(Tree * noh){

	if(noh==NULL) return;
	mostrarUm(noh);
	if(noh->esq!=NULL) pre_ordem(noh->esq);
	if(noh->dir!=NULL) pre_ordem(noh->dir);
}

void in_ordem(Tree * noh){

	if(noh==NULL) return;
	in_ordem(noh->esq);
	mostrarUm(noh);
	in_ordem(noh->dir);
	return;
}

void pos_ordem(Tree * noh){

	if(noh==NULL) return;
	if(noh->esq!=NULL) pos_ordem(noh->esq);
	if(noh->dir!=NULL) pos_ordem(noh->dir);
	mostrarUm(noh);
}

void mostrarUm(register Tree * noh){
	printf("%d ", (*noh).dados->i);
}

void inserir(Tree ** noh, Dados *reg){
	if(noh==NULL) return;
	else if(*noh==NULL){
		*noh=(Tree *) malloc(sizeof(Tree));
		(*noh)->dados=(Dados *) malloc(sizeof(Dados));
		*(*noh)->dados=*reg;
		return;
	}else if((*reg).i > (*noh)->dados->i){
		inserir(&(*noh)->dir, reg);
	}else if((*reg).i < (*noh)->dados->i){
		inserir(&(*noh)->esq, reg);
	}
}

