void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available())
    Serial.write(Serial1.read());
    if(Serial.available())
      Serial.write(Serial.read());

}
