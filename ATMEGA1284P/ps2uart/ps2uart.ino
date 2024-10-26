#define CORE_INT2_PIN  2
#include <Arduino.h>
#include <PS2KeyAdvanced.h>
#include <PS2KeyMap.h>

#define UART_OUT Serial1
#define DEBUG Serial


PS2KeyAdvanced keyboard;
PS2KeyMap keymap;


const uint8_t DataPin = 20;
const uint8_t IRQpin = 2;

void cputch(uint16_t c)
{  
  UART_OUT.write(c);
  //DEBUG.print(c, HEX);  
}

void setup() {
  UART_OUT.begin(115200);
  DEBUG.begin(115200);

  keyboard.begin(DataPin, IRQpin); 
  keyboard.setLock(0);  // Num lock off
  keyboard.setNoBreak( 1 );
  keyboard.setNoRepeat( 1 );
  keymap.selectMap( (char *)"FR" );

  uint16_t c;
  uint16_t ks;
  
  while(1)
  {
  
    while(!keyboard.available());

    // put your main code here, to run repeatedly:
    if(keyboard.available())
    {     
        c = keyboard.read();    
        ks = c;

        bool ctrl = c & PS2_CTRL; 
      
        c = keymap.remapKey(c);         
        c = c & 0xFF;
                
        if((ks & 0xFF) >= PS2_KEY_HOME && (ks & 0xFF) <= PS2_KEY_DN_ARROW) {
            cputch(ks & 0xFF);
        } else if((ks & 0xFF) >= PS2_KEY_KP0 && (ks & 0xFF) <= PS2_KEY_KP9) {
              cputch((ks & 0xFF) + 16);          
        } else if((ks & 0xFF) >= PS2_KEY_F1 && (ks & 0xFF) <= PS2_KEY_F12) {
              cputch(ks & 0xFF);          
        } else if(ctrl) {                      
            cputch(c & 0x1F); // CTRL-KEY            
        } /*else if (c > 127) {
              continue;
        }*/ else {
            cputch(c);                    
        }
    }
    delay(100);
  }
}

void loop() {
 
}


