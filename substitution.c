#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_string(string arg_letters);
string encrypt_string(string plaintext, string cypher);

int main(int argc, string argv[])
{

    if (argv[2] || !argv[1])
    {
        printf("Error, please input one argument");
        return 1;
    }
    else if(strlen(argv[1])!=26)
    {
        printf("Error, cypher needs to be 26 characters");
        return 1;
    }
    else
    {
        if (check_string(argv[1]))
        {
            printf("Error, cypher is invalid");
            return 1;
        }
    }
    string plain_text = get_string("plaintext: ");
    string cypher_text = encrypt_string(plain_text, argv[1]);
    printf("ciphertext: %s\n", cypher_text);
}

bool check_string(string arg_letters)
{
   for (int i = 0, j = strlen(arg_letters); i < j; i++)
   {
      if (!isalpha(arg_letters[i]))
      {
        return true;
      }
      for (int k = i+1; k < j; k++)
      {
         if (arg_letters[i] == arg_letters[k])
         {
            return true;
         }

      }
   }
   return false;
}

string encrypt_string(string text, string cypher)
{
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (islower(text[i]))
        {
            text[i] = tolower(cypher[text[i] - 97]);
        }
        else if (isupper(text[i]))
        {
            text[i] = toupper(cypher[text[i] - 65]);
        }
    }
    return text;
}