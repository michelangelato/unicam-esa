
/*
 * ESA #5 - V-I Characteristic Curve of a LED
 */

// test

#define STEPS 256     // 8 bit

const unsigned int RAMP_PIN = 5;  // pwm per generare la rampa
const unsigned int SB_PIN = 2;    // stand by pin
const unsigned int AV1 = A0;
const unsigned int AV2 = A1;

unsigned int i = 0;   // conta gli step durante la salita della rampa
int v1[STEPS];        // array valori V1
int v2[STEPS];        // array valori V2
int rd = 100;         // resistenza Rd
bool waiting = false; // Arduino nello stato di attesa

void setup() {
  Serial.begin(9600);
  pinMode(RAMP_PIN, OUTPUT);
  pinMode(SB_PIN, INPUT);
}

void loop() {
  Serial.println("Lettura dati in corso...");
  for (i = 0; i<STEPS; i++) {
    analogWrite(RAMP_PIN, i);   // incrementa il duty cycle di uno step
    v1[i] = analogRead(AV1);
    v2[i] = analogRead(AV2);
    delay(100);
  }
  
  Serial.println("n,V,A");
  for (i = 0; i<STEPS; i++) {
    Serial.print(i);
    Serial.print(",");
    Serial.print(v2[i]/1024.0*5.0, 4);
    Serial.print(",");
    Serial.println((5.0/1.024)*(v1[i]-v2[i])/rd, 4);
  }
  
  analogWrite(RAMP_PIN, 0); // spegne il led

  Serial.println("Tieni premuto il bottone per riavviare.");
  waiting = true;
  while(waiting) {
    delay(1000);
    waiting = digitalRead(SB_PIN) == LOW;
  }
}
