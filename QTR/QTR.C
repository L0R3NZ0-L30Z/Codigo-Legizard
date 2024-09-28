#include "QTR.h"

QTR::QTR() {

}

void QTR::init(int Pin1, int Pin2, int Pin3, int Pin4,) {
    pinMode(Pin1, INPUT);
    pinMode(Pin2, INPUT);
    pinMode(Pin3, INPUT);
    pinMode(Pin4, INPUT);
}


bool QTR::medir(int Pin) {
    int var = analogRead(Pin);
    if(var < 551) return false;
    else return true;
} 