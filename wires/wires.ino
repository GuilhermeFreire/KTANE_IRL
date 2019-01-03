const int sensor_pin = 0;
const int led_pin = 2;

const int allowed_std = 5;

// Wire color-voltage pairs
const int BLUE_VOLT = 336;

int connected = 1;
int voltage = -1;

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read analog input
  voltage = analogRead(sensor_pin);

  // LED off if wire is still connected
  if(BLUE_VOLT + allowed_std > voltage && BLUE_VOLT - allowed_std < voltage){
    digitalWrite(led_pin, LOW);
  }
  // LED on if wire is "cut"
  else{
    digitalWrite(led_pin, HIGH);
  }
  Serial.println(voltage);
}
