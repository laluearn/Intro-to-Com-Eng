#include  "LedControl.h"

LedControl lc=LedControl(11,13,10,4);  // CLK,DIN,CS,Number of LED Module

unsigned long delaytime=50;  // time to updates of the display

void setup() {
  int devices=lc.getDeviceCount();  // find no of LED modules
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {  // set up each device 
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }
}

void loop() { 
  int devices=lc.getDeviceCount();  // find no of LED modules
  for(int col=0;col<7;col++) {
    for(int address=0;address<devices;address++) {
      delay(delaytime);
      lc.setColumn(address,col,true);
      delay(delaytime);
      lc.setColumn(address,col,false);
    }
  }

  for(int row=8;row>0;row--) {
    for(int address=0;address<devices;address++) {
      delay(delaytime);
      lc.setRow(address,row,true);
      delay(delaytime);
      lc.setRow(address,row,false);
    }
  }

  for(int col=8;col>0;col--) {
    for(int address=0;address<devices;address++) {
      int row = 0;
      delay(delaytime);
      lc.setLed(address,row,col,true);
      delay(delaytime);
      lc.setLed(address,row,col,false);
    }
  }

  for(int row=0;row<8;row++) {
    for(int address=0;address<devices;address++) {
      int col = 0;
      delay(delaytime);
      lc.setLed(address,row,col,true);
      delay(delaytime);
      lc.setLed(address,row,col,false);
    }
  }
}
