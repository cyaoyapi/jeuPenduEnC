#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils.h"

char readCharacter(){
    char character = 0;
    character = toupper(getchar());
    while(getchar() != '\n');
    return character;
}
