#include <ESP32MX1508.h>

#define PINA 9
#define PINB 10
#define CH1 0                   // 16 Channels (0-15) are availible
#define CH2 1                   // Make sure each pin is a different channel and not in use by other PWM devices (servos, LED's, etc)

// Optional Parameters
#define RES 8                   // Resolution in bits:  8 (0-255),  12 (0-4095), or 16 (0-65535)     
#define FREQ  5000              // PWM Frequency in Hz    

MX1508 motorA(PINA,PINB, CH1, CH2);                       // Default-  8 bit resoluion at 2500 Hz
//MX1508 motorA(PINA,PINB, CH1, CH2, RES);                // Specify resolution
//MX1508 motorA(PINA,PINB, CH1, CH2, RES, FREQ);          // Specify resolution and frequency

void setup() {}

void loop() {
    motorA.motorGo(200);            // Pass the speed to the motor: 0-255 for 8 bit resolution
    delay(100);
    motorA.motorStop();             // Soft Stop    -no argument
    delay(100);
    motorA.motorRev(200);           // Pass the speed to the motor: 0-255 for 8 bit resolution
    delay(100);
    MotorA.motorBrake();            // Hard Stop    -no arguement
}