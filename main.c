#include <stdio.h>
#include <string.h>

void encryptRotationCipher(char message[], int key);
void decryptRotationCipher(char cipher[], int key);

void encryptSubCipher(char message[], char substitution[]);
void decryptSubCipher(char cipher[], char substitution[]);

void decryptRotationCipherAdv(char cipher[]);
void decryptSubCipherAdv(char cipher[]);

int main() {
    int selection, key;
    char message[256];
    
    printf("Please make a selection: \n");
    printf("Enter 1 for encryption using a rotation cipher\n");
    printf("Enter 2 for decryption using a rotation cipher\n");
    printf("Enter 3 for encryption using a substitution cipher\n");
    printf("Enter 4 for decryption using a substitution cipher\n");
    printf("Enter any other character to exit.\n");
    
    do {
        scanf("%d", &selection);
        
        
        switch(selection) {
            case 1:
                
                printf("Please enter a message to encrypt: \n");
                scanf("%s", message);
                printf("%s", message);
                printf("Please enter a key (integer) for rotation\n");
                scanf("%d", key);
                
                encryptRotationCipher(message, key);
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (selection >= 1 && selection <= 4);
    
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
    
    printf("Encrypted message: %s\n", message);  // prints the encrypted message
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
    
    for (i = 0 ; cipher[i] != '\0' ; i++) {     // loops through each char contained within the cipher string
                                                // until the \0 at the end of the string is reached.
        
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {     // if the char is lowercase, converts char to uppercase
            cipher[i] -= 32;                            // by subtracting 32 from the char value.
        } 
        
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {     // if the char is uppercase alphabetical, rotates the 
            cipher[i] -= key;                           // char value backwards by the input key value.
            if (cipher[i] < 'A') {                      // if the rotated char lies outside of the alphabetical ASCII
                cipher[i] = cipher[i] + 'Z' - 'A' + 1;  // corrects the value by changing char value to end of alphabet
            }
        } else {    // if the input char lies outside of the uppercase alphabetical range
            // does nothing, allowing the char to persist to the printed output
        }
    }
    printf("Decrypted message: %s\n", cipher);   // prints the decrypted message
}

// The below function encrypts a message, input as a string
// by replacing each char with the corresponding char
// of the given key, also input as a string of 26 different uppercase alphabetical char.
// Any punctuation input into the function is ignored and will
// persist through to the output, being a printed encrypted message.
// Example "THE QUICK BROWN FOX" encrypted with the key "BADCFEHGJILKNMPOSQRVTUYZXW"
// will print "VGF STJDL AQPYM EPZ".

void encryptSubCipher (char message[], char key[]) {
    
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // creates a string of the alphabet, used to find the index of chars
    char *finder;                                   // creates a char pointer
    int index, i;
    
    for (i = 0 ; message[i] != '\0' ; i++) {        // loops through each char contained within the message string
                                                    // until the \0 at the end of the string is reached.
        
        if (message[i] >= 'a' && message[i] <= 'z') {   // if the char is lowercase, converts char to uppercase
            message[i] -= 32;                           // until the \0 at the end of the string is reached.
        }

        if (message[i] >= 'A' && message[i] <= 'Z') {   // if the char is uppercase alphabetical,
            finder = strchr(alphabet, message[i]);      // sets the char pointer to where the char is found in the alphabet.
            index = (int)(finder - alphabet);           // sets index to the numerical index of the char, by casting the difference
                                                        // between the characters first instance and the start of the alphabet to an int.
            message[i] = key[index];                    // sets the char of the message to the corresponding char in the key string that
                                                        // holds the same numerical index.
        } else {  // if the input char lies outside of the uppercase alphabetical range
        // does nothing, allowing the char to persist to the output.
        }
    }

    printf("Encrypted message %s\n", message);  // prints the encrypted message
}

// The below function decrypts a cipher, input as a string
// by replacing each char with the corresponding char
// of the given key, also input as a string of 26 different uppercase alphabetical char.
// Any punctuation input into the function is ignored and will
// persist through to the output, being a printed encrypted message.
// Example "VGF STJDL AQPYM EPZ" decrypted with the key "BADCFEHGJILKNMPOSQRVTUYZXW"
// will print "THE QUICK BROWN FOX".

void decryptSubCipher (char cipher[], char key[]) {
    
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // creates a string of the alphabet, used to find the index of chars
    char *finder;                                   // creates a char pointer
    int index, i;
    
    for (i = 0 ; cipher[i] != '\0' ; i++) {         // loops through each char contained within the cipher string
                                                    // until the \0 at the end of the string is reached.
        
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {     // if the char is lowercase, converts char to uppercase
                cipher[i] -= 32;                        // until the \0 at the end of the string is reached.
        }
       
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {     // If the char is uppercase alphabetical,
            finder = strchr(key, cipher[i]);            // Sets the char pointer to where the char is found in the key.
            index = (int)(finder - key);                // Sets index to the numerical index of the char, by casting the difference
                                                        // between the characters first instance and the start of the key to an int.
            cipher[i] = alphabet[index];                // Sets the char of the message to the corresponding char in the alphabet string that
                                                        // holds the same numerical index.
        } else {    // if the input char lies outside of the uppercase alphabetical range         
            // does nothing, allowing the char to persist to the output.
        }
    }       
    
    printf("Decrypted message: %s\n", cipher);   // prints the decrypted message
} 