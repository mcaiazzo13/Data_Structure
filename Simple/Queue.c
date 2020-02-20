#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------QUEQUE-----------------------------------------------------
struct nodo{
    int info;
    struct nodo *pNext;
};
typedef struct nodo Nodo;

Nodo *testa = NULL;
Nodo *coda = NULL;

//-------------------------------insert from the last one and then we divide head and tail
void inserimento_coda(int dato){
    Nodo *nodoNuovo;
    nodoNuovo = malloc(sizeof(Nodo));
    nodoNuovo->info = dato;
    nodoNuovo->pNext = NULL;
    
    if(testa == NULL){ // empty queue we have to insert a node head and tail in the same time
        testa = nodoNuovo;
        nodoNuovo->pNext = NULL;
        coda = nodoNuovo;
    }
    else{
        // not empty queue so we have to insert a node
        nodoNuovo->pNext = coda;
        coda = nodoNuovo;
    }
}
//------------------------------- this is a queue so we remove the head end his previus become the head
void eliminazione_testa(){
    // bisogna cercare partendo dalla coda il nodo che punta alla testa e farlo diventare testa
    if(coda->info == testa->info){
        coda = NULL;
        testa = NULL;
    }
    else{
    
    Nodo *pt;
    pt = coda;
    
    while(pt != NULL){
        if(pt->pNext == testa){
            printf("elem -> %d",pt->info);
            pt->pNext = testa->pNext;
            free(testa);
            testa = pt;
        }
        pt = pt->pNext;
    }
    }
}
//-------------------------------show the queue from the tail to the head
// -------------------------------the higher value is the tail
void visita(){
    if(testa == NULL){
        printf("Coda vuota.");
    }
    else{
    Nodo *pt;
    pt = coda;
    do{
        printf("Elem -> %d \n",pt->info);
        pt = pt->pNext;
    }while(pt != NULL);
    }
}

int main(){
    int scelta,dato;
    do{
    puts("\n MENU \n\n1.inserimento \n2.eliminazione \n3.visita \n");
    scanf("%d",&scelta);
    switch (scelta) {
        case 1: // ins
            puts("Inserire dato");
            scanf("%d",&dato);
            inserimento_coda(dato);
            break;
        case 2: // elim
            eliminazione_testa();
            break;
        case 3: // vis
            visita();
            break;
        default: printf("Riprova");
            break;
    }
    }while(scelta != 4);
}
