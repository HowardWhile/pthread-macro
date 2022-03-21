
#include "my_class.hpp"
#include <stdio.h>

#define PAUSE printf("Press Enter key to continue...");  fgetc(stdin); 

int main (void)
{   
    PAUSE;
    my_class cc;
    cc.bg_add_start();
    cc.bg_sub_start();
    PAUSE;
    cc.bg_add_close();
    cc.bg_sub_close();
    PAUSE;
    printf("background work close...\r\n");
    PAUSE;
}