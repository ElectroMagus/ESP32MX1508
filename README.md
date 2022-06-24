
# MX1508 Driver Board Library for ESP32/Arduino

Arduino library for MX1508 dual DC motor driver compatible with the ESP32.

  

This was inspired by [this wonderful AVR Library](https://github.com/Saeterncj/MX1508). This is my first library, so please feel free to provide feedback.

The MX1508 Motor Driver is a nice, low cost motor driver  works from 2-10VDC, with a 1.5A operating current (2A peak).   The driver is ideal for battery powered, smaller DC motors.  

The ESP32 to use the LEDC Driver to send the PWM signals for speed control.  The ESP32 can multiplex many of its pin functions, this library creates PWM Channels and assigns them to the pins specified.  

The LEDC driver supports 8, 12 and 16 bit PWM resolution and can operate at a variety of frequencies allowing you to tune the driver to your particular motor.

  
  

## Objective

This library is made to simplify the use of MX1508 by allowing for the simple setup of motors and then using functions to drive them.    
```
#include <ESP32MX1508.h>
  

#define PINA 9
#define PINB 10
#define CH1 0 // 16 Channels (0-15) are availible
#define CH2 1 // Make sure each pin is a different channel and not in use by other PWM devices (servos, LED's, etc)

// Optional Parameters
#define RES 8 // Resolution in bits: 8 (0-255), 12 (0-4095), or 16 (0-65535)
#define FREQ 5000 // PWM Frequency in Hz

MX1508 motorA(PINA,PINB, CH1, CH2); // Default- 8 bit resoluion at 2500 Hz
//MX1508 motorA(PINA,PINB, CH1, CH2, RES); // Specify resolution
//MX1508 motorA(PINA,PINB, CH1, CH2, RES, FREQ); // Specify resolution and frequency
  

void setup() {
	Serial.begin(9600);
}

void loop() {
    motorA.motorGo(200);            // Pass the speed to the motor: 0-255 for 8 bit resolution
    delay(100);
    motorA.motorStop();             // Soft Stop    -no argument
    delay(100);
    motorA.motorRev(200);           // Pass the speed to the motor: 0-255 for 8 bit resolution
    delay(100);
    MotorA.motorBrake();            // Hard Stop    -no arguement
}

```

  


## Methods and Functions

 + motorGo(pwmVal)

	 - This sets the PWM val which is related to the speed, depending on selected resolution

 + motorRev(pwmVal)

	 + This sets the PWM val which is related to the speed, depending on selected resolution

 + motorStop()

	 + Stops the motor from moving in the current direction 

 + motorBrake()

	 - Actively brakes the motor 
