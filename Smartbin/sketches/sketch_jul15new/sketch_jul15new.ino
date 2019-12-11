#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define  Measure  1     //Mode select
int URECHO = 9;         // PWM Output 0-25000US,Every 50US represent 1cm
int URTRIG = 10;         // PWM trigger pin
int sensorValue = 0;    // variable to store the value coming from the sensor
int flame; //flame analog read pinno : A0
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
  pinMode(A0,INPUT);
  pinMode(22,OUTPUT);
 }
void loop()
{
  PWM_Mode();
  flamefun();
  airqual();
  delay(1000);
}
void flamefun(){
  flame = analogRead(A0);
  Serial.println(flame);
  if(flame>=1010){
    digitalWrite(22,HIGH);
    }
    else{
      digitalWrite(22,LOW);
      }
  }
 void airqual(){
  int sensorValue = analogRead(A1);
  Serial.print("Air Quality = ");
  Serial.print(sensorValue);

  Serial.println("*PPM");
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
    DistanceMeasured = (180-(LowLevelTime/50))/1.8;   // every 50us low level stands for 1cm
    if(DistanceMeasured<97){
        Serial.print(DistanceMeasured);
        Serial.println("cm");
        lcd.home();lcd.print("Reading : ");
        lcd.setCursor(10,0);
        lcd.print(DistanceMeasured);
        lcd.setCursor(13,0);lcd.print("%");
      }
      else{
          lcd.clear();
          lcd.home();
          lcd.print("Dustbin Full");
        }
    } 
  }
}
//successfull tobe modified for 180 deg
