#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10
#define TAM_NOME 50
#define TAM_TIPO 30

// Estrutura para representar um item
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

// Variáveis globais
Item mochila[MAX_ITENS];
int totalItens = 0;

// Função para adicionar item
void adicionarItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n❌ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }
    
    Item novoItem;
    
    printf("\n📦 Adicionar novo item:\n");
    printf("Nome: ");
    scanf(" %[^\n]", novoItem.nome);
    
    printf("Tipo: ");
    scanf(" %[^\n]", novoItem.tipo);
    
    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);
    
    mochila[totalItens] = novoItem;
    totalItens++;
    
    printf("\n✅ Item adicionado com sucesso!\n");
}

// Função para remover item pelo nome
void removerItem() {
    if (totalItens == 0) {
        printf("\n❌ Mochila vazia! Não há itens para remover.\n");
        return;
    }
    
    char nomeRemover[TAM_NOME];
    printf("\n🗑️ Remover item\n");
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeRemover);
    
    bool encontrado = false;
    
    // Procurar o item pelo nome
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = true;
            
            // Deslocar os itens restantes
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            
            totalItens--;
            printf("\n✅ Item '%s' removido com sucesso!\n", nomeRemover);
            break;
        }
    }
    
    if (!encontrado) {
        printf("\n❌ Item '%s' não encontrado na mochila.\n", nomeRemover);
    }
}

// Função para listar todos os itens
void listarItens() {
    printf("\n📋 LISTA DE ITENS NA MOCHILA\n");
    
    if (totalItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }
    
    // Cabeçalho da tabela
    printf("\n┌─────────────────────────────────────────────────────────────┐\n");
    printf("│ %-20s │ %-15s │ %-10s │\n", "NOME", "TIPO", "QUANTIDADE");
    printf("├───────────────────────────────────────────────────────────────┤\n");
    
    // Exibir cada item
    for (int i = 0; i < totalItens; i++) {
        printf("│ %-20s │ %-15s │ %-10d │\n", 
               mochila[i].nome, 
               mochila[i].tipo, 
               mochila[i].quantidade);
    }
    
    printf("└───────────────────────────────────────────────────────────────┘\n");
    printf("\nTotal de itens: %d/%d\n", totalItens, MAX_ITENS);
}

int main() {
    int opcao;
    
    printf("🎒 SISTEMA DE MOCHILA 🎒\n");
    printf("Capacidade máxima: %d itens\n\n", MAX_ITENS);
    
    do {
        // Menu interativo
        printf("\n========== MENU ==========\n");
        printf("1️⃣  Adicionar item\n");
        printf("2️⃣  Remover item\n");
        printf("3️⃣  Listar itens\n");
        printf("0️⃣  Sair\n");
        printf("==========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 0:
                printf("\n👋 Saindo do programa. Até mais!\n");
                break;
            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
        }
        
    } while(opcao != 0);
    
    return 0;
}