#ifndef QTR_H
#define QTR_H

#include <Arduino.h>

class  QTR {
public:
    QTR(); 
    int init(int Pin1, int Pin2, int Pin3, int Pin4); 
    bool medir(int pin);
};

#endif