#define trigPin1 4 //top
#define echoPin1 3 //top
#define trigPin2 8 //bottom
#define echoPin2 7 //bottom
#define v 5  //bottom
#define v1 6 //top
long duration1;
int distance1;
long duration2;
int distance2;
void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(v, OUTPUT);
  pinMode(v1, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  Serial.print("Distance1 = ");
  Serial.print(distance1);
  Serial.println(" cm");
  //delay(100);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
  Serial.print("Distance2 = ");
  Serial.print(distance2);
  Serial.println(" cm");
  //delay(100);
  // delay(500);
  if((distance2 >= 200)&&(distance2 <= 300))
  {
   analogWrite(v, 125);
   Serial.println("close");
  }
    else if((distance2 <200 ) && (distance2 >=30)){
      analogWrite(v, 200);
      Serial.println("Too Close");
    }
    else{
      analogWrite(v, 0);
      Serial.println("Path Clear");
         }
if((distance1 <=150)&&(distance1 >100)){
  analogWrite(v1, 125);
  Serial.println("top close");
}
else if((distance1 <= 100) &&(distance1 >50)){
   analogWrite(v1, 200);
   Serial.println("top so close");
}
else if((distance1 <=50)&&(distance1 >30)){
  analogWrite(v1, 250);
    Serial.println("top too close");
}
else{
   analogWrite(v1, 0);
   Serial.println("Not in range");
}
}
