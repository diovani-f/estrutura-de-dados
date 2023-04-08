#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Abb.h"

Abb* criar(int placa, int ano, char marca[]){
   Abb* a = (Abb*) malloc(sizeof(Abb));
   a->esq = NULL;
   a->dir = NULL;  
   a->placa = placa;
   a->ano = ano;
   strcpy(a->marca, marca);
   
   return a;
}

bool vazia(Abb* a){
   return (a == NULL);     
}

//imprime a arvore inteira;
void imprimirOrdemSimetrica(Abb* a){
   if (!vazia(a)){
      imprimirOrdemSimetrica(a->esq);
      printf("--------------------\n");
      printf("Placa:%d | ", a->placa);
      printf("Ano:%d | ", a->ano);
      printf("Marca:%s\n", a->marca);
      imprimirOrdemSimetrica(a->dir);
   }
}

//Imprime apenas um no da arvore;
void imprimirNo(Abb* a){
    if (!vazia(a)){
      printf("--------------------\n");
      printf("Placa:%d | ", a->placa);
      printf("Ano:%d | ", a->ano);
      printf("Marca:%s\n", a->marca);
      printf("--------------------\n");
   }
}

//insere ordenado por placa;
Abb* inserirPlaca(Abb* a, int placa, int ano, char marca[]){

   if (a == NULL){
      a = criar(placa, ano, marca);
   }
   else if (placa < a->placa)
      a->esq = inserirPlaca(a->esq, placa, ano, marca);
   else
      a->dir = inserirPlaca(a->dir, placa, ano, marca);
   return a;
}

//insere ordenado por ano;
Abb* inserirAno(Abb* a, int placa, int ano, char marca[]){

   if (a == NULL){
      a = criar(placa, ano, marca);
   }
   else if (ano < a->ano)
      a->esq = inserirAno(a->esq, placa, ano, marca);
   else
      a->dir = inserirAno(a->dir, placa, ano, marca);
   return a;
}

//insere ordenado por Marca;
Abb* inserirMarca(Abb* a, int placa, int ano, char marca[]){

   if (a == NULL){
      a = criar(placa, ano, marca);
   }

   else if (strcmp(marca, a->marca) == -1)
      a->esq = inserirAno(a->esq, placa, ano, marca);
   else
      a->dir = inserirAno(a->dir, placa, ano, marca);
   return a;
}

//Remove nó;
Abb* remover(Abb* a, int placa){
    if (vazia(a)) 
       return NULL;
    if (placa < a->placa)
       a->esq = remover(a->esq, placa);
    else if (placa > a->placa)
       a->dir = remover(a->dir, placa);
    else{
         // Caso 1: No sem filhos
         if ((a->esq == NULL) && (a->dir == NULL)){
            free(a);
            a = NULL;
         } else
         if (a->esq == NULL){ // Caso 2: Somente um filho (o da direita)
            Abb* t = a;
            a = a->dir;
            free(t);           
         } else
         if (a->dir == NULL){ // Caso 2: Somente um filho (o da esquerda)
            Abb* t = a;
            a = a->esq;
            free(t);           
         } else { // Caso 3: Os dois n�s
            Abb* f = a->esq; // vai para a SAE 
            while (f->dir != NULL)
               f = f->dir;
            a->placa = f->placa;
            f->placa = placa;
            a->esq = remover(a->esq, placa);
           // a->esq = remover(f, placa);
         }
    }
    return a; 
}

//Busca nó;
Abb* buscar(Abb* raiz, int placa){
   if (raiz == NULL) 
       return NULL;
   else if (placa < raiz->placa) 
       return buscar(raiz->esq, placa);
   else if (placa > raiz->placa) 
       return buscar(raiz->dir, placa);
   else return raiz;
}

//Liberar arvore;
Abb* liberar(Abb* a){
   if (!vazia(a)){
   liberar(a->esq);
   liberar(a->dir);
   free(a);
   }
   return NULL;
}