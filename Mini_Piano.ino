int button[5] = {12, 11 , 10 , 9 , 8 };
int tones[5] = {261.63, 293.66, 329.63, 349.23, 392};
int record = 6;
int play = 7;
int rec[100];
int rec_index = 0;
const int speakerPin = 3;
boolean checkRecord = false;
boolean checkPlay = false;
boolean buttonPress[5] = {false};
boolean keepNote = true;
int settime;
int k;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 5; i++)
  {
    pinMode(button[i], INPUT);
  }
  // record and replay
  pinMode(record, INPUT);
  pinMode(play, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  if (digitalRead(record) == HIGH && !checkRecord) 
  {
    checkPlay = false;
    checkRecord = true;
  }
  if (digitalRead(play) == HIGH && !checkPlay) 
  {
    checkPlay = true;
    checkRecord = false;
  }
  
  // record
  if (checkRecord)
  {
    for (k = 0; k < 5; k++)
    {
      if (digitalRead(button[k]) == HIGH && !buttonPress[k])
      {
//        settime = millis();
        buttonPress[k] = !buttonPress[k];
      }
//      if (millis - settime > 50)
//      {
        if (digitalRead(button[k]) == HIGH && !keepNote)
        {
          tone(speakerPin, tones[k]);
          keepNote = !keepNote;
          Serial.println(k);
          rec[rec_index] = tones[k];
          rec_index++;
        }
//      }
      
      if (digitalRead(button[k]) == LOW && buttonPress[k])
      {
        noTone(speakerPin);
        keepNote = false;
        buttonPress[k] = !buttonPress[k];
      }
    }
  }

  // play
  if (checkPlay)
  {
    for (int m = 0; m < rec_index; m++)
    {
      tone(speakerPin, rec[m]);
      delay(250);
      noTone(speakerPin);
      delay(250);
    }
    checkPlay = false;
  }

  // play piano
  if (checkRecord == false && checkPlay == false)
  {
    if(digitalRead(button[0]) == true){
        tone(speakerPin, tones[0]);
      }
      else if(digitalRead(button[1]) == true){
        tone(speakerPin, tones[1]);
      }
      else if(digitalRead(button[2]) == true){
        tone(speakerPin, tones[2]);
      }
      else if(digitalRead(button[3]) == true){
        tone(speakerPin, tones[3]);
      }
      else if(digitalRead(button[4]) == true){
        tone(speakerPin, tones[4]);
      }
      else{
        noTone(speakerPin);
      }
  }
}
