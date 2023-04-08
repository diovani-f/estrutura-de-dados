#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista.h"


Carro* inserirOrdenado(Carro *lista, int placa, int ano, char marca[]){
    Carro *aux, *novo = (Carro*)malloc(sizeof(Carro));

    if(novo){
        novo->placa = placa;
        novo->ano = ano;
        novo->placa = placa;
        strcpy(novo->marca, marca);

        if(lista == NULL){
            novo->proximo = NULL;
            lista = novo;
        }
        else if(novo->placa < lista->placa){
            novo->proximo = lista; 
            lista = novo;
        }
        else{
            aux = lista;
            while(aux->proximo && novo->placa > aux->proximo->placa)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");

    return lista;
}

Carro* removerLista(Carro *lista, int placa){
    Carro *aux, *remover = NULL;

    if(lista){
        if(lista->placa == placa){
            remover = lista;
            lista = remover->proximo;
        }
        else{
            aux = lista;
            while(aux->proximo && aux->proximo->placa != placa)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return lista;

}

void imprimirLista(Carro* lista){

    while (lista != NULL){
      printf("--------------------\n");
      printf("Placa:%d | ", lista->placa);
      printf("Ano:%d | ", lista->ano);
      printf("Marca:%s\n", lista->marca);
      printf("--------------------\n");
      lista = lista->proximo;
    } 
}

Carro* liberarLista(Carro* lista){
   while(lista != NULL){
      Carro* temp = lista->proximo;   
      free(lista);                 
      lista = temp;                
   }
   return NULL;
}