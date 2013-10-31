#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**********************************************************************************************************************************************
void cabecalho(){//Imprime da tela os DADOS do A_luno

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
	/*->>desempenho_P(int num, DADOS * nome_struct,int p, float *Media_Turma, float *Maior_nota, float *Menor_nota):
		
		Recebe num que indica quantas posições (do vetor do tipo DADOS nome_struct) devem ser lidas.
		Recebe p que indica qual posição do vetor nota[](situado em nome_struct) deve ser lida.
		Retorna num caso tudo funcione e retorna 0 caso falhe.
		*/
	/*->>desempenho(int num, DADOS * nome_struct, float *Media_Turma, float *Maior_nota, float *Menor_nota):
		
		Recebe num que indica quantas posições (do vetor do tipo DADOS nome_struct) devem ser lidas.
		Retorna num caso tudo funcione e retorna 0 caso falhe.*/
		
	/*->>Escrever_arq(char *nome_arquivo, char *T_arq, void *nome_struct,int tipo_struct, int quant):
		
		Recebe quant que indica quantas posições (do vetor do tipo DADOS nome_struct) devem ser escritas no arquivo.
		Recebe a string nome_arquivo que indicará o nome do arquivo de texto que será aberto(ou criado).
		Recebe a string T_arq que indicará o modo como o arquivo será aberto.
		Retorna o numero de dados gravados no arquivo(posições de nome_struct).
		*/
	/*->>Ler_arq(char *nome_arquivo, char *T_arq, void *nome_struct,int tipo_struct):
		
		Recebe a string nome_arquivo que indicará o nome do arquivo de texto que será aberto e lido.
		Recebe a string T_arq que indicará o modo como o arquivo será aberto.
		Os dados lidos no arquivo serão armazenados no vetor nome_struct, que é do tipo DADOS.
		Retorna o numero de dados lidos do arquivo(dados do tipo DADOS armazenados em nome_struct).
		*/
	/*->>localiza_M(int d, DADOS *nome_struct, char *s):
		
		Verifica a ocorrencia da matricula armazenada na string s nas primeiras d posições do vetor nome_struct.
		Retorna a posição da ocorrencia da string.
		Caso não encontre nenhuma ocorrecia, retorna -1.
		*/
	/*->>localiza_M(int d, DADOS *nome_struct, char *s):
		
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
	/*->>excluir_s(int p,int y, DADOS *nome_struct):
		
		Recebe p que indica a posição a ser excluida do vetor (do tipo DADOS) nome_struct.
		Recebe y que indica a ultima posição do vetor nome_struct.
		
	->>lista(int num, const DADOS *nome_struct):
		
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
		
	->>procura(int num, DADOS *nome_struct):
		Recebe num que indica o numero de posições do vetor nome_struct,
		onde devem ser verificadas a(s) ocorrencias de strings.
		
	*/
//*********************************************************************************************************************************************

#define NUM 4
#define DIM 3
#define DIMM 5
#define L_N 140
#define MAX 100
#define MEDIA(d) aluno[(d)].media_final=(0.15*aluno[(d)].nota[0]) + (0.3*aluno[(d)].nota[1]) + (0.35*aluno[(d)].nota[2])+(0.2*aluno[(d)].nota[3]);
#define NOW 2013

//------------------------------------------------------------------------------------------------------------------------------------------------
typedef struct{
	char nome[50];
	char matricula[11];
	char sexo[12];
	char ano_i[5];
	char senha[50];
	float media_final, nota[NUM];
	char media_f, nota_s[NUM];
	int semestre;
}DADOS;
	
//------------------------------------------------------------------------------------------------------------------------------------------------
//protótipos de funções.
	int ano_int(const char*);
	int desempenho_P(int,int, DADOS*,int, float*, float*, float *);
	int desempenho(int,int, DADOS*,float*, float*, float*);
	int Escrever_arq(const char*,const char*,const void*,const int,int);
	int Ler_arq(char*, char*, void*,int);
	int localiza_M(int,const DADOS*,char*);
	int localiza_N(int,const DADOS*,char*);
	int test_char(const char*);
	int test_int(const char*);
	int test_sexo(char*);
	void excluir_s(int,int,DADOS*);
	void lista(int,const DADOS*);
	void Matriz_Create(float[DIM][DIM],char);
	void Matriz_View(float[DIM][DIM], char c);
	void Multipli_Matriz(float[DIM][DIM],float[DIM][DIM], float [DIM][DIM],char);
	void procura(int,DADOS*);

//------------------------------------------------------------------------------------------------------------------------------------------------
enum{
	P1=0, P2, P3, trabalho=3
};

//*********************************************************************************************************************************************

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
int ordenar_struct(int num, DADOS *nome_struct){
	
	DADOS tmp;
	if(strcmp(nome_struct[num].matricula,nome_struct[num+1].matricula)>0){
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
void Ordenar(int num, DADOS *nome_struct){
	int i,y=0;
	if(num-1==0)return;
	for(i=0, y=0;i<num-1;i++){
		y+=ordenar_struct(i,nome_struct);
	}
	if(y==0)return;
	else Ordenar(num,nome_struct);
}
//*********************************************************************************************************************************************
void lista(int num, const DADOS *nome_struct){
	register int b;

	if(num>0){
        printf("Lista de alunos da turma: \n");
        for(b=0; b<num; b++){
			putchar(201); escrever_linha(); printf("%c\n",187);
			fecha_caixa(printf("%cNome: %s",186, nome_struct[b].nome));
			fecha_caixa(printf("%cSexo: %s",186, nome_struct[b].sexo));
			fecha_caixa(printf("%cMatr%ccula: %s",186, 161, nome_struct[b].matricula));
			putchar(200); escrever_linha(); printf("%c\n",188);
		}
	}else{
		puts("Nenhum aluno cadastrado.");
	}
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
void excluir_s(int p,int y, DADOS *nome_struct){
	register int i;
	
	for(i=p;i<y;i++){
		//A atribuição "nome_struct[i]=nome_struct[i+1]" é valida, pois é possivel fazer atribuições de estruturas do mesmo tipo.
		nome_struct[i]=nome_struct[i+1];
	}
		
}
//*********************************************************************************************************************************************
int localiza_M(int d, const DADOS *nome_struct, char *s){
	register int i;
	
	for(i=0;i<d; i++){
		if(strcmp(nome_struct[i].matricula,s)==0){
			return i;
		}
	}
	return -1;
}
//*********************************************************************************************************************************************
int localiza_N(int d, const DADOS *nome_struct, char *s){
	register int i;
	
	for(i=0;i<d; i++){
		if(stricmp(nome_struct[i].nome,s)==0){
			return i;
		}
	}
	return -1;
}
//*********************************************************************************************************************************************
void procura(int num, DADOS *nome_struct){
	register int p;
	char procura[50];
	
	if(num>0){
		do{
			system("cls || clear");
			printf("\nProcurar o aluno por: \n1)Parte do nome \n2)Parte da matr%ccula\n0)Retornar ao menu\n", 161);
			fflush(stdin);
			switch(getchar()){
				case '1':
					do{
						puts("Digite um trecho do nome:");
						fflush(stdin);
						gets(procura);
						strupr(procura);
					}while(procura[0]=='\0');
						
					for(p=0; p<num; p++){
						if(strstr(nome_struct[p].nome,procura)!=0){
							printf("%c",201); escrever_linha(); printf("%c\n",187);
							fecha_caixa(printf("%cNome: %s",186, nome_struct[p].nome));
							fecha_caixa(printf("%cSexo: %s",186, nome_struct[p].sexo));
							fecha_caixa(printf("%cMatr%ccula: %s",186, 161, nome_struct[p].matricula));
							printf("%c",200); escrever_linha(); printf("%c\n",188);
						}
					}
					break;
				case '2':
					do{
						printf("Digite um trecho da matr%ccula: \n", 161);
						fflush(stdin);
						gets(procura);
						strupr(procura);
					}while(procura[0]=='\0' || strlen(procura)>=10);
					for(p=0; p<num; p++){
						if(strstr(nome_struct[p].matricula,procura)!=0){
							printf("%c",201); escrever_linha(); printf("%c\n",187);
							fecha_caixa(printf("%cNome: %s",186, nome_struct[p].nome));
							fecha_caixa(printf("%cSexo: %s",186, nome_struct[p].sexo));
							fecha_caixa(printf("%cMatr%ccula: %s",186, 161, nome_struct[p].matricula));
							printf("%c",200); escrever_linha(); printf("%c\n",188);
						}
					}
					break;
				case '0':
					return;
					break;
				default:
					printf("Op%c%co incorreto", 135,198);
			}
			getchar();
		}while(1);
	}else{
		puts("Nenhum aluno cadastrado.");
	}
}
//*********************************************************************************************************************************************
int desempenho_P(int privilegios,int num, DADOS * nome_struct,int p, float *Media_Turma, float *Maior_nota, float *Menor_nota){
	//função que calcula o desempenho da turma em cada atividade desenvolvida. o parametro "int p" determina qual atividade ser quer calcular.
	register int i;
	
	Media_Turma[p]=0; 
	Menor_nota[p]=10;
	Maior_nota[p]=0;
	
	for(i=0;i<num;i++){
		if(nome_struct[i].nota_s[p]!='L'){
			if(privilegios==1){
				printf("\nAluno: %s \nMatr%ccula: %s\n", nome_struct[i].nome,161, nome_struct[i].matricula);
			}
			break;
		}else{
			if(nome_struct[i].nota[p]>Maior_nota[p]){
				Maior_nota[p]=nome_struct[i].nota[p];
			}
			if(nome_struct[i].nota[p]<Menor_nota[p]){
				Menor_nota[p]=nome_struct[i].nota[p];
			}
			Media_Turma[p]+=nome_struct[i].nota[p];
		}
	}
	if(i==num){
		if(p<3){
			printf("\nM%cdia da turma na P%d:", 130, p+1);
		}else{
			printf("\nM%cdia da turma no trabalho:", 130);
		}
		Media_Turma[p]/=num;
		printf("%.2f\n", Media_Turma[p]);
		printf("A menor nota obtida foi: %.2f\n", Menor_nota[p]);
		printf("A maior nota obtida foi: %.2f\n\n", Maior_nota[p]);
		return num;
	}else{
		printf("Nota ainda n%co foi lan%cada.\n", 198, 135);
		return 0;
	}
}
//*********************************************************************************************************************************************
int desempenho(int privilegios, int num, DADOS * nome_struct, float *Media_Turma, float *Maior_nota, float *Menor_nota){
	register int i;
	
	Media_Turma[4]=0;
	Menor_nota[4]=10;
	Maior_nota[4]=0;
	
	if(desempenho_P(  privilegios,  num  ,  nome_struct  , P1  , Media_Turma  , Maior_nota  ,  Menor_nota  )!=0){
		if(desempenho_P(  privilegios  ,  num  ,  nome_struct  , P2  ,  Media_Turma  ,  Maior_nota  ,  Menor_nota  )!=0){
			if(desempenho_P(  privilegios  ,  num  ,  nome_struct  , P3  ,  Media_Turma  ,  Maior_nota  ,  Menor_nota  )!=0){
				if(desempenho_P(  privilegios  ,  num  ,  nome_struct  ,  trabalho  ,  Media_Turma  ,  Maior_nota  ,  Menor_nota  )!=0){
					for(i=0;i<num;i++){
						if(nome_struct[i].media_f!='L'){
							break;
						}else{
							if(nome_struct[i].media_final>Maior_nota[4]){
								Maior_nota[4]=nome_struct[i].media_final;
							}
							if(nome_struct[i].media_final<Menor_nota[4]){
								Menor_nota[4]=nome_struct[i].media_final;
							}
							Media_Turma[4]+=nome_struct[i].media_final;
						}
					}
					if(i==num){
						Media_Turma[4]/=num;
						printf("\nM%cdia final da turma: %.2f\n", 130, Media_Turma[4]);
						printf("A menor nota obtida foi: %.2f\n", Menor_nota[4]);
						printf("A maior nota obtida foi: %.2f\n\n", Maior_nota[4]);
						return 1;
					}else{
						return 0;
					}
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;	
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void menu_ASCII(){
	printf("Menu: \n");
	printf("1) Digitar caracter\n");
	printf("2) Digitar codigo do caracter\n");
	printf("3) exibir lista de caracteres\n");
	printf("0) Sair\n");
}	
//---------------------------------------------------------------------------------------------------------------------------------------------------
void lista_char(){
	register int i;
	for(i=0;i<256; i++){
		printf("%d == %c\n",i,i);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void find_caracter(){
	char c;
	puts("Digite o caracter:");
	fflush(stdin);
	scanf("%c", &c);
	printf("\n\n%c<-->%d\n",c,c);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void find_code(){
	int c;
	puts("Digite o codigo:");
	scanf("%d", &c);
	printf("\n\n%d<-->%c\n",c,c);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void TABELA_ASCII(){
	
	do{
		system("cls || clear");
		menu_ASCII();
		fflush(stdin);
		switch(getchar()){
			case '1':
				find_caracter();
				break;
			case '2':
				find_code();
				break;
			case '3':
				lista_char();
				break;
			case '0':
				return;
				break;
			default:
				printf("op%c%co inexistente.", 135,198);
		}
		fflush(stdin);
		getchar();
	}while(1);
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
float MATRIZ_A[DIM][DIM], MATRIZ_B[DIM][DIM], MATRIZ_R[DIM][DIM];
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Matriz_View(float matriz[DIM][DIM], char c){
	register int x;
	register int y;
	
	for(x=0; x<DIM;x++){
		for(y=0;y<DIM; y++){
			printf("%c[%d][%d]=%.1f \t", c,x+1,y+1, matriz[x][y]);
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Multipli_Matriz(float matriz1[DIM][DIM],float matriz2[DIM][DIM], float matriz3[DIM][DIM], char c){
	register int x;
	register int y;
	register int k;
	float soma=0;
	for(x=0;x<DIM;x++){
		for(y=0;y<DIM;y++){
			for(k=0;k<DIM; k++){
				soma+=matriz1[x][k]*matriz2[k][y];
			}
			matriz3[x][y]=soma;
			soma=0;
		}
	}
	Matriz_View(MATRIZ_R, c);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Matriz_Create(float matriz[DIM][DIM], char c){
	int i,j;
	char resposta;
	
	do{
		for(i=0; i<DIM; i++){
			for(j=0; j<DIM; j++){
				printf("%c[%d][%d]=", c, i+1,j+1);
				scanf("%f", &matriz[i][j]);
				system("cls || clear");
			}
		}
		Matriz_View(matriz, c);
		printf("Deseja refazer essa matriz? \n");
		fflush(stdin);
		scanf("%c", &resposta);
	}while(resposta=='S' || resposta=='s');
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Menu_matriz(){
	
	printf("\t\tMenu de Op%c%ces: \n", 135, 228);
	printf("1) Gerar matriz 1\n", 135, 228);
	printf("2) Gerar matriz 2\n", 135, 228);
	printf("3) Gerar matriz de resultados\n", 135, 228);
	printf("0) Encerrar o programa\n", 135, 228);	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MULTI_MATRIZ(){
	
	do{
		system("cls || clear");
		Menu_matriz();
		fflush(stdin);
		switch(getchar()){
			case '1':
				Matriz_Create(MATRIZ_A, 'A');
				break;
			case '2':
				Matriz_Create(MATRIZ_B, 'B');
				break;
			case '3':
				Multipli_Matriz(MATRIZ_A, MATRIZ_B, MATRIZ_R, 'R');
				break;
			case '0':
				return;
				break;
			default:
				printf("Op%c%co incorreta. \n", 135,198);
		}getchar();
	}while(1);
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void menu_prog(){
	printf("1)Tabela ASCII\n");
	printf("2)Multiplica Matriz\n");
	printf("3)Alterar cores do sistema\n");
	printf("4)Outro programa\n");
	printf("0)Sair\n");
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#define CORES "0123456789ABCDEFabcdef"
//---------------------------------------------------------------------------------------------------------------------------------------------------
void menu_de_cores(){
	printf("Op%c%ces de cores: \n", 135, 228);
	printf("0 = Preto\t\t8 = Cinza escuro\n");
	printf("1 = Azul escuro\t\t9 = Azul\n");
	printf("2 = Verde escuro\tA = Verde\n");
	printf("3 = Verde-aqua\t\tB = Azul claro\n");
	printf("4 = Vermelho escuro\tC = Vermelho\n");
	printf("5 = Roxo\t\tD = Rosa\n");
	printf("6 = Amarelo escuro\tE = Amarelo\n");
	printf("7 = Cinza\t\tF = Branco\n");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int dizer_qual_cor(char *color){
	char c;
	
	if(stricmp(color,"Preto")==0){
		return c='0';
	}else if(stricmp(color,"Azul")==0){
		return c='9';
	}else if(stricmp(color,"Azul escuro")==0){
		return c='1';
	}else if(stricmp(color,"Azul claro")==0){
		return c='B';
	}else if(stricmp(color,"Verde")==0){
		return c='A';
	}else if(stricmp(color,"Verde escuro")==0){
		return c='2';
	}else if(stricmp(color,"Verde-aqua")==0){
		return c='3';
	}else if(stricmp(color,"Roxo")==0){
		return c='5';
	}else if(stricmp(color,"Branco")==0){
		return c='F';
	}else if(stricmp(color,"Amarelo")==0){
		return c='E';
	}else if(stricmp(color,"Amarelo escuro")==0){
		return c='6';
	}else if(stricmp(color,"Vermelho")==0){
		return c='C';
	}else if(stricmp(color,"Rosa")==0){
		return c='D';
	}else if(stricmp(color,"Cinza")==0){
		return c='7';
	}else if(stricmp(color,"Cinza escuro")==0){
		return c='8';
	}else{
		return c='\0';
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int cor_existe(char color){
	int i;
	
	for(i=0;i<22;i++){
		if(color==CORES[i]){
			return color;
		}
	}
	return color='\0';
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void COR_SYSTEM(){
	int i;
	char color[20],color_system[9]="color   ";
	printf("Escolher cores por: \n1)nome\n2)d%cgitos hexadecimais \n0)Sair\n", 161);
	fflush(stdin);
	switch(getchar()){
		case '2':
			for(i=0;i<2;i++){
				system("cls || clear");
				if(i==0){
					printf("Plano de fundo: \n");
				}else{
					printf("Primeiro plano: \n");
				}
				menu_de_cores();
				fflush(stdin);
				color[0]=getchar();
				if(cor_existe(color[0])!='\0'){
					color_system[i+6]=color[0];
				}else{
					puts("Cor incorreta.");
					getchar();
					return;
				}
			}
			break;
		case '1':
			for(i=0;i<2;i++){
				system("cls || clear");
				printf("Nome da cor do ");
				if(i==0){
					printf("Plano de fundo: \n");
				}else{
					printf("Primeiro plano: \n");
				}
				menu_de_cores();
				fflush(stdin);
				gets(color);
				if((char)dizer_qual_cor(color)!='\0'){
					color_system[i+6]=(char)dizer_qual_cor(color);
				}else{
					puts("Cor incorreta.");
					getchar();
					return;
				}
			}
			break;
		default:
			return;
	}
	system(color_system);
}
//*********************************************************************************************************************************************
void ACESSAR_PROGS(){
	char programa[100];
	int i;
	do{
		system("cls || clear");
		menu_prog();
		fflush(stdin);
		switch(getchar()){
			case '1':
				TABELA_ASCII();
				break;
			case '2':
				MULTI_MATRIZ();
				break;
			case '3':
				system("clear || cls");
				COR_SYSTEM();
				break;
			case '4':
				printf("Digite o nome do arquivo(sem a extens%co do arquivo) que deseja abrir: \n", 198);
				fflush(stdin);
				gets(programa);
				for(i=0; i<sizeof(programa); i++){
					if(programa[i]=='.'){
						programa[i]='\0';
						break;
					}
				}
				strcat(programa,".exe");
				fclose(stderr);
				if(system(programa)==0){
				}else{
					system("cls || clear");
					puts("nome incorreto.");
				}
				break;
			case '0':
				return;
				break;
			default:
				printf("Op%c%co incorreta. \n", 135,198);
		}
		getchar();
	}while(1);
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
