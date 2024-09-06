#ifndef MEDICIONES_H
#define MEDICIONES_H

#include <Arduino.h>

class  MEDICIONES {
public:
    MEDICIONES(); 
    int init(); 
    float medicion();
};

#endif