#define LED_1 12
#define LED_2 11
#define LED_3 10
#define button1 2
#define button2 4
#define button3 3

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT_PULLUP);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
  if (digitalRead(button1) == HIGH) {
    digitalWrite(LED_1,HIGH);
  }

  if (digitalRead(button2) == LOW) {
    digitalWrite(LED_2,HIGH);
  }

  if (digitalRead(button3) == LOW) {
    digitalWrite(LED_3,HIGH);
  }
}
