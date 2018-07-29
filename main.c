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
    printf("%s",secret_word);
    return 0;
}
