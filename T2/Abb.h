struct Abb{
   Abb* esq;
   Abb* dir;
   int placa, ano;
   char marca[30];
};


Abb* criar(int placa, int ano, char marca[]);
Abb* inserirAno(Abb* a, int placa, int ano, char marca[]);
Abb* inserirPlaca(Abb* a, int placa, int ano, char marca[]);
Abb* inserirMarca(Abb* a, int placa, int ano, char marca[]);
void imprimirOrdemSimetrica(Abb* a);
Abb* remover(Abb* a, int placa);
Abb* buscar(Abb* raiz, int placa);
void imprimirNo(Abb* a);
void digitarDados();
Abb* liberar(Abb* a);

