#include <stdio.h>

void encryptRotationCipher(char message[], int key);
void decryptRotationCipher(char cipher[], int key);

void encryptSubCipher(char message[], char substition[]);
void decryptSubCipher(char cipher[], char substition[]);

void decryptRotationCipherAdv(char cipher[]);
void decryptSubCipherAdv(char cipher[]);

int main()
{
    
    char message[] = "yeet";
    int key = 0;
    
    encryptRotationCipher(message, key);
    
    return 0;
}

void encryptRotationCipher(char message[], int key) 
{
    int i;
    char letter;
    
    for (i = 0 ; message[i] != '\0' ; i++)
    {
        letter = message[i];
        
        if (letter >= 'a' || letter <= 'z')
        {
            letter -= 32;
        }   else if (letter < 'A' || letter > 'Z') 
        {
            printf("Please enter only alphabetical characters");
            break;
        }
        
        letter = (letter + key);
        
        if (letter > 'Z')
        {
            letter = letter - 'Z' + 'A' - 1;
        }
        
        message [i] = letter;
    }
    
    printf ("%s", message);
}