#include <stdio.h>
#include <stdlib.h>

#define MULTIPLICAR '*'
#define DIVIDIR '/'
#define SOMAR '+'
#define SUBTRAIR '-'

typedef struct arv no;

struct arv
{
    char operador;
    int valor;
    no *esquerda;
    no *direita;
};

int calcular_valor(no *arvore);
int multiplicar(no *arvore_esquerda, no *arvore_direita);
int dividir(no *arvore_esquerda, no *arvore_direita);
int somar(no *arvore_esquerda, no *arvore_direita);
int subtrair(no *arvore_esquerda, no *arvore_direita);

int main()
{
    no arvore[16];
	
	arvore[0].operador = '+';
	arvore[0].esquerda = &arvore[1];
	arvore[0].direita  = &arvore[2];
	arvore[1].operador = '*';
    arvore[1].esquerda = &arvore[3]; 
    arvore[1].direita = &arvore[4];
	arvore[2].valor = 5;
    arvore[3].operador = '-';
    arvore[3].esquerda = &arvore[5]; 
    arvore[3].direita = &arvore[6];
    arvore[4].operador = '+';
    arvore[4].esquerda = &arvore[7];
    arvore[4].direita = &arvore[8];
    arvore[5].valor = 6;
    arvore[6].valor = 3;
    arvore[7].valor = 4;
    arvore[8].valor = 1;

	printf("Resultado da expressão: %d\n", calcular_valor(&arvore[0]));
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
}