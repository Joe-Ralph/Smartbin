#include <SoftwareSerial.h>//include library code
//********************************************
SoftwareSerial GPSmodule(10,11);//RX, TX
//**********************************************
void setup()
{
GPSmodule.begin(9600);   
Serial.begin(9600);  
Serial.print("Please enter AT command:");  
delay(100);
}
void loop()
{
 if (Serial.available()>0)
 GPSmodule.write(Serial.read());
 if (GPSmodule.available()>0)
 Serial.write(GPSmodule.read());
}
//All AT commands RUN Correctly

Befrore cOnnecting TO internet SEt apn to www
