#include <stdio.h>
#include "listacabecalho.c"
#include "listacabecalho.h"

void mostrarMenu() {
    printf("\n====== MENU - Lista com Cabeçalho ======\n");
    printf("1. Inserir no início\n");
    printf("2. Inserir no final\n");
    printf("3. Remover valor\n");
    printf("4. Imprimir lista\n");
    printf("5. Contar elementos\n");
    printf("6. Buscar valor\n");
    printf("7. Inverter lista\n");
    printf("8. Encontrar Maior valor\n");
    printf("9. Encontrar Menor valor\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}
int main() {
    Lista* lista = criarLista();
    int opcao, valor, resultado;
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir no início: ");
                scanf("%d", &valor);
                inserirInicio(lista, valor);
                break;
            case 2:
                printf("Digite o valor a inserir no final: ");
                scanf("%d", &valor);
                inserirFim(lista, valor); // precisa implementar no lista.c
                break;
            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                resultado = remover(lista, valor);
                if (resultado)
                printf("Valor removido com sucesso.\n");
                else
                printf("Valor não encontrado.\n");
                break;
            case 4:
                printf("Conteúdo da lista:\n");
                imprimirLista(lista);
                break;
            case 5:
                printf("A lista contém %d elemento(s).\n", contarElementos(lista)); // precisa implementar
                break;
            case 6:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                resultado = buscar(lista, valor); // precisa implementar
                if (resultado)
                printf("Valor encontrado na lista.\n");
                else
                printf("Valor não encontrado.\n");
            break;
            case 7:
                reverterLista(lista);
                printf("Lista invertida com sucesso.\n");
            break;
            case 8:
                printf("Maior valor da lista: %d",obterMaior(lista));
            break;
            case 9:
                printf("Maior valor da lista: %d",obterMenor(lista));
            break;
            case 0:
                printf("Encerrando programa.\n");
            break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
    printf("Operação final: concatenando a lista com sua cópia:\n");
    Lista* lista2 = copiarLista(lista);
    concatenarListas(lista,lista2);
    liberarLista(lista2);
    imprimirLista(lista);
    liberarLista(lista);
} 