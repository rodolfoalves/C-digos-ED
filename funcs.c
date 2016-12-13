#ifndef _FUNCS_C_
#define _FUNCS_C_
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "banda.h"

SLlist *sllCreate(){//Cria a lista
    SLlist * l;
    l = (SLlist *)malloc(sizeof(SLlist));
    
	if(l != NULL){//Se a matriz foi criada
        l->first = NULL;//Aponta para NULL
        return l;//Retorna a lista
    }
    return NULL;
}

int sllDestroy(SLlist *l){ //destroy a lista
    if(l != NULL){
        if(l->first != NULL){
            SLnode *aux = l->first;//Salva a primeira posição da lista
            SLnode *next = aux->next;//Salva a próxima posiçaõ da lista
            while(next != NULL){//Enquanto a próxima não for NULL
                free(aux);//Vai deletando elemento por elemento da lista
                next = next->next;//Guarda o proximo pra não perder a lista
                aux->next = next;//Salva o próximo
            }
            free(next);//Deleta o ultimo
            return TRUE;
        }
    }
    return FALSE;

}

int sllInsere(SLlist *l,void *br){//Vai inserindo na lista um atras do outro
	SLnode *novo,*p;
    if(l!=NULL){
        if(l->first == NULL){//Caso a lista esteja vazia,adicionar somente o novo elemento
            novo = (SLnode*) malloc(sizeof(SLnode));//Aloca o novo nó
            if(novo!=NULL){
				novo->data = br;//Recebe o novo dado
                novo->next = NULL;//Faz o primeiro apontar para NULL
                l->first=novo;//Faz o primeiro ser o novo
                return TRUE;
            }else{
                return FALSE;
            }
        }
        
        else{//Caso ja tenha um elemento na lista
            novo = (SLnode*) malloc(sizeof(SLnode));//Aloca o novo nó da lista
            if(novo!=NULL){
                novo->data=br;//Salva o dado do novo nó
                novo->next=NULL;//Faz o novo apontar para NULL
                p = l->first;//Salva o primeiro elemento da lista em um auxiliar
                while(p->next != NULL){//Roda a lista até achar a ultima posição
                    p=p->next;
                }
                p->next=novo;//Quando achar salva o novo elemento no final
                return TRUE;
            }else{
                return FALSE;
            }

        }
    }

}	

void* sllGetFirst(SLlist *l){ //pega a primeira posição da lista
    if(l != NULL){
        if(l->first != NULL){//Se existir um primeiro
            l->cur = l->first;//Salva o primeiro e retorna ele
            return l->cur->data;//Retorna ele
        }
        
    }
    return NULL;
}

void* sllGetNext(SLlist *l){//pega o proximo nó, caso exitas
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



int sllRemoveFirst(SLlist *l){//remove o primeiro elemento da lista
	SLnode *aux;//Cria o nó auxiliar
    void *data;
    if(l!=NULL)
    {
        aux=l->first;//Salva o primeiro elemento da lista para não perder
        data= aux->data;//Salva o conteudo do primeir elemento
        l->first = aux->next;//Faz o ponteiro do primeiro apontar para o segundo,que agora é o primeiro
        free(aux);//Deleta o antigo primeiro
        return data;
    }
    return FALSE;
}

void* sllQuery(SLlist *l,void *key,int(*cmp)(void*,void*)){//procura um elemento na lista	
	SLnode *cur;
	void *data;
	
	if(l!=NULL){
		if(l->first!=NULL){
			cur = l->first;//Salva o primeiro elemento da lista
			while(cur->next != NULL && cmp(cur->data,key) != TRUE){//Enquanto a lista não chegar no final ou enquanto não achar o elemento
				cur = cur-> next;//Avança na lista
			}
			if(cmp(cur->data,key) == TRUE){//Se achar o elemento procurado
				data = cur->data;//Salva 
				return data;//Retorna ela para a função
			}
			return NULL;
		}
	}
	return NULL;	
}


void* sllRemoveSpec(SLlist *l,void *key,int(*cmp)(void* , void*)){//remove um elemento específico da lista
	SLnode *cur;
	SLnode *prev;
	void *data;
	
	if(l!=NULL){
		if(l->first != NULL){
			prev = NULL;
			cur = l->first;//Salva o primeiro elemento da lista
			while(cur->next != NULL && cmp(cur->data,key) != TRUE){//Enquanto a lista não chegar no final ou enquanto não achar o elemento
				prev = cur;//O anterior recebe o atual
				cur = cur->next;//O atual recebe o próximo
			}
			if(cmp(cur->data,key) == TRUE){//Se achou o elemento procurado
				data = cur->data;//Salva
				if(prev != NULL){//Se ele não é o primeiro da lista
					prev->next = cur->next;//Salva o que vai ser retirado
				}
				else{//Se é o primeiro da lista
					l->first = cur->next;//Salva o que vai ser retirado
				}
				free(cur);//Deleta 
				return data;
			}
		}
	}
	return NULL;
}


#endif



