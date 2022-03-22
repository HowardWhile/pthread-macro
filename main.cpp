
#include "my_class.hpp"
#include <stdio.h>

#define PAUSE printf("Press Enter key to continue...");  fgetc(stdin); 

int main (void)
{   
    PAUSE;
    my_class cc;
    cc.bg_func_start();
    PAUSE;
    cc.bg_func_close();
    PAUSE;
    printf("background work close...\r\n");
    PAUSE;
}