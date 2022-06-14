#include <ESP32MX1508.h>

#define PINA 9
#define PINB 10
#define CH1 0                   // 16 Channels (0-15) are availible.
#define CH2 1                   // Make sure each pin is a different channel


MX1508 motorA(PINA,PINB, CH1, CH2);

void setup() {
   Serial.being(9600) ;

}

void loop() {
    motorA.motorGo(200);            // Pass the speed to the motor 0-255
    delay(100);
    motorA.stopMotor();             // Stop no argument
    delay(100);
    motorA.motorRev(200);           // Pass the speed to the motor 0-255
}