#ifndef FUNCS_H_
#define FUNCS_H_
#include<stdio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

typedef struct _Node_{
    void *data;
    struct _Node_ *next;
    struct _Node_ *prev;
}DLnode;

typedef struct _dllist_{
    DLnode *first;
    DLnode *cur;
}DLlist;


#ifdef _FUNCS_H_
    DLlist *dllCreate();//Cria a lista
    int dllInsereFirst(DLlist *l,void *elm);//Insere na primeira posição da lista
    int dllInsereLast(DLlist *l,void *elm);//Insere na ultima posição da lista
    int dllDestroy(DLlist *l);//Destroi a lista
    int dllInsereAfterSpec(DLlist *l,void *br,int(*cmp)(void*,void*));//Insere depois do elemento selecionado
    int dllInsereBeforeSpec(DLlist *l,void *br,int(*cmp)(void*,void*));//Insere antes do elemento selecionado
    void *dllGetFirst(Dllist *l);//Pega o primeiro elemento da lista
    void *dllGetxNext(DLlist *l);//Pega sempre o próximo elemento da lista
    void *dllQuery(DLlist *l, void *key,int (*cmp)(void*,void*));//Procura um elemento na lista
    void *dllRemoveSpec(DLlist *l, void *key,int (*cmp)(void*,void*));//Remove um elemento específico da lista
#else
    extern DLlist *dllCreate();//Cria a lista
    extern int dllInsereFirst(DLlist *l,void *elm);//Insere na primeira posição da lista
    extern int dllInsereLast(DLlist *l,void *elm);//Insere na ultima posição da lista
    extern int dllDestroy(DLlist *l);//Destroi a lista
    extern int dllInsereAfterSpec(DLlist *l,void *br,int(*cmp)(void*,void*));//Insere depois do elemento selecionado
    extern int dllInsereBeforeSpec(DLlist *l,void *br,int(*cmp)(void*,void*));//Insere antes do elemento selecionado
    extern void *dllGetFirst(DLlist *l);//Pega o primeiro elemento da lista
    extern void *dllGetxNext(DLlist *l);//Pega sempre o próximo elemento da lista
    extern void *dllQuery(DLlist *l, void *key,int (*cmp)(void*,void*));//Procura um elemento na lista
    extern void *dllRemoveSpec(DLlist *l, void *key,int (*cmp)(void*,void*));//Remove um elemento específico da lista

	#endif

#endif // FUNCS_H_INCLUDED




