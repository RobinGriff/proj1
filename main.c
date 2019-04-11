#include <stdio.h>

void encryptRotationCipher(char message[], int key);
void decryptRotationCipher(char cipher[], int key);

void encryptSubCipher(char message[], char substition[]);
void decryptSubCipher(char cipher[], char substition[]);

void decryptRotationCipherAdv(char cipher[]);
void decryptSubCipherAdv(char cipher[]);

int main() {
    
    char message[] = "ZFFU";
    int key = 1;
    encryptRotationCipher(message, key);
decryptRotationCipher(message, key);
    
    return 0;
}

void encryptRotationCipher(char message[], int key) {
    int i;
    char letter;
    
    while (key < 0) {
        key += 26;
    }   while (key >= 0) {
        key -= 26;
    }
        
    for (i = 0 ; message[i] != '\0' ; i++) {
        
        letter = message[i];
        
        while (key < 0) {
            key += 26;
        }
        
        if (letter >= 'a' && letter <= 'z') {
            letter -= 32;
            letter += key;
        }   else if (letter == ' ') {
            //do nothing
        }   else if (letter > 'A' || letter < 'Z') {
            letter += key;
        }   else {
            printf("Please enter only alphabetical characters");
        }
        
        if (letter > 'Z') {
            letter = letter - 'Z' + 'A' - 1;
        }
        
        message [i] = letter;
        printf("%s\n", message);
    }
}

void decryptRotationCipher (char cipher[], int key) {
    int i;
    char letter;
    
    while (key < 0) {
        key += 26;
    } while (key >= 26) {
        key -= 26;
    }
    
    for (i = 0 ; cipher[i] != '\0' ; i++) {
        
        letter = cipher[i];
        
        if (letter >= 'a' && letter <= 'z') {
            letter -= 32;
            letter -= key;
        } else if (letter == ' ') {
            //do nothing
        } else if (letter > 'A' || letter < 'Z') {
            letter -= key;
        } else {
            printf("Please enter only alphabetical characters");
        }
        
        if (letter < 'A') {
            letter = letter + 'Z' - 'A' + 1;
        }
        
        cipher[i] = letter;
        printf("%s\n", cipher);
    }
}

void encryptSubCipher (char message[], char substitution) {
    //yes
}