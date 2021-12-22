#include<stdio.h>
#include<string.h>
#include<libintl.h>
#include<locale.h>
#define _(string) gettext(string)
int main(void) {
    setlocale(LC_ALL, "");
    bindtextdomain("prog", "po");
    textdomain("prog");
    int a = 1 ,b = 100;
    int c;

    char ans[7];
    printf(_("Choose number from 1 to 100\n"));
    while (b - a > 0) {
        c = (b + a)/2;
        printf(_("Is the number greater than %d?\n"), c);
        scanf(" %s",ans);
        if (!(strcmp(ans, _("yes")))) a = c + 1;
        else if (!(strcmp(ans, _("no")))) b = c;
        else printf (_("Answer - yes or no\n"));
    }
    printf(_("Oh, I know... it's %d\n"), a);
    return 0;
}