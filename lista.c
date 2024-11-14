#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista_t *lista_cria()
{
    struct lista_t *lista;

    lista = malloc(sizeof(struct lista_t));

    if(lista == NULL)
    {
        return NULL;
    }

    lista->prim = NULL;
    lista->ult = NULL;
    lista->tamanho = 0;
    return lista;
}

struct lista_t* lista_destroi(struct lista_t* lst)
{
    struct item_t* aux;

    while(lst->prim != NULL)
    {
        aux = lst->prim;
		lst->prim = aux->prox;
        free(aux);
    }

    free(lst);
    return NULL;
}

int lista_insere(struct lista_t* lst, int item, int pos)
{
    struct item_t* elem;
    struct item_t* aux;

    //Se a lista e nula ou nao tem elementos ou a posicao e maior que o tamanho 
    if(lst == NULL || !(elem = malloc(sizeof(struct item_t))))
    {
        return -1;
    }
    
    elem->valor = item;

    //Se a lista nao tem ninguem
    if(lst->tamanho == 0)
    {
        lst->prim = elem;
        lst->ult = elem;

        elem->prox = NULL;
        elem->ant = NULL;

        return ++lst->tamanho;
    }
    
    //Se queremos colocar na primeira posicao
    if(pos == 0)
    {
        lst->prim->ant = elem;

        elem->prox = lst->prim;
        elem->ant = NULL;

        lst->prim = elem;

        return ++lst->tamanho;
    }

    //Posicao maior que o tamanho
    if(pos >= lst->tamanho || pos == -1)
    {
        lst->ult->prox = elem;
        elem->ant = lst->ult;
        elem->prox = NULL;
        lst->ult = elem;

        return ++lst->tamanho;
    }

    //Se nao for o ultimo elemento, nem o primeiro, e se a lista nao for vazia 
    aux = lst->prim;

    for(int i = 0; i < pos; i++)
    {
        aux = aux->prox;
    }

    elem->prox = aux;
    elem->ant = aux->ant;

    aux->ant->prox = elem;
    aux->ant = elem;

    return ++lst->tamanho;
}

int lista_retira(struct lista_t* lst, int* item, int pos)
{
    struct item_t* aux;

    //Se a lista e nula ou nao tem elementos ou a posicao e maior que o tamanho 
    if(lst == NULL || lst->tamanho <= 0)
    {
        return -1;
    }
    
    //Ha apenas um elemento
    if(lst->prim->prox == NULL)
    {
		*item = lst->prim->valor;
		free(lst->prim);
		lst->prim = NULL;
		lst->ult = NULL;
		return --lst->tamanho;
    }

    //Se queremos retirar da primeira posicao
    if(pos == 0)
    {
        aux = lst->prim;

        lst->prim = aux->prox;
        lst->prim->ant = NULL;

        *item = aux->valor;
        free(aux);
    
        aux = NULL;
        return --lst->tamanho;
    }

    //Retira ultimo
    if(pos == -1 || pos == lst->tamanho)
    {
        aux = lst->ult;
        lst->ult = aux->ant;
        lst->ult->prox = NULL;
        *item = aux->valor;
        free(aux);
        
        aux = NULL;
        return --lst->tamanho;
    }

    aux = lst->prim;

    for(int i = 0; i < pos; i++)
    {
        aux = aux->prox;
    }

    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;

    *item = aux->valor;
    free(aux);
  	aux = NULL;

    return --lst->tamanho;
}

int lista_consulta(struct lista_t* lst, int* item, int pos)
{
    struct item_t* aux;

    //Se a lista e nula ou nao tem elementos ou a posicao e maior que o tamanho 
    if(lst == NULL || lst->tamanho == 0)
    {
        return -1;
    }

    if(pos == -1 || pos >= lst->tamanho)
    {
        *item = lst->ult->valor;
        return lst->tamanho;
    }

    aux = lst->prim;

    for(int i = 0; i < pos; i++)
    {
        aux = aux->prox;
    }

    *item = aux->valor;
    return lst->tamanho;
}

int lista_procura(struct lista_t* lst, int valor)
{
    struct item_t* aux;
    int cont;

    //Se a lista e nula ou nao tem elementos
    if(lst == NULL || lst->tamanho == 0)
    {
        return -1;
    }
 
    aux = lst->prim;
    cont = 0;

    while(aux != NULL && aux->valor != valor)
    {
        aux = aux->prox;
        cont++;
    }

    if(aux == NULL)
    {
        return -1;
    }
    
    return cont;
}

int lista_tamanho(struct lista_t* lst)
{
    if(lst == NULL)
        return -1;

    return lst->tamanho;
}

void lista_imprime(struct lista_t* lst)
{
    struct item_t* aux;


    //Se a lista e nula ou nao tem elementos
    if(lst == NULL || lst->tamanho == 0)
    {
        return;
    }
    
    aux = lst->prim;

    while(aux->prox != NULL)
    {
        printf("%d", aux->valor);
        printf(" ");
        aux = aux->prox;
    }

    printf("%d", aux->valor);
}
