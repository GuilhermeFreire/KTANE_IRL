const int sensor_A0 = 0;
const int sensor_A1 = 1;
const int fail_LED = 2;
const int success_LED = 3;


const int allowed_std = 5;

// Wire color-voltage pairs
const int BLUE_VOLT = 336;
const int RED_VOLT = 512;

char str_buffer[256];
int voltage = -1;
int gameover;

void check_wire(int voltage, int comparison, int led_pin){
  if(comparison + allowed_std > voltage && comparison - allowed_std < voltage){
    if(!gameover){
      digitalWrite(led_pin, LOW);
    }
  }
  // LED on if wire is "cut"
  else{
    if(!gameover){
      digitalWrite(led_pin, HIGH);
    }
    gameover = 1;
  }
}

void setup() {
  pinMode(fail_LED, OUTPUT);
  pinMode(success_LED, OUTPUT);
  Serial.begin(9600);
  gameover = 0;
}

void loop() {
  // Read analog input
  int voltage_A0 = analogRead(sensor_A0);
  int voltage_A1 = analogRead(sensor_A1);

  // The correct wire to cut is the RED one.
  // If the correct wire is cut => light up success LED
  // Otherwise light up the fail LED.

  // LED off if wire is still connected
  check_wire(voltage_A0, BLUE_VOLT, success_LED);
  check_wire(voltage_A1, RED_VOLT, fail_LED);

  sprintf(str_buffer, "%d, %d", voltage_A0, voltage_A1);
  Serial.println(str_buffer);
}
