#ifndef ESP32MX1508_h
#define ESP32MX1508_h

#include "Arduino.h"

class MX1508 {
  public:
    MX1508(uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2); 
    void motorGo(long pwmVal); 
    void motorRev(long pwmVal);
    int getPWM();
    void stopMotor(); 
	  
  private:
    uint8_t _pinIN1;
    uint8_t _pinIN2;
    uint8_t _ledCH1;        // ESP32 ledc Channel for PWM   
    uint8_t _ledCH2;         
	  long _pwmVal;
};

#endif
