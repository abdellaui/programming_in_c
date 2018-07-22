/*
 * File:   Regxp.h
 * Author: solution
 *
 * Created on 11. listopad 2011, 16:00
 */
#include <stdio.h>
#include <string.h>
#include <pcre.h>

#define COUNT(a, b) (sizeof(a)/sizeof(b))

#ifndef REGEX_H
#define	REGEX_H
#define OVECCOUNT 30

char *preg_error(int rc);

pcre *preg_compile(char* regxp);

char **preg_match(char *regxp, char *data, int resultLimit);

char **preg_match_all(char *regxp, char *data, int resultLimit);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif



#endif /* REGXP_H */
