#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "structs.h"
#include "fileops.h"

int main(void)
{
    int range;
    input_days(&range);
    struct data_set measure[range];
    print_days(&range);
    emul_measures(measure, range);
    //print_measures(measure, range);
    write_data_file(measure, range, "data.txt");
    read_data_file(measure, "data.txt");
    print_data_file(measure, range);
    return 0;
}
