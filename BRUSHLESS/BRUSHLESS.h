#ifndef BRUSHLESS_H
#define BRUSHLESS_H

#include <Arduino.h>

class  BRUSHLESS {
public:
    BRUSHLESS(); 
    int init(); 
    int drive(int M1, int M2, int M3, int M4);
};

#endif