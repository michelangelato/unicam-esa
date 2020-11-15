
/*
 * ESA #2 - Temperature Monitor System
 */


// variante 1

#define PIN A0
#define VOLT 3.3
#define R1 10000
#define C1 1.009249522e-03
#define C2 2.378405444e-04
#define C3 2.019202697e-07

double volt;  // voltaggio tra 0 e 1023
double voltR; // voltaggio reale tra 0 e 3,3      
double rt;    // resistenza termistore
double logRt; // log(rt)
double tempK; // temperatura in Kelvin
double tempC; // temperatura in Celsius

void setup() {
  Serial.begin(9600);         // output su seriale
  analogReference(EXTERNAL);  // configura tensione riferimento con 3,3V
}

void loop() {
  volt = analogRead(PIN);     // lettura tensione ai capi di R1
  voltR = VOLT*volt/1023;     // conversione v in un range da 0 a 3,3
  rt = R1*(VOLT/voltR) - R1;  // resistenza termistore
  logRt = log(rt);
  
  // formula di Steinhart-Hart (°K)
  tempK = 1.0 / (C1 + C2*logRt + C3*logRt*logRt*logRt);
  
  tempC = tempK - 273.15;     // conversione in °C
  Serial.print("temperatura °K: "); Serial.println(tempK, DEC);
  Serial.print("temperatura °C: "); Serial.println(tempC, DEC);
  Serial.print("resistenza (ohm): "); Serial.println(rt); Serial.print("\n");
  delay(3000);
}



// variante 2

#define PIN A0
#define VOLT 3.3
#define R1 4700
#define C1 1.009249522e-03
#define C2 2.378405444e-04
#define C3 2.019202697e-07

double volt;  // voltaggio tra 0 e 1023
double voltR; // voltaggio reale tra 0 e 3,3      
double rt;    // resistenza termistore
double logRt; // log(rt)
double tempK; // temperatura in Kelvin
double tempC; // temperatura in Celsius

void setup() {
  Serial.begin(9600);         // output su seriale
  analogReference(EXTERNAL);  // configura tensione riferimento con 3,3V
}

void loop() {
  volt = analogRead(PIN);     // lettura tensione ai capi di R1
  voltR = VOLT*volt/1023;     // conversione v in un range da 0 a 3,3
  rt = R1*(VOLT/voltR) - R1;  // resistenza termistore
  logRt = log(rt);
  
  // formula di Steinhart-Hart (°K)
  tempK = 1.0 / (C1 + C2*logRt + C3*logRt*logRt*logRt);
  
  tempC = tempK - 273.15;     // conversione in °C
  Serial.print("temperatura °K: "); Serial.println(tempK, DEC);
  Serial.print("temperatura °C: "); Serial.println(tempC, DEC);
  Serial.print("resistenza (ohm): "); Serial.println(rt); Serial.print("\n");
  delay(3000);
}

// variante 3

#define PIN A0
#define VOLT 5
#define R1 10000
#define C1 1.009249522e-03
#define C2 2.378405444e-04
#define C3 2.019202697e-07

double volt;  // voltaggio tra 0 e 1023
double voltR; // voltaggio reale tra 0 e 3,3      
double rt;    // resistenza termistore
double logRt; // log(rt)
double tempK; // temperatura in Kelvin
double tempC; // temperatura in Celsius

void setup() {
  Serial.begin(9600);         // output su seriale
  analogReference(EXTERNAL);  // configura tensione riferimento con 3,3V
}

void loop() {
  volt = analogRead(PIN);     // lettura tensione ai capi di R1
  voltR = VOLT*volt/1023;     // conversione v in un range da 0 a 3,3
  rt = R1*(VOLT/voltR) - R1;  // resistenza termistore
  logRt = log(rt);
  
  // formula di Steinhart-Hart (°K)
  tempK = 1.0 / (C1 + C2*logRt + C3*logRt*logRt*logRt);
  
  tempC = tempK - 273.15;     // conversione in °C
  Serial.print("temperatura °K: "); Serial.println(tempK, DEC);
  Serial.print("temperatura °C: "); Serial.println(tempC, DEC);
  Serial.print("resistenza (ohm): "); Serial.println(rt); Serial.print("\n");
  delay(3000);
}

// variante 4

#define PIN A0
#define VOLT 3.3
#define R1 4700
#define C1 1.009249522e-03
#define C2 2.378405444e-04
#define C3 2.019202697e-07

double volt;  // voltaggio tra 0 e 1023
double voltR; // voltaggio reale tra 0 e 3,3      
double rt;    // resistenza termistore
double logRt; // log(rt)
double tempK; // temperatura in Kelvin
double tempC; // temperatura in Celsius

void setup() {
  Serial.begin(9600);         // output su seriale
  analogReference(EXTERNAL);  // configura tensione riferimento con 3,3V
  pinMode(13, OUTPUT);
}

void loop() {
  volt = analogRead(PIN);     // lettura tensione ai capi di R1
  voltR = VOLT*volt/1023;     //  conversione v in un range da 0 a 3,3
  rt = R1*(VOLT/voltR) - R1;  // resistenza termistore
  logRt = log(rt);
  tempK = 1.0 / (C1 + C2*logRt + C3*logRt*logRt*logRt);
  tempC = tempK - 273.15;     // conversione in °C

  if (tempC >= 22.0) {
    Serial.println("Troppo caldo."); digitalWrite(13, HIGH);
  } else {
    Serial.println("Temperatura ok."); digitalWrite(13, LOW);
  }
  
  Serial.print("temperatura °C: "); Serial.println(tempC, DEC); Serial.print("\n");
  delay(2000);
}
