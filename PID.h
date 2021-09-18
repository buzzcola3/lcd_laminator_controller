#include <FastPID.h>

#define PIN_INPUT     cur_temp
#define PIN_SETPOINT  temp
#define PIN_OUTPUT    5

float Kp=0.1, Ki=0.5, Kd=0, Hz=10;
int output_bits = 8;
bool output_signed = false;

FastPID myPID(Kp, Ki, Kd, Hz, output_bits, output_signed);

void PID()
{
  int setpoint = analogRead(PIN_SETPOINT) / 2; 
  int feedback = analogRead(PIN_INPUT);
  uint32_t before, after;
  before = micros();
  uint8_t output = myPID.step(setpoint, feedback);
  after = micros();
  
  analogWrite(PIN_OUTPUT, output);
 // Serial.print("runtime: "); 
 // Serial.print(after - before);
 // Serial.print(" sp: "); 
 // Serial.print(setpoint); 
 // Serial.print(" fb: "); 
 // Serial.print(feedback);
 // Serial.print(" out: ");
 // Serial.println(output);
}