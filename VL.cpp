#include "VL.h"

VL::VL() : pcf(PCF8574_ADDRESS) {}

void VL::init() {
    Wire.begin(SDA_PIN, SCL_PIN);
    pcf.begin();                 

    for (int i = 0; i < SENSOR_COUNT; i++) {
        pcf.write(i, LOW);
    }
    delay(10);

    for (int i = 0; i < SENSOR_COUNT; i++) {
        pcf.write(i, HIGH);
        delay(10);

        if (sensors[i].begin(0x29)) {  
            sensors[i].setAddress(newAddresses[i]);  
            Serial.printf("Sensor %d initialized at 0x%02X\n", i, newAddresses[i]);
        } else {
            Serial.printf("Sensor %d failed to initialize.\n", i);
        }

        pcf.write(i, LOW); 
        delay(10);
    }
}

int* VL::measure() {
    VL53L0X_RangingMeasurementData_t measureData;

    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensors[i].rangingTest(&measureData, false);

        if (measureData.RangeStatus == 0) {
            measurements[i] = measureData.RangeMilliMeter;
        } else {
            measurements[i] = -1;  
        }
    }
    return measurements; 
}
