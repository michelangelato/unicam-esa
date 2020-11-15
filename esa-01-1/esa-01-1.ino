int tempo;
int ledPin = 8;
int buttonPin = 9;
int a;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(random(5000, 10000));
  digitalWrite(ledPin, HIGH);
  a = 0;
  while(digitalRead(buttonPin) == LOW) {
    a++;
    delay(1);
  }
  Serial.println(a);
  digitalWrite(ledPin, LOW);
}
