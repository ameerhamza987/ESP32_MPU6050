// MPU6050 Library for ESP-32
// Written by: Muhammad Ameer Hamza
// Date of creation: 20-04-2024
// Library Includes Following:
//  ---------------------------------------------------------
//  |   Functionality                         | Description |
//  ---------------------------------------------------------
//  |       ReadAccel                         |Read        |
//  |       ReadGyro                          |Read        |
//  |       calculateRoll                     |Read        |
//  |       calculatePitch                    |Read        |
//  |       estimateAngleFromQuaternions      |Read        |
//  ---------------------------------------------------------
//   mpu.readAccel(ax, ay, az);
//   mpu.readGyro(gx, gy, gz);
//   roll = mpu.calcRoll(ax, ay, az);
//   pitch = mpu.calcPitch(ax, ay, az);
//   mpu.AngelQuaternion(roll, pitch, yaw);
//
//
// Repository:
// The source code for this library can be found on GitHub/GitLab at:
// https://github.com/ameerhamza987/ESP32_MPU6050

#include <Wire.h>

#ifndef MPU6050_H
#define MPU6050_H
class MPU6050
{

public:
    MPU6050(uint8_t address = 0x68); // The default value of the register is 0x68
    // Initialize the MPU6050
    bool begin();
    // fucntion to read acceleration data
    void readAccel(float &accelX, float &accelY, float &accelZ);
    // fucntion to read acceleration data
    void readGyro(float &gyroX, float &gyroY, float &gyroZ);
    // function to calculate roll using acclerometer
    float calcRoll(float accelX, float accelY, float accelZ);
    // function to calculate pitch using acclerometer
    float calcPitch(float accelX, float accelY, float accelZ);
    // function to estimate angel from quaternion
    void AngelQuaternion(float &roll, float &pitch, float &yaw);

private:
    uint8_t i2cAddr; // I2C address of MPU6050

    // Private function to read data from MPU6050
    void readMPU6050(uint8_t regAddr, uint16_t &data);
};
#endif