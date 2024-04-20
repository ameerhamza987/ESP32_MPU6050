// MPU6050 Library for ESP-32
// Written by: Muhammad Ameer Hamza
// Date of creation: 20-04-2024
// Libraryb Includes Following:

//  ---------------------------------------------------------
//  |   Functionality                         | Description |
//  ---------------------------------------------------------
//  |       ReadAccel                         |Read        |
//  |       ReadGyro                          |Read        |
//  |       calculateRoll                     |Read        |
//  |       calculatePitch                    |Read        |
//  |       estimateAngleFromQuaternions      |Read        |
//  ---------------------------------------------------------
//
// Description:
// This library provides a set of functions to interface with the MPU6050 IMU sensor over I2C using ESP-32. It includes functions for reading acceleration data, reading gyroscope data, calculating roll and pitch, and estimating angles from quaternions. The library is designed to be simple to use and integrates seamlessly with the Arduino framework.
//
// Usage:
// - Include the library in your project:
//   #include "MPU6050.h"
//
// - Create an instance of the MPU6050 class with the default I2C address (0x68):
//   MPU6050 mpu;
//
// - Initialize the sensor in the setup() function:
//   mpu.begin();
//
// - Use the library functions to read data and calculate angles in the loop() function:
//   float ax, ay, az;
//   float gx, gy, gz;
//   float roll, pitch, yaw;
//
//   mpu.readAcceleration(ax, ay, az);
//   mpu.readGyroscope(gx, gy, gz);
//   roll = mpu.calculateRoll(ax, ay, az);
//   pitch = mpu.calculatePitch(ax, ay, az);
//   mpu.estimateAngleFromQuaternions(roll, pitch, yaw);
//
// License:
// This library is open-source and licensed under the MIT License. See the LICENSE file in the repository for more details.
//
// Repository:
// The source code for this library can be found on GitHub/GitLab at:
// https://github.com/ameerhamza987/ESP32_MPU6050



    // formulas to calculate the pitch and roll
    // roll = 180 * atan2(accelY, sqrt(accelX*accelX + accelZ*accelZ))/PI
    // pitch = 180 * atan2(accelX, sqrt(accelY*accelY + accelZ*accelZ))/PI
