// ============================================================================
// PRATICA: SISTEMA DE BIBLIOTECA - PARTE 1
//
// OBJETIVO DESTA PARTE:
// Implementar o cadastro e a listagem de livros usando um array estatico.
// Focar em structs, entrasa/saida de dados e organizacao basica.
//
//
// ===========================================================================

#include<stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Definicao da Estrutura (struct) ---
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// --- Funcao para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} 

// --- Funcao Principal (main) ---
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // --- Laco Principal de Menu ---
    do {

        // Exibe o menu de opcoes.
        printf("=============================\n");
        printf("    BIBLIOTECA - PARTE 1\n");
        printf("==============================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("--------------------------------\n");
        printf("Escolha uma opcao: ");

        // Le a opcao do usuario.
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf.

        // --- Processamento da Opcao ---
        switch (opcao) {
            case 1: // CADASTRO DE LIVRO
                printf("--- Cadastro de Novo Livro ---\n\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = 0;
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = 0;
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = 0;

                    printf("Digite a edicao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada(); 
                    
                    totalLivros++;
                    // totalLivros = totalLivros + 1;

                    printf("\nLivro cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Nao e possivel cadastrar mais livros.\n");
                }

                printf("\nPressione ENTER para continuar...");
                getchar(); // Pausa para o usuario ler a mensagem antes de voltar ao menu.
                break;

            case 2: // LISTAGEM DE LIVROS
            printf("--- Lista de Livros cadastrado ainda.\n");
            
            if (totalLivros == 0) {
                printf("nenhum livro cadastrado.\n");
            } else {
                for ( int i = 0; i < totalLivros; i++) {
                    printf("LIVROS %d:\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edicao: %d\n", biblioteca[i].edicao);
                   
                }
                printf("------------------------------------\n");
            }

            // A pausa e crucial para que o usuario veja a lista antes
            // do proximo loop limpar a tela.
            printf("\nPressione ENTER para continuar...");
            getchar(); 
            break;

            case 0: // SAIR
                printf("\nSaindo do sistema...\n");
                break;

            default: // OPCAO INVALIDA
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("\nPressione ENTER para continuar...");
                getchar(); 
                break;
        }

    } while (opcao != 0);    
                             
    return 0; // Fim do programa.
}