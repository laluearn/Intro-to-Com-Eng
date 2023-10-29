int bitPattern[12] = {B11111001, B10100100, B10110000, B10011001, B10010010, B10000010, B11111000, B10000000, B10010000, B11000000, B11001110, B11000111};
long randNumber;
const byte numPins = 8;
const int segmentPins[8] = {5, 6, 7, 8, 9, 10, 11, 12};
int currentNum = 0;
int currentRand = 5;
boolean isBitSet;
int buttonA = 3;
int buttonG = 4;

void setup() 
{
  // setup pin mode and randomseed
  Serial.begin(9600);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonG, INPUT_PULLUP);
  for (int i = 0; i < numPins; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }
  randomSeed(analogRead(0));
  for (int segment = 0; segment < 8; segment++)
  {
    isBitSet = bitRead(bitPattern[0], segment);
    digitalWrite(segmentPins[segment], isBitSet);
  }
}

bool lastBtnStatusA = HIGH;
bool lastBtnStatusG = HIGH;

void loop() 
{ 
  bool currentBtnStatusA = digitalRead(buttonA);
  bool currentBtnStatusG = digitalRead(buttonG);
  
  // display 7 segment 
  if (currentBtnStatusA < lastBtnStatusA)
  {
    handle_add_button();
  }
  
  lastBtnStatusA = currentBtnStatusA;
  
  if (currentBtnStatusG < lastBtnStatusG)
  {
    handle_guest_button();
  }
  
  lastBtnStatusG = currentBtnStatusG;

  delay(50);
}

void handle_add_button() 
{
  // press to increase the number
  currentNum = (currentNum + 1) % 9;
  for (int segment = 0; segment < 8; segment++)
  {
    isBitSet = bitRead(bitPattern[currentNum], segment);
    digitalWrite(segmentPins[segment], isBitSet);
  }
}

void handle_guest_button()
{
  // press guess answer
  Serial.print(currentNum+1);
  Serial.print(" ");
  Serial.println(currentRand+1);
  if (currentNum > currentRand) {
    for (int segment = 0; segment < 8; segment++)
    {
      isBitSet = bitRead(bitPattern[10], segment);
      digitalWrite(segmentPins[segment], isBitSet);
    }
    delay(1000);
    for (int segment = 0; segment < 8; segment++)
    {
      isBitSet = bitRead(bitPattern[currentNum], segment);
      digitalWrite(segmentPins[segment], isBitSet);
    }
    return;
  }
  if (currentNum < currentRand) {
    for (int segment = 0; segment < 8; segment++)
    {
      isBitSet = bitRead(bitPattern[11], segment);
      digitalWrite(segmentPins[segment], isBitSet);
    }
    delay(1000);
    for (int segment = 0; segment < 8; segment++)
    {
      isBitSet = bitRead(bitPattern[currentNum], segment);
      digitalWrite(segmentPins[segment], isBitSet);
    }
    return;
  }
  if (currentNum == currentRand) {
    for (int segment = 0; segment < 8; segment++)
    {
      isBitSet = bitRead(bitPattern[9], segment);
      digitalWrite(segmentPins[segment], isBitSet);
    }
    delay(1000);
  }
  currentRand = random(0, 8);
  Serial.println(currentRand); 
  
  for (int segment = 0; segment < 8; segment++)
  {
    isBitSet = bitRead(bitPattern[currentNum], segment);
    digitalWrite(segmentPins[segment], isBitSet);
  }
}
