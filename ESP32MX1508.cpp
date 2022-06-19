#include "ESP32MX1508.h"

MX1508::MX1508( uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2) {
  _pinIN1 = pinIN1; 
  _pinIN2 = pinIN2;  
  _ledCH1 = ledCH1;         // ESP32 LED Channel for PWM to Pin  
  _ledCH2 = ledCH2;         // 0 - 15 are availible by default
  pinMode(_pinIN1, OUTPUT);
  ledcSetup(_ledCH1, 20000, 8);         // Setup channel at 20kHz with 8 bit (0-255) resolution
  ledcAttachPin(_pinIN1, _ledCH1);
  pinMode(_pinIN2, OUTPUT);
  ledcSetup(_ledCH2, 20000, 8);         // Setup channel at 20kHz with 8 bit (0-255) resolution
  ledcAttachPin(_pinIN2, _ledCH2);
}

MX1508::MX1508( uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2, uint8_t resolution) {
  _pinIN1 = pinIN1; 
  _pinIN2 = pinIN2;  
  _ledCH1 = ledCH1;         // ESP32 LED Channel for PWM to Pin  
  _ledCH2 = ledCH2;         // 0 - 15 are availible by default
  pinMode(_pinIN1, OUTPUT);
  ledcSetup(_ledCH1, 20000, resolution);         // Setup channel at 20kHz with 8, 12, or 16 bit resolution .
  ledcAttachPin(_pinIN1, _ledCH1);
  pinMode(_pinIN2, OUTPUT);
  ledcSetup(_ledCH2, 20000, resolution);         // Setup channel at 20kHz with 8 (0-255), 12 (0-4095), or 16 (0-65535) bit resolution
  ledcAttachPin(_pinIN2, _ledCH2);
}

void MX1508::stopMotor() {                      // Kept for backwards compatibility
  ledcWrite(_ledCH1, 0);
  ledcWrite(_ledCH2, 0);
}

void MX1508::motorStop() {
  ledcWrite(_ledCH1, 0);
  ledcWrite(_ledCH2, 0);
}

void MX1508::motorGo(long pwmSpeed) {
  _pwmVal = pwmSpeed;
  ledcWrite(_ledCH1, _pwmVal);
  ledcWrite(_ledCH2, 0);
} 

void MX1508::motorRev(long pwmSpeed) {
  _pwmVal = pwmSpeed;
  ledcWrite(_ledCH1, 0);
  ledcWrite(_ledCH2, _pwmVal);
}
  

 