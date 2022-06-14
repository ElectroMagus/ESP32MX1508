# MX1508 Driver Board Library for ESP32/Arduino
Arduino library for MX1508 dual DC motor driver compatible with the ESP32.

This was originally from the wonderful AVR Library at https://github.com/Saeterncj/MX1508.git.  This is my first library, so I'm also using their project as a skeleton for the extra information. 

It was modified for the ESP32 to use the LEDC Driver to send the PWM signals for speed control.  Since the ESP32 can multiplex many of its pin functions, this library creates PWM Channels and assigns them to the pins specified. 




## Objective
This library is made to simplify the use of MX1508.  This Arduino Libary only requires a few lines of code to 
start controlling DC motors with mx1508.
 
```
#include <ESP32MX1508.h>

#define PINA 9
#define PINB 10
#define CH1 0                   // 16 Channels (0-15) are availible.
#define CH2 1                   // Make sure each pin is a different channel


MX1508 motorA(PINA,PINB, CH1, CH2);

void setup() {}

void loop() {
    motorA.motorGo(200);            // Pass the speed to the motor motorGo and motorRev 0-255.    Depending on voltage/motor, you will need to adjust to figure out a starting value.
}
```

## Methods and Functions
  + motorGo(pwmVal)
    - This sets the PWM val which is related to the speed, depending on voltage and motor type. 
  + motorRev(pwmVal)
    - This sets the PWM val which is related to the speed, depending on voltage and motor type.
  + stopMotor()
    - Simply stops the motor.
  + getPwm()
    - Returns the current PWM value of the motor.
    
