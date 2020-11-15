
/*
 * ESA #3 - Signal Reading and ADC
 */

// test 1   // Digital Signal Reading
/*
#define DPIN 2

void setup() {
  Serial.begin(9600);
  pinMode(DPIN, INPUT);
}

void loop() {
  int sensorValue = digitalRead(DPIN);
  Serial.println(sensorValue, DEC);
  delay(10);
}
*/




// test 2   // A/D Conversion
/*
void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(A0);
  Serial.print("Valore ADC: ");
  Serial.println(adcValue);
  delay(50);
}
*/



// test 3   // Analogic Signal Reading
/*
void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(A0);
  Serial.print("Valore ADC:\t");
  Serial.print(adcValue);

  float tensione = (adcValue*5.00)/1023.00;
  Serial.print("\t\tTensione (V):\t");
  Serial.println(tensione);
  delay(100);
}
*/


// test 6   // Analogic Signal Reading with LED

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int adcValue = analogRead(A0);
  Serial.print("Valore ADC:\t");
  Serial.print(adcValue);

  float tensione = (adcValue*5.00)/1023.00;
  Serial.print("\t\tTensione (V):\t");
  Serial.println(tensione);

  if (tensione > 3.3) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  
  delay(100);
}
