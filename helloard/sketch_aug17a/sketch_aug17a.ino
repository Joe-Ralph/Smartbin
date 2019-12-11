#include <SoftwareSerial.h>
#include <DFRobot_sim808.h>
#define PIN_TX    10
#define PIN_RX    11
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  //******** Initialize sim808 module *************
  while(!sim808.init())
  {
      Serial.print("Sim808 init error\r\n");// found error
      delay(1000);
  }
  delay(3000);

  if( sim808.attachGPS())
      Serial.println("Open the GPS power success");
  else 
      Serial.println("Open the GPS power failure");
      
  Serial.println("Init Success");
}

void loop() {
   if(sim808.getGPS())
    {
      Serial.print(sim808.GPSdata.year);
      Serial.print("/");
      Serial.print(sim808.GPSdata.month);
      Serial.print("/");
      Serial.print(sim808.GPSdata.day);
      Serial.print(" ");
      Serial.print(sim808.GPSdata.hour);
      Serial.print(":");
      Serial.print(sim808.GPSdata.minute);
      Serial.print(":");
      Serial.print(sim808.GPSdata.second);
      Serial.print(":");
      Serial.println(sim808.GPSdata.centisecond);
      Serial.print("latitude :");
      Serial.println(sim808.GPSdata.lat);
      Serial.print("longitude :");
      Serial.println(sim808.GPSdata.lon);
      Serial.print("speed_kph :");
      Serial.println(sim808.GPSdata.speed_kph);
      Serial.print("heading :");
      Serial.println(sim808.GPSdata.heading);
      Serial.println();
    }
     //************* Turn off the GPS power ************
    sim808.detachGPS();
}
