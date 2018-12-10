#include <LiquidCrystal.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


const int rs = 13, en = 12, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int const RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
int x=0;
int y=0;
int x2=0;
char diff_lux[16];
float DIFF_LUX;
char string= ' ';
bool END= false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  irrecv.enableIRIn();

}

void loop() {
  if(irrecv.decode(&results))
  {
     Serial.println(results.value, HEX);
     if(!END) {
     switch(results.value)
      {
        case 0xFFA25D:
        string = '1';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFF629D:
        string = '2';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFFE21D:
        string = '3';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;

        case 0xFF22DD:
        string = '4';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFF02FD:
        string = '5';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFFC23D:
        string = '6';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;

        case 0xFFE01F:
        string = '7';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFFA857:
        string = '8';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFF906F:
        string = '9';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;

        case 0xFF9867:
        string = '0';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;

        case 0xFF6897:
        string = '.';
        diff_lux[x2] = string;
        x2++;
        lcd.print(string);
        x++;
        lcd.setCursor(x,y);
        delay(100);
        break;
        
        case 0xFF38C7:
        lcd.clear();
        for (int a=x2; a<=16; a++)
        {
            diff_lux[a]= '0';  
        }
        DIFF_LUX = atof(diff_lux);
        lcd.setCursor(0,0);
        lcd.print("Saved !!");
        Serial.print("Var = ");
        Serial.println(DIFF_LUX);
        END = true;
        delay(1000);
        lcd.clear();
        Serial.println("END !!!!!!");
        break;
      }
      Serial.println(diff_lux);
      irrecv.resume(); 
     }
     }
  }
