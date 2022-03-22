#ifndef MY_CLASS_H
#define MY_CLASS_H

#pragma once

#include "my_macro.hpp"
#include <unistd.h>
#include <iostream>

class my_class
{
public:
    int count;

    my_class()    
    {
        this->count = 0;
    }

    ~my_class()
    {

    }

    BACKGROUND_WORKER(my_class, bg_func)
    {
        while (true)
        {
            this->count++;
            std::cout << "out from my_class::func:\t" << this->count << std::endl;
            usleep(100000);
        }
    }

private:
};

#endif