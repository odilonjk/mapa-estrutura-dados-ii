#include <stdio.h>
#include <stdlib.h>

/**
 * Aluno: Odilon Jonathan Kröger
 * RA: 17150705
 * Professor: Fábio Ataide de Lima
 * 
 * O código fonte desta atividade também se encontra em meu github:
 * https://github.com/odilonjk/mapa-estrutura-dados-ii
 * 
 * Ambiente em que este código foi compilado e testado:
 * Linux: Debian 9
 * Compilador: gcc
 */ 

//  Constantes
#define MULTIPLICAR '*'
#define DIVIDIR '/'
#define SOMAR '+'
#define SUBTRAIR '-'
#define RAIZ 'R'
#define ESQUERDA 'E'
#define DIREITA 'D'
#define SEM_OPERADOR '#'

typedef struct arv no;

struct arv
{
    char operador;
    int valor;
    no *esquerda;
    no *direita;
};

no arvore[16];

//  Prototipação
int calcular_valor(no *arvore);
int multiplicar(no *arvore_esquerda, no *arvore_direita);
int dividir(no *arvore_esquerda, no *arvore_direita);
int somar(no *arvore_esquerda, no *arvore_direita);
int subtrair(no *arvore_esquerda, no *arvore_direita);
void exibir_calculo_arvore();
void imprimir_arvore();
void limpar_tela();
int obter_acao(int acao);
void tratar_acao(int acao);
void calcular_arvore_mapa();
void gerar_arvore();
int obter_acao_gerar_arvore(int acao_arvore);
void tratar_acao_gerar_arvore(int acao_arvore);
void adicionar_no();
int procurar_indice_no(char operador);
void arvore_insere(int indice_pai, char oper, int valor, char lado);
void limpar_arvore();
 
int main()
{
    int acao = -1;
    limpar_arvore();
    do
    {
        acao = obter_acao(acao);
        limpar_tela();
        tratar_acao(acao);
    } while (acao != 0);

    return 0;
};

int multiplicar(no *arvore_esquerda, no *arvore_direita)
{
	return calcular_valor(arvore_esquerda) * calcular_valor(arvore_direita);
};

int somar(no *arvore_esquerda, no *arvore_direita)
{
    return calcular_valor(arvore_esquerda) + calcular_valor(arvore_direita);
};

int dividir(no *arvore_esquerda, no *arvore_direita)
{
    return calcular_valor(arvore_esquerda) / calcular_valor(arvore_direita);
};

int subtrair(no *arvore_esquerda, no *arvore_direita)
{
    return calcular_valor(arvore_esquerda) - calcular_valor(arvore_direita);
};

int calcular_valor(no *arvore){
    switch (arvore->operador)
    {
        case MULTIPLICAR:
		    return multiplicar(arvore->esquerda, arvore->direita);
    
        case DIVIDIR:
            return dividir(arvore->esquerda, arvore->direita);

        case SOMAR:
		    return somar(arvore->esquerda, arvore->direita);

        case SUBTRAIR:
		    return subtrair(arvore->esquerda, arvore->direita);

        default:
        	return arvore->valor;
    }
};

int obter_acao(int acao)
{
    printf("\n||--------------------------------------------------------||\n");
    printf("||                          Menu                          ||\n");
    printf("|| (1) Calcular árvore pré definida pela atividade mapa.  ||\n");
    printf("|| (2) Gerar uma árvore.                                  ||\n");
    printf("|| (0) Desligar.                                          ||\n");
    printf("||--------------------------------------------------------||\n\n");
    scanf("%d", &acao);
    return acao;
};

void tratar_acao(int acao)
{
    switch (acao)
    {
        case 0:
            printf("Desligando o sistema...\n");
            break;
    
        case 1:
            calcular_arvore_mapa();
            break;

        case 2:
            gerar_arvore();
            break;

        default:
            break;
    }
};

/*
 * Esta é a árvore do enunciado da atividade.
 * A sua expressão matemática equivale a 5 + ((4+1) * (6-3))
 */
