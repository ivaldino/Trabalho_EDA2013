#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/******************************************************************************************************************************************/
//constanstes , defines e prepocessadores (excepting includes)
#define arqData "cidades.DAT"

const char estados[][3]={
			"AC","AL","AP","AM","BA","CE","DF","ES","GO",
			"MA","MT","MS","MG","PA","PB","PR","PE","PI",
			"RJ","RN","RS","RO","RR","SC","SP","SE","TO"};
#ifndef stricmp
	#define stricmp strcasecmp
#endif

/******************************************************************************************************************************************/
/*MANUAL PARA FUNÇÕES:*/
	/*->>ano_int(char *t):
		Recebe uma string e retorna um inteiro no formato (AAAA).
		Ex: recebe a string "2013" e retorna o valor ((int) 2013).
		*/
	/*->>Escrever_arq(char *nome_arquivo, char *T_arq, void *nome_struct,int tipo_struct):
		Recebe a string nome_arquivo que indicará o nome do arquivo de texto que será aberto(ou criado).
		Recebe a string T_arq que indicará o modo como o arquivo será aberto.
		Retorna o numero de Cidade gravados no arquivo(posições de nome_struct).
		*/
	/*->>Ler_arq(char *nome_arquivo, char *T_arq, void *nome_struct):
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
	/*->>localiza_N(int d, Cidade *nome_struct, char *s):
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
	char uf[3];/*String de 2 caracteres(+'\0') que Armazena sigla do Estado*/
	Rendimento rende;//Variável do rendimento;
}Cidade;

typedef struct _arvore{
	Cidade* cidade;
	//struct _arvore* pai;
	struct _arvore* esq;
	struct _arvore* dir;
}Tree;

//------------------------------------------------------------------------------------------------------------------------------------------------
//protótipos de funções.
	int ano_int(const char*);
	int Escrever_arq(const char *T_arq, const void *cidade, const int tipo_struct);
	int Ler_arq(char *T_arq,Tree** raiz);
	int localiza_M(int,const Cidade*,char*);
	int localiza_N(int,const Cidade*,char*);
	int test_char(const char*);
	int test_int(const char*);
	int test_sexo(char*);
	void excluir_s(int,int,Cidade*);
	void lista(int,const Cidade*);
	void procura(int,Cidade*);
	int valida_Rendimento(Rendimento r);
	int ordenar_struct(int num, Cidade *nome_struct);
	void Ordenar(int num, Cidade *nome_struct);
	void inserir(Tree ** noh, Cidade *reg);
	unsigned short maiorNoh(register unsigned short esq, register unsigned short dir);
	void mostrarUm(Tree * noh);
	void pre_ordem(Tree * noh);
	void in_ordem(Tree * noh);
	void pos_ordem(Tree * noh);
	unsigned short profundidade(Tree * noh);
	unsigned int contar_folhas(Tree * noh);
	void mostrar_folhas(Tree * noh);
	void aponta(Tree * noh, int idFunction);

//******************************************************************************************************************************************

void aponta(Tree * noh, register const int idFunction){
	switch(idFunction){
		case 1://mostrarUm();
			mostrarUm(noh);
			break;
		case 2:
			Escrever_arq("a+b", noh, sizeof(Cidade));
			break;
	}
}


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
	printf("%s\n",((*noh)).cidade->nome);
	printf("%s\n",((*noh)).cidade->uf);
	//printf("%s\n",(((*noh)).cidade->nome , ((*noh)).cidade->rend.);
	
}

void inserir(Tree ** noh, Cidade *reg){
	if(noh==NULL) return;
	else if(*noh==NULL){
		*noh=(Tree *) malloc(sizeof(Tree));
		(*noh)->cidade=(Cidade *) malloc(sizeof(Cidade));
		*(*noh)->cidade=*reg;
		return;
	}else if(stricmp((*reg).nome ,(**noh).cidade->nome)>0){
		inserir(&(*noh)->dir, reg);
	}else if(stricmp((*reg).nome ,(**noh).cidade->nome)<0){
		inserir(&(*noh)->esq, reg);
	}else if(stricmp((*reg).nome ,(**noh).cidade->nome)==0){
		if(stricmp((*reg).nome ,(**noh).cidade->nome)>0){
			inserir(&(*noh)->dir, reg);
		}
	}
}
/******************************************************************************************************************************************/
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
//******************************************************************************************************************************************
int valida_Rendimento(Rendimento r){
	return (r.total!= r._1SalMin +r._1a2SalMin +r._2a3SalMin +r._3a5SalMin 
		+r._5a10SalMin +r._10a20SalMin +r._20maisSalMin +r.semRendimento) ? -1: 1;
}
//******************************************************************************************************************************************
void string_beleza(char * s, size_t size){
	register unsigned short i;
	for(i=0; i<size; i++){
		*(s+i)= ' ';
	}
}
//******************************************************************************************************************************************
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
//******************************************************************************************************************************************
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
								printf("\n%c Caracter invalido\n", *s);
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
//**********************************************************************************************************************

int localiza_N(int d, const Cidade *nome_struct, char *s){
	register int i;
	
	for(i=0;i<d; i++){
		if(stricmp(nome_struct[i].nome,s)==0){
			return i;
		}
	}
	return -1;
}
//**********************************************************************************************************************
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
//**********************************************************************************************************************
/**
	Manipulação de arquivos:
	long ftell(FILE*); //retorna a posicao corrente onde vc esta no arquivo. (posicionamento por bytes)
	void rewind(FILE*);//retorna à posicao inicial do arquivo(SEEK_SET).
	int fseek(FILE*, long salto, int origin); //origin: (SEEK_SET=0, SEEK_CUR=1, SEEK_END=2)
	SEEK_SET=0; //indica o inicio do arquivo.
	SEEK_CUR=1; //indica a posicao corrente do arquivo.
	SEEK_END=2; //indica o final do arquivo.
*/
//**********************************************************************************************************************
int Escrever_arq(const char *T_arq, const void *cidade, const int tipo_struct){
	int retorno=0;
	
	FILE *arq_alunos; 
	
	if((arq_alunos=fopen(arqData, T_arq))==NULL){
		fprintf(stderr, "N%co foi poss%cvel abrir o arquivo!\n\n", 198, 161);
		getchar();
		exit(1);
	}else if((retorno =fwrite(cidade,tipo_struct, 1 ,arq_alunos))!=1){
			fprintf(stderr, "Falha ao gravar arquivo!\n\n", 198, 161);
			fclose(arq_alunos);
	}
	fclose(arq_alunos);
	return retorno;
}
//**********************************************************************************************************************
int Ler_arq(char *T_arq,Tree** raiz){
	int retorno=0;
	int i=0;
	printf("%d\n", i++);
	FILE *arq_city;
	printf("%d\n", i++);
	if((arq_city=fopen(arqData,T_arq))==NULL){
		printf("%d\n", i++);	
	}else{
		printf("%d\n", i++);
		Cidade cidade;
		rewind(arq_city);
		while(fread(&cidade, sizeof(Cidade),1,arq_city)){
		printf("%d\n", i++);
			inserir(raiz, &cidade);
			printf("%d\n", i++);
			retorno++;
		}
	}
	fclose(arq_city);
	return retorno;
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
