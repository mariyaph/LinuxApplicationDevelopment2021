#include <curses.h>
#include <locale.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define DX 3
int main (int argc, char *argv[]) {

    if (argc<2) {
        fprintf(stderr,"No argument");
        return 0;
    }
    int file = open(argv[1],O_RDONLY);
    if (file == -1) {
        fprintf (stderr,"Can't open file");
        return 0;
    }
    
    struct stat info;
    stat(argv[1], &info);
    int len = info.st_size;
    
    char *buf = malloc(sizeof(char)*(len+2));
    read(file,buf,len);
    int num = 0;
    char a = '\n';
    char *p = buf;
    while ((p = strchr(p+1,a)) != NULL)  num++;

    char **s = calloc(num+2,sizeof(char*));
    s[0] = buf;
    s[num+1] = buf + len + 1;
    p = buf;
    int i=0;
    while ((p = strchr(p+1,a)) != NULL) {
        i+=1;
        s[i] = p+1;
    }

    WINDOW *win;
    setlocale(LC_ALL,"ru_RU.UTF-8");
    initscr ();
    noecho();
    cbreak();
    printw(argv[1]);
    refresh();
    
    int l_y = LINES - 2*DX;
    int l_x = COLS - 2*DX;
    win = newwin(l_y, l_x, DX, DX);
    keypad(win, TRUE);
    
    int page = 1;
    int c = 0;
    int flag = 0;
    int page_max = (num+l_y)/(l_y-2);
    int dx = 0;
    int n_y, n_x;
    while (flag == 0) {
        werase(win);
        wmove(win, 1,0);
        n_y = (num+1<page*(l_y-2))?num+1:page*(l_y-2);
        for (i = (page-1)*(l_y-2); i<n_y;i++) {
            n_x = s[i+1] - 1 - (s[i]+dx);
            if (n_x<=0) {n_x = 0; }
            else if (n_x > l_x-6) { n_x = l_x-6; }
            wprintw(win,"  %2d:", i+1);
            if (n_x > 0) waddnstr(win,s[i]+dx,n_x);
            wprintw(win,"\n");
        }
        box(win,0,0);

        switch (c = wgetch(win)) {
            case 27:
                flag = 1;
                break;
            case ' ':
            case KEY_DOWN:
                if (page+1<=page_max) page++;
                break;
            case KEY_UP:
                if (page-1>=1) page--;
                break;
            case KEY_RIGHT:
                dx++;
                break;    
            case KEY_LEFT:
                if (dx-1>=0) dx--;
                break;
        }
    } 
    endwin ();
    free(buf);
    free(s);
    close(file);
    return 0;
}