#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void displayinit(void){

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.cp437(true); 

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("INIT"));
  display.display();
}

void ausgabe(int state, float temp){
    switch(state){
    case heiz_60:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Heizen auf 60 Grad"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;    
    case (einmeisch):
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Einmai-"));
      display.println(F("schen"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
    case heiz_63:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Heizen auf 63 Grad"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
    case(rast_45):
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("45 min"));
      display.println(F("Rast"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case heiz_66:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Heizen auf 66 Grad"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case(rast_10):
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("10 min"));
      display.println(F("Rast"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case heiz_72:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Heizen auf 72 Grad"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case(rast_15):
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("15 min"));
      display.println(F("Rast"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case heiz_76:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Heizen auf 76 Grad"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case ende:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("ENDE"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case MAN:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("MANUELL"));
      display.println(F("AN"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
   case MOFF:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("MANUELL"));
      display.println(F("AUS"));
      display.print(F("T: "));
      display.print(temp);
      display.display();
      break;
    }
}
