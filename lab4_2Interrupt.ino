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
  attachInterrupt(0, BTN1, FALLING );
  attachInterrupt(1, BTN2, FALLING );
}

void BTN1(){
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2,LOW);
    digitalWrite(LED_3,LOW);
    delay(5000);
}

void BTN2(){
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2,LOW);
    digitalWrite(LED_3,LOW);
    delay(5000);
}

void loop() {
    digitalWrite(LED_1,HIGH);
    delay(5000);
    digitalWrite(LED_1,LOW);
    
    for (int i=1;i<=6;i++) {
      digitalWrite(LED_2,HIGH);
      delay(250);
      digitalWrite(LED_2,LOW);
      delay(250);
    } 

    digitalWrite(LED_3,HIGH);
    delay(7000);
    digitalWrite(LED_3,LOW);
}
    
