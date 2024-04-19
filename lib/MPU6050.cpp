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

#include "MPU6050.h"
#include <math.h>

// Constructor
MPU6050::MPU6050(uint8_t address) : i2cAddr(address) {}

// Initialize the MPU6050
bool MPU6050::begin() {
    Wire.begin();
    // Initialize the MPU6050 with configuration from the datasheet where the Slave address for MPU6050 is 0x68
    Wire.beginTransmission(i2cAddr);
    Wire.write(0x6B); // Power Management 1 register, allows the user to configure the power mode and clock source.
    Wire.write(0x6C); // Wake up MPU6050
    Wire.endTransmission(true);
    
    // Additional configurations can be added here if necessary
    return true;
}