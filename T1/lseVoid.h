
typedef struct{
   void* info;
   struct Lista* prox;
} Lista;

Lista* criar();
Lista* inserirInicio(Lista* lista, void* elemento);
Lista* inserirFim(Lista* lista, void* elemento);
bool vazia(Lista* lista);
Lista* liberar(Lista* lista);

/*
   As funcoes a seguir recebem ponteiros para funcoes.
      
   imprimir: Recebe uma lista e um ponteiro para uma funcao que 
   imprime os elementos individuais da lista. 
   
   buscar: Recebe uma lista, um ponteiro para um elemento e um
   ponteiro para uma funcao que compara se dois elementos são iguais.
   
   retirar: Recebe uma lista, um ponteiro para um elemento e um 
   ponteiro para uma funcao que compara se dois elementos são iguais.
   
   O usuario desta lista deve implementar funcoes que sigam a assinatura
   dos parametros das funcoes. Sao elas:

   void imprimirElemento(void*) - imprime um elemento passado como parametro
      Ex.: imprimirTime(void* time), 
	       imprimirJogador(void* jogador)
	    
   bool iguais(void*, void*) - compara dois elementos em relacao a igualdade.
      Ex.: timesIguais(void* time1, void* time2), 
	       jogadoresIguais(void* jogador1, void* jogador2)
   
*/
void imprimir(Lista* lista, void imprimirElemento(void*));
void* buscar(Lista* lista, void* elemento, bool iguais(void*, void*));
Lista* retirar(Lista* lista, void* elemento, bool iguais(void*, void*));

