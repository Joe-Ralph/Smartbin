int flame;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(22,OUTPUT);
}

void loop() {
  flame = analogRead(A0);
  Serial.println(flame);
  if(flame>=1010){
    digitalWrite(22,HIGH);
    }
    else{
      digitalWrite(22,LOW);
      }
}
