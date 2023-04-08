#include <cstdlib>
#include <iostream>
#include "Abb.h"
#include "lista.h"

using namespace std;

void digitarInfo(int *placa, int *ano, char marca[]){

    printf("Digite a placa do veiculo:\n");
    scanf("%d", &*placa);
    printf("Digite o ano do veiculo:\n");
    scanf("%d", &*ano);

    fflush(stdin);
    printf("Digite a marca do carro:\n");
    fgets(marca, 30, stdin);
}

void menu(){
    Abb* APlaca = NULL;
    Abb* APlacaAux = NULL;
    Abb* AAno = NULL;
    Abb* AMarca = NULL;
    Carro* lista = NULL;

    int ano, placa, opcao=0;;
    char marca[30];

    do{
        printf("Digite qual operacao deseja realizar:\n1 - Inserir veiculo\n2 - Listar veiculos\n3 - Remover veiculos\n4 - Buscar veiculo\n5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            digitarInfo(&placa, &ano, marca);
            if(buscar(APlaca, placa) != NULL){
                printf("Ja existe um carro cadastrado com essa placa!\nRefaca a operacao.\n\n");
                break;
            }
            lista =inserirOrdenado(lista, placa, ano, marca);
            APlaca = inserirPlaca(APlaca, placa, ano, marca);
            AAno = inserirAno(AAno, placa, ano, marca);
            AMarca = inserirMarca(AMarca, placa, ano, marca);
            printf("Carro inserido com sucesso!\n");
            break;
        case 2:
            printf("Por placa:\n");
            imprimirLista(lista); //Aqui coloquei imprimir a lista pq é o que diz na epecificação. Mas a arvore ordena por laca tbm...
            printf("Por ano:\n");
            imprimirOrdemSimetrica(AAno);
            printf("Por marca:\n");
            imprimirOrdemSimetrica(AMarca);
            break;
        case 3:
            printf("Digite a placa do veiculo que deseja remover:\n");
            scanf("%d", &placa);
            APlaca = remover(APlaca, placa);
            AAno = remover(AAno, placa);
            AMarca = remover(AMarca, placa);
            lista = removerLista(lista, placa);
            printf("Carro removido com sucesso!\n");
            break;
        case 4:
            printf("Digite a placa do veiculo que deseja bucsar:\n");
            scanf("%d", &placa);
            APlacaAux = buscar(APlaca, placa);
            imprimirNo(APlacaAux); //criar arvore aux;
            break;
        default:
            break;
        }
    }while(opcao != 5);

    APlaca = liberar(APlaca);
    AAno = liberar(AAno);
    AMarca = liberar(AMarca);
    APlacaAux = liberar(APlacaAux);
    lista = liberarLista(lista);
}

int main()
{
    menu();
    return EXIT_SUCCESS;
}
