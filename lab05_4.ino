int bitPattern[11] = {B11000000, B11111001, B10100100, B10110000, B10011001, B10010010, B10000010, B11111000, B10000000, B10010000, B01111111};
const byte numPins = 8;
const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8, 9} ;
int incomingByte = 0;
char incomingChar ;

void setup() 
{
  Serial.begin(9600);
  for (int i = 0; i < numPins; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
  Serial.print("Please enter number : ");
}

void loop() 
{
  boolean isBitSet;
  if (Serial.available()>0)
  {
    incomingByte = Serial.read();
    if (incomingByte != 10) {
      incomingChar = incomingByte;
      Serial.println(incomingChar);
      if (incomingByte > 47 && incomingByte < 58) 
      {
        for (int segment = 0; segment < 8; segment++)
        {
          isBitSet = bitRead(bitPattern[incomingByte - '0'], segment);
          digitalWrite(segmentPins[segment], isBitSet);
        }
      }
      
      else
      {
        Serial.println("Input isn't number !!! Try Again !!!!");
        for (int segment = 0; segment < 8; segment++)
        {
          isBitSet = bitRead(bitPattern[10], segment);
          digitalWrite(segmentPins[segment], isBitSet);
        }
      }
      Serial.print("Please enter number : ");
    }
  }
}
