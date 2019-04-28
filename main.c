#include <stdio.h>
#include <string.h>

void encryptRotationCipher(char message[], int key);
void decryptRotationCipher(char cipher[], int key);

void encryptSubCipher(char message[], char substitution[]);
void decryptSubCipher(char cipher[], char substitution[]);

void decryptRotationCipherAdv(char cipher[]);
void decryptSubCipherAdv(char cipher[]);

int main() {
    
//    char message[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
//    char key[] = "BADCFEHGJILKNMPOSQRVTUYZXW";
    char cipher[] = "VGF STJDL AQPYM EPZ ITNOR PUFQ VGF KBWX CPH";
    int key = 3;
    
//    decryptSubCipher(cipher, key);
    
//    encryptSubCipher(message, key);
//    encryptRotationCipher(message, key);
    decryptRotationCipher(cipher, key);
    
    return 0;
}

void encryptRotationCipher(char message[], int key) {
    int i;
    
    while (key < 0) {
        key += 26;
    } while (key >= 26) {
        key -= 26;
    }
    
    for (i = 0 ; message[i] != '\0' ; i++) {
        
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] -= 32;
        }
        
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] += key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 'Z' + 'A' - 1;
            }
        } else {
            // do nothing
        }
    }
    
    printf("%s", message);
}

void decryptRotationCipher (char cipher[], int key) {
    int i;
    
    while (key < 0) {
        key += 26;
    } while (key >= 26) {
        key -= 26;
    }
    
    for (i = 0 ; cipher[i] != '\0' ; i++) {
        
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            cipher[i] -= 32;
        } 
        
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            cipher[i] -= key;
            if (cipher[i] < 'A') {
                cipher[i] = cipher[i] + 'Z' - 'A' + 1;
            }
        } else {
            //do nothing
        }
    }
    printf("%s", cipher);
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