#include<stdio.h>
#include<stdlib.h>

menu(){
	//menu de Opcoes
	printf("\nMenu de op%c%ces:\n",135, 228);
	printf("1) Cadastrar os dados de rendimento de uma cidade\n");
	printf("2) Consultar os dados de uma cidade\n");
	printf("3) Excluir uma cidade\n");
	printf("5) Mostrar a rela%c%co de cidades ordenada por nome\n", 135, 198);
	printf("6) Gerar relat%crio de cidades\n", 162);
	printf("7) Sair do programa\n");
}

int main(){
menu();
getchar();
}
