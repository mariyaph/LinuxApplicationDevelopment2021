#define _GNU_SOURCE
#include<dlfcn.h>
#include<string.h>
typedef int (*remove_type)(const char *fname);
int remove (const char *fname) {
    remove_type trueremove;
    trueremove = (remove_type)dlsym(RTLD_NEXT, "remove");
    if (!strstr(fname,"PROTECT")) {
        return trueremove(fname);
    } else {
        return 0;
    }

}