#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pendu.h"

/*
 Function for selecting the secret word randomly
 among a list of words.
 This function assign the selected word in given
 char's pointer.

*/
void selectSecretWord(char* secret_word){
    FILE * fichier = NULL;
    const int MIN = 1;
    int max = countWords(); // Count the number of words in the list
    srand(time(NULL));
    int random_number = (rand() % (max - MIN + 1)) + MIN;
    int i = 1;

    fichier = fopen(WORDS_LIST_FILE,"r");
    if(fichier != NULL){
        while(fgets(secret_word,LINE_SIZE,fichier) != NULL){
            if(i == random_number){
                break;
            }else{
                i++;
            }
        }
        fclose(fichier);
    }
    else{
        exit(0);
    }

}


/*
 Function return the number of words in the list.
 It's use by the function : selectSecretWord
*/
int countWords(){
    FILE* fichier = NULL;
    int number_of_words = 0;
    char word[LINE_SIZE] = "";
    fichier = fopen(WORDS_LIST_FILE,"r");
    if(fichier != NULL){
        while(fgets(word,LINE_SIZE,fichier) != NULL){
            number_of_words = number_of_words + 1;
        }
        fclose(fichier);
    }else{
        exit(0);
    }
    return number_of_words;
}


/*
 Function to check if the proposed character by the gamer is in
 the secret word
*/
int existsIn(char proposed_character, char* secret_word, char* secret_word_for_displaying){
    int exists = 0;

    for(int i = 0; i < strlen(secret_word) -1; i++){
    	if(secret_word[i] == proposed_character){
    		secret_word_for_displaying[i] = proposed_character;
    		exists = 1;
    	}
    }
    return exists;

}


/*
 Function to check if the gamer wins the party.
 We check that there are not * in the char * secret_word_for_displaying
*/

int toWinGame(char* secret_word_for_displaying){
	int victory = 1;
	for(int i = 0; i < strlen(secret_word_for_displaying) - 1; i++){
		if(secret_word_for_displaying[i] == '*'){
			victory = 0;
		}
	}
	return victory;

}
