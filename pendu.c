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
