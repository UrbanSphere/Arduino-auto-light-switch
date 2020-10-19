#include <Wire.h>
#include <DS3231.h>

#define lightSwitch 4
#define hourOn 20   
#define minuteOn 20  
#define secondOn 0
#define hourOff 20  
#define minuteOff 21 
#define secondOff 0

DS3231 clock;
RTCDateTime dt;

void setup() 
{
  Serial.begin(9600);
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);
  pinMode(lightSwitch, OUTPUT);
}

void loop() 
{
  dt = clock.getDateTime();
  timeDisplay();

  // Switches the light on at given time
  if(dt.hour == hourOn && dt.minute == minuteOn && dt.second == secondOn)
  {
    Serial.println("LIGHTS ON!");
    digitalWrite(lightSwitch, HIGH);
  }

  // Switches the light off at given time
  if(dt.hour == hourOff && dt.minute == minuteOff && dt.second == secondOff)
  {
    Serial.println("LIGHTS OFF!");
    digitalWrite(lightSwitch, LOW);
  }
  
  delay(1000);
}

void timeDisplay()
{
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
}
