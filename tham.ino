int Button[5] = {12, 11, 10, 9, 8};
int recording[100] = {};
int play = 7;
int record = 6;
int Piezo = 3;
int record_note = 0;
bool checkrecording = false;
bool checkplaying = false;

bool keepNote = true;
bool normal = true;
int settime;

double note[5] = {261.63, 293.66, 329.63, 349.23, 392};

bool buttonPress[5] = {false};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(Button[i], INPUT);
  }
  pinMode(play, INPUT);
  pinMode(record, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(play) == true && !checkplaying) {
    checkplaying = true;
    checkrecording = false;
    Serial.println("Playing");
  }

  if (digitalRead(record) == true && !checkrecording) {
    checkplaying = false;
    checkrecording = true;
    Serial.println("Recording");

    record_note = 0;
  }

  if (checkplaying) {
    for (int i = 0; i < record_note; i++) {
      tone(Piezo, note[recording[i]], 250);
      delay(100);
      noTone(Piezo);
      delay(100);
    }
    checkplaying = false;
  }

  if (checkrecording) {
    for (int i = 0; i < 5; i++) {
      if (digitalRead(Button[i]) == HIGH && !buttonPress[i]) {
        settime = millis();
        buttonPress[i] = !buttonPress[i];
      }
      if (millis() - settime > 50) {
        if (digitalRead(Button[i]) == HIGH && !keepNote) {
          Serial.print("Recording ");
          Serial.println(i);
          tone(Piezo, note[i], 250);
          keepNote = !keepNote;
          recording[record_note] = i;
          record_note++;
        }
      }
      if (digitalRead(Button[i]) == LOW && buttonPress[i]) {
        noTone(Piezo);
        keepNote = false;
        buttonPress[i] = !buttonPress[i];
      }
    }
  }

  if(normal == true && checkrecording == false && checkplaying == false){
      if(digitalRead(Button[0]) == true){
        tone(Piezo, note[0] , 250);
      }
      else if(digitalRead(Button[1]) == true){
        tone(Piezo, note[1] , 250);
      }
      else if(digitalRead(Button[2]) == true){
        tone(Piezo, note[2] , 250);
      }
      else if(digitalRead(Button[3]) == true){
        tone(Piezo, note[3] , 250);
      }
      else if(digitalRead(Button[4]) == true){
        tone(Piezo, note[4] , 250);
      }
      else if(digitalRead(Button[5]) == true){
        tone(Piezo, note[5] , 250);
      }
      else if(digitalRead(Button[6]) == true){
        tone(Piezo, note[6] , 250);
      }
      else{
        noTone(Piezo);
      }
  }
}
