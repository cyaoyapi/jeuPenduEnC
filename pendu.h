#ifndef PENDU_H_INCLUDED
#define PENDU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_LIST_FILE "liste_mots.txt"
#define LINE_SIZE 20
void selectSecretWord(char*);
int countWords();
int existsIn(char, char*, char*);
int toWinGame(char*);

#endif // PENDU_H_INCLUDED
