#ifndef QTR_H
#define QTR_H

#include <Arduino.h>

class  QTR {
public:
    QTR(); 
    void init(int Pin1, int Pin2, int Pin3, int Pin4); 
    bool medir(int Pin); //Dentro de los parentesis van todos los valores a mostrar
};

#endif

// TUTORIAL - https://www.youtube.com/watch?v=OcN34M_JUy8