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
#include "utils.h"

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


    int tries = 10; // Number of tries
    int proposed_character = 0;
    int continue_game = 1;

    printf("==============Bienvenue dans le jeu du pendu==============\n");
    while(continue_game){
        printf("Il vous reste %d coup(s) a jouer\n",tries);
        printf("Quel est le mot secret ? %s\n",secret_word_for_displaying);        printf("Proposez une lettre : ");
        proposed_character = readCharacter(); // reading the proposed character
        // Check if the proposed character is in the secret word
        if(existsIn(proposed_character, secret_word, secret_word_for_displaying) == 0){
            tries--;
        }
        //Check if the gamer wins the party
        if(toWinGame(secret_word_for_displaying)){
            printf("Bravo! Vous avez gangez. Le moot secret etait bien %s\n",secret_word);
            break;
        }else{
            if(tries == 0){
                printf("Vous avez epuisez le nombre de coups possibles.Vous avez perdu.\nVLe mot secret etait %s\n",secret_word);
                continue_game = 0;
            }
        }

    }


    return 0;
}
