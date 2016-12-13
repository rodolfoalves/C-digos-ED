#ifndef FUNCS_H_
#define FUNCS_H_
#include<stdio.h>
#include<string.h>	
#define TRUE 1
#define FALSE 0

typedef struct _Node_{
    void *data;
    struct _Node_ *next;
}SLnode;

typedef struct _SLlist_{
    SLnode *first;
    SLnode *cur;
}SLlist;


#ifdef _FUNCS_H_     
    SLlist *sllCreate();//Cria a lista
    int sllInsere(SLlist *l,void *elm);//Insere na primeira posição da lista
    int sllDestroy(SLlist *l);//Destroi a lista
    void *sllGetFirst(SLlist *l);//Pega o primeiro elemento da lista
    void *sllGetxNext(SLlist *l);//Pega sempre o próximo elemento da lista
    int sllRemoveFirst(SLlist *l);//Remove o primeiro elemento da lista
    void *sllQuery(SLlist *l, void *key,int (*cmp)(void*,void*));//Procura um elemento na lista
    void *sllRemoveSpec(SLlist *l, void *key,int (*cmp)(void*,void*));//Remove um elemento específico da lista
#else

    extern SLlist *sllCreate();
    extern int sllInsere(SLlist *l,void *br);
    extern int sllDestroy(SLlist *l);
    extern void *sllGetFirst(SLlist *l);
    extern void *sllGetxNext(SLlist *l);
    extern int sllRemoveFirst(SLlist *l);
    extern void *sllQuery(SLlist *l, void *key,int (*cmp)(void*,void*));
    extern void *sllRemoveSpec(SLlist *l, void *key,int (*cmp)(void*,void*));
	    
	#endif

#endif // FUNCS_H_INCLUDED




