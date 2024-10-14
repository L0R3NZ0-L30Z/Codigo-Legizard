#ifndef VL_H
#define VL_H

#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <PCF8574.h>

#define SDA_PIN 36
#define SCL_PIN 35
#define PCF8574_ADDRESS 0x20
#define SENSOR_COUNT 6

class VL {
public:
    VL();               
    void init();                      
    int measure(uint8_t sensorAddress); 

private:
    PCF8574 pcf;           
    Adafruit_VL53L0X sensors[SENSOR_COUNT]; 
    const uint8_t newAddresses[SENSOR_COUNT] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35};

    void initializeSensor(uint8_t index);
};

#endif
