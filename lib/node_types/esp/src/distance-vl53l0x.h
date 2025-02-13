// distance-vl53l0x.h
// I2C Time of flight distance sensor

#ifndef _IOTEMPOWER_VL53L0X_H_
#define _IOTEMPOWER_VL53L0X_H_

#include <Arduino.h>
#include <i2c-device.h>

#include <VL53L0X.h> // here only this in cpp MPU6050_6Axis_MotionApps20.h

#define IOTEMPOWER_VL53L0X_MAXDIST 8190

class Distance_Vl53l0x : public I2C_Device {
    private:
        bool _calibrate = false;
        int _precision = 1;
        bool _long_range;
        bool _high_accuracy_slow;
        unsigned long starttime;
        bool discard_done = false;
        VL53L0X *sensor = NULL;
    public:
        Distance_Vl53l0x(const char* name, 
                    bool long_range=false, bool high_accuracy_slow=false);
        Distance_Vl53l0x& with_precision(int precision) {
            if(precision < 1) precision = 1;
            _precision = precision;
            return *this;
        }

        void i2c_start();
        bool measure();
};

#endif // _IOTEMPOWER_VL53L0X_H_