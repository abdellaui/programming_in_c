#include "Regex.h"

pcre *preg_compile(char* regxp)
{
    pcre *re; // Pcre pointer
    const char *error; // Const char error pointer
    int errorOffset;

    re = pcre_compile(
            regxp, /* regexp */
            PCRE_MULTILINE, /* default options */
            &error, /* for error message */
            &errorOffset, /* for error offset */
            NULL /* use default character tab*/
            );

    if(!re)
    {
        printf("PCRE compilation failed at expression offset %d: %s\n",
                errorOffset,
                error);
        exit(1);
    }

    return re;
}

char *preg_error(int rc)
{
    char *errorMsg = (char*) malloc(128);

    switch(rc)
    {
        case PCRE_ERROR_NOMATCH :
            errorMsg = "No match found in string \n";
        break;

        case PCRE_ERROR_MATCHLIMIT :
            errorMsg = "Match is out of possible matches \n";
        break;

        case PCRE_ERROR_NOMEMORY :
            errorMsg = "Out of memory \n";
        break;

        default:
            sprintf(errorMsg, "Match error %d \n", rc);
        break;
    }

    return errorMsg;
}

char **preg_match(char *regxp, char *data, int resultLimit)
{
    pcre *re = preg_compile(regxp); // Pcre pointer
    int rc, ovector[OVECCOUNT]; //state integers

    rc = pcre_exec(
            re, /* The compiled pattern */
            NULL, /* No extra data */
            data, /* the subject string */
            strlen(data), /* Length of subject */
            0, /* Start at offset 0*/
            0, /* Default options */
            ovector, /* Output vector for substring info */
            OVECCOUNT); /* Number of elements in the output */

    if(rc < 0)
    {
        printf("%s", preg_error(rc));
        exit(1);
    }

    char **results = (char**) malloc(resultLimit * sizeof(char*));

    if(rc < 3)
    {
        printf("Match did not catch all the groups \n");
    }else{
        char *tmp;
        int i = 3, it = 0, tmpInt = 0;

        for(it; it < resultLimit; it++)
        {
            tmp = data + ovector[i-1];
            tmpInt = ovector[i] - ovector[i-1];
            results[it] = (char*) malloc(tmpInt + 1);
            sprintf(results[it], "%.*s", tmpInt, tmp);
            i += 2;
        }
    }
    return results;
}


char **preg_match_all(char *regxp, char *data, int resultLimit)
{
    pcre *re = preg_compile(regxp); // Pcre pointer
    int rc, ovector[OVECCOUNT], offsetStart = 0; //state integers

    char **results = (char**) malloc(OVECCOUNT * sizeof(char*));
    int it = 0, ite = 0;

    while((rc = pcre_exec(
            re, /* The compiled pattern */
            NULL, /* No extra data */
            data, /* the subject string */
            strlen(data), /* Length of subject */
            offsetStart, /* Start at offset 0*/
            0, /* Default options */
            ovector, /* Output vector for substring info */
            OVECCOUNT)) > 0) /* Number of elements in the output */
    {
        char *tmp;
        int tmpInt = 0, i = 3;

        for(it; it < resultLimit; it++)
        {
            tmp = data + ovector[i-1];
            tmpInt = ovector[i] - ovector[i-1];
            results[ite] = (char*) malloc(tmpInt + 1);
            sprintf(results[ite], "%.*s", tmpInt, tmp);
            i += 2; ++ite;
        }
        it = 0;
        offsetStart = ovector[i-2];
        (*ovector) = NULL;
    }

    return results;
}
