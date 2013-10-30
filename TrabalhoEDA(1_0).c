#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
//#include<math.h>
//#include<conio.h>
//#include<windows.h>
//#define CONST 100
//"http://www.censo2010.ibge.gov.br/apps/mapa/"
/*
typedef struct{
int value;
char caracter;
float decimal;
double nano;
}estruct;
*/

typedef struct _pessoa{
	unsigned long _id_p;
	int idade;
	char genero;
	char *nacionalidade, *cor_raca, *escolaridade;
	char estado_s;//Casado='C',Desquitado ou separado judicialmente'J',Divorciado='D',Viúvo='V',Solteiro='S';
	char *religiao;
	char deficiencia;
}Pessoa;

struct familia{
	Pessoa *familia;
	float salario;/*baseado no salario minimo*/
};

typedef struct _bem{
	/*
	Rádio
	Televisão
	Máquina de lavar roupa
	Geladeira
	Telefone celular
	Telefone fixo
	Microcomputador
	Microcomputador com acesso à Internet
	Motocicleta para uso particular
	Autmóvel para uso particular
	*/
	unsigned long _id_b;
	char* nome;
}Bem;

struct domicilio{
	Pessoa *moradores;
	Bem *bens;
};

struct _cidade{
	unsigned long code;
	char estado[3];
}

menu(){
	printf("\nMenu de op%c%ces:\n",135, 228);
	printf("1) Cadastrar os dados de rendimento de uma cidade\n");
	printf("2) Consultar os dados de uma cidade\n");
	printf("3) Excluir uma cidade\n");
	printf("5) Mostrar a rela%c%co de cidades ordenada por nome\n", 135, 198);
	printf("6) Gerar relat%crio de cidades\n", 162);
	printf("7) Sair do programa\n");
}

int main(){
// To do!
menu();
//system("pause>NULL");
getchar();
//return 0;
}
