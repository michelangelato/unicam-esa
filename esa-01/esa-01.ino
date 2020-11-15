
// ESA exercise - test 6

#define PWM_PIN 10  // the PWM pin the LED is attached to

int fade = 5;         // how many points to fade the LED by
int brightness = 0;   // how bright the LED is

void setup() {
  pinMode(PWM_PIN, OUTPUT);
}

void loop() {
  analogWrite(PWM_PIN, brightness);     // set the LED brightness
  brightness = brightness + fade; // increase the brightness value

  if (brightness <= 0 || brightness >= 255) {
    fade = -fade;   // reverse the fade amount
  }

  delay(30);  // wait 30 ms
}



/*
// ESA exercise - test 5

#define LED 12  // digital pin of the led

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);  // turn on LED
}

void loop() {
  
}
*/



/*
// ESA exercise - test 4
#define RED_LED 13  // digital pin of green led
#define GRE_LED 12  // digital pin of red led
#define YEL_LED 11  // digital pin of yellow led

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GRE_LED, OUTPUT);
  pinMode(YEL_LED, OUTPUT);
}

void loop() {
  digitalWrite(YEL_LED, HIGH);  // turn on yellow LED
  digitalWrite(GRE_LED, LOW);   // turn off green LED
  digitalWrite(RED_LED, LOW);   // turn off red LED
  delay(1000);                  // wait a second
  digitalWrite(YEL_LED, LOW);   // turn off yellow LED
  digitalWrite(GRE_LED, HIGH);  // turn on green LED
  digitalWrite(RED_LED, LOW);   // turn off red LED
  delay(1000);                  // wait a second
  digitalWrite(YEL_LED, LOW);   // turn off yellow LED
  digitalWrite(GRE_LED, LOW);   // turn off green LED
  digitalWrite(RED_LED, HIGH);  // turn on red LED
  delay(1000);                  // wait a second
}
*/



/*
// ESA exercise - test 3
#define RED_LED 13  // digital pin of green led
#define GRE_LED 12  // digital pin of red led

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GRE_LED, OUTPUT);
}

void loop() {
  digitalWrite(GRE_LED, HIGH);  // turn on green LED
  digitalWrite(RED_LED, LOW);   // turn off red LED
  delay(1000);                  // wait a second
  digitalWrite(GRE_LED, LOW);   // turn off green LED
  digitalWrite(RED_LED, HIGH);  // turn on red LED
  delay(1000);                  // wait a second
}
*/



/*
// ESA exercise - test 2
#define LED 13  // digital pin of the led

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  // turn on LED
  delay(3000);              // wait 3 seconds
  digitalWrite(LED, LOW);   // turn off LED
  delay(1000);              // wait 1 second
}
*/



/*
// ESA exercise - test 1
#define LED 13  // digital pin of the led

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  // turn on LED
  delay(1000);              // wait a second
  digitalWrite(LED, LOW);   // turn off LED
  delay(1000);              // wait a second
}
*/
