
#include "my_class.hpp"
#include <stdio.h>

#define PAUSE printf("Press Enter key to continue...");  fgetc(stdin); 

int main (void)
{   
    my_class cc;

    printf("backgroud worker start...\r\n"); 
    PAUSE;        

    cc.bg_func1_Start();
    cc.bg_func2_Start();
    PAUSE;

    cc.bg_func1_Close(); 
    cc.bg_func2_Close(); 
    printf("backgroud worker close...\r\n");
    PAUSE;    

    printf("demo complete...\r\n");
}