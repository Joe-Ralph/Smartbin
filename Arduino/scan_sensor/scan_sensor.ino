int s[9] = {0,0,0,0,0,0,0,0,0};

void setup() {
  
Serial.begin(9600);
}
void loop()
{
  s[0]= digitalRead(A0);
    s[1]= digitalRead(A1);
      s[2]= digitalRead(A2);
        s[3]= digitalRead(A3);
          s[4]= digitalRead(A4);
            s[5]= digitalRead(A5);
              s[6]= digitalRead(A6);
                s[7]= digitalRead(A7);
 
  for(int i=0;i<8;i++)
  {
Serial.print(s[i]);
  }
  delay(700);
  Serial.println();
}
