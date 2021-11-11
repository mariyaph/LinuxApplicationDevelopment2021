#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rhash.h"
#include <errno.h>
#ifdef FUN
  #include<readline/readline.h>
#endif  
int main (void) {
    char digest[64];
    char output[130];
    rhash_library_init();
    int res; 
    char *line = NULL;
    size_t n = 0;
    ssize_t nread;
    char *p1,*p2;
    int len;
    while (1) {
#ifndef FUN
   if ((nread = getline (&line, &n, stdin)) == -1) break;
#else
    if ((line = readline("")) == NULL) break;
#endif
        if ((p1 = strtok (line," ")) == NULL) {
            fprintf (stderr,"ERROR: ALG STRING/FILE\n");
            continue;
        }
        if ((p2 = strtok (NULL," \n\0")) == NULL) {
            fprintf(stderr, "ERROR: ALG STRING/FILE\n");
            continue;
        }
        
        if (!((strcmp(p1,"SHA1") == 0)||(strcmp(p1,"sha1") == 0)||(strcmp(p1,"TTH") == 0)||(strcmp(p1,"tth") == 0)||(strcmp(p1,"MD5") == 0)||(strcmp(p1,"md5") == 0))) {
            fprintf(stderr,"No such hash algorithm\n");
            continue;
        }
        if (p2[0] == '"') {
            p2++;
            len = strlen(p2);
            if (p2[len-1] == '"') len--;
            
            if ((p1[0] == 'S')||(p1[0] == 's'))  {
                if ((res = rhash_msg(RHASH_SHA1, p2, len, digest))<0) {
                     fprintf(stderr,"message digest calculation error");
                     continue;
                }
            }
            else if ((p1[0] == 'T')||(p1[0] == 't'))  {
                if ((res = rhash_msg(RHASH_TTH, p2, len, digest))<0) {
                     fprintf(stderr,"message digest calculation error");
                     continue;
                } 
            }
          else {
             if ((res = rhash_msg(RHASH_MD5, p2, len, digest))<0) {
                 fprintf(stderr,"message digest calculation error");
                 continue;
             }
          }
        }
        else {
            if ((p1[0] == 'S')||(p1[0] == 's'))  {
                if ((res = rhash_file(RHASH_SHA1, p2, digest)) <0 ) {
                    fprintf(stderr, "LibRHash error: %s: %s\n", p2, strerror(errno));
                    continue;
                 }
       }
            else if ((p1[0] == 'T')||(p1[0] == 't'))  {
                if ((res = rhash_file(RHASH_TTH, p2, digest)) <0 ) {
                     fprintf(stderr, "LibRHash error: %s: %s\n", p2, strerror(errno));
                     continue;
                 } 
        } else {
                if ((res = rhash_file(RHASH_MD5, p2, digest)) <0 ) {
                    fprintf(stderr, "LibRHash error: %s: %s\n", p2, strerror(errno));
                     continue;
                 }
              }    
        } 
         if (p1[0] == 'S'){
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1),(RHPR_HEX | RHPR_UPPERCASE));
        } else if (p1[0] == 's') {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1),(RHPR_BASE32 | RHPR_UPPERCASE));
        } else if (p1[0] == 'T') {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH),(RHPR_HEX | RHPR_UPPERCASE));
        } else if (p1[0] == 't') {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH),(RHPR_BASE32 | RHPR_UPPERCASE));
        } else if (p1[0] == 'M') {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5),(RHPR_HEX | RHPR_UPPERCASE));
        } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5),(RHPR_BASE32 | RHPR_UPPERCASE));
        }        
      printf ("%s\n",output); 
    }
    free(line);
    return 0;
}