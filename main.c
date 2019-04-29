#include <stdio.h>
#include <string.h>

void encryptRotationCipher(char message[], int key);
void decryptRotationCipher(char cipher[], int key);

void encryptSubCipher(char message[], char substitution[]);
void decryptSubCipher(char cipher[], char substitution[]);

void decryptRotationCipherAdv(char cipher[]);
void decryptSubCipherAdv(char cipher[]);

int main() {
    
    char cipher[] = "XYZ, ABC";
//    char key[] = "BADCFEHGJILKNMPOSQRVTUYZXW";
//    char cipher[] = "VGF STJDL AQPYM EPZ ITNOR PUFQ VGF KBWX CPH";
    int key = 3;
    
//    decryptSubCipher(cipher, key);
    
//    encryptSubCipher(message, key);
//   encryptRotationCipher(message, key);
    decryptRotationCipher(cipher, key);
    
    return 0;
}

// The below function encrypts a message, input as a string,
// by rotating the alphabetical 'index' by a key, input as an int.
// Any punctuation input into the function is ignored and will
// persist through to the output, being a printed encrypted message.
// Example 'XYZ, ABC' encrypted with a key of 3 would print 'ABC, DEF'.

void encryptRotationCipher(char message[], int key) {
    int i;
    
    while (key < 0) {       // These while statements ensure that the input
        key += 26;          // key is < 0 and >= 26. This does not change the
    } while (key >= 26) {   // alphabetical rotation as a rotation of -1 is
        key -= 26;          // equivalent to a rotation of 25 and so on.
    }
    
    for (i = 0 ; message[i] != '\0' ; i++) {    // loops through each char contained within the message string
                                                // until the \0 at the end of the string is reached.
                                                
        if (message[i] >= 'a' && message[i] <= 'z') {   // if the char is lowercase, converts char to uppercase
            message[i] -= 32;                           // by subtracting 32 from the char value.    
        }
        
        if (message[i] >= 'A' && message[i] <= 'Z') {   // if the char is uppercase alphabetical, rotates the 
            message[i] += key;                          // char value by the input key value.
            if (message[i] > 'Z') {                     // if the rotated char lies outside of the alphabetical ASCII
                message[i] = message[i] - 'Z' + 'A' - 1;// corrects the value by changing char value to start of alphabet
            }
        } else {    // if the input char lies outside of the uppercase alphabetical range
            // does nothing, allowing the char to persist to the output
        }
    }
    
    printf("%s", message);  // prints the encrypted message
}

// The below function decrypts a cipher, input as a string,
// by rotating the alphabetical 'index' by a key, input as an int.
// Any punctuation input into the function is ignored and will
// persist through to the output, being a printed decrypted message.
// Example 'XYZ, ABC' decrypted with a key of 3 would print 'UVW, XYZ'.

void decryptRotationCipher (char cipher[], int key) {
    int i;
    
    while (key < 0) {       // These while statements ensure that the input
        key += 26;          // key is < 0 and >= 26. This does not change the
    } while (key >= 26) {   // alphabetical rotation as a rotation of -1 is
        key -= 26;          // equivalent to a rotation of 25 and so on.
    }
    
    for (i = 0 ; cipher[i] != '\0' ; i++) {     // loops through each char contained within the message string
                                                // until the \0 at the end of the string is reached.
        
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {     // if the char is lowercase, converts char to uppercase
            cipher[i] -= 32;                            // by subtracting 32 from the char value.
        } 
        
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {     // if the char is uppercase alphabetical, rotates the 
            cipher[i] -= key;                           // char value backwards by the input key value.
            if (cipher[i] < 'A') {                      // if the rotated char lies outside of the alphabetical ASCII
                cipher[i] = cipher[i] + 'Z' - 'A' + 1;  // corrects the value by changing char value to start of alphabet
            }
        } else {    // if the input char lies outside of the uppercase alphabetical range
            // does nothing, allowing the char to persist to the printed output
        }
    }
    printf("%s", cipher);   // prints the decrypted message
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