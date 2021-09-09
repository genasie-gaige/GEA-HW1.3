#include "pig_latin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char *translate(const char *phrase)
{
    char *phraseTranslated = calloc(10, sizeof(char));  
    char *hold = calloc(10, sizeof(char));      
    strcpy(phraseTranslated, phrase);
    int length = strlen(phraseTranslated);
    if((phrase[0] == 'x' && phrase[1] =='r') || 
        (phrase[0] == 'y' && phrase[1] == 't') || 
        phrase[0] == 'a' || phrase[0] == 'e' ||
        phrase[0] == 'i' || phrase[0] == 'o' || phrase[0] == 'u')
    {
        phraseTranslated[length++] = 'a';       
        length = strlen(phraseTranslated);
        phraseTranslated[length++] = 'y';
        return phraseTranslated;
    } 
    else
    {
        do
        {    
            int timesToRepeat = 1;
            if(phraseTranslated[0] == 'q' && phraseTranslated[1] == 'u')
            {
                timesToRepeat++;
            }  
            for(int i = 0; i < timesToRepeat; i++)   
            {
                hold[0] = phraseTranslated[0];
                int length = strlen(phraseTranslated);
                int firstLetter = 0;
                int secondLetter = 1;  
                while(secondLetter < length){
                    phraseTranslated[firstLetter] = phraseTranslated[secondLetter];
                    firstLetter++;
                    secondLetter++;
                }
                phraseTranslated[length--] = '\0'; 
                phraseTranslated[length--] = hold[0];
            }        
        }
        while (phraseTranslated[0] != 'a' && 
            phraseTranslated[0] != 'e' && 
            phraseTranslated[0] != 'i' && 
            phraseTranslated[0] != 'o' && 
            phraseTranslated[0] != 'u' &&
            phraseTranslated[0] != 'y');
        
        length = strlen(phraseTranslated);
        phraseTranslated[length++] = 'a';       
        length = strlen(phraseTranslated);
        phraseTranslated[length++] = 'y';
        return phraseTranslated; 
    }   
}


