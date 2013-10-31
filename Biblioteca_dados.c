#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**********************************************************************************************************************************************
void cabecalho(){//Imprime da tela os Cidade do A_luno

	 printf("\n%c%s\n", 201, linha_l);
     printf("%c Desenvolvedor: ELISEU EGEWARTH\n", 186);
     printf("%c Matr%ccula: 12/0029693\n", 186,161);
     printf("%c Disciplina: ICC - Introdu%c%co %c Ci%cncia da Computa%c%co \n",186,135,198,133,136,135,198);
     printf("%c Turma: AA \n%c%s\n", 186, 200,linha_l);
}*/
/*MANUAL PARA FUNÇÕES:*/
	/*->>ano_int(char *t):
		Recebe uma string e retorna um inteiro no formato (AAAA).
		Ex: recebe a string "2013" e retorna o valor ((int) 2013).
		*/
	/*->>desempenho_P(int num, Cidade * nome_struct,int p, float *Media_Turma, float *Maior_nota, float *Menor_nota):
		Recebe num que indica quantas posições (do vetor do tipo Cidade nome_struct) devem ser lidas.
		Recebe p que indica qual posição do vetor nota[](situado em nome_struct) deve ser lida.
		Retorna num caso tudo funcione e retorna 0 caso falhe.
		*/
	/*->>desempenho(int num, Cidade * nome_struct, float *Media_Turma, float *Maior_nota, float *Menor_nota):
		Recebe num que indica quantas posições (do vetor do tipo Cidade nome_struct) devem ser lidas.
		Retorna num caso tudo funcione e retorna 0 caso falhe.*/
	/*->>Escrever_arq(char *nome_arquivo, char *T_arq, void *nome_struct,int tipo_struct, int quant):
		Recebe quant que indica quantas posições (do vetor do tipo Cidade nome_struct) devem ser escritas no arquivo.
		Recebe a string nome_arquivo que indicará o nome do arquivo de texto que será aberto(ou criado).
		Recebe a string T_arq que indicará o modo como o arquivo será aberto.
		Retorna o numero de Cidade gravados no arquivo(posições de nome_struct).
		*/
	/*->>Ler_arq(char *nome_arquivo, char *T_arq, void *nome_struct,int tipo_struct):
		Recebe a string nome_arquivo que indicará o nome do arquivo de texto que será aberto e lido.
		Recebe a string T_arq que indicará o modo como o arquivo será aberto.
		Os Cidade lidos no arquivo serão armazenados no vetor nome_struct, que é do tipo Cidade.
		Retorna o numero de Cidade lidos do arquivo(Cidade do tipo Cidade armazenados em nome_struct).
		*/
	/*->>localiza_M(int d, Cidade *nome_struct, char *s):
		Verifica a ocorrencia da matricula armazenada na string s nas primeiras d posições do vetor nome_struct.
		Retorna a posição da ocorrencia da string.
		Caso não encontre nenhuma ocorrecia, retorna -1.
		*/
	/*->>localiza_M(int d, Cidade *nome_struct, char *s):
		Verifica a ocorrencia do nome armazenado na string s nas primeiras d posições do vetor nome_struct.
		Retorna a posição da ocorrencia da string.
		Caso não encontre nenhuma ocorrecia, retorna -1.
		*/
	/*->>test_char(char *s):
		Recebe uma string e verifica se todos os caracteres dessa string são letras.
		Conta quantos numeros ou caracteres especiais(simbolos) existem na string s.
		Retorna a quantidade de caracteres da string que não são letras(alfabeto padrão(Brasil)).
		Retorna 0 caso a string só possua letras(alfabeto padrão(Brasil)).
		*/
	/*->>test_int(char *s):
		Recebe uma string e verifica se todos os caracteres dessa string são numeros.
		Conta quantos caracteres que não são numeros existem na string s.
		Retorna a quantidade de caracteres da string que não são numeros.
		Retorna 0 caso a string só possua numeros.
		*/
	/*->>test_sexo(char *s):
		Recebe uma string e verifica se o primeiro caracter dessa string corresponde a algum dos sexos('M','m','F','f').
		Escreve "Feminino " na string s caso detecte a ocorrencia de 'F' ou 'f'.
		Escreve "Masculino " na string s caso detecte a ocorrencia de 'M' ou 'm'.
		Tambem adiciona um caracter especial ao final da string referente a cada sexo.
		Retorna 1 se o caracter tiver um sexo correspondente.
		Retorna 0 caso o caracter não tiver um sexo correspondente.
		*/
	/*->>excluir_s(int p,int y, Cidade *nome_struct):
		Recebe p que indica a posição a ser excluida do vetor (do tipo Cidade) nome_struct.
		Recebe y que indica a ultima posição do vetor nome_struct.
	->>lista(int num, const Cidade *nome_struct):
		Recebe num que indica o numero de posições do vetor nome_struct que devem ser exibidas na tela(output).
	->>Matriz_Create(float matriz[DIM][DIM], char c):
		Recebe a matriz matriz e o caracter c.
		Define os valores de matriz cujo simbolo é c.
	->>Matriz_View(float matriz[DIM][DIM], char c):
		Recebe a matriz matriz e o caracter c.
		Imprime matriz na tela(output).
	->>Multipli_Matriz(float matriz1[DIM][DIM],float matriz2[DIM][DIM], float matriz3[DIM][DIM], char c):
		Recebe matriz1, matriz2 e matriz3.
		Efetua a multiplicação da matriz1 pela matriz2.
		O Resultado da multiplicação é armazenado na matriz3.
	->>procura(int num, Cidade *nome_struct):
		Recebe num que indica o numero de posições do vetor nome_struct,
		onde devem ser verificadas a(s) ocorrencias de strings.
	*/
