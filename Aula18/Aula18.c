#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int i);
Lista *insere_ordenado(Lista *l, int i);
int lst_vazia(Lista *l);
void lst_libera(Lista *l);
Lista *lst_retira(Lista *l, int v);
Lista *lst_busca(Lista *l, int v);
Lista *lst_busca_ordenada(Lista *l, int v);
int lst_igual(Lista *l1, Lista *l2);

int main() // na stack vai ter um ponteiro pra cabeca  ->> na pilha
{
    Lista* minha_lista = lst_cria();
    Lista* minha_lista2 = lst_cria();

    for (int i = 0; i < 500; i++){
        minha_lista = insere_ordenado(minha_lista, i+1);
        minha_lista2 = insere_ordenado(minha_lista2, i+1);
    }

    lst_imprime(minha_lista);
    printf("\nBuscando na lista.\n");
    printf("Digite um valor a ser buscado:");
    int valor_busca = 0;
    scanf("%d", &valor_busca);

    printf("O elemento ");
    if(lst_busca_ordenada(minha_lista, valor_busca)){
        printf("foi encontrado...\n");
        
        printf("Voce quer deleta-lo? S/N");
        char opcao;
        scanf(" %c%*c", &opcao);

        switch(opcao){
            case 's':
            case 'S':
                minha_lista = lst_retira(minha_lista, valor_busca);
            break;
        }

    } else {
        printf("nao encontrado...\n");
    }

    return 0;
}
//O tempo de busca em uma lista ordenada é a metade do tempo de busca em uma lista desordenada

Lista* lst_cria(void)
{
    return NULL;
}

Lista* lst_insere(Lista* l, int i)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo)
    {
        printf("Memoria insuficiente...");
        exit(1);
    }   

    novo->info = i;
    novo->prox = l; // RECEBE NULO

    return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p; // o p sempre vai apontar para o proximo termo e o l para o primeiro

    for(p = l; p!=NULL; p = p->prox) //p recebe o endereço para a estrutura l e vai adicionando o próximo endereço e só para quando p chegar em null
        printf("info = %d\n", p->info);
}

Lista *lst_retira(Lista *l, int v){
    Lista *ant = NULL;
    Lista *p = l;
    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }

    if (p == NULL) { // verificacao para saber se o valor NAO foi achado, ou seja, bateu no ultimo NULL.
        return l;
    }

    if (ant == NULL){ // verificacao para caso o valor seja o primeiro item da lista, ou seja, ant já começa e termina em NULL.
        l = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);

    return l;
}

int lst_vazia(Lista *l){
    if(l == NULL){
        return 1;
    } else {
        return 0;
    }
}

void lst_libera(Lista *l){
    Lista *p = l; // p percorre a lista
    while(p != NULL){
        Lista *aux = p->prox; // aux = ponteiro temporario pra liberar o presente e guardar o futuro
        free(p);
        p = aux;
    }
}

Lista *lst_busca(Lista *l, int v){
    Lista *p;
    for(p = l; p != NULL; p=p->prox){
        if(p->info == v){
            return p;
        }
    }
    return NULL; // nao achou o elemento !!
}

Lista *lst_busca_ordenada(Lista *l, int v) {
    Lista *p;
    for (p = l; p != NULL && p->info <= v; p = p->prox) {
        if (p->info == v) {
            return p; // achou o valor
        }
    }
    return NULL; // não achou
}


Lista *insere_ordenado(Lista *l, int v){
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = l;

    while(p!=NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;

    if (ant == NULL){
        novo->prox = l;
        l = novo;
    } else {
        novo->prox = p;
        ant->prox = novo;
    }

    return l;
}

int lst_igual(Lista *l1, Lista *l2){
    Lista *p1;
    Lista *p2;

    for(p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox){
        if(p1->info != p2->info){
            return 0;
        }
    }

    return p1==p2;
}