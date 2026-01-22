#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 50
#define TAM_STRING 100

struct Usuarios {
    char nome[TAM_STRING];
    char dataNascimento[TAM_STRING];
    char email[TAM_STRING];
    char telefone[TAM_STRING];
    
};


void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função auxiliar para limpar a tela de forma multiplataforma
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

int main() {
    struct Usuarios cadastro[MAX_USER];
    int totalUsuarios = 0;

    int opcao;

    do {


        printf("====================================\n");
        printf("     Cadastro de Usuário\n");
        printf("====================================\n");
        printf("1 - Cadastrar novo usuário\n");
        printf("2 - Listar todos os usuário\n");
        printf("0 - Sair\n");
        printf("------------------------------------\n");
        printf(" Escolha uma opção "); 


        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf


        switch (opcao) {
            case 1: //CADASTRO DE NOVO USUÁRIO
            printf("--- Cadastro de Novo Usuário ---\n\n");

            if (totalUsuarios < MAX_USER) {
                printf("Digite o nome do usuário: ");
                fgets(cadastro[totalUsuarios].nome, TAM_STRING, stdin);

                printf("Digite data de nascimento: ");
                fgets(cadastro[totalUsuarios].dataNascimento, TAM_STRING, stdin);

                printf("Digite o email: ");
                fgets(cadastro[totalUsuarios].email, TAM_STRING,stdin);

                printf("Digite o telefone: ");
                fgets(cadastro[totalUsuarios].telefone, TAM_STRING,stdin);

                cadastro[totalUsuarios].nome[strcspn(cadastro[totalUsuarios].nome, "\n")] = '\0';
                cadastro[totalUsuarios].dataNascimento[strcspn(cadastro[totalUsuarios].dataNascimento, "\n")] = '\0';
                cadastro[totalUsuarios].email[strcspn(cadastro[totalUsuarios].email, "\n")] = '\0';
                cadastro[totalUsuarios].telefone[strcspn(cadastro[totalUsuarios].telefone, "\n")] = '\0';


                totalUsuarios++;

                printf("\n Cadastro realizado com sucesso!\n");
            } else {
                printf(" Não é possível cadastrar mais usuários. \n");
            }

            printf("\nPressione Enter para continuar...");
            getchar(); //Pausa para o usuário ler a mensagem antes de voltar ao menu.
            break;

        case 2 :
             printf("--- Lista de usuários cadastrados ---\n\n");

             if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado ainda.\n");

             } else {
                for (int i = 0; i < totalUsuarios; i++) {
                    printf("--------------------------------------\n");
                    printf("Usuário: %d\n", i + 1);
                    printf("Nome: %s\n", cadastro[i].nome);
                    printf("Data de nascimento: %s\n", cadastro[i].dataNascimento);
                    printf("Email: %s\n", cadastro[i].email);
                    printf("Telefone: %s\n", cadastro[i].telefone);
                }
                 printf("--------------------------------------\n");
             }

             printf("\nPressione Enter para continuar...");
             getchar();
             break;

        case 0:
             printf("\nSaindo do sistema...\n");
             break;

            default: 
                printf("\nOpção inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcao != 0); 
    return 0;

}
        