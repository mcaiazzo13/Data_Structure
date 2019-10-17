//-------------------------------------------------------LINKED LIST---------------------------------------------------
#include <stidio.h>
#include <string.h>
#include <stdlib.h>
//-------------------------------- struct 
struct nodo{
    int dato;
    struct nodo *pNext;
};
typedef struct nodo Nodo;

Nodo *testa = NULL;
//-------------------------------search node for insert and remove in the center
Nodo cerca_nodo(int info){
    Nodo *pt;
    pt = testa;
    do{
        if(pt->dato == info){
            printf("\n*Dato esistente e trovato.\n");
        }
        pt = pt->pNext;
    }while(pt->dato == info);
    
    return *pt;
}
//-------------------------------insert node and sobstitution on the head
void inserimento_testa(int info){
    Nodo *nuovoNodo;
    nuovoNodo = malloc(sizeof(Nodo));
    nuovoNodo->dato = info;
    nuovoNodo->pNext = NULL;
    
    if(testa == NULL){
        testa = nuovoNodo;
    }
    else{
        nuovoNodo->pNext = testa;
        testa = nuovoNodo;
    }
}
//-------------------------------insert a data and insert it in desidered position (with the right input)
void inserimento_mezzo(int info1,int info2){
    // cercare info2 poi info1 punta a quello che info2 punta e info2 punta a info1.
    Nodo *nuovoNodo;
    nuovoNodo = malloc(sizeof(Nodo));
    nuovoNodo->dato = info1;
    nuovoNodo->pNext = NULL;
    
    Nodo *pt;
    pt = testa;
    do{
        if(pt->dato == info2){
            printf("Elemento trovato");
        }
        else{
        pt = pt->pNext;
        }
    }while(pt->dato != info2);
    
    
    nuovoNodo->pNext = pt->pNext;
    pt->pNext = nuovoNodo;
}

// REMOVE

// remove the node head and switch it with his next
void eliminazione_testa(){
    if (testa == NULL){
        printf("Non è possibile eliminare poichè la lista è vuota.");
    }
    else{
        Nodo *pr;
        pr = testa->pNext;
        free(testa);
        testa = pr;
    }
}
// remove data in whereever position searching it by the key 
void eliminazione_mezzo(int info1){
    // cerca il nodo da eliminare e lo elimina dopo aver fatto gli opportuni scambi di link
    Nodo *pt,*pr;
    pt = testa;
    pr = testa;
    do{ // cerca nodo
        if(pt->dato == info1){
            printf("elemento trovato");
        }
        else{
            pr = pt;
            pt = pt->pNext;
        }
    }while(pt->dato != info1);
    
    printf("\n *** Elemento -> %d",pt->dato);
    pr->pNext = pt->pNext;
    free(pt);
 }
//------------------------print the list from the head 
void visita(){
    if(testa == NULL){
        printf("Lista vuota.");
    }
    else{
        Nodo *pt;
        pt = testa;
        do{
            printf("%d \n",pt->dato);
            pt = pt->pNext;
        }while(pt != NULL);
    }
}
int main(){
    int scelta,dato,dato1;
    do{
    puts("\n MENU \n\n 1.insert head \n 2.insert middle \n 3.remove head \n 4.remove middle \n 5.print \n");
    scanf("%d",&scelta);
    switch (scelta) {
        case 1: // funziona
            puts("inserire dato");
            scanf("%d",&dato);
            inserimento_testa(dato);
            break;
        case 2: // funziona
            puts("inserire dato da inserire ");
            scanf("%d",&dato);
            puts("inserire dato da cercare ");
            scanf("%d",&dato1);
            inserimento_mezzo(dato, dato1);
            break;
        case 3: // funziona
            eliminazione_testa();
            break;
        case 4: // da fare
            puts("inserire dato");
            scanf("%d",&dato);
            eliminazione_mezzo(dato);
            break;
        case 5: // funziona
            visita();
            break;
        default:
            break;
    }
    }while(scelta != 6);
}
