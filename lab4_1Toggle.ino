#define LED_1 12
#define LED_2 11
#define LED_3 10
#define button1 2
#define button2 4
#define button3 3
unsigned long DebounceTime1 = 0;
unsigned long DebounceTime2 = 0;
unsigned long DebounceTime3 = 0;
bool buttonStatus1 = false;
bool buttonStatus2 = false;
bool buttonStatus3 = false;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT_PULLUP);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
  if (digitalRead(button1) == HIGH && !buttonStatus1) {
    buttonStatus1 = true;
    DebounceTime1 = millis();  
  }  
  if (buttonStatus1 && millis()- DebounceTime1 > 200) {
    digitalWrite(LED_1,!digitalRead(LED_1));
    buttonStatus1 = false;
  }
  
  if (digitalRead(button2) == LOW && !buttonStatus2) {
    buttonStatus2 = true;
    DebounceTime2 = millis();  
  }
  if (buttonStatus2 && millis()- DebounceTime2 > 200) {
    digitalWrite(LED_2,!digitalRead(LED_2));
    buttonStatus2 = false;
  }

  if (digitalRead(button3) == LOW && !buttonStatus3) {
    buttonStatus3 = true;
    DebounceTime3 = millis();  
  }
  if (buttonStatus3 && millis()- DebounceTime3 > 200) {
    digitalWrite(LED_3,!digitalRead(LED_3));
    buttonStatus3 = false;
  }
}
