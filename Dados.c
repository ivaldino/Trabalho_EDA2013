#include<stdio.h>
#include<stdlib.h>

typedef struct _rendimento{
	/* Estrutura de dados que define o rendimento da cidade.*/
	unsigned long total;/* Valor de total tem que estar de acordo com a soma dos valores dos outros campos abaixo.*/
	unsigned long _1SalMin;
	unsigned long _1a2SalMin;
	unsigned long _2a3SalMin;
	unsigned long _3a5SalMin;
	unsigned long _5a10SalMin;
	unsigned long _10a20SalMin;
	unsigned long _20maisSalMin;
	unsigned long semRendimento;
}Rendimento;

typedef struct _cidade{
	/* Estrutura de dados que define uma cidade.*/
	char* nome; 
	/* ponteiro p/ char onde será armazenado o nome da cidade. //Alocar dinamicamente o tamanho da string\\ Verificar se ñ comprometerá leitura em arquivo*/
	char estado[3];/*String de 2 caracteres(+'\0') que Armazena sigla do Estado*/
	Rendimento rende;//Variável do rendimento;
}Cidade;

typedef struct _arvore{
	Cidade* cidade;
	//struct _arvore* pai;
	struct _arvore* esq;
	struct _arvore* dir;
}Arvore;
