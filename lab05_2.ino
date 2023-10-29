#define LED_1 11
#define LED_2 10
#define LED_3 9
#define LED_4 8

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
    int val = analogRead(0);
  Serial.println(val);
   if (val > 1000) 
   {
    digitalWrite(LED_1, HIGH); 
   }
   else
   {
    digitalWrite(LED_1, LOW); 
   }
   
   if (val > 900 && val < 999) 
   {
    digitalWrite(LED_2, HIGH); 
   }
   else
   {
    digitalWrite(LED_2, LOW); 
   }

   if (val > 500 && val < 600) 
   {
    digitalWrite(LED_3, HIGH); 
   }
   else
   {
    digitalWrite(LED_3, LOW); 
   }
   
   if (val > 600 && val < 710) 
   {
    digitalWrite(LED_4, HIGH); 
   }
   else
   {
    digitalWrite(LED_4, LOW); 
   }
}
