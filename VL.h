#ifndef VL_H
#define VL_H

#include <Arduino.h>

class  VL {
public:
    VL(); 
    int init(); 
    float medir(int direccion);
};

#endif