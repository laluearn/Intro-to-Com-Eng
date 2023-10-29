#define BUTTON_NORTH 11
#define LED_N_R 8
#define LED_N_Y 9
#define LED_N_G 10

#define BUTTON_EAST 12
#define LED_E_R 3
#define LED_E_Y 4
#define LED_E_G 5

#define BUTTON_WALK 13
#define LED_W_R 7
#define LED_W_G 6

#define goN 0
#define waitN 1
#define goE 2
#define waitE 3
#define goWalk 4
#define off1 5
#define on1 6
#define off2 7
#define on2 8
#define off3 9

struct State {
  unsigned long ST_Out;    //6-bit pattern to street output
  unsigned long Time;      //delay in ms units
  unsigned long NextST[8]; //next state for inputs [000,111]
};

typedef const struct State SType;

SType FSM[10] = {
                {B00110010, 3000, {goN, waitN, waitN, waitN, goN, waitN, waitN, waitN}}, //goN
                {B01010010,  500, {goE, goWalk, goE, goE, goE, goWalk, goE, goE}}, //waitN
                {B10000110, 3000, {goE, waitE, goE, waitE, waitE, waitE, waitE, waitE}}, //goE
                {B10001010,  500, {goWalk, goWalk, goWalk, goWalk, goN, goWalk, goN, goWalk}}, //waitE
                {B10010001, 3000, {goWalk, goWalk, off1, off1, off1, off1, off1, off1}}, //goWalk
                {B10010000,  500, {on1, on1, on1, on1, on1, on1, on1, on1}}, //off1
                {B10010001,  500, {off2, off2, off2, off2, off2, off2, off2, off2}}, //on1
                {B10010000,  500, {on2, on2, on2, on2, on2, on2, on2, on2}}, //off2
                {B10010001,  500, {off3, off3, off3, off3, off3, off3, off3, off3}}, //on2
                {B10010000,  500, {goN, goN, goE, goE, goN, goN, goN, goN}}, //off3
               };

unsigned long ST = 0; //index to current state

void setup() {
  pinMode(BUTTON_NORTH, INPUT_PULLUP);
  pinMode(LED_N_R, OUTPUT);
  pinMode(LED_N_Y, OUTPUT);
  pinMode(LED_N_G, OUTPUT);

  pinMode(BUTTON_EAST, INPUT_PULLUP);
  pinMode(LED_E_R, OUTPUT);
  pinMode(LED_E_Y, OUTPUT);
  pinMode(LED_E_G, OUTPUT);

  pinMode(BUTTON_WALK, INPUT_PULLUP);
  pinMode(LED_W_R, OUTPUT);
  pinMode(LED_W_G, OUTPUT);

  Serial.begin(9600);
}

int input=0,North=0,East=0,Walk=0;

void loop() {
  
  digitalWrite(LED_N_R, !(FSM[ST].ST_Out & B10000000));
  digitalWrite(LED_N_Y, !(FSM[ST].ST_Out & B01000000));
  digitalWrite(LED_N_G, !(FSM[ST].ST_Out & B00100000));

  digitalWrite(LED_E_R, !(FSM[ST].ST_Out & B00010000));
  digitalWrite(LED_E_Y, !(FSM[ST].ST_Out & B00001000));
  digitalWrite(LED_E_G, !(FSM[ST].ST_Out & B00000100));

  digitalWrite(LED_W_R, !(FSM[ST].ST_Out & B00000010));
  digitalWrite(LED_W_G, !(FSM[ST].ST_Out & B00000001));

  delay(FSM[ST].Time);
  
  North = !digitalRead(BUTTON_NORTH);
  East = !digitalRead(BUTTON_EAST);
  Walk = !digitalRead(BUTTON_WALK);

  input = North * 4 + East * 2 + Walk;
  ST = FSM[ST].NextST[input];
  Serial.println(ST);
}
