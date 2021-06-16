#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isValid(string s);

int main(int argc, string argv[])
{
    if ((argc != 2) || (isValid(argv[1]) == 0))
    {
        printf("./caesar key\n");
        return 1;
    }
    else
    {
            
        string alphacount = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";// a string that's contain the alphabetical digits
            
        string plaintext = get_string("plaintext: ");
        int num = atoi(argv[1]);// a variable that  stores the number typed by the user
        int len = strlen(plaintext);
        for (int i = 0; i < len; i++)
        {
                
            if (isupper(plaintext[i]))
            {
                plaintext[i] = (int) plaintext[i] % (int)'A';//modulum of 'A' so it stores a number from 0 to 25, for implement in alphacount
                int temp = ((int) plaintext[i] + num) % 26 ;
                plaintext[i] = alphacount[(temp)];
            }
            else if (islower(plaintext[i]))
            {
                plaintext[i] = plaintext[i] % 'a';//modulum of 'a' so it stores a number from 0 to 25, for implement in alphacount
                int temp = ((int) plaintext[i] + num) % 26 ;
                plaintext[i] = alphacount[(temp)];//alphacount only stores uppercase so it requires the tolower extension
                plaintext[i] = tolower(plaintext[i]);//that is of lowercase letters so it must continue as lowercase
                   
            }
            else
            {
                plaintext[i] = plaintext[i];
            }
        
            printf("ciphertext: %s\n", plaintext);
            
        }
    
    }
}

    bool isValid(string s)
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if (isdigit(s[i]) == false)
            {
                return 0;
                break;
            }
        }
    
        return 1;
    }
