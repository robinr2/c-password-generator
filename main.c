#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

unsigned int get_password_length(unsigned int min_password_length, unsigned int max_password_length) 
{
    printf("Passwort-Generator\n");
    
    unsigned int password_length;
    while (1)
    {
        printf("\nLänge des Passworts: ");
        scanf("%d", &password_length);
        
        if (password_length < min_password_length || password_length > max_password_length)
        {
            printf("Ungültige Eingabe: Das Passwort muss %d-%d Zeichen lang sein.\n", min_password_length, max_password_length);
            continue;
        }
        
        break;
    }
    
    return password_length;
}

unsigned char get_include_special_characters()
{
    while (1)
    {
        char include_special_characters;
        printf("Sonderzeichen hinzufügen? (j/n) ");
        scanf(" %c", &include_special_characters);
        
        switch (include_special_characters)
        {
            case 'j':
                return 1;
            case 'n':
                return 0;
            default:
                printf("Ungültige Eingabe: Gebe \"j\" für ja oder \"n\" für nein ein.\n\n");
                break;
        }
    }
}

int get_random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main() 
{    
    const int MIN_PASSWORD_LENGTH = 8;
    const int MAX_PASSWORD_LENGTH = 20;
    
    unsigned int password_length = get_password_length(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    unsigned char include_special_characters = get_include_special_characters();
    
    const char* UPPERCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* LOWERCASE_LETTERS = "abcdefghijklmnopqrstuvwxyz";
    const char* DIGITS = "0123456789";
    const char* SPECIAL_CHARACTERS = ".!?()[]{}";
    const char* CATEGORIES[4] = {UPPERCASE_LETTERS, LOWERCASE_LETTERS, DIGITS, SPECIAL_CHARACTERS};
    const int MAX_CATEGORY_INDEX = include_special_characters ? 3 : 2;

    char* password = (char*)calloc(password_length, sizeof(char));
    srand(time(0)); 
    for (int i = 0; i < password_length; i++)
    {
        int random_category = get_random_number(0, MAX_CATEGORY_INDEX);
        int random_symbol = get_random_number(0, sizeof(CATEGORIES[random_category]));
        password[i] = CATEGORIES[random_category][random_symbol];
    }
    
    printf("Passwort: %s", password);
    
    free(password);
    
    return 0;
}  
