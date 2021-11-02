#include <stdio.h>
#include <unistd.h>

#include "menu.h"
#include "help.h"
#include "fileops.h"

#define DBG(x) printf("DEBUG %s\n", x)

extern char *optarg;
extern int optind, opterr, optopt;

int main (int argc, char **argv)
{
    const char *f_src = NULL;
    const char *f_dst = NULL;

    //to avoid errors, uncomment next
    opterr = 0;

    int com;
    while ((com = getopt(argc, argv, "sdh")) != -1) {
        switch (com) {
        case 's' : {
            f_src = optarg;
            break; }
        case 'd' : {
            f_dst = optarg;
            break; }
        case 'h' : {
            help_com(argv[0]);
            return 0;
            break; }
        default : {
            printf("to help, type [-h]\n");
            //DBG("Found unknown option");
            break; }
        }
    }

    file_cp(f_src, f_dst);

}