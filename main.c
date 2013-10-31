#include <stdio.h>
#include <stdlib.h>
#include "dados.c"

/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Prototipos*/
void menu();
Cidade* cadastro();
int valida_Rendimento(Rendimento r);
/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/

Cidade* cadastro(){
	Cidade* c=(Cidade*) malloc(sizeof(Cidade));
	//printf("\n");
	printf("Digite o nome da cidade:\n");
	do{
		gets(c->nome);
	}while(c->nome[0]=='\0');
	printf("Digite o estado:\n");
	do{
		gets(c->estado);
	}while(c->estado[0]=='\0');
	printf("Digite o rendimento total da cidade:\n");
	scanf("%ld", c->rende.total);
	scanf("%ld", c->rende._1SalMin);
	scanf("%ld", c->rende._1a2SalMin);
	scanf("%ld", c->rende._2a3SalMin);
	scanf("%ld", c->rende._3a5SalMin);
	scanf("%ld", c->rende._5a10SalMin);
	scanf("%ld", c->rende._10a20SalMin);
	scanf("%ld", c->rende._20maisSalMin); 
	scanf("%ld", c->rende.semRendimento);
	if((*c).rende.total!=((*c).rende._1SalMin +(*c).rende._1a2SalMin +(*c).rende._2a3SalMin +(*c).rende._3a5SalMin 
		+(*c).rende._5a10SalMin +(*c).rende._10a20SalMin +(*c).rende._20maisSalMin +(*c).rende.semRendimento)){
			return NULL;//tranformar calculo em funcao de validacao. protótipo: int valida_Rendimento(Rendimento r);
	}else return c;
}

int main(){
	
	
	
menu();
getchar();
}

void menu(){
	//menu de Opcoes
	printf("\nMenu de op%c%ces:\n",135, 228);
	printf("1) Cadastrar os dados de rendimento de uma cidade\n");
	printf("2) Consultar os dados de uma cidade\n");
	printf("3) Excluir uma cidade\n");
	printf("5) Mostrar a rela%c%co de cidades ordenada por nome\n", 135, 198);
	printf("6) Gerar relat%crio de cidades\n", 162);
	printf("7) Sair do programa\n");
}
