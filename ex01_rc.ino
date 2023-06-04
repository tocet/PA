#define BAUDRATE 115200

void setup() {
  Serial.begin(BAUDRATE);
  pinMode(31,OUTPUT);
  digitalWrite(31,HIGH);
}

long long p_millis = 0;
#define T_SAMPLE 2
void loop() {
if(millis() - p_millis>T_SAMPLE) {
  Serial.println(analogRead(A1));
  p_millis = millis();
}
}
