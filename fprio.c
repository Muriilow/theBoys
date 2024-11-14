
#include <stdio.h>
#include <stdlib.h>
#include "fprio.h"
//Checa se o item passado ja existe na fila
//retorna -1 se ha este item na fila
//retorna 1 se nao ha este item na fila
int checar_repetido(struct fprio_t* f, void* item)
{
    struct fpnodo_t* aux;

    aux = f->prim;

    if(aux->item == item)
        return -1;

    //Checando se o valor é repetido
    while(aux->prox != NULL)
    {
        aux = aux->prox;
        if(aux->item == item)
            return -1;
    }

    return 1;
}
struct fprio_t* fprio_cria()
{
    struct fprio_t* fila;

    fila = malloc(sizeof(struct fprio_t));
    if(fila == NULL)
    {
        return NULL;
    }
    
    //Inicializando valores
    fila->prim = NULL;
    fila->num = 0;

    return fila;
}

struct fprio_t* fprio_destroi(struct fprio_t *f)
{
    struct fpnodo_t* aux;

    if(f == NULL)
    {
        return NULL;
    }
    
    //Destroi o primeiro da fila e entao muda o seu ponteiro
    while(f->prim != NULL)
    {
        aux = f->prim;
        f->prim = aux->prox;
        free(aux->item);
        free(aux);
    }

    free(f);
    return NULL;
}


int fprio_insere(struct fprio_t* f, void* item, int tipo, int prio)
{
    struct fpnodo_t* elem;
    struct fpnodo_t* aux;
    int erro;
    int ehRepetido;

    erro = f == NULL || item == NULL;

    if(erro || !(elem = malloc(sizeof(struct fpnodo_t))))
    {
        return -1;
    }

    elem->item = item;
    elem->tipo = tipo;
    elem->prio = prio;

    //Se a fila for vazia
    if(f->num == 0)
    {
        f->prim = elem;
        elem->prox = NULL;

        return ++f->num;
    }

    aux = f->prim;
    //Checa se ha repetido e retorna um inteiro
    ehRepetido = checar_repetido(f, item);  

    if(ehRepetido == -1)
    {
        free(elem);
        elem = NULL;
        return -1;
    }
        
    //Se o primeiro elemento tem uma prioridade maior
    if(aux->prio > prio)
    {
        elem->prox = aux;
        f->prim = elem;

        return ++f->num;
    }

    //Se só ha um elemento na fila com uma prioridade menor
    if(aux->prox == NULL && aux->prio < prio)
    {
        aux->prox = elem;
        elem->prox = NULL;
        
        return ++f->num;
    }

    //Encontrar a posicao adequada do nodo por meio da prioridade
    while(aux->prox != NULL && aux->prio <= prio)
    {
        //Se o proximo elemento tem uma prioridade maior
        if(aux->prox->prio > prio)
        {
            //Colocar o novo elem entre aux e aux->prox
            elem->prox = aux->prox;
            aux->prox = elem;

            return ++f->num;
        }
        
        aux = aux->prox;
    }
    
    //Ha de ser o ultimo elemento da fila, pois o auxiliar nao possue proximo
    aux->prox = elem;
    elem->prox = NULL;

    return ++f->num;

}

void *fprio_retira(struct fprio_t* f, int* tipo, int* prio)
{
    struct fpnodo_t* aux;
    void* item;
    int varNulas;

    varNulas = f == NULL || tipo == NULL || prio == NULL;

    if(varNulas || f->num == 0)
    {
        return NULL;
    }

    aux = f->prim;
    
    f->prim = aux->prox;

    //retornos
    *tipo = aux->tipo;
    *prio = aux->prio;
    
    item = aux->item;

    free(aux);
    aux = NULL;

    f->num--;
    return item;
}


int fprio_tamanho(struct fprio_t* f)
{
    if(f == NULL)
    {
        return -1;
    }

    return f->num;
}

void fprio_imprime(struct fprio_t *f)
{
    struct fpnodo_t* aux;

    //Se a fila é nula ou nao tem elementos
    if(f == NULL || f->num == 0)
    {
        return;
    }

    aux = f->prim;
    while(aux->prox != NULL)
    {
        printf("(%d %d)", aux->tipo, aux->prio);
        printf(" ");

        aux = aux->prox;
    }

    printf("(%d  %d)", aux->tipo, aux->prio);
}
