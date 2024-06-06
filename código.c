#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Número máximo de usuários atingido.\n");
        return;
    }

    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char confirmPassword[MAX_PASSWORD_LENGTH];

    printf("Digite o nome de usuário: ");
    scanf("%s", username);

    // Verifica se o usuário já existe
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Nome de usuário já existe.\n");
            return;
        }
    }

    printf("Digite a senha: ");
    scanf("%s", password);

    printf("Confirme a senha: ");
    scanf("%s", confirmPassword);

    if (strcmp(password, confirmPassword) != 0) {
        printf("As senhas não correspondem. Registro falhou.\n");
        return;
    }

    // Adiciona o novo usuário
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;

    printf("Usuário registrado com sucesso!\n");
}

void loginUser() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Digite o nome de usuário: ");
    scanf("%s", username);
    printf("Digite a senha: ");
    scanf("%s", password);

    // Verifica as credenciais
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login bem-sucedido!\n");
            return;
        }
    }

    printf("Nome de usuário ou senha incorretos.\n");
}

void menu() {
    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Registrar novo usuário\n");
        printf("2. Acessar conta\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (choice != 3);
}

int main() {
    menu();
    return 0;
}
