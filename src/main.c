#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
 };
 
typedef struct {
    int tam;
    struct ListNode *inicio;
} Lista;

void CriarLista(Lista *lista){
    lista->tam = 0;
    lista->inicio = NULL;
}

void Inserir(Lista *lista, int num) {
    struct ListNode *aux, *novo = (struct ListNode*)malloc(sizeof(struct ListNode));
    novo->val = num;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
        novo->next = NULL;
    } else {
        aux = lista->inicio;
        while(aux->next) aux = aux->next;
        aux->next = novo;
        novo->next = NULL;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    typedef struct {
        struct ListNode *inicio;
    } Lista;

    Lista lista;
    lista.inicio = NULL;

    struct ListNode *ordem = NULL;

    if(!list1) return list2;
    if(!list2) return list1;

    if(list1->val <= list2->val) {
        lista.inicio = list1;
        list1 = list1->next;
    } else {
        lista.inicio = list2;
        list2 = list2->next;
    }
   
    ordem = lista.inicio;

    while(list1 != NULL && list2 != NULL) {
        if(list1->val <= list2->val) {
            ordem->next = list1;
            list1 = list1->next;
        } else {
            ordem->next = list2;
            list2 = list2->next;
        }
        ordem = ordem->next;
    }

    if(list1 != NULL) {
        ordem->next = list1;
        } else {
    ordem->next = list2;
}


return lista.inicio;
}

int main() {
    
    Lista list1, list2;
    CriarLista(&list1);
    CriarLista(&list2);

    for(int i = 1; i < 10; i = i + 2)
        Inserir(&list1, i);

    for(int i = 0; i < 9; i = i + 2)
        Inserir(&list2, i);
    
    struct ListNode *list3 = mergeTwoLists(list1.inicio, list2.inicio);

    while(list3) {
        printf("%d ", list3->val);
        list3 = list3->next;
    }
    
    return 0;
}
