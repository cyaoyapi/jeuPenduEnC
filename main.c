/*
========================================================================
    The goal of the hangman game is to find a hidden word
    in less than 10 tries.
=========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "pendu.h"

int main()
{
    /* Randomly choosing of the secret word from a list of word */
    char secret_word[LINE_SIZE] = "";
    selectSecretWord(secret_word); // using a function defined in pendu.c

    /* For displaying secret word */
    char secret_word_for_displaying[LINE_SIZE] = "";
    for(int i=0; i < strlen(secret_word) - 1; i++){ // initialisation
        secret_word_for_displaying[i] = '*';
    }

    printf("%s",secret_word);
    printf("%s",secret_word_for_displaying);

    return 0;
}
