#include "ESP32MX1508.h"

MX1508::MX1508( uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2) {
  _pinIN1 = pinIN1; 
  _pinIN2 = pinIN2;  
  _ledCH1 = ledCH1;         // ESP32 LED Channel for PWM to Pin  
  _ledCH2 = ledCH2;         // 0 - 15 are availible by default
  pinMode(_pinIN1, OUTPUT);
  ledcSetup(_ledCH1, 2500, 8);         // Setup channel at 2500Hz with 8 bit (0-255) resolution
  ledcAttachPin(_pinIN1, _ledCH1);
  pinMode(_pinIN2, OUTPUT);
  ledcSetup(_ledCH2, 2500, 8);         // Setup channel at 2500Hz with 8 bit (0-255) resolution
  ledcAttachPin(_pinIN2, _ledCH2);
  _maxpwm = 255;                       // Sets a flag on the motor so the object knows the max pwm value
}

MX1508::MX1508( uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2, uint8_t resolution) {
  _pinIN1 = pinIN1; 
  _pinIN2 = pinIN2;  
  _ledCH1 = ledCH1;         // ESP32 LED Channel for PWM to Pin  
  _ledCH2 = ledCH2;         // 0 - 15 are availible by default
  pinMode(_pinIN1, OUTPUT);
  ledcSetup(_ledCH1, 2500, resolution);         // Setup channel at 2500Hz with 8 (0-255), 12 (0-4095), or 16 (0-65535) bit resolution
  ledcAttachPin(_pinIN1, _ledCH1);
  pinMode(_pinIN2, OUTPUT);
  ledcSetup(_ledCH2, 2500, resolution);         // Setup channel at 2500Hz with 8 (0-255), 12 (0-4095), or 16 (0-65535) bit resolution
  ledcAttachPin(_pinIN2, _ledCH2);
  if (resolution == 8) { _maxpwm = 255; }     // Sets a flag on the motor so the object knows the max pwm value
  if (resolution == 12) { _maxpwm = 4095; }
  if (resolution == 16) { _maxpwm = 65535; }
}

MX1508::MX1508( uint8_t pinIN1, uint8_t pinIN2, uint8_t ledCH1, uint8_t ledCH2, uint8_t resolution, long freq) {
  _pinIN1 = pinIN1; 
  _pinIN2 = pinIN2;  
  _ledCH1 = ledCH1;         // ESP32 LED Channel for PWM to Pin  
  _ledCH2 = ledCH2;         // 0 - 15 are availible by default
  pinMode(_pinIN1, OUTPUT);
  ledcSetup(_ledCH1, freq, resolution);         // Setup channel at specified Hz with 8 (0-255), 12 (0-4095), or 16 (0-65535) bit resolution
  ledcAttachPin(_pinIN1, _ledCH1);
  pinMode(_pinIN2, OUTPUT);
  ledcSetup(_ledCH2, freq, resolution);         // Setup channel at specified Hz with 8 (0-255), 12 (0-4095), or 16 (0-65535) bit resolution
  ledcAttachPin(_pinIN2, _ledCH2);
  if (resolution == 8) { _maxpwm = 255; }     // Sets a flag on the motor so the object knows the max pwm value
  if (resolution == 12) { _maxpwm = 4095; }
  if (resolution == 16) { _maxpwm = 65535; }
}

void MX1508::stopMotor() {                      // Kept for backwards compatibility
  ledcWrite(_ledCH1, 0);
  ledcWrite(_ledCH2, 0);
}

void MX1508::motorStop() {
  ledcWrite(_ledCH1, 0);
  ledcWrite(_ledCH2, 0);
}

void MX1508::motorBrake() {
  ledcWrite(_ledCH1, _maxpwm);
  ledcWrite(_ledCH2, _maxpwm);
 
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
  

 