# MX1508 Driver Board Library for ESP32/Arduino
Arduino library for MX1508 dual DC motor driver compatible with the ESP32.

This was originally from the wonderful AVR Library at https://github.com/Saeterncj/MX1508  This is my first library, so I'm also using their project as a skeleton for the extra information. 

It was modified for the ESP32 to use the LEDC Driver to send the PWM signals for speed control.  Since the ESP32 can multiplex many of its pin functions, this library creates PWM Channels and assigns them to the pins specified.    




## Objective
This library is made to simplify the use of MX1508.  This Arduino Libary only requires a few lines of code to 
start controlling DC motors with mx1508.  Resolutions of 8, 12, and 16 bits are supported for control of the motor speed.
 
```
#include <ESP32MX1508.h>

#define PINA 9
#define PINB 10
#define CH1 0                   // 16 Channels (0-15) are availible.
#define CH2 1                   // Make sure each pin is a different channel and not in use by other PWM devices (servos, LED's, etc)
#define RES 8                   // Resolution in bits:  8 (0-255),  12 (0-4095), or 16 (0-65535)
                                // 8 is default and an optional parameter


MX1508 motorA(PINA,PINB, CH1, CH2, RES);

void setup() {}

void loop() {
    motorA.motorGo(200);            // Pass the speed to the motor: 0-255 for 8 bit resolution
    delay(100);
    motorA.stopMotor();             // Stop no argument
    delay(100);
    motorA.motorRev(200);           // Pass the speed to the motor: 0-255 for 8 bit resolution
    delay(100);
}
```

## Methods and Functions
  + motorGo(pwmVal)
    - This sets the PWM val which is related to the speed, depending on selected resolution
  + motorRev(pwmVal)
    - This sets the PWM val which is related to the speed, depending on selected resolution
  + stopMotor()
    - Simply stops the motor
  
