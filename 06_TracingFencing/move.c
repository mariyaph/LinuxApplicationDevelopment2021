#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<string.h>
int finish(FILE *infile, FILE *outfile, char *delfile, char *output) {
        int err;
        errno = 0;
        if (fclose(outfile) == EOF) {
            perror("fclose outfile");
            err = errno;
            if (fclose(infile) == EOF) {
                perror("fclose infile");
            }
        if (remove(output)!=0) {
            perror("remove outfile");
        }
        return err;  
    }   
    errno = 0;
     if (fclose(infile) == EOF) {
         err = errno;
         perror("fclose infile");
         if (remove(output)!= 0) {
              perror("remove outfile");
         }
         return err;
    } 
    errno = 0;
    if (remove(delfile)!=0) {
       err=errno;
       perror("remove");
       if (strcmp(delfile,output)!=0) {
           if (remove(output)!=0) {
               perror("remove outfile");
           }
       }
       return err;
    }
    return 0;
}
int main(int argc, char *argv[])   {
    FILE * infile;
    FILE * outfile;
    int ch = 0;
    int err;
    if (argc != 3) {
         fprintf(stderr, "Usage: %s <infile> <outfile>\n", argv[0]);
        return 0;
    }
    errno = 0;
    infile = fopen(argv[1], "r");
    if (infile == NULL) {
        perror("fopen infile");
        return errno; 
    }
    errno = 0;
    outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        perror("fopen outfile");
        err = errno;
        if (fclose(infile) == EOF) {
             perror("fclose infile");
        }
        return err; 
    }
    errno = 0;
    ch = fgetc(infile);
    while (ch  != EOF) {
        errno = 0;
        if (fputc(ch,outfile)==EOF) {
            perror("fputc");
            err = errno;
         finish(infile,outfile,argv[2],  argv[2]);
            return err; 
        }
        errno = 0;
        ch = fgetc(infile);
    }
    if ((ch == EOF) && !(feof(infile)))  {
        perror("fgetc");
        err = errno;
        finish(infile, outfile, argv[2], argv[2]);
        return err;
    }
    return finish(infile, outfile, argv[1], argv[2]);
    
}
