#define BAUDRATE 115200
#include <PID_v1.h>
double wart_ustalona, Vin, Vout;
double Kp=2, Ki=0, Kd=0;
#define PIN_VIN A1
#define PIN_VOUT 2
PID myPID(&Vin, &Vout, &wart_ustalona, Kp, Ki, Kd, DIRECT);

void setup() {
  Serial.begin(BAUDRATE);
  myPID.SetMode(AUTOMATIC);
  wart_ustalona = 500;  // 0-1023 -> 5*500/1023 = 2.5V
}

long long p_millis = 0;
#define T_SAMPLE 10

void loop() {
if(millis() - p_millis>T_SAMPLE) {
  Vin = analogRead(PIN_VIN);
  Serial.println(Vin);
  myPID.Compute();
  p_millis = millis();
  analogWrite(PIN_VOUT, Vout);
}
}
