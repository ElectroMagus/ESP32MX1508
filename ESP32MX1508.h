#ifndef ESP32MX1508_h
#define ESP32MX1508_h

#include "Arduino.h"

class MX1508 {
  public:
    MX1508(uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2); 
    MX1508(uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2, uint8_t resolution);
    MX1508(uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2, uint8_t resolution, long freq);
    void motorGo(long pwmVal); 
    void motorRev(long pwmVal);
    void motorStop();                 // Sets both signals to low to allow motor to spin down
    void motorBrake();                // Sets boths signals to high to hard brake the motor 
    void stopMotor();                 // Kept for backwards compatibility
    
	  
  private:
    uint8_t _pinIN1;        // Pin to MX1508
    uint8_t _pinIN2;
    uint8_t _ledCH1;        // ESP32 ledc Channel for PWM   
    uint8_t _ledCH2;
    uint8_t resolution;     // PWM Resolution  
    long freq;              // PWM Freq   
	  long _pwmVal;           // PWM Value (speed)
    long _maxpwm;           // Max PWM Value of the Motor
};

#endif
