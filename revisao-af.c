#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
}Lista;

Lista *cria(void){
    return NULL;
}

Lista *insere(Lista *l, int v){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;
    return novo;
}

int comprimento(Lista *l){
    int contador = 0;
    for(Lista *p = l; p != NULL; p = p->prox){
        contador++;
    }
    return contador;
}

Lista *ultimo(Lista *l){
    Lista *p = l;
    Lista *ant = NULL;
    while(p != NULL){
        ant = p;
        p = p->prox;
    }
    return ant;
}

Lista *concatena(Lista *l1, Lista *l2){
    Lista *fim = ultimo(l1);
    fim->prox = l2;
    return l1;
}

Lista *retira_n(Lista *l, int n){
    Lista *p = l;
    Lista *ant = NULL;
    while(p!=NULL){
        if(p->info == n){
            if(ant == NULL){
                l = p->prox;
                free(p);
                p = l;
            } else {
                ant->prox = p->prox;
                free(p);
                p = ant->prox;
            }
        } else {
            ant = p;
            p = p->prox;
        }
    }
    return l;
}

Lista *inverte(Lista *l){
    Lista *anterior = NULL;
    Lista *atual = l;
    Lista *proximo = NULL;
    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

int igual(Lista *l1, Lista *l2){
    Lista *p1;
    Lista *p2;
    for(p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if (p1->info != p2->info){
            return 0;
        }
    }
    return p1 == p2;
}

Lista *copia(Lista *l){
    Lista *nova = NULL;
    Lista *fim = NULL;
    for(Lista *p = l; p != NULL; p = p->prox){
        Lista *novo = (Lista*)malloc(sizeof(Lista));
        novo->info = p->info;
        novo->prox = NULL;
        if (nova == NULL){
            nova = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }
    return nova;
}

void *libera(Lista *l){
    Lista *p = l;
    while (p!=NULL){
        Lista *temp = p;
        free(p);
        p = p->prox;
    }
}

Lista *merge(Lista *l1, Lista *l2){
    Lista *nova = NULL;
    Lista *fim = NULL;
    while (l1 != NULL || l2 != NULL){
        if(l1!=NULL){
            Lista *novo = (Lista*)malloc(sizeof(Lista));
            novo->info = l1->info;
            novo->prox = NULL;
            
            if (nova == NULL){
                nova = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }
            l1 = l1->prox;
        }
        if(l2!= NULL){
            Lista *novo = (Lista*)malloc(sizeof(Lista));
            novo->info = l2->info;
            novo->prox = NULL;
            if (nova == NULL){
                nova = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }
            l2 = l2->prox;
        }
    }
    return nova;
}

Lista *separa(Lista *l, int v){
    Lista *p = l;
    while (p != NULL && p->info != v){
        p = p->prox;
    }
    if (p == NULL){
        return NULL;
    }
    Lista *nova = p->prox;
    p->prox = NULL;
    
    return nova;
}

Lista *insere_ordenado(Lista *l, int v){
    Lista *ant = NULL;
    Lista *p = l;
    Lista *novo;
    while (p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }
    novo = (Lista*)malloc(sizeof(Lista));
    novo->info = p->info;
    if (ant == NULL){
        novo->prox = l;
        l = novo;
    } else {
        novo->prox = p;
        ant->prox = novo;
    }
    return l;
}

int main() {
    Lista *minhaLista = cria();
    minhaLista = insere(minhaLista, 1);
    minhaLista = insere(minhaLista, 2);
    minhaLista = insere(minhaLista, 3);
    printf("%d", comprimento(minhaLista));
    Lista *tamanho = ultimo(minhaLista);
    printf("\nultimo nó: %d", tamanho->info);
    printf("\n");
    imprime(minhaLista);
    minhaLista = separa(minhaLista, 2);
    printf("\n");
    imprime(minhaLista);
    return 0;
}




















