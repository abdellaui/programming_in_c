#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "regxp.h"

/*
 *
 */
int main(int argc, char** argv)
{
    char **results;
    int i = 0;
    results = preg_match("(\\w+):(\\w+)", "Word:abbrevation:discous:dictionary:list:hashmap");

    while(results[i] != NULL)
    {
        printf("%s\n", results[i]);
        i++;
    }
    printf("\t --- \t\n");
    results = NULL;
    struct resulter **resultset = preg_match_all("(\\w+):(\\w+)", "Word:abbrevation:discous:dictionary:list:hashmap");
    i = 0;

    printf("asd: %d\n", resultset[0]->info->countOfMatches);
    printf("cd: %d\n", sizeof(resultset));
    while(resultset[i])
    {
        printf("%s\n", resultset[i]->match);
        printf("%s\n", resultset[i]->info->pattern);
        i++;
    }

    return (EXIT_SUCCESS);
}