void calcular_arvore_mapa()
{
    arvore[0].operador = '+';
    arvore[0].esquerda = &arvore[1];
    arvore[0].direita  = &arvore[2];
    arvore[1].operador = '*';
    arvore[1].esquerda = &arvore[3]; 
    arvore[1].direita = &arvore[4];
    arvore[2].valor = 5;
    arvore[2].operador = '#';
    arvore[3].operador = '-';
    arvore[3].esquerda = &arvore[5]; 
    arvore[3].direita = &arvore[6];
    arvore[4].operador = '+';
    arvore[4].esquerda = &arvore[7];
    arvore[4].direita = &arvore[8];
    arvore[5].valor = 6;
    arvore[5].operador = '#';
    arvore[6].valor = 3;
    arvore[6].operador = '#';
    arvore[7].valor = 4;
    arvore[7].operador = '#';
    arvore[8].valor = 1;
    arvore[8].operador = '#';
    exibir_calculo_arvore();
};

//  Método utilizado para o usuário gerar uma árvore manualmente.
void gerar_arvore()
{
    int acao_arvore = -1;
    do
    {
        acao_arvore = obter_acao_gerar_arvore(acao_arvore);
        limpar_tela();
        tratar_acao_gerar_arvore(acao_arvore);
    } while (acao_arvore != 0);
};


int obter_acao_gerar_arvore(int acao_arvore)
{
    printf("\n||--------------------------||\n");
    printf("||           Menu           ||\n");
    printf("|| (1) Adicionar nó.        ||\n");
    printf("|| (2) Calcular expressão.  ||\n");
    printf("|| (3) Limpar árvore.       ||\n");
    printf("|| (0) Voltar.              ||\n");
    printf("||--------------------------||\n\n");
    scanf("%d", &acao_arvore);
    return acao_arvore;
};

void tratar_acao_gerar_arvore(int acao_arvore)
{
    
    switch (acao_arvore)
    {
        case 1:
            adicionar_no();
            break;
    
        case 2:
            exibir_calculo_arvore();
            break;

        case 3:
            limpar_arvore();
            break;

        case 0:
            printf("Voltando ao menu inicial.");
            break;

        default:
            printf("Ops! Esta opção não existe... Tente novamente!");
            break;
    }
};

void adicionar_no()
{
	char pai, oper, lado, tipo;
    int valor;
    printf("\nQual o operador do nó pai?\n");
    scanf("%c",&pai);
    scanf("%c",&pai);
    printf("\nEste nó possúi valor ou operador?\n(V) Valor - (O) Operador\n");
    scanf("%c",&tipo);
    scanf("%c",&tipo);
    if(tipo == 'V')
    {
        printf("\nDigite o valor do nó: ");
        scanf("%d",&valor);
        oper = '#';
    }
    else
    {
        printf("\nDigite o operador do nó: ");
        scanf("%c",&oper);
        scanf("%c",&oper);
    }
    printf("Qual o lado da subárvore?\n(R) Raiz - (E) Esquerda - (D) Direita\n");
    scanf("%c",&lado);
    scanf("%c",&lado);
    arvore_insere(procurar_indice_no(pai), oper, valor, lado);
    limpar_tela();
    imprimir_arvore();
};

int procurar_indice_no(char oper)
{
    int i;
	for (i = 0; i < 15; i++)
    {
		if (arvore[i].operador == oper)
        {
			return i; 
		} 
	}
	return 0;
};

void arvore_insere(int indice_pai, char oper, int valor, char lado)
{
    int filho = 0;
    if (ESQUERDA == lado) 
    {
        filho = 2 * indice_pai + 1;
        arvore[indice_pai].esquerda = &arvore[filho];
    }
    else if (DIREITA == lado)
    {
        filho = 2 * indice_pai + 2;
        arvore[indice_pai].direita = &arvore[filho];
    }
    arvore[filho].operador = oper;
    arvore[filho].valor = valor;
};

void imprimir_arvore()
{
    int i;
    for (i = 0; i <= 15; i++)
    {
        if(SEM_OPERADOR == arvore[i].operador)
        {
    		printf("| %d ", arvore[i].valor);
        }
        else
        {
    		printf("| %c ", arvore[i].operador);
        }
	}
    printf("\n");
};

void exibir_calculo_arvore()
{
    imprimir_arvore();
    printf("Resultado da expressão: %d\n", calcular_valor(&arvore[0]));
};

void limpar_arvore()
{
    int i;
    
    for(int i=0; i<=15; i++)
    {
        arvore[i].operador = '\0';
        arvore[i].valor = 0;
    }
    
};

//  Limpa a tela considerando o sistema operacional para executar o comando correto
void limpar_tela()
{
    #ifdef _WIN32
    printf("cls");
    #endif
    #ifdef linux
    printf("\033c");
    #endif
};