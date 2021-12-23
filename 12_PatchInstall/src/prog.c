#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<libintl.h>
#include<locale.h>
#include "config.h"
#include <argp.h>
#define _(string) gettext(string) 

const char *argp_program_version = "prog 0.0";
const char *argp_program_bug_address = "bug@gmail.com";
static char doc[] = "GUESSING GAME -- a program that guesses which number you have chosen from 1 to 100";
static struct argp_option options[] =  {
    {"roman", 'r', 0, 0, "Use roman numerical system" },
    {0}
};               
struct arguments  {
    int roman;
};
static error_t parse_opt (int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'r':
            arguments->roman = 1;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
      }
        return 0;
 }
static struct argp argp = {options, parse_opt, NULL, doc};

void to_roman(char *roman, int x) {
    int div = x / 10;
    int mod  = x % 10;
    int k = 0;
    switch (div) {
        case 1:
            roman[k++]='X';
            break;
        case 2:
            roman[k++]='X';
            roman[k++]='X';
            break;
        case 3:
            roman[k++]='X';
            roman[k++]='X';
            roman[k++]='X';
            break;
        case 4:
            roman[k++]='X';
            roman[k++]='L';
            break;
        case 5:
            roman[k++]='L';
            break;
        case 6:
            roman[k++]='L';
            roman[k++]='X';
            break;        
        case 7:
            roman[k++]='L';
            roman[k++]='X';
            roman[k++]='X';
            break;
        case 8:
            roman[k++]='L';
            roman[k++]='X';
            roman[k++]='X';
            roman[k++]='X'; 
            break;   
        case 9:
            roman[k++]='X';
            roman[k++]='C';
            break;
        case 10:
            roman[k++]='C';
    }
    switch (mod) {
        case 1:
            roman[k++]='I';
            break;
        case 2:
            roman[k++]='I';
            roman[k++]='I';
            break;
        case 3:
            roman[k++]='I';
            roman[k++]='I';
            roman[k++]='I';
            break;
        case 4:
            roman[k++]='I';
            roman[k++]='V';
            break;
        case 5:
            roman[k++]='V';
            break;
        case 6:
            roman[k++]='V';
            roman[k++]='I';
            break;        
        case 7:
            roman[k++]='V';
            roman[k++]='I';
            roman[k++]='I';
            break;
        case 8:
            roman[k++]='V';
            roman[k++]='I';
            roman[k++]='I';
            roman[k++]='I'; 
            break;   
        case 9:
            roman[k++]='I';
            roman[k++]='X';
            break;
    }
    roman[k]='\0';
}

int from_roman(char *roman) {
    int x = 0;
    int a = 0;
    int b = 0;
    int i = 0;
    while (roman[i]!='\0') {
        switch(roman[i]) {
            case 'I': 
                b = 1;
                break;
            case 'V': 
                b = 5;
                break;
            case 'X': 
                b = 10;
                break;
            case 'L':  
                b = 50;
                break; 
            case 'C': 
               b = 100;
               break;
        }       
        if (a>=b) x += a; 
        else x -= a; 
        a = b;
        i++;
    }
    x += a;
    return x;
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain(PACKAGE, LOCALE_PATH);
    textdomain(PACKAGE);
    struct arguments arguments;
    arguments.roman = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    
    char roman[9];
    int a = 1 ,b = 100;
    int c;
    char ans[7];
    if (arguments.roman) {
        printf(_("Choose number from I to C\n"));
    } else {
        printf(_("Choose number from 1 to 100\n"));
    } 
    while (b - a > 0) {
        c = (b + a)/2;
        if (arguments.roman) {
            to_roman(roman, c);
            printf(_("Is the number greater than %s?\n"), roman);
        } else {
            printf(_("Is the number greater than %d?\n"), c);
        }
        scanf(" %s",ans);
        if (!(strcmp(ans, _("yes")))) a = c + 1;
        else if (!(strcmp(ans, _("no")))) b = c;
        else printf (_("Answer - yes or no\n"));
    }
    if (arguments.roman) {
        to_roman(roman, a);
        printf(_("Oh, I know... it's %s\n"), roman);
    } else {
        printf(_("Oh, I know... it's %d\n"), a);
    }
    
    return 0;
}