#include <avr/wdt.h>

#include <Wire.h>
//#include <MemoryFree.h>

#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2
#define ON 1
#define OFF 0
#define RELAY 8
#define TASTER 9
#define SCHALTER 10
#define FEHLER -100.00

#define ERSTETEMP 60.0
#define ZWEITETEMP 62.5
#define DRITTETEMP 66.0
#define VIERTETEMP 72.0
#define FUNFTETEMP 77.0
#define ERSTERAST 2100000
#define ZWEITERAST 600000
#define DRITTERAST 900000

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

enum states{
  heiz_60,
  einmeisch,
  heiz_63,
  rast_45,
  heiz_66,
  rast_10,
  heiz_72,
  rast_15,
  heiz_76,
  ende,
  MAN,
  MOFF
};


static unsigned long timeold = 0;
static unsigned long timenew = 0;

static uint8_t newstate = heiz_60;
static uint8_t brennerstat = 0;

static uint8_t speicherplatz = 0;
static float speicher[20] = { 0.0 };
static int stoerung = 0;


static float temperatur = 0;
static int thermostat = 0;


void setup() {
  // put your setup code here, to run once:
   // Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
  pinMode(TASTER, INPUT_PULLUP);
  pinMode(SCHALTER, INPUT_PULLUP);

  sensors.begin();

  displayinit();

  configure_wdt();

  speicherfuellen();

  speicherplatz = 0;


}

void loop() {
  // put your main code here, to run repeatedly:

    sensors.requestTemperatures();

  temperatur = filterfuckingtemp(sensors.getTempCByIndex(0));

  if(digitalRead(SCHALTER)){
  /*
  Serial.print(digitalRead(SCHALTER));
  Serial.print(";");
  Serial.print(newstate);
  Serial.print(";");
  Serial.print(digitalRead(TASTER));
  Serial.print(";");
  Serial.println(temperatur);
  */

  state_machine(newstate,temperatur);
    
  }

  else{
    if(thermostat == 0){
      if (digitalRead(TASTER) && (brennerstat == OFF)){

        ausgabe(MAN,temperatur);
        digitalWrite(RELAY, ON);
        
        while(digitalRead(TASTER)){}
        
        brennerstat = 1;
        
      }
      else if(digitalRead(TASTER) && (brennerstat == 1)){
        ausgabe(MOFF,temperatur);
        digitalWrite(RELAY, OFF);
        while(digitalRead(TASTER)){}
 
        brennerstat = 0;
        
      }
  
      if (brennerstat == ON){
        
        ausgabe(MAN,temperatur);
//
//        Serial.print(digitalRead(SCHALTER));
//        Serial.print(";");
//        Serial.print("Manuell");
//        Serial.print(";");
//        Serial.print(digitalRead(TASTER));
//        Serial.print(";");
//        Serial.println("BRENNER AN");    
      }
      else{
        ausgabe(MOFF,temperatur);

//        Serial.print(digitalRead(SCHALTER));
//        Serial.print(";");
//        Serial.print("Manuell");
//        Serial.print(";");
//        Serial.print(digitalRead(TASTER));
//        Serial.print(";");
//        Serial.println("BRENNER AUS");
        
      }

    }

    else{
      
    }
    
    
  }
//   Serial.println(freeMemory());
   delay(500);
   wdt_reset();

}
