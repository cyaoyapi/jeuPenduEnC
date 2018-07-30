#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils.h"



/*
    Function to to clean the buffer.
*/

void cleanBuffer(){
    char character = 0;
    while(character != '\n' && character != EOF){
        character = getchar();
    }
}


/*
    Function to read a character.
*/

char readCharacter(){
    char character = 0;
    character = toupper(getchar());
    while(getchar() != '\n');
    return character;
}



/*
    Function to read the standard in with security.
*/
int readStdin(char* characters, int size){
    char* entryPosition = NULL; // To store the position of '\n' stored by function fgets

    if(fgets(characters, size, stdin) != NULL){
        entryPosition = strchr(characters,'\n');
        if(entryPosition != NULL){
            *entryPosition = '\0';

        }else{ // If we don't get '\n' : the entry overflow the available size
            cleanBuffer();
        }
        return 1;
    }
    else{
        cleanBuffer();
        return 0;
    }
}


/*
    Function to read a long entered by the user.
*/

long readLong(char* characters, int size){
    if(readStdin(characters, size)){
        return strtol(characters, NULL, 10);
    }else{
        return 0;
    }
}


/*
    Function to read a double entered by the user.
*/

double readDouble(char* characters, int size){
    char* entryPosition = NULL; // To store and remplace ',' by '.'
    if(readStdin(characters, size)){
        entryPosition = strchr(characters,',');
        if(entryPosition != NULL){
            *entryPosition = '.';
        }
        return strtod(characters, NULL);
    }else{
        return 0;
    }
}

