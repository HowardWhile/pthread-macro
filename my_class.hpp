#ifndef MY_CLASS_H
#define MY_CLASS_H

#pragma once

#include "my_macro.hpp"
#include <unistd.h>
#include <iostream>

class my_class
{
public:
    int count1;
    int count2;

    my_class()    
    {
        this->count1 = 0;
        this->count2 = 0;
    }

    ~my_class()
    {

    }

    BACKGROUND_WORKER(my_class, add)
    {
        while (true)
        {
            this->count1++;
            std::cout << "out from my_class::add:\t" << this->count1 << std::endl;
            usleep(100000);
        }
    }

    BACKGROUND_WORKER(my_class, sub)
    {
        while (true)
        {
            this->count2--;
            std::cout << "out from my_class::sub:\t" << this->count2 << std::endl;
            usleep(100000);
        }
    }

private:
};

#endif