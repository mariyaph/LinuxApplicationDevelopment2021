#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
//#include "config.h"
#define PM 10
int main (int argc, char *argv[]) {
    if (argc < 4) {
     fprintf (stderr, "Not enough arguments\n");
     return 0;
    }
    char *str = argv[3];
    char *substr = argv[2];
    char *regexp = argv[1];
    int i;
    int b;
    int k;
    char msgbuf[100];
    char ch;
    int reti;
    regex_t r;
    regmatch_t pm[PM];
    reti = regcomp(&r, regexp, REG_EXTENDED);
    if (reti) {
        regerror(reti, &r,msgbuf,sizeof(msgbuf));
        fprintf(stderr,"Could not compile regex: %s\n", msgbuf);
        return 0;
    }
    reti = regexec(&r, str, PM, pm, 0);
    if (!reti) {
        for (i=0; i<pm[0].rm_so;i++) printf("%c",str[i]);
        b = 0;
        for ( i = 0; i < strlen(substr); i++) {
            ch = substr[i];
            if (ch == '\\') {
                if (b == 0)  b = 1;
                else {
                    printf("%c",'\\');
                    b = 0;
                }
            } else if (b != 0) {
                k=(int)ch - (int)'0';
                if ((k>=0) && (k <=9)) {
                    if (pm[k].rm_so < 0) {
                        fprintf(stderr, "Incorrect number of pocket\n");
                        return 0;
                    }
                    for (int j = pm[k].rm_so; j<pm[k].rm_eo; j++) printf("%c", str[j]);
                } else if (ch=='n') printf("%c",'\n');
                else printf("%c",ch);
                b = 0;
            } else if  (b == 0)  { 
               printf("%c", ch);
            }
         }
         if (b==1) {
             fprintf(stderr, "Unfinished command\n");
             return 0;
         }
         for (i=pm[0].rm_eo; i <strlen(str); i++) printf("%c",str[i]);
         printf("\n");
    } else if (reti == REG_NOMATCH) {
        puts("No Match");
    }  else {
        regerror(reti, &r,msgbuf,sizeof(msgbuf));
        fprintf(stderr,"Regex match failed: %s\n", msgbuf);
        return 0;
    }
    regfree(&r);
    return 0;
}