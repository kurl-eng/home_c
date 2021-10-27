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
    struct data_set measures[range];
    print_days(&range);
    emul_measures(measures, range);
    //print_measures(measure, range);
    write_data_file(measures, range, "data.txt");
    int count = read_data_file(measures, "data.txt");
    if(count != -1) {
         print_data_file(measures, range);
     }
    save_bin_f(measures, range * sizeof(struct data_set), "data.bin");
    //memset(measures, 0, range * sizeof(struct data_set));
    //print_data_file(measures, range);
    load_bin_f(measures, range * sizeof(struct data_set), "data.bin");
    //print_data_file(measures, range);
    return 0;
}
