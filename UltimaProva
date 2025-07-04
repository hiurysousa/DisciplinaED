#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista *cria_lista(void);
Lista *insere_lista(Lista *l, int valor);
void imprime_lista(Lista *l);
int comprimento_lista(Lista *l);
int maiores (Lista *l, int n);
Lista *ultimo(Lista *l);
Lista *concatena(Lista *l1, Lista *l2);
Lista *retira_lista(Lista *l, int v);
Lista *retira_n (Lista *l, int n);
Lista *busca(Lista *l1, int n);
Lista* separa(Lista* l, int n);

int main() {
    Lista *minha_lista = cria_lista();
    
    for (int i = 1; i < 4; i++){
        minha_lista = insere_lista(minha_lista, i);
    }
    imprime_lista(minha_lista);
    printf("\nA lista contém %d elementos.", comprimento_lista(minha_lista));
    printf("\nExistem %d valores maiores que 1.", maiores(minha_lista, 1));
    return 0;
}

Lista *cria_lista(void){
    return NULL;
}

Lista *insere_lista(Lista *l, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    
    novo->info = valor;
    novo->prox = l;
    
    return novo;
}

void imprime_lista(Lista *l){
    Lista *p;
    for(p=l; p != NULL; p = p->prox){
        printf(" %d ", p->info);
    }
}

int comprimento_lista(Lista *l){
    Lista *p;
    int cont = 0;
    for(p = l; p != NULL; p = p->prox){
        cont++;    
    }
    return cont;
}

int maiores (Lista *l, int n){
    Lista *p;
    int cont = 0;
    for(p = l; p != NULL; p = p->prox){
        if (p->info > n){
            cont++;
        }
    }
    return cont;
}

Lista *ultimo(Lista *l){
    Lista *p = l;
    Lista *ant = NULL;
    while (p!=NULL){
        ant = p;
        p = p->prox;
    }
    return ant;
}

Lista *concatena(Lista *l1, Lista *l2){
    Lista *ult = ultimo(l1);
    ult->prox = l2;
    
    return l1;
}

Lista *retira_lista(Lista *l, int v){
    Lista *p = l;
    Lista *ant = NULL;
    
    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL){
        return l;
    }
    
    if (ant == NULL){
        l = p->prox;
    } else {
        ant->prox = p->prox;
    }
    
    free(p);
    return l;
}

Lista *busca(Lista *l1, int n){
    Lista *p;
    for (p = l1; p != NULL; p = p->prox){
        if (p->info == v){
            return p;
        }
    }
    return NULL;
}

Lista *retira_n (Lista *l, int n){ 
    while (busca(l, n) != NULL) {
        l = retira_lista(l, n);
    }
    return l;
}

Lista* separa(Lista* l, int n) { // AKI GPT P BAIXO QUESTÃO 2.6
    Lista *p = l;

    // Percorre até encontrar o valor n ou o fim da lista
    while (p != NULL && p->info != n) {
        p = p->prox;
    }

    if (p == NULL) {
        // n não encontrado: lista não é alterada, retorna NULL
        return NULL;
    }

    // p aponta para o nó com info == n
    Lista *nova = p->prox;  // nova lista começa depois de n
    p->prox = NULL;         // separa a lista aqui

    return nova;            // retorna a segunda lista
}

// Função para inserir no final (para manter a ordem de intercalação)
Lista* lista_insere_final(Lista* l, float v) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = NULL;

    if (l == NULL) return novo;

    Lista *p = l;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novo;
    return l;
}

// Função que intercala os nós de l1 e l2 em uma nova lista
Lista* merge(Lista* l1, Lista* l2) { // QUESTÃO 2.7 CONCATENAR PELA POSICAO
    Lista *nova = NULL;
    
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            nova = lista_insere_final(nova, l1->info);
            l1 = l1->prox;
        }
        if (l2 != NULL) {
            nova = lista_insere_final(nova, l2->info);
            l2 = l2->prox;
        }
    }
    
    return nova;
}

Lista* inverte(Lista* l) { // QUESTÃO 2.8 inverte
    Lista *ant = NULL;
    Lista *atual = l;
    Lista *prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;    // salva o próximo
        atual->prox = ant;     // inverte o ponteiro
        ant = atual;           // avança o anterior
        atual = prox;          // avança o atual
    }

    return ant; // 'ant' agora aponta para o novo início da lista
}


















