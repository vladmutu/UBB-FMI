#include "my_utils.h"
#pragma once
void trimTrailing(char* str)
{
    int index, i;

    /* Set default index */
    index = -1;

    /* Find last index of non-white space character */
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            index = i;
        }

        i++;
    }

    /* Mark next character to last non-white space character as NULL */
    str[index + 1] = '\0';
}

void removeSpacesNewLinesFromInput()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}
