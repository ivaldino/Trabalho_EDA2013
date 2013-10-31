
#include "biblioteca_dados.c"

/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Prototipos*/
void menu();
Cidade* cadastro();
/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/

Cidade* cadastro(){
	Cidade* c=(Cidade*) malloc(sizeof(Cidade));
	//printf("\n");
	printf("Rendimento o nome da cidade:\n");
	do{
		gets(c->nome);
	}while(c->nome[0]=='\0');
	printf("Rendimento o estado:\n");
	do{
		gets(c->estado);
	}while(c->estado[0]=='\0');
	printf("Rendimento total da cidade:\n");
	scanf("%ld", &(*c).rende.total);
	printf("Rendimento At%c 1 sal%crio m%cnimo:\n", 130,160 ,161);
	scanf("%ld", &(*c).rende._1SalMin);
	printf("Rendimento Mais de 1 a 2 sal%crios m%cnimos:\n",160 ,161);
	scanf("%ld", &(*c).rende._1a2SalMin);
	printf("Rendimento Mais de 2 a 3 sal%crios m%cnimos:\n",160 ,161);
	scanf("%ld", &(*c).rende._2a3SalMin);
	printf("Rendimento Mais de 3 a 5 sal%crios m%cnimos:\n",160 ,161);
	scanf("%ld", &(*c).rende._3a5SalMin);
	printf("Rendimento Mais de 5 a 10 sal%crios m%cnimos:\n",160 ,161);
	scanf("%ld", &(*c).rende._5a10SalMin);
	printf("Rendimento Mais de 10 a 20 sal%crios m%cnimos:\n",160 ,161);
	scanf("%ld", &(*c).rende._10a20SalMin);
	printf("Rendimento Mais de 20 sal%crios m%cnimos:\n",160 ,161);
	scanf("%ld", &(*c).rende._20maisSalMin); 
	printf("Rendimento Sem rendimento:\n");
	scanf("%ld", &(*c).rende.semRendimento);
	if(valida_Rendimento((*c).rende)<1){
		printf("valor n%co bate!", 198);
		return NULL;
	}else return c;
}
int main(){
	short i;
	do{
		menu();
		scanf("%hd", &i);
		limpa();
		switch(i){
			case 1:
				Escrever_arq("cidades.DAT", "w+", cadastro(), sizeof(Cidade), 1);
		}
		getchar();
	}while(i!=7);
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
