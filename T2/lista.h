struct Carro{
   int placa;
   int ano;
   char marca[30];
   Carro *proximo;
};


Carro* inserirOrdenado(Carro *lista, int placa, int ano, char marca[]);
Carro* removerLista(Carro *lista, int placa);
Carro* liberarLista(Carro *lista);
void imprimirLista(Carro *lista);
