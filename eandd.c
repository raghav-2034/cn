#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char result[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            result[i] = (text[i] - 'A' + 3) % 26 + 'A'; // Encrypt Uppercase
        } else if (islower(text[i])) {
            result[i] = (text[i] - 'a' + 3) % 26 + 'a'; // Encrypt Lowercase
        } else {
            result[i] = text[i]; // Keep other characters unchanged
        }
    }
    result[strlen(text)] = '\0'; // Null-terminate the result
}

void decrypt(char text[], char result[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            result[i] = (text[i] - 'A' - 3 + 26) % 26 + 'A'; // Decrypt Uppercase
        } else if (islower(text[i])) {
            result[i] = (text[i] - 'a' - 3 + 26) % 26 + 'a'; // Decrypt Lowercase
        } else {
            result[i] = text[i]; // Keep other characters unchanged
        }
    }
    result[strlen(text)] = '\0'; // Null-terminate the result
}

int main() {
    char text[100], result[100];
    int choice;


    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Choose an option:\n");
    printf("1. Encrypt the text\n");
    printf("2. Decrypt the text\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(text, result);
            printf("Encrypted text: %s\n", result);
            break;
        case 2:
            decrypt(text, result);
            printf("Decrypted text: %s\n", result);
            break;
        default:
            printf("Invalid choice. Please select 1 or 2.\n");
    }

    return 0;
}