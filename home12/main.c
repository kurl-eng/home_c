#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "menu.h"
#include "help.h"
#include "fileops.h"

#define BUFFER 1024
#if defined DEBUG
#define DBG(x) printf("%s, func: %s, line: %d\n", x, __func__, __LINE__)
#else
#define DBG(x)
#endif

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
            DBG("getopt found source file");
            f_src = argv[optind];
            //f_src = optarg;
            //printf("Found source option string %s optind %d optopt %d opterr %d\n",
                    //optarg, optind, optopt, opterr);
            break; }
        case 'd' : {
            DBG("getopt found destination file");
            f_dst = argv[optind];
            //f_dst = optarg;
            //printf("Found destination option string %s optind %d optopt %d opterr %d\n",
                    //optarg, optind, optopt, opterr);
            break; }
        case 'h' : {
            help_com(argv[0]);
            return 0;
            break; }
        default : {
            printf("to help, type [-h]\n");
            DBG("Found unknown option");
            return 0;
            break; }
        }
    }

    //отладка трассировкой.
    DBG("ARGUMENTS IN FUNCTION");
    //не могу передать в функцию данные через optarg
    file_cp(f_src, f_dst);
}