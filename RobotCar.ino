int enA = 10;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enB = 5;

//int dark = 310;
bool turn = 0;

bool firstBlink = false;
bool secBlink = false;

unsigned long setFirstBlink = 0;
unsigned long previousMillis = 0;
unsigned long waitTime = 0;

//set pin of sensor
#define Sensor_RR A0
#define Sensor_R A1
#define Sensor_C A2
#define Sensor_L A3
#define Sensor_LL A4
#define LDR 12

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  //reading sensor value
  int sensor1 = analogRead(Sensor_RR);
  int sensor2 = analogRead(Sensor_R);
  int sensor3 = analogRead(Sensor_C);
  int sensor4 = analogRead(Sensor_L);
  int sensor5 = analogRead(Sensor_LL);
  //reading LDR value; LDR < 300 == blink
  int LDR_value = digitalRead(LDR);
  
  if (millis() - setFirstBlink >= 500)
  {
    setFirstBlink = millis();
    //check range sensor
    Serial.print("sensor1 : ");
    Serial.println(sensor1);
    Serial.print("sensor2 : ");
    Serial.println(sensor2);
    Serial.print("sensor3 : ");
    Serial.println(sensor3);
    Serial.print("sensor4 : ");
    Serial.println(sensor4);
    Serial.print("sensor5 : ");
    Serial.println(sensor5);
    Serial.println("\t");
  }
  
  int black = 400;
  int white = 500;

//  Serial.println(LDR_value);
//  delay(2000);
  //line
  
  if (sensor1 < 400 && sensor2 < 400 && sensor3 < 400 && sensor4 < 400 && sensor5 < 400)
  {
    stop_car();
    while(digitalRead(LDR) == 1);
    waitTime = millis();
    while(millis()-waitTime < 3000)
      if(digitalRead(LDR) == 1)
        while(millis()-waitTime < 3000)
          if(digitalRead(LDR) == 0)
            turn = true;
    previousMillis = millis();
    if(turn)
    {
      go_forward();
      delay(100);
      turn_right();
      delay(500);          
    }
    else
    {
      go_forward();
      delay(100);
      turn_left();
      delay(500);
    }
    turn = false;
  }
  
  else if (sensor2 < black)
  {
    go_backward();
    if (millis() - previousMillis >= 30)
    {
      previousMillis = millis();
    }
    turn_right();
    if (millis() - previousMillis >= 30)
    {
      previousMillis = millis();
    }
  }
  
  else if (sensor4 < black)
  {
    go_backward();
    if (millis() - previousMillis >= 20)
    {
      previousMillis = millis();
    }
    turn_left();
    if (millis() - previousMillis >= 30)
    {
      previousMillis = millis();
    }
  }

  else if (sensor3 < black && sensor5 < black)
  {
    //60 degrees
    while (analogRead(A1) > white || analogRead(A2) > white)
      turn_left();
      go_forward();
  }
  
  else if (sensor2 < black && sensor3 < black)
  {
    go_backward();
    if (millis() - previousMillis >= 400)
    {
      previousMillis = millis();
    }
    go_forward();
    if (millis() - previousMillis >= 150)
    {
      previousMillis = millis();
    }
    turn_left();
    if (millis() - previousMillis >= 300)
    {
      previousMillis = millis();
    }
  }
   else if (sensor1 < black && sensor3 < black)
  {
    //30 degrees
    while(analogRead(A3) > white || analogRead(A2) > white)
      turn_right();
      go_forward();
  }
  else if (sensor1 < black && sensor2 < black)
  {
    go_backward();
    if (millis() - previousMillis >= 400)
    {
      previousMillis = millis();
    }
    go_forward();
    if (millis() - previousMillis >= 150)
    {
      previousMillis = millis();
    }
    turn_left();
    if (millis() - previousMillis >= 400)
    {
      previousMillis = millis();
    }
  }
  else if (sensor3 < black)
  {
    go_backward();
    if (millis() - previousMillis >= 30)
    {
      previousMillis = millis();
    }
    go_forward();
    if (millis() - previousMillis >= 40)
    {
      previousMillis = millis();
    }
  }
}

void go_forward()
{
  analogWrite(enA, 130); //motor1 = right
  analogWrite(enB, 130); //motor2 = left

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turn_left()
{
  analogWrite(enA, 130); //motor1 = right
  analogWrite(enB, 0); //motor2 = left
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turn_right()
{
  analogWrite(enA, 0); //motor1 = right
  analogWrite(enB, 130); //motor2 = left
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop_car()
{
  analogWrite(enA, 0); //motor1 = right
  analogWrite(enB, 0); //motor2 = left
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void go_backward()
{
  analogWrite(enA, 120); //motor1 = right
  analogWrite(enB, 120); //motor2 = left
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
