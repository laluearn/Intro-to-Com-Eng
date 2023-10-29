++
#define Port1 2
#define Port2 3
#define Port3 4

void setup() {
  pinMode(Port1, OUTPUT);
  pinMode(Port2, OUTPUT);
  pinMode(Port3, OUTPUT);
}

void loop() {
//  1,2
  pinMode(Port1, OUTPUT);
  pinMode(Port2, OUTPUT);
  pinMode(Port3, INPUT);
  
  digitalWrite(Port1, LOW);
  delay(500);
  digitalWrite(Port2, HIGH);
  delay(500);

  digitalWrite(Port1, HIGH);
  delay(500);
  digitalWrite(Port2, LOW);
  delay(500);
//  3,4
  pinMode(Port1, INPUT);
  pinMode(Port2, OUTPUT);
  pinMode(Port3, OUTPUT);

  digitalWrite(Port2, LOW);
  delay(500);
  digitalWrite(Port3, HIGH);
  delay(500);

  digitalWrite(Port2, HIGH);
  delay(500);
  digitalWrite(Port3, LOW);
  delay(500);
//  5,6
  pinMode(Port1, OUTPUT);
  pinMode(Port2, INPUT);
  pinMode(Port3, OUTPUT);

  digitalWrite(Port1, LOW);
  delay(500);
  digitalWrite(Port3, HIGH);
  delay(500);

  digitalWrite(Port1, HIGH);
  delay(500);
  digitalWrite(Port3, LOW);
  delay(500);

//  5
  pinMode(Port1, OUTPUT);
  pinMode(Port2, INPUT);
  pinMode(Port3, OUTPUT);
  digitalWrite(Port1, LOW);
  delay(500);
  digitalWrite(Port3, HIGH);
  delay(500);
  
//  4,3
  pinMode(Port1, INPUT);
  pinMode(Port2, OUTPUT);
  pinMode(Port3, OUTPUT);
  digitalWrite(Port2, HIGH);
  delay(500);
  digitalWrite(Port3, LOW);
  delay(500);

  digitalWrite(Port2, LOW);
  delay(500);
  digitalWrite(Port3, HIGH);
  delay(500);

//  2,1
  pinMode(Port1, OUTPUT);
  pinMode(Port2, OUTPUT);
  pinMode(Port3, INPUT);
  digitalWrite(Port1, HIGH);
  delay(500);
  digitalWrite(Port2, LOW);
  delay(500);

  digitalWrite(Port1, LOW);
  delay(500);
  digitalWrite(Port2, HIGH);
  delay(500);
}
