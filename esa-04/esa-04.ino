
/*
 * ESA #4 - Resistance Value Measurement
 */

// test

int d[4] = { 2, 3, 4, 5 };
float r[4] = { 470000.0, 47000.0, 4700.0, 470.0 };
int n = 0;
float vin = 3.3, vx, vr, rx, i;
String unit = "ohm";

void setup() {
  Serial.begin(9600);
  pinMode(d[0], INPUT);
  pinMode(d[1], INPUT);
  pinMode(d[2], INPUT);
  pinMode(d[3], INPUT);
}

void loop() {
  
  for (int p=0; p<4; p++) {
    pinMode(d[p], OUTPUT);
    digitalWrite(d[p], HIGH);
    delay(100);
    n = analogRead(A0);
    pinMode(d[p], INPUT);

    if (n == 1023) {
      Serial.println("Rx = infinito");
      p = 4;
    }
    else if (n >= 105) {
      vx = n / 1023.0 * vin;
      vr = vin - vx;
      i = vr / float(r[p]);
      rx = vx / i;
      Serial.print("Rx = ");
      if (rx >= 1000000) {
        Serial.print(rx/1000000); Serial.println(" M\u03a9");
      }
      else if (rx >= 1000) {
        Serial.print(rx/1000);    Serial.println(" K\u03a9");
      }
      else {
        Serial.print(rx);         Serial.println(" \u03a9");
      }
      p = 4;
    }
  }
  delay(5000);
}
