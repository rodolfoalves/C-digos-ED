#ifndef _FUNCS_C_
#define _FUNCS_C_
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "banda.h"

DLlist *dllCreate(){//Cria a lista
    DLlist * l;
    l = (DLlist *)malloc(sizeof(DLlist));

	if(l != NULL){//Se a matriz foi criada
        l->first= NULL;//Aponta para NULL
        l->cur = NULL;
        return l;//Retorna a lista
    }
    return NULL;
}

int dllDestroy(DLlist *l){ //destroy a lista
    DLnode *cur,*aux;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            while(cur != NULL){//Enquanto a próxima não for NULL
                free(cur->data);//Vai deletando elemento por elemento da lista
                aux = cur;//Guarda o proximo pra não perder a lista
                cur = cur->next;//Salva o próximo
                free(aux);
            }
            free(l);//Deleta o ultimo
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsereFirst(DLlist*l,void*data){
    DLnode *newnode;
    if(l != NULL){
        newnode = (DLnode*)malloc(sizeof(DLnode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = l->first;
            if(l->first != NULL){
                l->first->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsereLast(DLlist*l,void*data){
    DLnode *aux,*newnode;

    if(l!=NULL){
        newnode = (DLnode*)malloc(sizeof(DLnode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;
            aux = l->first;
        }
        if(aux != NULL){
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = newnode;
        }
        else{
            l->first = newnode;
        }
        newnode->prev = aux;
        return TRUE;
    }
    return FALSE;
}

int dllInsereAfterSpec(DLlist *l,void *key,int(*cmp)(void*,void*)){//Insere apos o spec
	DLnode *newnode,*spec,*next,*prev;
    void*data;

	if(l!=NULL){
        newnode = (DLnode*)malloc(sizeof(DLnode));
        if(newnode != NULL){
            newnode->data = data;
            if(l->first == NULL){
                newnode->next = newnode->prev = NULL;
                l->first = newnode;
            }
            else{
                spec = l->first;
                while(cmp(spec->data,key)!=TRUE && spec->next != NULL){
                    spec = spec->next;
                }
                if(cmp((spec->data),key) == TRUE){
                    next = spec->next;
                    newnode->next = next;
                    newnode->prev = prev;
                    if(next!=NULL){
                        next->prev = newnode;
                    }
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int dllInsereBeforeSpec(DLlist *l,void *key,int(*cmp)(void*,void*)){//Insere apos o spec
	DLnode *newnode,*spec,*next,*prev;
    void*data;

	if(l!=NULL){
        newnode = (DLnode*)malloc(sizeof(DLnode));
        if(newnode != NULL){
            newnode->data = data;
            if(l->first == NULL){
                newnode->next = newnode->prev = NULL;
                l->first = newnode;
            }
            else{
                spec = l->first;
                while(cmp(spec->data,key)!=TRUE && spec->next != NULL){
                    spec = spec->next;
                }
                if(cmp(spec->data,key)==TRUE){
                    prev = prev->next;
                    newnode ->next = spec;
                    spec->prev = prev;
                    if(prev!=NULL){
                        prev->next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void* dllGetFirst(DLlist *l){ //pega a primeira posição da lista
    if(l != NULL){
        if(l->first != NULL){//Se existir um primeiro
            l->cur = l->first;//Salva o primeiro e retorna ele
            return l->cur->data;//Retorna ele
        }

    }
    return NULL;
}

void* dllGetNext(DLlist *l){//pega o proximo nó, caso exitas
    if(l != NULL){
        if(l->cur != NULL){
            l->cur = l->cur->next;//Faz o elemento apontar para o proximo
            if(l->cur != NULL){//Se o proximo não for NULL
                return l->cur->data;//Retorna ele
            }
        }
    }
    return NULL;
}

void* dllQuery(DLlist *l,void *key,int(*cmp)(void*,void*)){//procura um elemento na lista
	DLnode *aux;
	void *data;

	if(l!=NULL){
		if(l->first!=NULL){
			aux = l->first;//Salva o primeiro elemento da lista
			while(aux->next != NULL && cmp(aux->data,key) != TRUE){//Enquanto a lista não chegar no final ou enquanto não achar o elemento
				aux = aux-> next;//Avança na lista
			}
			if(cmp(aux->data,key) == TRUE){//Se achar o elemento procurado
				data = aux->data;//Salva
				return data;//Retorna ela para a função
			}
			return NULL;
		}
	}
	return NULL;
}


void* dllRemoveSpec(DLlist *l,void *key,int(*cmp)(void* , void*)){//remove um elemento específico da lista
	void *data;
	DLnode *spec,*next,*prev;
	if(l!=NULL){
		if(l->first != NULL){
			spec = l->first;//Salva o primeiro elemento da lista
			while(spec->next != NULL && cmp(spec->data,key) != TRUE){//Enquanto a lista não chegar no final ou enquanto não achar o elemento
				spec = spec->next;//O atual recebe o próximo
			}
			if(cmp(spec->data,key) == TRUE){//Se achou o elemento procurado
				data = spec->data;//Salva
                prev = spec->prev;
                next = spec->next;
				if(prev != NULL){//Se ele não é o primeiro da lista
					prev->next = next;//Salva o que vai ser retirado
				}
				else{//Se é o primeiro da lista
					l->first = next;//Salva o que vai ser retirado
				}
				return data;
			}
		}
	return NULL;
	}
}


#endif