//*********************************************************************************************************************************************

#define DIMM 5
#define L_N 140
#define MAX 100
#define NOW 2013

//------------------------------------------------------------------------------------------------------------------------------------------------
typedef struct _rendimento{
	/* Estrutura de Cidade que define o rendimento da cidade.*/
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
	/* Estrutura de Cidade que define uma cidade.*/
	char nome[50]; 
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

//------------------------------------------------------------------------------------------------------------------------------------------------
//protótipos de funções.
	int ano_int(const char*);
	int Escrever_arq(const char*,const char*,const void*,const int,int);
	int Ler_arq(char*, char*, void*,int);
	int localiza_M(int,const Cidade*,char*);
	int localiza_N(int,const Cidade*,char*);
	int test_char(const char*);
	int test_int(const char*);
	int test_sexo(char*);
	void excluir_s(int,int,Cidade*);
	void lista(int,const Cidade*);
	void procura(int,Cidade*);
	int valida_Rendimento(Rendimento r);

//------------------------------------------------------------------------------------------------------------------------------------------------
enum{
	P1=0, P2, P3, trabalho=3
};

//*********************************************************************************************************************************************

void limpa(){
	system("clear || cls");
}

void escrever_linha(void){
	char linha_l[]={205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
					205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
					205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
					205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
					205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,'\0'};
	printf("%s",linha_l);
}
void fecha_caixa(int i){
	if(i<141){
		int y=141-i;
		register u;
		for(u=0;u<y;u++){
			putchar(' ');
		}
		printf("%c\n",186);
	}
	else putchar('\n');
}
//*********************************************************************************************************************************************
int valida_Rendimento(Rendimento r){
	return (r.total!= r._1SalMin +r._1a2SalMin +r._2a3SalMin +r._3a5SalMin 
		+r._5a10SalMin +r._10a20SalMin +r._20maisSalMin +r.semRendimento) ? -1: 1;
}
//*********************************************************************************************************************************************
void string_beleza(char * s, size_t size){
	register unsigned short i;
	for(i=0; i<size; i++){
		*(s+i)= ' ';
	}
}
//*********************************************************************************************************************************************
int test_int(const char *s){
	int d, r=0;
	int c=strlen(s);
	
	for(d=0; d<c; d++, s++){
		if(!(*s>=48 && *s<=57)){
			r++;
		}
	}
	return r;
}
//*********************************************************************************************************************************************
int test_char(const char *s){
    
    int d, r=0;
    int c=strlen(s);
    
    for(d=0; d<c; d++, s++){
		if(!(*s>=65 && *s<=90)&& !(*s>=97 && *s<=122) && !(*s>=128 && *s<=165) && !(*s>=181 && *s<=183) ){
			if(!(*s>=198 && *s<=199) && !(*s>=210 && *s<=216)){
				if(!(*s>=224 && *s<=229) && !(*s>=233 && *s<=235)){
					if(*s!= ' '){
						if(*s!= (char) (-58)){
							if(*s!= (char) (-121)){
								printf("%c Caracter invalido\n", *s);
								r++;
							}
						}
					}
				}
			}
		}
	}
    return r;
}
//*********************************************************************************************************************************************
int test_sexo(char *s){
	int r=0;
	
	if(*s=='f' || *s=='F'){
		strcpy(s, "Feminino ");
		*(s+9)= (char) 12;
		*(s+10)='\0';
		r++;
	}
	if(*s=='m' || *s=='M'){
		strcpy(s, "Masculino ");
		*(s+10)= (char) 11;
		*(s+11)='\0';
		r++;
	}
	return r;
}
//*********************************************************************************************************************************************
int ordenar_struct(int num, Cidade *nome_struct){
	
	Cidade tmp;
	if(strcmp(nome_struct[num].nome,nome_struct[num+1].nome)>0){
		tmp=nome_struct[num];
		nome_struct[num]=nome_struct[num+1];
		nome_struct[num+1]=tmp;
		return 1;
	}
	else{
		return 0;
	}
}
//*********************************************************************************************************************************************
void Ordenar(int num, Cidade *nome_struct){
	int i,y=0;
	if(num-1==0)return;
	for(i=0, y=0;i<num-1;i++){
		y+=ordenar_struct(i,nome_struct);
	}
	if(y==0)return;
	else Ordenar(num,nome_struct);
}
//*********************************************************************************************************************************************
int ano_int(const char *t){
	if(*t=='\0'){
		return 0;
	}
	else{
	    int m;
	    m= (((int)*t)- 48)*1000;
	    return (m+(ano_int(t+1)/10));
	}
}
//*********************************************************************************************************************************************
int Escrever_arq(const char *nome_arquivo, const char *T_arq, const void *nome_struct, const int tipo_struct, int quant){
	int retorno=0;
	
	FILE *arq_alunos; 
	
	if((arq_alunos=fopen(nome_arquivo, T_arq))==NULL){
		fprintf(stderr, "N%co foi poss%cvel abrir o arquivo!\n\n", 198, 161);
		getchar();
		exit(1);
	}else if((retorno =fwrite(nome_struct,tipo_struct, quant ,arq_alunos))!=quant){
			fprintf(stderr, "Falha ao gravar arquivo!\n\n", 198, 161);
			fclose(arq_alunos);
			return quant - retorno;
	}
	fclose(arq_alunos);
	return retorno;
}
//*********************************************************************************************************************************************
int Ler_arq(char *nome_arquivo, char *T_arq,void *nome_struct, int tipo_struct){
	int retorno=0;
			
	FILE *arq_alunos;
	
	if((arq_alunos=fopen(nome_arquivo,T_arq))==NULL){
		
	}else{
		if((retorno=fread(nome_struct, tipo_struct,MAX,arq_alunos))!=MAX){
			
		}
	}
	fclose(arq_alunos);
	return retorno;
}
//*********************************************************************************************************************************************
void excluir_s(int p,int y, Cidade *nome_struct){
	register int i;
	
	for(i=p;i<y;i++){
		//A atribuição "nome_struct[i]=nome_struct[i+1]" é valida, pois é possivel fazer atribuições de estruturas do mesmo tipo.
		nome_struct[i]=nome_struct[i+1];
	}
		
}
//*********************************************************************************************************************************************
int localiza_N(int d, const Cidade *nome_struct, char *s){
	register int i;
	
	for(i=0;i<d; i++){
		if(stricmp(nome_struct[i].nome,s)==0){
			return i;
		}
	}
	return -1;
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
