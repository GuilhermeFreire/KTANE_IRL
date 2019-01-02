const int sensor_pin = 0;
const int led_pin = 2;

int connected = 1;
int voltage = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(sensor_pin);
  if(voltage > 0){
    digitalWrite(led_pin, HIGH);
  }
  else{
    digitalWrite(led_pin, LOW);
  }
  Serial.println(voltage);
}
