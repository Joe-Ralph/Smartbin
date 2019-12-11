#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define  Measure  1     //Mode select
int URECHO = 3;         // PWM Output 0-25000US,Every 50US represent 1cm
int URTRIG = 5;         // PWM trigger pin    // select the input pin for the potentiometer
int sensorValue = 0;    // variable to store the value coming from the sensor
LiquidCrystal_I2C lcd(0x20, 16, 2);
unsigned int DistanceMeasured= 0;

void setup()
{
  //Serial initialization
  Serial.begin(9600);                        // Sets the baud rate to 9600
  pinMode(URTRIG,OUTPUT);                    // A low pull on pin COMP/TRIG
  digitalWrite(URTRIG,HIGH);                 // Set to HIGH
  pinMode(URECHO, INPUT);                    // Sending Enable PWM mode command
  delay(500);
  Serial.println("Init the sensor");
  lcd.begin();
lcd.backlight();

 }
void loop()
{
  PWM_Mode();
  delay(100);
}

void PWM_Mode()                              // a low pull on pin COMP/TRIG  triggering a sensor reading
{
  lcd.clear();
  Serial.print("Distance Measured=");
  digitalWrite(URTRIG, LOW);
  digitalWrite(URTRIG, HIGH);               // reading Pin PWM will output pulses
  if( Measure)
  {
    unsigned long LowLevelTime = pulseIn(URECHO, LOW) ;
    if(LowLevelTime>=45000)                 // the reading is invalid.
    {
      Serial.print("Invalid");
    }
    else{
    DistanceMeasured = LowLevelTime /50;   // every 50us low level stands for 1cm
    Serial.print(DistanceMeasured);
    Serial.println("cm");
    lcd.home();lcd.print("Reading : ");
    lcd.setCursor(10,0);
    lcd.print(DistanceMeasured);
    lcd.setCursor(13,0);lcd.print("cm");
    } 
  }
  delay(1000);
}
//successfull tobe modified for 180 deg
