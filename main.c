#include <stdio.h>
#include <string.h>

void encryptRotationCipher(char message[], int key);
void decryptRotationCipher(char cipher[], int key);

void encryptSubCipher(char message[], char substitution[]);
void decryptSubCipher(char cipher[], char substitution[]);

void decryptRotationCipherAdv(char cipher[]);
void decryptSubCipherAdv(char cipher[]);

int main() {
    
    char message[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
//    char key[] = "BADCFEHGJILKNMPOSQRVTUYZXW";
//    char cipher[] = "VGF STJDL AQPYM EPZ ITNOR PUFQ VGF KBWX CPH";
    
    int key = 3;
    
//    decryptSubCipher(cipher, key);
    
//    char message[] = "ZFFU";
//    char key[] = "WEET";
    
//    encryptSubCipher(message, key);
//    int key = 1;
    encryptRotationCipher(message, key);
//    decryptRotationCipher(message, key);
    
    return 0;
}

void encryptRotationCipher(char message[], int key) {
    int i;
    char letter;
    
    while (key < -26) {
        key += 26;
    }   while (key >= 26) {
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

void encryptSubCipher (char message[], char key[]) {
    
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *finder;
    int index, i;
    
    for (i = 0 ; message[i] != '\0' ; i++) {
        
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] -= 32;
        }

        if (message[i] >= 'A' && message[i] <= 'Z') {
            finder = strchr(alphabet, message[i]);
            index = (int)(finder - alphabet);
            message[i] = key[index];
        }   else {
        // do nothing
        }
    }

    printf("%s", message);
}

void decryptSubCipher (char cipher[], char key[]) {
    
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *finder;
    int index, i;
    
    for (i = 0 ; cipher[i] != '\0' ; i++) {
        
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {
                cipher[i] -= 32;
        }
       
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            finder = strchr(key, cipher[i]);
            index = (int)(finder - key);
            cipher[i] = alphabet[index];
        } else {
            // do nothing
        }
    }       
    
    printf("%s", cipher);
}